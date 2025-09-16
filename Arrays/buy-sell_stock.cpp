// brute force approach :
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit=0;
            int n=prices.size();
            for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
      int profit=prices[j]-prices[i];
              if(profit>0){
               max_profit=max(profit,max_profit);
              }
              }
            
             
            }
            return max_profit;
        }
    };

    //optimal approach :
    class Solution {
        public:
            int maxProfit(vector<int>& prices) {
                int max_profit=0;
                int n=prices.size();
                int min_price=prices[0];
                for(int i=0;i<n;i++){
          
                   int cost = prices[i]-min_price;
                   max_profit=max(cost,max_profit);
                   min_price=min(min_price,prices[i]);
                  
                 
                }
                return max_profit;
            }
        };