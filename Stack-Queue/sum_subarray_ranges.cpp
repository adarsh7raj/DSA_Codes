// TC: O(n) SC: O(n)

// In this approach we will find the next smaller and next greater element on the left and right side for each element
// then we will calculate the contribution of each element as minimum and maximum in subarrays 
//using the formula used in sum of subarray minimums and sum of subarray maximums


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

long long  sumSubarrayMin(vector<int>& arr) {
    long long sum = 0;
    
    int n = arr.size();

    vector<int> nsl = nextSmallerLeft(arr);
    vector<int> nsr = nextSmallerRight(arr);
    
    for (int i = 0; i < n; i++) {
        long long ls = i - nsl[i];
        long long rs = nsr[i] - i;
        long long count = ls * rs;
        sum = sum + (count * arr[i]);
    }
    return sum;
}
vector<int> nextGreaterLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

vector<int> nextGreaterRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st; // stores indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

long long  sumSubarrayMax(vector<int>& arr) {
    long long sum = 0;
 
    int n = arr.size();

    vector<int> ngl = nextGreaterLeft(arr);
    vector<int> ngr = nextGreaterRight(arr);
    
    for (int i = 0; i < n; i++) {
        long long ls = i - ngl[i];
        long long rs = ngr[i] - i;
        long long count = ls * rs;
        sum = sum + (count * arr[i]);
    }
    return sum;
}
    long long subArrayRanges(vector<int>& nums) {
        long long max_sum=sumSubarrayMax(nums);
        long long min_sum=sumSubarrayMin(nums);
        return max_sum-min_sum;
    }
};