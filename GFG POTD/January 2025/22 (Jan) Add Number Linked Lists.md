# 22 Add Two Numbers Represented by Linked Lists

**The problem can be found at the following link: [Add Two Numbers Represented by Linked Lists](https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1)**

---

## Problem Statement

Given two linked lists `num1` and `num2` representing two non-negative integers, the digits are stored in reverse order, and each node contains a single digit. Add the two numbers and return the sum as a linked list.

### Example:

#### Input:
```
num1: 2 -> 4 -> 3
num2: 5 -> 6 -> 4
```

#### Output:
```
7 0 8
```

#### Explanation:
The two numbers represented are `342` and `465`. Their sum is `342 + 465 = 807`, which is represented as `7 -> 0 -> 8` in reverse order.

---

## Approach

### Steps:

1. **Reverse the input linked lists:**
   - Since the input lists represent numbers in reverse order, reverse them for easier addition starting from the least significant digit.

2. **Add corresponding digits:**
   - Traverse both reversed lists simultaneously, adding the digits along with any carry from the previous addition.

3. **Handle carry-over:**
   - If the sum of two digits exceeds 9, carry forward the quotient to the next addition.

4. **Create the result list:**
   - Append the remainder of the sum (i.e., `sum % 10`) to the result list.

5. **Reverse the result list:**
   - Reverse the result list before returning it to preserve the desired order of digits.

6. **Trim leading zeros:**
   - If either list contains leading zeros, skip them.

---

## Code

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = nullptr, *curr = head, *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* trimLeadingZeros(Node* head) {
        while (head->next != nullptr && head->data == 0)
            head = head->next;
        return head;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        Node* res = nullptr, *curr = nullptr;
        int carry = 0;

        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);

        num1 = reverse(num1);
        num2 = reverse(num2);

        while (num1 != nullptr || num2 != nullptr || carry != 0) {
            int sum = carry;

            if (num1 != nullptr) {
                sum += num1->data;
                num1 = num1->next;
            }

            if (num2 != nullptr) {
                sum += num2->data;
                num2 = num2->next;
            }

            Node* newNode = new Node(sum % 10);
            carry = sum / 10;

            if (res == nullptr) {
                res = newNode;
                curr = newNode;
            } else {
                curr->next = newNode;
                curr = curr->next;
            }
        }

        return reverse(res);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Explanation

- **reverse Function:**
  - Reverses the linked list to facilitate addition starting from the least significant digit.

- **trimLeadingZeros Function:**
  - Removes leading zeros in the linked lists.

- **addTwoLists Function:**
  - The main function to add two numbers represented by linked lists. It performs the addition and returns the resultant list in the desired order.

- **printList Function:**
  - Prints the elements of the linked list.

---

## Complexity Analysis

- **Time Complexity:**
  - `O(N + M)`, where `N` and `M` are the lengths of the two linked lists.

- **Space Complexity:**
  - `O(max(N, M))`, for storing the resultant linked list.

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to reach out on LinkedIn: [Aniket Yadav](https://www.linkedin.com/in/aniket-yadav-2162ab239/).

⭐ Star this repository if you found it helpful or interesting! ⭐
