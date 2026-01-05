
// TC: O(n) SC: O(n)

// In this approach we will find the next smaller element on the left and right side for each element
// then we will calculate the contribution of each element as minimum in subarrays using the formula
//or we can go to each element arr[i] and find how many subarrays can be formed with arr[i] as minimum
// then we can add the contribution of each element to get the final answer

class Solution {
public:
vector<int> nextSmallerLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

vector<int> nextSmallerRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st; // stores indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

int sumSubarrayMins(vector<int>& arr) {
    long long sum = 0;
    int m = 1e9 + 7;
    int n = arr.size();

    vector<int> nsl = nextSmallerLeft(arr);
    vector<int> nsr = nextSmallerRight(arr);
    
    for (int i = 0; i < n; i++) {
        long long ls = i - nsl[i];
        long long rs = nsr[i] - i;
        long long count = ls * rs % m;
        sum = (sum + (count * arr[i]) % m) % m;
    }
    return sum;
}

};