
// TC : O(2n) where n is length of nums
// SC : O(n) for stack and output vector
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
     nums.push_back(nums[i]);
        }
    int k=nums.size();
    stack<int>st;
    vector<int>nge(k,-1);
   
    
    for(int i=k-1; i>=0;i--){
  while(!st.empty() && st.top()<=nums[i]){
    st.pop();
  }
  if(st.empty()){
    nge[i]=-1;
  }
  else{
    nge[i]=st.top();
  }
  st.push(nums[i]);
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(nge[i]);
    }
    return ans;
    }
};