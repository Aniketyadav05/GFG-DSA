# 3. Height of Binary Tree

**The problem can be found at the following link: [Height of Binary Tree](https://www.geeksforgeeks.org/problems/height-of-binary-tree/1)**

---

## Problem Statement

Given the root of a binary tree, the task is to find its height.  
- The **height** of a binary tree is the number of edges on the longest path from the root node to a leaf node.
- An **empty tree** has a height of `0`.
- A **tree with a single node** has a height of `0`.

---

## Example:

### Input:
```
Tree:   1
       /   \
      2     3
     / \
    4   5
```

### Output:
```
2
```

Explanation:
- The longest path from the root node `1` to the leaf nodes (`4` or `5`) has `2` edges.
- Therefore, the height of the tree is `2`.

---

## Approach

We use **Breadth-First Search (BFS) / Level Order Traversal** to calculate the height of the tree iteratively.

### Steps:

1. **Base Case**:
   - If the tree is empty (`root == NULL`), return `0`.

2. **Level Order Traversal using a Queue**:
   - Push the root node into the queue.
   - Traverse level by level:
     - Count the number of nodes at the current level.
     - Process each node and push its children into the queue.
     - After processing a level, increment the `depth` counter.

3. **Return Depth**:
   - The final value of `depth` gives the height of the binary tree.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to build tree from input string
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
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

class Solution {
  public:
    int height(Node* node) {
        if (!node) return 0;

        queue<Node*> q;
        q.push(node);
        int depth = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            depth++;
        }
        return depth - 1;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.height(root) << endl;
        cout << "~\n";
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  - **O(N)**, where `N` is the number of nodes in the tree, as each node is visited once.

- **Space Complexity**:  
  - **O(N)** in the worst case (when the tree is completely unbalanced and behaves like a linked list).

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case, a space-separated string representing the binary tree in level order.

### Output:
- An integer representing the height of the binary tree.

---

## Example Walkthrough

### Input:
```
1
1 2 3 4 5 N N
```

### Output:
```
2
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐
