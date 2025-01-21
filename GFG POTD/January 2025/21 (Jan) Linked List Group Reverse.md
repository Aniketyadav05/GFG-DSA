# 21. Reverse a Linked List in Groups of Given Size

**The problem can be found at the following link: [Reverse a Linked List in Groups of Given Size](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)**

## Problem Statement

Given a linked list of size `N` and a positive integer `k`, reverse the linked list in groups of size `k`. If the number of nodes is not a multiple of `k`, then left-out nodes in the end should remain as it is.

### Example:

#### Input:
```
LinkedList: 1->2->3->4->5->6->7->8->NULL, K = 3
```

#### Output:
```
3 2 1 6 5 4 7 8
```

#### Explanation:
The linked list is reversed in groups of size `3`. After reversing, it becomes `3->2->1->6->5->4->7->8->NULL`.

---

## Approach

### Steps:

1. Use a stack to temporarily store nodes in groups of size `k`.
2. Reverse the nodes within each group by popping them from the stack and linking them.
3. If the remaining nodes are fewer than `k`, they remain in the original order.

---

## Code

```cpp
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        stack<Node*> st; 
        Node* curr = head; 
        Node* prev = nullptr; 
  
        while (curr != nullptr) { 
            int count = 0; 
            while (curr != nullptr && count < k) { 
                st.push(curr); 
                curr = curr->next; 
                count++; 
            } 

            while (!st.empty()) { 
                if (prev == nullptr) { 
                    prev = st.top(); 
                    head = prev; 
                    st.pop(); 
                } else { 
                    prev->next = st.top(); 
                    prev = prev->next; 
                    st.pop(); 
                } 
            } 
        } 
  
        prev->next = nullptr; 
        return head; 
    }
};

int main(void) {
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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
```

---

## Explanation

- **reverseKGroup Function:**
  - The function checks if the linked list is empty or `k` is `1`. If so, it returns the original head.
  - It uses a stack to reverse nodes in groups of size `k`.
  - After processing each group, it links the reversed nodes to the previous group.

- **printList Function:**
  - This function prints the elements of the linked list.

---

## Complexity Analysis

- **Time Complexity:**
  - `O(N)`, where `N` is the number of nodes in the linked list.

- **Space Complexity:**
  - `O(k)` for the stack used to reverse nodes in groups of size `k`.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please feel free to reach out on LinkedIn: [Aniket Yadav](https://www.linkedin.com/in/aniket-yadav-2162ab239/).

⭐ Star this repository if you found it helpful or interesting! ⭐
