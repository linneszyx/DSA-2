#include <bits/stdc++.h>
using namespace std;
// Node Class
class Node
{
public:
    string key;
    int value;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
// LRU Cache Class
class LRUCache
{
public:
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> m;
    LRUCache(int maxSize)
    {
        this->maxSize = maxSize > 1 ? maxSize : 1;
    }
    void insertKeyValue(string key, int value)
    {
        // 2 cases
        // 1. if key already exists, update the value and move it to the front
        if (m.count(key) != 0)
        {
            auto it = m[key];
            it->value = value;
        }
        // 2. if key doesn't exist
        else
        {
            // 2.1. if cache is full, remove the last element from the list and map
            if (l.size() == maxSize)
            {
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }
            // 2.2. add the new node to the front of the list and map
            Node n(key, value);
            l.push_front(n);
            m[key] = l.begin();
        }
    }
    int getValue(string key) {
        if(m.count(key) != 0) {
            auto it = m[key];
            int value = it->value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return m[key]->value;
        }
        return -1;
    }
    string mostRecentKey() {
        return l.front().key;
    }
};
int main()
{
    LRUCache lru(3);
    lru.insertKeyValue("mango", 10);
    lru.insertKeyValue("apple", 20);
    lru.insertKeyValue("guava", 30);
    cout << lru.mostRecentKey() << endl;
    lru.insertKeyValue("mango", 40);
    cout << lru.mostRecentKey() << endl;
    lru.insertKeyValue("banana", 20);
    if(lru.getValue("apple") == -1) {
        cout << "apple doesn't exist" << endl;
    }
    if(lru.getValue("guava") == -1) {
        cout << "guava doesn't exist" << endl;
    }
    if(lru.getValue("mango") == -1) {
        cout << "mango doesn't exist" << endl;
    }
    if(lru.getValue("banana") == -1) {
        cout << "banana doesn't exist" << endl;
    }
    return 0;
}