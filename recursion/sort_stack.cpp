

class Solution {
  public:
  void insertElement(stack<int>&st,int val){
      if(st.empty()|| st.top()<=val){
          st.push(val);
          return;
      }
      int temp=st.top();
      st.pop();
      insertElement(st,val);
      st.push(temp);
  }
    void sortStack(stack<int> &st) {
        // code here
       if(st.empty()){
           return ;
       }
       int val=st.top();
       st.pop();
       sortStack(st);
       insertElement(st,val);
        
    }
};
