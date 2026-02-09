
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



// more clean code

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, pair<int,int>>> sack;

        for (int i = 0; i < wt.size(); i++) {
            double ratio = (double)val[i] / wt[i];
            sack.push_back({ratio, {wt[i], val[i]}});
        }

        // sort by value/weight DESCENDING
        sort(sack.rbegin(), sack.rend());

        double profit = 0.0;

        for (int i = 0; i < sack.size() && capacity > 0; i++) {
            int weight = sack[i].second.first;
            int value  = sack[i].second.second;

            if (weight <= capacity) {
                profit += value;
                capacity -= weight;
            } else {
                profit += ((double)capacity / weight) * value;
                capacity = 0;
            }
        }
        return profit;
    }
};
