//optimal solution: O(n) or O(nlogn):
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    map<int, int> m;
    int curXor = 0;
    int count = 0;
    m[curXor]++;
    for (int i = 0; i < n; i++) {
        curXor = curXor ^ A[i];

      

        int rem = curXor ^ B;  
        if (m.count(rem)) {
            count +=m[rem];  // count all previous occurrences
        }

        m[curXor]++;
    }

    return count;
}

// or we can do this to :
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    map<int, int> m;
    int curXor = 0;
    int count = 0;
 
    for (int i = 0; i < n; i++) {
        curXor = curXor ^ A[i];

      if(curXor==B){
         count++;
      }

        int rem = curXor ^ B;  // use B, not 'k'

        if (m.count(rem)) {
            count +=m[rem];  // count all previous occurrences
        }

        m[curXor]++;
    }

    return count;
}
