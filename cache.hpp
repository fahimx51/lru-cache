#pragma once
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>
using namespace std;

class Cache {
    int capacity;
    list<pair<string, int>> order; 
    unordered_map<string, list<pair<string, int>>::iterator> pos;  

public:
    Cache(int cap) : capacity(cap) {
        if (cap <= 0) throw invalid_argument("capacity must be positive");
    }

    int get(const string& key) {
        if (!pos.count(key)) return -1;
        order.splice(order.begin(), order, pos[key]); 
        return pos[key]->second;
    }

    void put(const string& key, int value) {
        if (pos.count(key)) {  // update existing key
            pos[key]->second = value;
            order.splice(order.begin(), order, pos[key]);
            return;
        }
        if ((int)order.size() == capacity) { 
            pos.erase(order.back().first);
            order.pop_back();
        }
        order.push_front({key, value});
        pos[key] = order.begin();
    }
};