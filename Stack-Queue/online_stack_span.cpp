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
// brute force O(n) 

class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
       int count=1;
      while(!st.empty() && price>=st.top().first){
        count+=st.top().second;
        st.pop();
      }
      st.push({price,count});
      return count;
        }
    
};