#include <cassert>
#include <iostream>
#include "cache.hpp"
using namespace std;

int main() {
    // example from the task
    {
        Cache c(2);
        c.put("A", 10);
        c.put("B", 20);
        assert(c.get("A") == 10);
        c.put("C", 30);
        assert(c.get("B") == -1);
        assert(c.get("C") == 30);
        assert(c.get("A") == 10);
    }
    // updating a key changes its value and makes it most recent
    {
        Cache c(2);
        c.put("A", 1);
        c.put("B", 2);
        c.put("A", 100);
        c.put("C", 3);  // evicts B, not A
        assert(c.get("B") == -1);
        assert(c.get("A") == 100);
    }
    // capacity 1
    {
        Cache c(1);
        c.put("A", 1);
        c.put("B", 2);
        assert(c.get("A") == -1);
        assert(c.get("B") == 2);
    }
    // missing key
    {
        Cache c(2);
        assert(c.get("nope") == -1);
    }
    // invalid capacity
    {
        bool thrown = false;
        try { Cache c(0); } catch (const invalid_argument&) { thrown = true; }
        assert(thrown);
    }
    cout << "All tests passed\n";
    return 0;
}