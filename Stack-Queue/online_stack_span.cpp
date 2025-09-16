// brute force O(n^2) 

class StockSpanner {
    stack<int>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        if(st.empty()){
      st.push(price);
      return 1;
        }
        else{
            stack<int>st1=st;
            while(!st1.empty() && st1.top()<=price){
                count++;
              st1.pop();
            }
            st.push(price);
            return count;
        }
    }
};

// optimal solution : TC: O(2n) SC: O(2n)

 class StockSpanner {
    stack<pair<int,int>>st;
    int index=-1;
public:
    StockSpanner() {
      
    }
    
    int next(int price) {
        index++;
        int ans;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(st.empty()){
            ans=index+1;
        }
        else{
             ans =  index - st.top().second;

        }
         
           st.push({price,index});
           return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */