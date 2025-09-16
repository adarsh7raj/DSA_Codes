
//optimal solution : O(n);
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    double total_profit = 0;
    vector<pair<double, int>> val_wt;

    // Calculate profit-to-weight ratio and store with index
    for (int i = 0; i < n; i++) {
        double ratio = (double)val[i] / wt[i]; // FIXED: proper float division
        val_wt.push_back({ratio, i});
    }

    // Sort by ratio in descending order
    sort(val_wt.begin(), val_wt.end(), [](pair<double, int>& a, pair<double, int>& b) {
        return a.first > b.first;
    });

    int i = 0;
    while (capacity > 0 && i < n) {
        int idx = val_wt[i].second;

        if (wt[idx] <= capacity) {
            total_profit += val[idx];
            capacity -= wt[idx];
        } else {
            total_profit += (double)val[idx] / wt[idx] * capacity;
            capacity = 0;
        }
        i++;
    }

    return total_profit;
}
