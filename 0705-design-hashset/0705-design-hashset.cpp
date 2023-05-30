// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class MyHashSet
{
public:
    /** Initialize your data structure here. */
    vector<int> hsh;
    MyHashSet()
    {
        hsh.resize(1e6 + 1);
    }

    void add(int key)
    {
        hsh[key] = 1;
    }

    void remove(int key)
    {
        if (hsh[key] > 0)
            hsh[key]--;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        if (hsh[key] > 0)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */