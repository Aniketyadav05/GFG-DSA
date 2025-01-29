# 29 Implement Power Function (x^n)

**The problem can be found at the following link: [Implement Power Function](https://www.geeksforgeeks.org/problems/powx-n/1)**

---

## Problem Statement

Given a double `b` (base) and an integer `e` (exponent), the task is to compute `b^e` efficiently.

- If `e == 0`, return `1` (since anything raised to the power of 0 is 1).
- If `e < 0`, return `1 / (b^|e|)`.
- Optimize the calculation using **fast exponentiation** (divide and conquer approach).

---

## Example:

### Input:
```
b = 2.0
e = 3
```

### Output:
```
8.00000
```

Explanation:
- `2^3 = 2 * 2 * 2 = 8`

### Input:
```
b = 2.0
e = -2
```

### Output:
```
0.25000
```

Explanation:
- `2^(-2) = 1 / (2^2) = 1 / 4 = 0.25`

---

## Approach

We use **Fast Exponentiation (Recursive Method)** to efficiently compute `b^e` in **O(log e)** time.

### Steps:

1. **Base Case**:
   - If `e == 0`, return `1`.

2. **Handle Negative Exponent**:
   - Convert `b^(-e) = 1 / (b^e)`.

3. **Divide and Conquer**:
   - Recursively compute `power(b, e/2)`, storing it in `temp`.
   - If `e` is **even**, return `temp * temp`.
   - If `e` is **odd**, return `b * temp * temp`.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double power(double b, int e) {
        if (e == 0) return 1;

        if (e < 0) return 1 / power(b, -e);

        double temp = power(b, e / 2);

        if (e % 2 == 0)
            return temp * temp;
        else
            return b * temp * temp;
    }
};

// Driver Code
int main() {
    cout << fixed << setprecision(5);  // Set precision for floating-point output
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**: **O(log e)**
  - The recursion reduces the exponent by half at each step.

- **Space Complexity**: **O(log e)**
  - Due to recursive function calls.

---

## Input and Output Format

### Input:
1. Number of test cases `T`.
2. For each test case:
   - A double value `b` (base).
   - An integer `e` (exponent).

### Output:
- The computed value of `b^e`, formatted to **5 decimal places**.

---

## Example Walkthrough

### Input:
```
2
2.0 3
2.0 -2
```

### Output:
```
8.00000
0.25000
```

---

## Contribution and Support

If you have any questions, feel free to ask.  
⭐ If this solution helped you, please give it a star! ⭐
