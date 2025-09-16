// brute force : 

#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans;
    for (int j = 0; j < a.size(); j++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        queue<int> result;

        int k = j + 1;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().second <= i - k)
                pq.pop();

            pq.push({a[i], i});  // fixed: was 'nums[i]' but should be 'a[i]'

            if (i >= k - 1)
                result.push(pq.top().first);
        }

        ans.push_back(result.front());  // fixed: result.top() → result.front()
    }
    return ans;
}


// better  solution :

#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> res(n + 1, INT_MIN);
    vector<int> pse(n, -1), nse(n, n);
    stack<int> st;

    // Previous Smaller Element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty()) pse[i] = st.top();
        st.push(i);
    }

    // Clear the stack for reuse
    while (!st.empty()) st.pop();

    // Next Smaller Element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty()) nse[i] = st.top();
        st.push(i);
    }

    // Fill the res[] with max of minimums for window sizes
    for (int i = 0; i < n; i++) {
        int len = nse[i] - pse[i] - 1;
        res[len] = max(res[len], a[i]);
    }

    // Fill remaining entries
    for (int i = n - 1; i >= 1; i--)
        res[i] = max(res[i], res[i + 1]);

    // Final answer
    res.erase(res.begin()); // remove dummy 0th index
    return res;
}


//optimal solution 
#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n + 1, INT_MIN);
    stack<int> st;

    for (int i = 0; i <= n; i++) {
        int curr = (i == n) ? INT_MIN : a[i];

        while (!st.empty() && a[st.top()] >= curr) {
            int index = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int len = i - left - 1;

            ans[len] = max(ans[len], a[index]);
        }
        st.push(i);
    }

    // Fill the remaining values to make sure ans[i] >= ans[i+1]
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    // Remove dummy 0th index
    ans.erase(ans.begin());

    return ans;
}

