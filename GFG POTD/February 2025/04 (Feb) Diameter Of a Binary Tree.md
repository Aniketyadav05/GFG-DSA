# 4 Diameter of Binary Tree

**The problem can be found at the following link: [Diameter of Binary Tree](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1)**

---

## Problem Statement

The **diameter** of a binary tree is the **length of the longest path** between any two nodes in the tree. The length of a path is measured in terms of the number of edges.

The task is to find the diameter of a given binary tree.

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
3
```

### Explanation:
- The longest path in the tree is `4 → 2 → 1 → 3` or `5 → 2 → 1 → 3`, which consists of **3 edges**.

---

## Approach

We use **Recursion with Postorder Traversal** to compute the **diameter efficiently in O(N) time**.

### Steps:

1. **Recursive Function (`diameterRecur`)**:
   - Compute the height of the left and right subtrees.
   - Compute the **diameter** as the sum of left and right subtree heights.
   - Keep track of the **maximum diameter found so far**.

2. **Base Case**:
   - If the tree is empty (`root == nullptr`), return `0`.

3. **Return Height**:
   - The height of the current subtree is `1 + max(leftHeight, rightHeight)`.
   - Update the **maximum diameter** encountered so far.

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
        left = NULL;
        right = NULL;
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
    int diameterRecur(Node* root, int &res) {
        if (root == nullptr) return 0;

        int lHeight = diameterRecur(root->left, res);
        int rHeight = diameterRecur(root->right, res);

        res = max(res, lHeight + rHeight);

        return 1 + max(lHeight, rHeight);
    }

    int diameter(Node* root) {
        int res = 0;
        diameterRecur(root, res);
        return res;
    }
};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
        cout << "~\n";
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  - **O(N)**, where `N` is the number of nodes, as each node is visited once.

- **Space Complexity**:  
  - **O(H)**, where `H` is the height of the tree (for recursive call stack).
  - In a balanced tree, `H = log N`, so space complexity is **O(log N)**.
  - In a skewed tree, `H = N`, so space complexity is **O(N)**.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case, a space-separated string representing the binary tree in level order.

### Output:
- An integer representing the **diameter** of the binary tree.

---

## Example Walkthrough

### Input:
```
1
1 2 3 4 5 N N
```

### Output:
```
3
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐
