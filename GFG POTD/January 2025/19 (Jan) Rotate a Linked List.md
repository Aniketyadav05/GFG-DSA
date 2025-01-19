# 19 Reverse a Linked List

**The problem can be found at the following link: [Reverse a Linked List](https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1)**

## Problem Statement

Given a linked list of `N` nodes, the task is to reverse the list.

### Example:

#### Input:
```
LinkedList: 1->2->3->4->5->NULL
```

#### Output:
```
5 4 3 2 1
```

#### Explanation:
After reversing the list, the elements are `5->4->3->2->1->NULL`.

---

## Approach

### Using a Stack:

1. Traverse the linked list and push each node onto a stack.
2. Once all nodes are on the stack, pop each node and rearrange the links to reverse the list.

---

## Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        stack<Node*> s;
        Node* temp = head;
        
        while (temp != NULL) {
            s.push(temp);
            temp = temp->next;
        }
        
        head = s.top();
        s.pop();
        temp = head;
        
        while (!s.empty()) {
            temp->next = s.top();
            s.pop();
            temp = temp->next;
        }
        
        temp->next = NULL;
        return head;
    }
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution ob;
    head = ob.reverseList(head);

    printList(head);

    return 0;
}
```

---

## Explanation

- **reverseList Function:**
  - The function uses a stack to store the nodes while traversing the linked list.
  - After storing all nodes, it pops them and rearranges the links to reverse the list.

- **printList Function:**
  - It prints the reversed linked list.

---

## Complexity Analysis

- **Time Complexity:**
  - `O(N)`, where `N` is the number of nodes in the linked list.

- **Space Complexity:**
  - `O(N)` for the stack used to store the nodes.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please feel free to reach out on LinkedIn: [Aniket Yadav](https://www.linkedin.com/in/aniket-yadav-2162ab239/).

⭐ Star this repository if you found it helpful or interesting! ⭐
