# 19. Rotate a Linked List

**The problem can be found at the following link: [Rotate a Linked List](https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1)**

## Problem Statement

Given a singly linked list and an integer `k`, rotate the linked list to the right by `k` places.

### Example:

#### Input:
```
LinkedList: 1->2->3->4->5->NULL, k = 2
```

#### Output:
```
4 5 1 2 3
```

#### Explanation:
After rotating the list by 2 places, the new list becomes `4->5->1->2->3->NULL`.

---

## Approach

### Steps:

1. Calculate the length of the linked list.
2. Update `k` as `k % length` to handle cases where `k` is greater than the length of the list.
3. If `k` is 0, return the original list as no rotation is needed.
4. Traverse the list to the `(length - k)`-th node.
5. Update the next pointer of the current node to `NULL` and make the next node as the new head.
6. Link the last node of the list to the original head.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (k == 0 || head == nullptr)
            return head;

        Node *curr = head;
        int len = 1;
      
        while (curr->next != nullptr) {
            curr = curr->next;
            len += 1;
        }
        
        k %= len;
        if (k == 0)
            return head;
          
        curr->next = head; // Make it circular
        
        curr = head;
        for (int i = 1; i < len - k; i++)
            curr = curr->next;
    
        head = curr->next;
        curr->next = nullptr;
        return head;
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

        Node* head = nullptr;
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}
```

---

## Explanation

- **rotate Function:**
  - It calculates the length of the list and updates `k` as `k % length`.
  - If `k` is 0, it returns the original head.
  - Otherwise, it makes the list circular, moves to the `(length - k)`-th node, and updates the next pointers to rotate the list.

- **printList Function:**
  - It prints the linked list starting from the head.

---

## Complexity Analysis

- **Time Complexity:**
  - `O(N)`, where `N` is the number of nodes in the linked list.

- **Space Complexity:**
  - `O(1)` as only constant extra space is used.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please feel free to reach out on LinkedIn: [Aniket Yadav](https://www.linkedin.com/in/aniket-yadav-2162ab239/).

⭐ Star this repository if you found it helpful or interesting! ⭐
