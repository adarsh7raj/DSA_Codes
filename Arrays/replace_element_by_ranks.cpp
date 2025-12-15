


// TC -> O(N log N)
// SC -> O(N)
//without using priority queue
class Solution {
  public:
int find(vector<pair<int,int>>& ranks, int target) {
    int l = 0;
    int r = ranks.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;  // safer than (l + r) / 2

        if (ranks[mid].first > target) {
            r = mid - 1;
        } else if (ranks[mid].first < target) {
            l = mid + 1;
        } else { // ranks[mid].first == target
            return ranks[mid].second;
        }
    }

    return 0;  // not found
}

    vector<int> replaceWithRank(vector<int> &arr, int N) {
      vector<int>temp=arr;
      vector<int>result;
      sort(temp.begin(),temp.end());
      vector<pair<int,int>>ranks;
      int k = 1;
ranks.push_back({temp[0], k});

for (int i = 1; i < temp.size(); i++) {
    if (temp[i] != temp[i-1]) {
        k++; // only increase when value changes
    }
    ranks.push_back({temp[i], k});
}
      
      for(int i=0;i<N;i++){
          int rank=find(ranks,arr[i]);
          result.push_back(rank);
      }
     
       return result;
    }
};


// using hash map
// TC -> O(N log N)
// SC -> O(N)
// User function Template for C++

class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // Step 1: Copy original array
        vector<int> temp = arr;

        // Step 2: Sort the copy
        sort(temp.begin(), temp.end());

        // Step 3: Assign ranks using a hash map
        unordered_map<int, int> rank;  // value -> rank
        int r = 1;

        for (int i = 0; i < N; i++) {
            if (rank.find(temp[i]) == rank.end()) { 
                // first time we see this value
                rank[temp[i]] = r;
                r++;
            }
        }

        // Step 4: Replace each element in original array with its rank
        vector<int> result;
        result.reserve(N);
        for (int i = 0; i < N; i++) {
            result.push_back(rank[arr[i]]);
        }

        return result;
    }
};


