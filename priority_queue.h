#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include "person.h"

class PriorityQueue {
private:
    std::priority_queue<Person, std::vector<Person>, PersonCompare> pq;
public:
    void insert(const Person& p) { pq.push(p); }
    bool erase_top() { if (pq.empty()) return false; pq.pop(); return true; }
    const Person& top() const { return pq.top(); }
    bool empty() const { return pq.empty(); }
    size_t size() const { return pq.size(); }

    void display(std::ostream& os = std::cout) const {
        if (pq.empty()) { os << "Queue is empty\n"; return; }
        auto copy = pq; // copy to iterate
        while (!copy.empty()) {
            const Person& p = copy.top();
            os << p.name << " (" << p.gender << ", " << p.age << ")\n";
            copy.pop();
        }
    }
};
