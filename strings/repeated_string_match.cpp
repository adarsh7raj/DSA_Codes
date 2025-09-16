//teribble approach and npt works forall test cases:

class Solution {
    public:
        int repeatedStringMatch(string a, string b) {
       
            int n=a.size();
            bool sub_string_present=false;
            int count=1;
            string temp=a;
            bool ones=false;
    
              if (a.find(b) != string::npos) {
                cout<<"hi";
                return 1;
              }
            if(a.size()>b.size()){
                for(int i=0;i<b.size();i++){
                    int j=i;
                    int k=0;
                    if(a.find(b)!=string::npos){
                        return i+1;
                    }
      while(j<a.size() && k<b.size()){
                if(a[j]==b[k]){
                k++;
                j++;
                }
                else{
                k=0;
                j++;
                }
               }
               if(k>=b.size()){
                sub_string_present=true;
                return count;
               }
                      else{
                        a=a+temp;
                    count++;
               }
                }
                if(!sub_string_present){
                    return -1;
                }
             return count;
            }
    
            
             for(int i=0;i<b.size();i++){
              int j=0;
              int k=0;
              
      while(j<a.size() && k<b.size()){
              if(a==b){
                return i+1;
              }
              if(a[a.size()-1-j]==b[b.size()-1-k]){
                k++;
                j++;
              }
              else{
                k=0;
                
                j++;
              }
            
             }
           
           
             if(k>=b.size()){
              sub_string_present=true;
          
     return count;
             
               
             }
             else{
            
             a=a+temp;
           
                count++;
          
             }
               
             }
           
           if(!sub_string_present){
            return -1;
           }
            return count;
        }
    };

    //optimal solution : O(n):
    class Solution {
        public:
            int repeatedStringMatch(string a, string b) {
                const int n = ceil((double)b.length() / a.length());
                string s;
        
                for (int i = 0; i < n; ++i) {
                    s += a;
                }
        
                if (s.find(b) != string::npos) { // this will take O(n*m) we  can use KML algo for TC O(n+m)
                    return n;
                }
        
                if ((s + a).find(b) != string::npos) {
                    return n + 1;
                }
        
                return -1;
            }
        };
        // optimal approach :
        //we can use KMP algo to find if string is present in other string or not 