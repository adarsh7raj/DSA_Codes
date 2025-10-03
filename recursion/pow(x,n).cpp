//optimal approach: O(logn):
class Solution {
    public:
        double myPow(double x, int n) {
            double ans=1.0;
            long negative_no=n;
            if(negative_no<0){
                negative_no=-1*negative_no;
            }
while (negative_no>0){
    if(negative_no%2==0){
        x=x*x;
        negative_no=negative_no/2;
    }
    else{
        ans=ans*x;
        negative_no--;
    }
}
if(n<0){
    ans=(double)(1.0)/(double)(ans);
  
}
return ans;
{
}

        }
    };



//optimal approach: O(logn) by recursion : 




class Solution {
    public:
        double myPow(double x, int n) {
            return cal(x,n);
        }
        
       double cal(double x, int n) {
            if (n == 0){
                 return 1;  
            }
            if (n < 0) { 
                x = 1 / x;  
                if (n == INT_MIN) {  
                    return x * myPow(x, -(n + 1));
                }
                n = -n;
            }
            
            
            double half = myPow(x, n / 2);
            
            return (n % 2 == 0) ? half * half : x * half * half;
        }
    };
    