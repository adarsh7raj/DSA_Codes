
// TC: O(n^2*26) SC: O(26) ~ O(1)
class Solution {
public:
    pair<int,int> find(vector<int> &items) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int f : items) {
            if(f > 0) {   // ignore characters not present
                maxi = max(maxi, f);
                mini = min(mini, f);
            }
        }
        return {maxi, mini};
    }

    int beautySum(string s) {
        int sum = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            vector<int> items(26, 0);  // reset for each new starting index
            for(int j = i; j < n; j++) {
                items[s[j] - 'a']++;
                auto max_min = find(items);
                sum += max_min.first - max_min.second;
            }
        }

        return sum;
    }
};
