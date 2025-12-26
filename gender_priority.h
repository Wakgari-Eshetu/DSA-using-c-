#pragma once
#include <queue>
#include <iostream>
#include "person.h"

class GenderPriorityQueue {
private:
    std::queue<Person> femaleQ;
    std::queue<Person> maleQ;
public:
    void insert(const Person& p) {
        if (p.gender == 'F' || p.gender == 'f') femaleQ.push(p);
        else maleQ.push(p);
    }

    // remove highest-priority element (female first); returns true if removed
    bool remove(Person& out) {
        if (!femaleQ.empty()) { out = femaleQ.front(); femaleQ.pop(); return true; }
        if (!maleQ.empty()) { out = maleQ.front(); maleQ.pop(); return true; }
        return false;
    }

    void display(std::ostream& os = std::cout) const {
        std::queue<Person> f = femaleQ;
        std::queue<Person> m = maleQ;
        if (f.empty() && m.empty()) { os << "Queue is empty\n"; return; }
        int idx = 1;
        os << "Queue (Females first, then Males)\n";
        while (!f.empty()) {
            const Person& p = f.front();
            os << idx++ << ". " << p.name << " (" << p.gender << ", " << p.age << ")\n";
            f.pop();
        }
        while (!m.empty()) {
            const Person& p = m.front();
            os << idx++ << ". " << p.name << " (" << p.gender << ", " << p.age << ")\n";
            m.pop();
        }
    }

    bool empty() const { return femaleQ.empty() && maleQ.empty(); }
    size_t size() const { return femaleQ.size() + maleQ.size(); }
};
