# Level Order Traversal of a Binary Tree 🌳

**The problem can be found at the following link: [Level Order Traversal](https://www.geeksforgeeks.org/problems/level-order-traversal/1)**

---

## Problem Statement

Given a binary tree, the task is to perform a **Level Order Traversal** of the tree. Level Order Traversal means visiting all nodes of the tree level by level, starting from the root and moving down to the leaves.

---

## Example:

### Input:
```
1
1 2 3 4 5 6 7
```

### Output:
```
1 2 3 4 5 6 7
```

---

## Approach

We use a **Breadth-First Search (BFS)** approach to traverse the tree level by level. BFS is implemented using a **queue** data structure.

### Steps:

1. **Initialize a Queue**:
   - Start by enqueueing the root node of the tree.

2. **Process the Queue**:
   - Dequeue a node from the queue and process it (add its value to the result).
   - Enqueue its left child if it exists.
   - Enqueue its right child if it exists.
   - Repeat until the queue is empty.

3. **Result**:
   - The nodes are processed in the order they are visited, which ensures level-order traversal.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->data);
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(Node* node) {
    if (node == nullptr)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<vector<int>> res = ob.levelOrder(root);
        for (auto level : res) {
            for (int ele : level)
                cout << ele << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  - **O(N)**, where `N` is the number of nodes in the tree. Each node is visited exactly once.

- **Space Complexity**:  
  - **O(M)**, where `M` is the maximum number of nodes at any level in the tree. This is the maximum size of the queue.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case:
   - A string representing the tree in level-order format. `N` indicates a null node.

### Output:
- The level-order traversal of the tree, printed level by level.

---

## Example Walkthrough

### Input:
```
1
1 2 3 4 5 6 7
```

### Output:
```
1 2 3 4 5 6 7
```

---

## Real-Life Example 🌍

Imagine you are organizing a family tree 🧑‍👩‍👧‍👦. You want to list all family members generation by generation, starting from the oldest (root) to the youngest (leaves). Level Order Traversal helps you achieve this by listing all members of the same generation together before moving to the next.

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐