//brute force approach:
class Solution {
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                  if(matrix[i][j]==target){
                     return true;
                  }
            }       
         }
         return false;
    }

}

//better aproach : O(n)+O(logn)
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            // brute force approach:
    
            long long  m=matrix.size();
            long long  n=matrix[0].size();
            for(int i=0;i<m;i++){
                if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                    int low=0;
                    int high=n-1;
                    int mid=(low+high)/2;
                    while(low<=high){
                        if(matrix[i][mid]==target){
                            return true;
                        }
                        else if(matrix[i][mid]>target){
                            high=mid-1;
                        }
                        else{
                         low=mid+1;
                        }
                    }
                }
           
            }
            return false;
        }
    };

//optimal approach: O(logn*m):
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    long long  m=matrix.size();
    long long  n=matrix[0].size();

    long long  low=0;
    long long  high=n*m-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        int i=(mid/n);
        int j=(mid%n);
        cout<<i;
        if(matrix[i][j]==target){
            return true;
        }
        else if(matrix[i][j]>target){
            high=mid-1;
        }
        else{
         low=mid+1;
        }
    
    }
    return false;
}
