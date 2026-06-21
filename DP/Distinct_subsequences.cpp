
// dp[m-1]

// means:

// Number of ways to form t[m-1...]
// using s[i+1...]

// Remember:

// dp[j]

// always represents:

// ways to form t[j...]
// from next row's source string

// which is:

// s[i+1...]

// Suppose:

// s = "a"
// t = "a"

// Then:

// m = 1

// So:

// dp[0]

// means:

// ways to form "a"
// from current next-row source

// Initially before processing any characters:

// dp = [0,1]

// Why?

// Meaning of each index
// dp[1] = 1

// means:

// ways to form ""
// from empty source

// which is 1.

// dp[0] = 0

// means:

// ways to form "a"
// from empty source

// which is impossible.

// So 0.

// Important Understanding

// At:

// i = n-1

// the next row corresponds to:

// i+1 = n

// which means:

// empty source string

// So initially:

// dp[j]

// represents:

// ways to form t[j...]
// from empty source

// Hence:

// empty target → 1
// non-empty target → 0

// So specifically:

// dp[m-1]

// means:

// ways to form last character of t
// from empty source

// which is:

// 0

// initially.

class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        // dp[j] = ways to form t[j...]
        vector<unsigned long long> dp(m + 1, 0);

        // Empty target can always be formed
        dp[m] = 1;

        // Traverse s from back
        for (int i = n - 1; i >= 0; i--) {

            vector<unsigned long long> curr(m + 1, 0);

            curr[m] = 1;

            // Traverse t from back
            for (int j = m - 1; j >= 0; j--) {

                if (s[i] == t[j]) {

                    // take + skip
                    curr[j] = dp[j + 1] + dp[j];
                }
                else {

                    // skip
                    curr[j] = dp[j];
                }
            }

            dp = curr;
        }

        return (int)dp[0];
    }
};