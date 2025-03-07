#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    // Function to find the closest prime pair in a given range [left, right]
    vector<int> closestPrimes(int left, int right) {
        const vector<bool> isPrime = sieveEratosthenes(right + 1);
        vector<int> primes;

        // Collect all prime numbers in the given range
        for (int i = left; i <= right; ++i)
            if (isPrime[i])
                primes.push_back(i);

        // If less than 2 primes are found, return {-1, -1}
        if (primes.size() < 2)
            return {-1, -1};

        // Find the pair of primes with the smallest difference
        int minDiff = INT_MAX;
        int num1 = -1, num2 = -1;

        for (int i = 1; i < primes.size(); ++i) {
            const int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i - 1];
                num2 = primes[i];
            }
        }

        return {num1, num2}; // Return the closest prime pair
    }

private:
    // Function to generate prime numbers using the Sieve of Eratosthenes
    vector<bool> sieveEratosthenes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        // Mark non-prime numbers
        for (int i = 2; i * i < n; ++i)
            if (isPrime[i])
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;

        return isPrime; // Returns a boolean vector where true means prime
    }
};

// Main function to test closestPrimes function
int main() {
    Solution sol; // Create an instance of Solution

    int left, right;
    cout << "Enter the left boundary: ";
    cin >> left;
    cout << "Enter the right boundary: ";
    cin >> right;

    // Call closestPrimes function
    vector<int> result = sol.closestPrimes(left, right);

    // Print the closest prime pair
    if (result[0] == -1)
        cout << "No prime pairs found in the given range." << endl;
    else
        cout << "Closest prime pair: " << result[0] << " and " << result[1] << endl;

    return 0; // Successful execution
}
