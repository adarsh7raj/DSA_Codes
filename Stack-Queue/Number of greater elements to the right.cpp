

// TC : O(n*m) where n is length of indices and m is average elements to right
// SC : O(1) no extra space used
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
      vector<int>ans;
    for(int i=0;i<indices.size();i++){
        int idx=indices[i];
        int num=arr[idx];
        int count=0;
        for(int j=idx;j<arr.size();j++){
            if(arr[j]>num){
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
    
    }
};

// optimal approach
// TC : O(n) where n is length of arr
// SC : O(n) for stack and output vector
#include<stack>
vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    int n=arr.size();
    stack<int>st;
    vector<int>nge(n,0);
   
    
    for(int i=n-1; i>=0;i--){
  while(!st.empty() && st.top()<=arr[i]){
    st.pop();
  }
  nge[i]=st.size();
  st.push(arr[i]);
    }
    vector<int>ans;
    for(int i=0;i<indices.size();i++){
        ans.push_back(nge[indices[i]]);
    }
    return ans;
}