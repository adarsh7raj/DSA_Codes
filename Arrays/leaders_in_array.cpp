class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        int maxSoFar = arr[n - 1];
        ans.push_back(maxSoFar);

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxSoFar) {
                maxSoFar = arr[i];
                ans.push_back(arr[i]);
            }
        }

        reverse(ans.begin(), ans.end()); // maintain original order
        return ans;
    }
};
