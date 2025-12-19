//Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum 
//total cost. The cost to connect two ropes is the sum of their lengths. 
// TC : O(n log n)
// SC : O(n)

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int cost=0;
        priority_queue<int,vector<int>,greater<int>>ropes;
        for(auto it : arr){
            ropes.push(it);
        }
       
        while(ropes.size()>1){
        
          int first=ropes.top();
          ropes.pop();
          int second=ropes.top();
          ropes.pop();
          cost+=first+second;
          ropes.push(first+second);
            
        }
        return cost;
    }
};