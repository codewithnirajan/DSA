//Tail recursion 

#include <iostream>
using namespace std;

// Tail recursive function
int sumTail(int n, int acc) {
    if (n == 0)
        return acc;

    return sumTail(n - 1, acc + n);
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of natural numbers = " << sumTail(n, 0);

    return 0;
}

