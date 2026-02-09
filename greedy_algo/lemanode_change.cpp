//TC:O(n)
//SC:O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int ten_dollar=0;
        int five_dollar=0;
        for(int i=0;i<bills.size();i++){
          if(bills[i]==5){
            five_dollar++;
          }
          else if(bills[i]==10){
            if(five_dollar==0){
                return false;
            }
            five_dollar--;
            ten_dollar++;
          }
          else{
            if(five_dollar<=0){
                return false;
            }
            if(ten_dollar>0){
                ten_dollar--;
                five_dollar--;
            }
            else{
                if(five_dollar<3){
                    return false;
                }
                five_dollar-=3;
            }
            
          }
        }
        return true;
    }
};