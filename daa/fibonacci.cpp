#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Time Complexity: O(2^n) (a commonly used upper bound; more precisely O(phi^n))
 * Space Complexity: O(n)
 * The recursion depth is proportional to n because it reaches the base case
 * after at most n recursive calls. The extra space is used by the call stack.
 */
void recursive(int n) {
    for (int i = 0; i < n; ++i)
        cout << fibonacci(i) << " ";
}

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void iterative(int n) {
    if (n <= 0) {
        cout << endl;
        return;
    }

    int a1 = 0;
    int a2 = 1;

    cout << a1 << " ";

    if (n == 1) {
        cout << endl;
        return;
    }

    cout << a2 << " ";

    for (int i = 2; i < n; i++) {
        int a3 = a2 + a1;
        a1 = a2;
        a2 = a3;
        cout << a2 << " ";
    }

    cout << endl;
}

int main() {
    recursive(10);
    cout << endl;
    iterative(10);
    return 0;
}
