#include "pqueue.hpp"
#include <string>

pqueue::handle pqueue::insert(int priority, std::string const& name) {
    auto iter = std::make_unique<size_t>(heap.size());
    heap.emplace_back(heap_element{priority, std::move(iter), name});
    auto handle = heap.back().iter.get();
    return handle;
}

void pqueue::erase(handle it) {
    size_t pos = *it;
    if (pos != heap.size() - 1) {
        std::swap(heap[pos], heap.back());
        *(heap[pos].iter) = pos;
    }
    heap.pop_back();
}

void pqueue::update_priority(handle const& it, int new_priority) {
    heap[*it].priority = new_priority;
}

std::string pqueue::extract_min() {
    std::string s = heap.front().payload;
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    *(heap.front().iter) = 0;
    return s;
}

std::string const& pqueue::get(handle const& it) const {
    return heap[*it].payload;
}

int pqueue::get_priority(handle const& it) const {
    return heap[*it].priority;
}

size_t pqueue::size() const {
    return heap.size();
}
