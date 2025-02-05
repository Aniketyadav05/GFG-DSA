# 05 Mirror Tree

**The problem can be found at the following link: [Mirror Tree](https://www.geeksforgeeks.org/problems/mirror-tree/1)**

---

## Problem Statement

Given a **binary tree**, the task is to **convert it into its mirror tree**.  
The mirror of a binary tree is obtained by swapping the left and right child of every node.

---

## Example:

### Input:
```
Tree:     1
        /   \
       2     3
      / \
     4   5
```

### Output:
```
Mirror Tree:
      1
    /   \
   3     2
        /   \
       5     4
```

### Explanation:
- The left and right children of every node are swapped.

---

## Approach

We use **Level Order Traversal with a Queue (BFS)** to convert the tree into its mirror.

### Steps:

1. **Base Case**:
   - If the tree is empty (`root == nullptr`), return.

2. **Use a Queue for Level Order Traversal**:
   - Push the root node into the queue.
   - Traverse level by level:
     - Swap the left and right children of the current node.
     - Push the left and right children into the queue.

3. **Continue until all nodes are processed**.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to build tree from input string
Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// Function to print tree in level order
string levelOrder(Node *root) {
    if (root == nullptr) return "N\n";

    string str;
    queue<Node *> qq;
    qq.push(root);

    while (!qq.empty()) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            str += "N ";
            continue;
        }
        str += (to_string(curr->data) + " ");
        qq.push(curr->left);
        qq.push(curr->right);
    }
    while (!str.empty() && !isdigit(str.back())) {
        str.pop_back();
    }
    return str;
}

class Solution {
  public:
    void mirror(Node* node) {
        if (node == nullptr) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Swap left and right children
            swap(curr->left, curr->right);

            // Add children to queue for further processing
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        ob.mirror(root);
        cout << levelOrder(root);
        cout << "\n";
        cout << "~\n";
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  - **O(N)**, where `N` is the number of nodes, since each node is visited once.

- **Space Complexity**:  
  - **O(N)** for the queue used in BFS (worst case for skewed trees).

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case, a space-separated string representing the binary tree in level order.

### Output:
- The level order traversal of the mirrored tree.

---

## Example Walkthrough

### Input:
```
1
1 2 3 4 5 N N
```

### Output:
```
1 3 2 N N 5 4
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐
