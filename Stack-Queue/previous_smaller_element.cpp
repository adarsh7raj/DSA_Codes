

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
    int n=arr.size();
    stack<int>temp;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
int current=arr[i];
while(!temp.empty() && temp.top()>=current){
    temp.pop();
}
if(temp.empty()){
    ans[i]=-1;
    
}
else{
    ans[i]=temp.top();
  
}
  temp.push(current);
    }
    return ans;
    }
};