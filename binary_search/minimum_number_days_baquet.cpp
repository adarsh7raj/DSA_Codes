

//TC: O(n log m) , SC: O(1)
class Solution {
public:
bool isPossible(vector<int>& bloomDay,int m,int k,int days){

    for(int i=0;i<bloomDay.size();i++){
       int adj=0;
        while( i<bloomDay.size()&& bloomDay[i]<=days){
          adj++;
          
          if(adj==k){
            m--;
            break;
          }
          i++;
        }
    }
    if(m<=0){
        return true;
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
    int n=bloomDay.size();
    int l=1;
    int r= *max_element(bloomDay.begin(),bloomDay.end());
    if((long long )m*k>n){
        return -1;
    }
    while(l<=r){
        int mid=l+(r-l)/2;
        if(isPossible(bloomDay,m,k,mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
    }
};

// slightly cleaner version

class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // break adjacency
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
