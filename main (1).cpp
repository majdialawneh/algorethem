#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative factorial function
long long iterativeFactorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Recursive factorial function
long long recursiveFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}

int main() {
    // Test cases
    int testCases[] = {5, 10, 20, 30, 40};
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    // Measure execution time for each test case
    for (int i = 0; i < numTestCases; ++i) {
        int n = testCases[i];

        // Iterative factorial
        auto start = high_resolution_clock::now();
        long long iterativeResult = iterativeFactorial(n);
        auto stop = high_resolution_clock::now();
        auto iterativeDuration = duration_cast<microseconds>(stop - start);

        // Recursive factorial
        start = high_resolution_clock::now();
        long long recursiveResult = recursiveFactorial(n);
        stop = high_resolution_clock::now();
        auto recursiveDuration = duration_cast<microseconds>(stop - start);

        cout << "n = " << n << endl;
        cout << "Iterative factorial: " << iterativeResult << ", Time taken: " << iterativeDuration.count() << " microseconds" << endl;
        cout << "Recursive factorial: " << recursiveResult << ", Time taken: " << recursiveDuration.count() << " microseconds" << endl;
        cout << endl;
    }

    // Attempt to calculate factorial for a large value of n (to observe stack overflow issue)
    int largeN = 40;
    cout << "Attempting to calculate factorial for n = " << largeN << endl;
    cout << "Recursive factorial: " << recursiveFactorial(largeN) << endl; // Stack overflow may occur

    return 0;
}