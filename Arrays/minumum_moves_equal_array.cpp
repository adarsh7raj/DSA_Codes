

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        int moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }
        return moves;
    }
};
// TC : O(nlogn) SC : O(1)

class Solution {
    public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0;
        int j=n-1;
        int moves=0;
        while(i<j){
            moves+=nums[j]-nums[i];
            i++;
            j--;
        }
}