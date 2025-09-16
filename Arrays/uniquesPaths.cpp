//brute force recursion  approach : but this will give TLE;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            return paths(0,0,m,n);
    };
    int paths(int i,int j , int m , int n){
        if(i==(m-1)&&j==(n-1)){
            return 1;
        }
        if(i>=m||j>=n){
            return 0;
        }
        else{
            return paths(i+1,j,m,n)+paths(i,j+1,m,n);
        }
    }
    };


//optimal solution: 
class Solution {
    public:
        int uniquePaths(int m, int n) {
            int size=m+n-2;
            long long result=1;
            int r=0;
        
       
          if(m>=n){
             r=n-1;
          }
          else{
             r=m-1;
          }
            for(int i=0;i<r;i++){
                result=result*(size-i);
                result=(result)/(i+1);
            }
            return result;
        }
    };