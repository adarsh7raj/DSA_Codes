// Brute force solution with approx O(n^3) solution

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> pascal_traingle;
            for(int i=1;i<=numRows;i++){
                vector<int> rows;
                for (int j=1;j<=i;j++){
                    int value=GenerateRow(i-1,j-1);
                    rows.push_back(value);
                }
                pascal_traingle.push_back(rows);
            }
            return pascal_traingle;
        }
        int GenerateRow(int n,int r){
            
            long long result=1;
            for(int i=0;i<r;i++){
      result=result*(n-i);
      result=result/(i+1);
            }
            return result;
          
        }
    };

    
    //optimal solution with O(n^2) complexity

    class Solution {
        public:
            vector<vector<int>> generate(int numRows) {
                vector<vector<int>> pascal_traingle;
                for(int i=1;i<=numRows;i++){
                    
                  
                    pascal_traingle.push_back(GenerateRow(i));
                }
                return pascal_traingle;
            }
            vector<int> GenerateRow(int n){
                vector<int> ans_row;
                ans_row.push_back(1);
                long long result=1;
                for(int i=1;i<n;i++){
          result=result*(n-i);
          result=result/(i);
        ans_row.push_back(result);
                }
                return ans_row;
              
            }
        };
        