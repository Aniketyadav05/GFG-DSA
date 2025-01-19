# 20. Merge Two Sorted Linked Lists

**The problem can be found at the following link: [Merge Two Sorted Linked Lists](https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1)**

## Problem Statement

Given two sorted linked lists, merge them into a single sorted linked list. The new list should be made by splicing together the nodes of the given lists.

### Example:

#### Input:
```
LinkedList 1: 1->3->5->7->NULL
LinkedList 2: 2->4->6->8->NULL
```

#### Output:
```
1 2 3 4 5 6 7 8
```

#### Explanation:
The merged linked list is `1->2->3->4->5->6->7->8->NULL`.

---

## Approach

### Steps:

1. If one of the lists is empty, return the other list.
2. Compare the data of the current nodes of both lists.
3. Recursively merge the remaining lists based on the smaller value.
4. Link the smaller node to the result of the recursive merge.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if (head1 == nullptr) 
            return head2;
        if (head2 == nullptr) 
            return head1;

        if (head1->data <= head2->data) {
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        } else {
            head2->next = sortedMerge(head1, head2->next);
            return head2;
        }
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1);
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2);
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
```

---

## Explanation

- **sortedMerge Function:**
  - It checks for empty lists and returns the other list if one is empty.
  - It recursively merges the remaining parts of the lists by linking the smaller node first.

- **insertSorted Function:**
  - It inserts a new node in the correct position to keep the list sorted.

- **printList Function:**
  - It prints the elements of the merged linked list.

---

## Complexity Analysis

- **Time Complexity:**
  - `O(N + M)`, where `N` and `M` are the lengths of the two linked lists.

- **Space Complexity:**
  - `O(1)` extra space for the iterative approach, and `O(N + M)` due to recursion stack in the recursive approach.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please feel free to reach out on LinkedIn: [Aniket Yadav](https://www.linkedin.com/in/aniket-yadav-2162ab239/).

⭐ Star this repository if you found it helpful or interesting! ⭐
