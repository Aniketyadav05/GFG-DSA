# 23 Clone a Linked List with Next and Random Pointer

**The problem can be found at the following link: [Clone a Linked List with Next and Random Pointer](https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1)**

---

## Problem Statement

You are given a linked list where each node has two pointers:  
1. `next` - pointing to the next node in the list.  
2. `random` - pointing to any node in the list or `NULL`.

The task is to create a deep copy (clone) of the given linked list.

### Example:

#### Input:
```
Nodes: [1, 2, 3, 4]
Random Links: [2, 4, NULL, 1]
```

#### Output:
```
[1, 2], [2, 4], [3, NULL], [4, 1]
```

---

## Approach

### Steps:

1. **Insert cloned nodes between original nodes:**
   - For each node in the original list, create a new node with the same value.
   - Insert the new node immediately after the corresponding original node.

2. **Set the `random` pointers of the cloned nodes:**
   - For each node in the original list, if its `random` pointer is not `NULL`, set the `random` pointer of its clone to point to the clone of the original's `random` node.

3. **Separate the cloned list from the original:**
   - Restore the original list by skipping the cloned nodes, and construct the cloned list by linking the cloned nodes.

---

## Code

```cpp
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        
        Node* curr = head;

        // Step 1: Insert cloned nodes between original nodes
        while (curr != NULL) {
            Node* newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Set the random pointers of cloned nodes
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the cloned list from the original list
        curr = head;
        Node* clonedHead = head->next;
        Node* clone = clonedHead;

        while (clone->next != NULL) {
            curr->next = curr->next->next;
            clone->next = clone->next->next;

            curr = curr->next;
            clone = clone->next;
        }
        
        curr->next = NULL;
        clone->next = NULL;

        return clonedHead;
    }
};
```

---

## Explanation

- **Step 1:**  
   - Insert a new node after every original node with the same value.  
   - Example: Original list `1 -> 2 -> 3` becomes `1 -> 1' -> 2 -> 2' -> 3 -> 3'`.

- **Step 2:**  
   - Copy the `random` pointers from the original nodes to the corresponding cloned nodes.  
   - Example: If `1.random = 3`, then `1'.random = 3'`.

- **Step 3:**  
   - Restore the original list and extract the cloned list by splitting the interleaved list.  
   - Example: Split `1 -> 1' -> 2 -> 2' -> 3 -> 3'` into `1 -> 2 -> 3` and `1' -> 2' -> 3'`.

---

## Complexity Analysis

- **Time Complexity:**  
  - `O(N)`, where `N` is the number of nodes in the linked list. Each node is traversed three times: for insertion, setting `random` pointers, and separating the lists.

- **Space Complexity:**  
  - `O(1)`, as no extra space is used other than the cloned nodes.

---

## Input and Output Explanation

### Input Format:
- Number of test cases `T`.
- For each test case:
  - Number of nodes `N`.
  - A pair of integers: `[data, random_index]` for each node, where `random_index` is `-1` if the random pointer is `NULL`.

### Output Format:
- A list of cloned nodes and their `random` pointers in the format `[data, random_index]`.

---

## Contribution and Support

For discussions or questions regarding the code, feel free to reach out!

⭐ If you found this helpful, consider giving it a star! ⭐
