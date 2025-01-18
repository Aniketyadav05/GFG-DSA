# 18 Reverse a Linked List

**The problem can be found at the following link: [Reverse a Linked List](https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1)**
## Problem Statement:

Given a linked list of `N` nodes. The task is to reverse this list.

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
After reversing the list, elements are `5->4->3->2->1->NULL`.

### Approach:

1. **Use a Stack:**
   - Traverse the linked list and push each node onto a stack.
   - Once all nodes are on the stack, pop each node and rearrange the links to reverse the list.

### Code

```cpp
// Initial Template for C++
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
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

// User function template for C++

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        stack<Node*> s;
        Node* temp = head;
        
        while (temp->next != NULL) {
            s.push(temp);
            temp = temp->next;
        }
        
        head = temp;
        
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int T, n, l, firstdata;
    cin >> T;
    cin.ignore();
    while (T--) {
        Node *head = NULL, *tail = NULL;

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int index = 0;
        n = arr.size();
        if (n != 0) {
            head = new Node(arr[0]);
            tail = head;
        }

        for (int i = 1; i < n; i++) {
            l = arr[i];
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
        cout << "~\n";
    }
    return 0;
}
```

### Explanation:

- **reverseList Function:**
  - It uses a stack to store nodes while traversing the linked list.
  - After storing all nodes, it pops them and changes the links to reverse the list.

- **Main Function:**
  - It reads multiple test cases, converts each test case into a linked list, and calls the `reverseList` function.

### Complexity Analysis:

- **Time Complexity:**
  - The time complexity is `O(N)` where `N` is the number of nodes in the linked list.

- **Space Complexity:**
  - The space complexity is `O(N)` for the stack used to store the nodes.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/aniket-yadav-2162ab239/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

