# 25 Find the First Node of Loop in Linked List

**The problem can be found at the following link: [Find the First Node of Loop in Linked List](https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1)**

---

## Problem Statement

Given a linked list that may contain a loop, find the first node of the loop if it exists. If there is no loop, return `-1`.

---

## Example:

### Input:
```
Linked List: [1 -> 2 -> 3 -> 4 -> 5]
Loop Position: 2
```

### Output:
```
2
```

Explanation: The second node in the linked list is the starting point of the loop.

---

## Approach

This problem uses **Floyd’s Cycle Detection Algorithm** (also known as the two-pointer approach) to both detect the loop and find the first node of the loop.

### Steps:

1. **Detect the Loop**:
   - Use two pointers, `slow` and `fast`, where `slow` moves one step at a time and `fast` moves two steps at a time.
   - If `slow` and `fast` meet, a loop is detected.

2. **Find the First Node of the Loop**:
   - Move one of the pointers (`slow`) back to the head of the linked list.
   - Move both `slow` and `fast` one step at a time until they meet. The meeting point is the first node of the loop.

3. **Return the Result**:
   - Return the data of the first node of the loop, or `-1` if no loop exists.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
    
        // Detect loop using Floyd’s Cycle Detection Algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Reset one pointer to head and move both one step at a time
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // First node of the loop
            }
        }
        return nullptr; // No loop
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        assert(k <= arr.size());
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        Node *ans = ob.findFirstNode(head);
        cout << (ans == NULL ? -1 : ans->data) << "\n";
        cout << "~\n";
    }
    return 0;
}
```

---

## Explanation

### Example Walkthrough:

#### Input:
```
Linked List: [1 -> 2 -> 3 -> 4 -> 5]
Loop Position: 2
```

#### Process:
1. Detect the loop using `slow` and `fast` pointers.
2. Reset `slow` to the head of the list and move both pointers one step at a time until they meet.
3. The meeting point is the first node of the loop.

#### Output:
```
2
```

---

## Complexity Analysis

- **Time Complexity:**  
  - `O(N)`, where `N` is the number of nodes in the linked list. Both detection and finding the first node involve traversing the list.

- **Space Complexity:**  
  - `O(1)`, as no extra space is used.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case:
   - Space-separated list of integers representing the linked list.
   - Integer representing the position of the node where the loop is formed (0 for no loop).

### Output:
- The data of the first node of the loop if it exists, or `-1` if there is no loop.

---

## Contribution and Support

For any questions or suggestions, feel free to contribute or raise an issue!  
⭐ If this solution helped you, don't forget to star it! ⭐
