//TC: O(n log m) , SC: O(1)
class Solution {
public:
bool isPossible(vector<int>&nums,int th,int div){
    int sum=0;
    for(int i=0;i<nums.size();i++){
     int dividend= ceil((double)nums[i]/div);
     sum+=dividend;
    }
    if(sum<=th){
        return true;
    }
    return false;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(nums,threshold,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};