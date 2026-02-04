
// TC: log(n)*log(n) , SC: O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
     if(dividend==INT_MIN && divisor ==-1){
        return INT_MAX;
     }  
     bool is_negative=false;
   if(dividend>=0 && divisor<0){
    is_negative=true;
   }
   if(dividend<0 && divisor>=0){
    is_negative=true;
   }
long long n = abs((long long)dividend);
long long d = abs((long long)divisor);

long long  ans=0;
   while(n>=d){
  int count=0;
  int sum=0;
  
   while(n>= d<<(count+1)){
   
    count++;

   }
   n-=d<<count;
   ans+=1<<count;

   }
   return is_negative?-ans:ans;
     
    }
};