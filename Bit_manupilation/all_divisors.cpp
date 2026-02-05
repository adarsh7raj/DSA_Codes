class Solution {
public:
    void print_divisors(int n) {
        vector<int> large;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";      // smaller divisor
                if (i != n / i) {
                    large.push_back(n / i);  // larger divisor
                }
            }
        }

        // print larger divisors in reverse
        for (int i = large.size() - 1; i >= 0; i--) {
            cout << large[i] << " ";
        }
    }
};
