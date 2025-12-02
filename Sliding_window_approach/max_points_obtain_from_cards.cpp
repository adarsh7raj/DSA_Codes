

//optimal solution using sliding window
//TC:O(3k)  SC:O(k)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if (k >= n) return accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int K = k; // preserve original k

        vector<int> leftSum(K+1, 0);
        vector<int> rightSum(K+1, 0);

        // leftSum[i] = sum of first i elements
        for (int i = 1; i <= K; ++i) {
            leftSum[i] = leftSum[i-1] + cardPoints[i-1];
        }

        // rightSum[i] = sum of last i elements
        for (int i = 1; i <= K; ++i) {
            rightSum[i] = rightSum[i-1] + cardPoints[n - i];
        }

        int result = 0;
        for (int i = 0; i <= K; ++i) {
            result = max(result, leftSum[i] + rightSum[K - i]);
        }

        return result;
    }
};


// we can also do this in O(k) time and O(1) space

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if (k >= n) return accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int total = 0;
        for (int x : cardPoints) total += x;

        int window = n - k;
        int curr = 0;
        for (int i = 0; i < window; ++i) curr += cardPoints[i];

        int minWindow = curr;
        for (int i = window; i < n; ++i) {
            curr += cardPoints[i];
            curr -= cardPoints[i - window];
            minWindow = min(minWindow, curr);
        }

        return total - minWindow;
    }
};
