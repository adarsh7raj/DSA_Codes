

// User function Template for C++
//TC: O(M * N) where M is the size of arr and N is the range of numbers (0 to 99999)
//SC: O(N) for the result vector and O(N) for the queue in the
class Solution {
  public:
 
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int M=1e5;
      vector<int>result(M,INT_MAX);
      
      queue<pair<int,int>>q;
      
      result[start]=0;
      
      q.push({0,start});
      
      while(!q.empty()){
          int node=q.front().second;
          int dist=q.front().first;
          q.pop();
       
          for(auto it:arr){
              int nw=(it*node)%M;
              if(dist+1<result[nw]){
                  result[nw]=dist+1;
                  q.push({dist+1,nw});
              }
          }
          
      }
      return result[end]==INT_MAX?-1:result[end];
    }
};
