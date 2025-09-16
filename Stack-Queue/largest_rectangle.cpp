// TC:O(3n) and SC:)(3n)


// first find the index of next smallest of a element from left and then same from right
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();
       priority_queue<int>ar;
       vector<int> Left(n, -1); // -1 if no smaller to the left
    stack<int> st; // store indexes

    for (int i = 0; i < n; ++i) {  // must start from start of array if finding from left
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            Left[i] = st.top(); // index of the next smaller on the left
        }
        st.push(i);
    }


    // to make the stack empty
    while (!st.empty()) {
        st.pop();
        }
    vector<int> Right(n, n); // n means no smaller to the right
   

    for (int i = n - 1; i >= 0; --i) {  // must start from end of array if finding element from right;
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            Right[i] = st.top(); // index of the next smaller on the right
        }
        st.push(i);
    }
        for(int i=0;i<n;i++){
            int area=(Right[i]-Left[i]-1)*heights[i];
            ar.push(area);
        }
        return ar.top();
    }
};

// optimal approach : TC : O(2n) and SC : O(2n)

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
};


// more intitutive way : 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // Sentinel
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
