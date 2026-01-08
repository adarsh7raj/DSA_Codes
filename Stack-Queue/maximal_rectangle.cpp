
// TC: O(n*m) SC: O(m)
class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // Add sentinel to flush the stack
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                 st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
              
                int width = nse-pse-1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
while(!st.empty()){
    int height=heights[st.top()];
    int nse=n;
    st.pop();
    int pse=st.empty()?-1:st.top();
    int width=(nse-pse-1);
    maxArea=max(maxArea,height*width);
}
        return maxArea;
    }




    int maximalRectangle(vector<vector<char>>& matrix) {
        // nse and pse
         vector<vector<int>> mat;
         vector<int> row;
for(char c : matrix[0]) {
    row.push_back(c - '0'); // if it's a digit char like '1'
}
mat.push_back(row);
       
         for(int i=1;i<matrix.size();i++){
            vector<int>temp;
               for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    int val=1+mat[i-1][j];
              temp.push_back(val);
                }
                else{
                    temp.push_back(0);
                }
               
               }
               mat.push_back(temp);
         }
         int maxi=INT_MIN;

         for(int i=0;i<mat.size();i++){
             maxi=max(maxi,largestRectangleArea(mat[i]));
         }
         return maxi;
    }

};