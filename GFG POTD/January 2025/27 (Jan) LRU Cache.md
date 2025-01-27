# 27 LRU Cache

**The problem can be found at the following link: [LRU Cache](https://www.geeksforgeeks.org/problems/lru-cache/1)**

---

## Problem Statement

Design a data structure for an LRU (Least Recently Used) Cache. Implement the following operations for the cache:
1. **get(key)**: Returns the value of the key if it exists in the cache; otherwise, return `-1`.
2. **put(key, value)**: Inserts or updates the value of the key. If the cache exceeds its capacity, the least recently used item should be evicted.

---

## Example:

### Input:
```
Capacity: 2
Operations: PUT(1, 10), PUT(2, 20), GET(1), PUT(3, 30), GET(2), GET(3)
```

### Output:
```
10 -1 30
```

Explanation:
- PUT(1, 10): Cache is now [(1, 10)].
- PUT(2, 20): Cache is now [(2, 20), (1, 10)].
- GET(1): Returns 10 and moves (1, 10) to the front. Cache is now [(1, 10), (2, 20)].
- PUT(3, 30): Evicts least recently used (2, 20). Cache is now [(3, 30), (1, 10)].
- GET(2): Returns `-1` as (2, 20) was evicted.
- GET(3): Returns 30 and moves (3, 30) to the front. Cache is now [(3, 30), (1, 10)].

---

## Approach

We use a combination of:
1. **Doubly Linked List**:
   - To maintain the order of elements based on usage.
   - The most recently used element is at the front, and the least recently used is at the back.
   
2. **Hash Map**:
   - For O(1) access to the nodes of the linked list using their keys.

### Steps:

1. **Initialization**:
   - Use a `list` for the doubly linked list and an `unordered_map` to map keys to the list iterators.
   - Store the cache capacity.

2. **`get(key)`**:
   - If the key exists in the cache, move the corresponding node to the front of the list and return its value.
   - If the key does not exist, return `-1`.

3. **`put(key, value)`**:
   - If the key already exists, update its value and move it to the front of the list.
   - If the key does not exist:
     - If the cache is full, remove the least recently used element (the back of the list).
     - Add the new key-value pair to the front of the list.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
  private:
    int capacity;
    list<pair<int, int>> cache; // Doubly linked list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> map; // Hash map for fast access

  public:
    // Constructor to initialize the cache with the given capacity
    LRUCache(int cap) : capacity(cap) {}

    // Function to return the value corresponding to the key
    int get(int key) {
        if (!map.count(key)) return -1; // Key not found
        cache.splice(cache.begin(), cache, map[key]); // Move accessed node to the front
        return map[key]->second; // Return the value
    }

    // Function to store a key-value pair
    void put(int key, int value) {
        if (map.count(key)) {
            // Key already exists; update value and move node to the front
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
        } else {
            // Key does not exist
            if (cache.size() == capacity) {
                // Cache is full; remove the least recently used element
                map.erase(cache.back().first);
                cache.pop_back();
            }
            // Add the new key-value pair to the front of the list
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int capacity;
        cin >> capacity;
        LRUCache* cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key, value;
                cin >> key >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        delete cache;
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:
  - `get(key)`: O(1) due to hash map lookup and list splice.
  - `put(key, value)`: O(1) for both insertion and eviction operations.

- **Space Complexity**:
  - O(Capacity) for the doubly linked list and hash map.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case:
   - Cache capacity.
   - Number of queries.
   - Each query can be either:
     - `PUT key value`
     - `GET key`

### Output:
- For each `GET` query, print the value of the key or `-1` if the key is not found.

---

## Example Walkthrough

### Input:
```
1
2
6
PUT 1 10
PUT 2 20
GET 1
PUT 3 30
GET 2
GET 3
```

### Output:
```
10 -1 30
```

---

## Contribution and Support

If you have any questions, feel free to reach out or raise an issue.  
⭐ If this solution helped you, please give it a star! ⭐
