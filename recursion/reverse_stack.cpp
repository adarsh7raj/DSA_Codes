

Time Complexity (TC)

Let stack size = n.

reverseStack is called n times (one for each element).

Each call makes a call to pushBack, which can take O(n) in worst case (to place an element at bottom).

So:

TC=O(n)×O(n)=O(n²)

✅ Time Complexity = O(n²)

💾 Space Complexity (SC)

Recursion depth:

reverseStack → up to n recursive calls.

Each call also uses pushBack → which can also recurse up to n calls.

So maximum recursion depth = O(n).

No extra data structures used (only recursion stack).

✅ Space Complexity = O(n)


class Solution {
  public:
  void pushBack(stack<int>&st,int val){
      if(st.empty()){
          st.push(val);
          return ;
      }
      int temp=st.top();
      st.pop();
      pushBack(st,val);
      st.push(temp);
  }
    void reverseStack(stack<int> &st) {
        // code here
       if(st.empty()){
           return;
       } 
       int val=st.top();
       st.pop();
       reverseStack(st);
       pushBack(st,val);
       
    }
};