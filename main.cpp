#include <iostream>
#include "cache.hpp"
using namespace std;

int main() {
    Cache cache(2);
    cout << "cache = Cache(2)\n";

    cache.put("A", 10);
    cout << "put(\"A\", 10)\n";
    cache.put("B", 20);
    cout << "put(\"B\", 20)\n";
    cout << "get(\"A\") -> " << cache.get("A") << "\n";
    cache.put("C", 30);
    cout << "put(\"C\", 30)   // evicts B\n";
    cout << "get(\"B\") -> " << cache.get("B") << "\n";
    cout << "get(\"C\") -> " << cache.get("C") << "\n";
    cout << "get(\"A\") -> " << cache.get("A") << "\n";
    return 0;
}