#include "SortedVectorDict.hpp"
#include <cstddef>
#include <iostream>
// search thru vector
// find value greater than key
// insert key right before "greater than value"

std::size_t SortedVectorDict::size()
{
    return size();
}
void SortedVectorDict::insert(int key)
{

    /*add key to end of vector
     * while key is less than vector[vector.length-i]
     *      swap
     *      i--
     *
     */

    auto i = data.size();
    // std::cout << i << std::endl;
    if (data.empty()) {
        data.push_back(key);
    } else {
        int temp = data.back();

        data.push_back(key);
        std::cout << "data[i]:" << data[i - 1] << "  key:" << key << "   key > data[i]" << (key > data[i - 1]) << std::endl;

        while (key < data[i - 1]) {
            temp = data[i];
            std::cout << std::endl
                      << "sort" << std::endl;
            //  data[i] = data[i + 1];
            data[i + 1] = temp;
            i--;
            std::cout << key << std::endl;
        }
    }
}

bool SortedVectorDict::lookup(int key) const
{

    for (auto i = 0; i < data.size(); i++) {
        if (data[i] == key) {
            return i;
        }
    }

    return false;
}

void SortedVectorDict::remove(int key)
{
    // just taken from unsorted vector

    // TODO: cant just place in middle
    for (auto i = 0; i < data.size(); i++) {
        if (data[i] == key && i != data.size()) {
            data[i] = data.back();
            data.pop_back();
        }
    }
}
std::size_t SortedVectorDict::lookup_idx(int key) const
{
    /* go halfway thru vec, check if key is greater than value.
     * if greater than, check halfway next half,
     * if less than check halfway previous half
     * repeat
     */
    // int n = 2;
    // int i = data.size() / n;
    // while (data[i] != key) {
    //     if (key > data[i]) {
    //         i += data.size() / n;
    //     }
    // }

    return 0;
}
