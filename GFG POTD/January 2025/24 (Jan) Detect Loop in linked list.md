# 24 Detect Loop in a Linked List

**The problem can be found at the following link: [Detect Loop in Linked List](https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1)**

---

## Problem Statement

Given a linked list, determine if there is a loop (cycle) in the linked list.  
A loop in a linked list occurs when a node's `next` pointer points back to one of the previous nodes in the list, forming a cycle.

---

## Example:

### Input:
```
Linked List: [1, 2, 3, 4, 5]
Position to form loop: 2
```

### Output:
```
true
```

Explanation: The second node in the linked list points back to an earlier node, forming a loop.

---

## Approach

To detect a loop in the linked list, the **Floyd’s Cycle Detection Algorithm** (also known as the two-pointer approach) is used.

### Steps:

1. **Initialize two pointers**:
   - `slow` pointer moves one step at a time.
   - `fast` pointer moves two steps at a time.

2. **Traverse the list**:
   - If `slow` and `fast` pointers meet at some point, a loop exists.
   - If `fast` or `fast->next` becomes `NULL`, no loop exists.

3. **Return the result**:
   - Return `true` if a loop is detected; otherwise, return `false`.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution {
  public:
    bool detectLoop(Node* head) {
        Node *slow = head, *fast = head;

        // Traverse the linked list
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, a loop exists
            if (slow == fast) {
                return true;
            }
        }
        return false;
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

        int pos;
        cin >> pos;
        cin.ignore();

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
            loopHere(head, tail, pos);
        }

        Solution ob;
        if (ob.detectLoop(head))
            cout << "true\n";
        else
            cout << "false\n";

        // Free the allocated memory
        unordered_set<Node*> visited;
        Node* current = head;
        while (current && visited.find(current) == visited.end()) {
            visited.insert(current);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
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
1. Initialize `slow` and `fast` pointers at the head of the linked list.
2. Move `slow` one step and `fast` two steps at a time.
3. If `slow` and `fast` meet, a loop is detected.

#### Output:
```
true
```

---

## Complexity Analysis

- **Time Complexity:**  
  - `O(N)`, where `N` is the number of nodes in the linked list. The `slow` and `fast` pointers traverse the list at most once.

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
- `true` if a loop is detected; otherwise, `false`.

---

## Contribution and Support

For any questions or improvements, feel free to reach out or raise an issue!  
⭐ If this helped you, don't forget to star it! ⭐
