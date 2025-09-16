// brute force approach TC: O(n^2) SC:O(n):

void rotate(vector<vector<int>>&matrix){
    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i]=mat[i][j];
        }
    }
}


//optimal  approach O(2n^2): first take the transpose and swap leftmost column to the right most column
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) { 
            int n=matrix[0].size();
            for (int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            
            for(int i=0;i<n/2;i++){
                for(int j=0;j<n;j++){
                    swap(matrix[j][i],matrix[j][n-1-i]);
                }
            };
        };

        //better approach :  first take transpose then reverse the rows  TC: O(n^2)

        
        class Solution {
            public:
                void rotate(vector<vector<int>>& matrix) { 
                    int n = matrix.size();
            
                    // Step 1: Transpose (swap only once) it takes O(n^2)
                    for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {  // ✅ Start j from i+1 to avoid double swapping
                            swap(matrix[i][j], matrix[j][i]);
                        }
                    }
            
                    // Step 2: Reverse each row


                    for (int i = 0; i < n; i++) {  // takes O(n) time
                        reverse(matrix[i].begin(), matrix[i].end());  // takes O(n) time reverse the matrix
                    }
                }
            };

        }