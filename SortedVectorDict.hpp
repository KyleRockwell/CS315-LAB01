#pragma once
#include "Dictionary.hpp"
#include <cstddef>
#include <memory_resource>
#include <vector>
class SortedVectorDict : public Dictionary {
public:
    void insert(int) override;
    bool lookup(int) const override;
    void remove(int) override;
    std::size_t size();

private:
    std::vector<int> data;

    std::size_t lookup_idx(int) const;
};
