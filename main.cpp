#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "Dictionary.hpp"
#include "SortedLinkedListDict.hpp"
#include "SortedVectorDict.hpp"
#include "UnsortedLinkedListDict.hpp"
#include "UnsortedVectorDict.hpp"

enum InputType { RANDOM,
    NEARLY_SORTED };

std::vector<int> generate_keys(int N)
{

    // Uses a random distribution to generate keys randomly

    std::vector<int> keys(N);
    std::mt19937 rng(42); //
    std::uniform_int_distribution<int> dist(1, 500 * N);

    for (int& k : keys)
        k = dist(rng);
    return keys;
}
// code to test if vector is sorted correctly, and if size is correct
// rng taken from benchmark function
void sorted_vector_test()
{
    // SortedVectorDict dict;
    // const int M = 500;
    // const int N = 5000;
    // std::vector<int> keys = generate_keys(N);
    // std::mt19937 rng(100);
    // std::uniform_int_distribution<int> dist(1, 500 * N);
    // std::vector<int> lookups(M);
    // for (int& k : lookups)
    //     k = dist(rng);
    //
    // auto start_insert = std::chrono::high_resolution_clock::now();
    // for (int k : keys)
    //     dict.insert(k);
    //
    // if (dict.size() == 0) {
    //     std::cout << "empty dictionary" << std::endl;
    //
    // } else if (dict.size() == 1) {
    //     std::cout << "dict of one element: " << dict[0];
    //
    // } else {
    //     int j = 0;
    //     for (int i = 1; i <= dict.size(); i++) {
    //         if (j > i) {
    //             std::cout << "dict is not in order" << dict[i] << ">" << dict[j] << std::endl;
    //             return;
    //         }
    //         j++;
    //     }
    //     std::cout << "dict is in order. dict size is:" << dict.size();
    // }
}

void benchmark(Dictionary* dict, const std::string& label, int N, std::ofstream& csv)
{
    const int M = 500;
    std::vector<int> keys = generate_keys(N);
    std::mt19937 rng(100);
    std::uniform_int_distribution<int> dist(1, 500 * N);
    std::vector<int> lookups(M);
    for (int& k : lookups)
        k = dist(rng);

    auto start_insert = std::chrono::high_resolution_clock::now();
    for (int k : keys)
        dict->insert(k);

    auto end_insert = std::chrono::high_resolution_clock::now();

    auto start_lookup = std::chrono::high_resolution_clock::now();
    for (int k : lookups) {
        dict->lookup(k);
    }
    auto end_lookup = std::chrono::high_resolution_clock::now();

    auto insert_time = std::chrono::duration_cast<std::chrono::microseconds>(end_insert - start_insert).count();
    auto total_lookup_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_lookup - start_lookup).count();
    long long avg_lookup_ns = total_lookup_time_ns / M;

    std::cout << label << " [" << "N=" << N << "] — Insert: " << insert_time << "us, Avg Lookup: " << avg_lookup_ns << "ns\n";
    csv << label << "," << "," << N << "," << insert_time << "," << avg_lookup_ns << "\n";

    delete dict;
}

int main()
{
    std::ofstream csv("benchmark_results_avgonly.csv");
    csv << "Structure,InputType,N,InsertTime(us),AvgLookup(ns)\n";

    std::vector<int> sizeV = { 5000, 500000 };
    for (auto N : sizeV) {
        benchmark(new UnsortedVectorDict(), "Unsorted Vector", N, csv);
        benchmark(new SortedVectorDict(), "Sorted Vector", N, csv);
        benchmark(new UnsortedLinkedListDict(), "Unsorted Linked List", N, csv);
        benchmark(new SortedLinkedListDict(), "Sorted Linked List", N, csv);
    }

    csv.close();
    // sorted_vector_test();
    return 0;
}
