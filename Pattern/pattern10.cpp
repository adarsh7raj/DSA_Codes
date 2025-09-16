#include <iostream>
using namespace std;

int main() {
    int row;
    cout << "Enter the size of the pattern: ";
    cin >> row;

    int n = (row + 1) / 2; // middle row
    int k = 0;

    for (int i = 1; i <= row; i++) {
        if (i <= n) {
            k++;
        } else {
            k--;
        }

        for (int j = 1; j <= row; j++) {
            if (j >= n - k + 1 && j <= n + k - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
