// brute force : TC:O(n^2) and SC: O(2n)

int findCelebrity(const vector<vector<int>>& M, int n) {
    vector<int> knownMe(n, 0); // how many people know i
    vector<int> iKnow(n, 0);   // how many people i know

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (M[i][j] == 1) {
                iKnow[i]++;
                knownMe[j]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (knownMe[i] == n - 1 && iKnow[i] == 0) {
            return i; // i is the celebrity
        }
    }

    return -1; // no celebrity
}





// optimal solution TC: O(3n), SC: O(1)

  int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        stack<int>st;
for(int i=0;i<n;i++){
    st.push(i);
}
   
while(st.size()>1){
    int first=st.top();
    st.pop();
    int second=st.top();
    st.pop();
    
    if(mat[first][second]&& !mat[second][first]){
        st.push(second);
    }
    else if(!mat[first][second] && mat[second][first]){
        st.push(first);
    }
}
if(st.empty()){
    return -1;
}
int person=st.top();
st.pop();
int row=0;
int column=0;
for(int i=0;i<n;i++){
    if(i==person){
        continue;
    }
    row=row+mat[person][i];
    column=column+mat[i][person];
}
if(row==0 && column==n-1){
    return person;
}
else{
    return -1;
}
    }


    // another optimal solution TC: O(n) SC: O(1) without using stack

    class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
     
     int first=0;
     int last=mat.size()-1;
     while(first<last){
         if(mat[first][last]==1){
             first++;
     }
     else if(mat[last][first]==1){
         last--;
     }
     else{
         first++;
         last--;
     }
    }
    if(first>last){
        return -1;
    }
    for(int i=0;i<mat.size();i++){
        if(i==first){
            continue;
        }
        if(mat[first][i]==1 || mat[i][first]==0){
            return  -1;
        }
    }
    return first;
    }
};