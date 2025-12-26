#pragma once
#include <string>

struct Person {
    std::string name;
    char gender; // 'M' or 'F'
    int age;
    Person(const std::string& n = "", char g = 'M', int a = 0) : name(n), gender(g), age(a) {}
};

struct PersonCompare {
    // Return true if a has LOWER priority than b
    bool operator()(const Person& a, const Person& b) const {
        int pa = (a.gender == 'F' || a.gender == 'f') ? 2 : 1;
        int pb = (b.gender == 'F' || b.gender == 'f') ? 2 : 1;
        if (pa != pb) return pa < pb; // lower numeric score => lower priority
        return a.age < b.age; // younger => lower priority
    }
};
