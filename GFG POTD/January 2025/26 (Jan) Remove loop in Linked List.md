# 26 Remove Loop in Linked List

**The problem can be found at the following link: [Remove Loop in Linked List](https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1)**

---

## Problem Statement

Given a linked list that may contain a loop, modify the list to remove the loop if it exists, without breaking the structure of the linked list.

---

## Example:

### Input:
```
Linked List: [1 -> 2 -> 3 -> 4 -> 5], Loop Position: 2
```

### Output:
```
true
```

Explanation: The loop starting from the second node is removed, and the modified linked list is now [1 -> 2 -> 3 -> 4 -> 5].

---

## Approach

The problem can be solved by detecting the loop and removing it. The approach uses a **Hashing Method** to detect the loop efficiently.

### Steps:

1. **Use a HashSet to Detect the Loop**:
   - Traverse the linked list while maintaining a record of visited nodes in a hash set.
   - If a node is visited more than once, a loop is detected.

2. **Break the Loop**:
   - Keep track of the previous node during traversal.
   - Once a loop is detected, set the `next` pointer of the previous node to `nullptr`, breaking the loop.

3. **Edge Cases**:
   - If the linked list is empty or does not contain a loop, return without modifying the list.

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
        next = NULL;
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

bool isLoop(Node* head) {
    if (!head)
        return false;

    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow) {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node* head) {
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {
    while (head) {
        if (myMap.find(head) == myMap.end())
            return true;
        if (myMap[head] != (head->data))
            return true;

        head = head->next;
    }
    return false;
}

class Solution {
  public:
    void removeLoop(Node* head) {
        unordered_set<Node *> st;
        Node* prev = nullptr;

        while (head != nullptr) {
            if (st.find(head) == st.end()) {
                st.insert(head);
                prev = head;
                head = head->next;
            } else {
                prev->next = nullptr;  // Break the loop
                break;
            }
        }
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

        unordered_map<Node*, int> myMap;

        int n, num;
        n = arr.size();

        Node *head, *tail;
        num = arr[0];
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 1; i < n; i++) {
            num = arr[i];
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        cin.ignore();
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "false\n";
        else
            cout << "true\n";
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Explanation

### Example Walkthrough:

#### Input:
```
Linked List: [1 -> 2 -> 3 -> 4 -> 5], Loop Position: 2
```

#### Process:
1. Traverse the linked list and maintain a hash set of visited nodes.
2. Detect a loop when visiting a node already in the hash set.
3. Remove the loop by setting the `next` pointer of the previous node to `nullptr`.

#### Output:
```
true
```

---

## Complexity Analysis

- **Time Complexity:**  
  - `O(N)`, where `N` is the number of nodes in the linked list. Each node is visited once.

- **Space Complexity:**  
  - `O(N)`, due to the use of a hash set to store visited nodes.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case:
   - Space-separated list of integers representing the linked list.
   - Integer representing the position of the node where the loop is formed (0 for no loop).

### Output:
- `true` if the loop is successfully removed, and the linked list is intact.
- `false` if the linked list is not modified correctly.

---

## Contribution and Support

For any questions or suggestions, feel free to contribute or raise an issue!  
⭐ If this solution helped you, don't forget to star it! ⭐
