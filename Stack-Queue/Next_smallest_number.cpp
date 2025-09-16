// optimal TC : O(n) SC: O(n):

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.

   
    std::stack<int>temp;
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
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