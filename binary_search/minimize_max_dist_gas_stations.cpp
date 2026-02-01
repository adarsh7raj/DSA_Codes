//TC O(log(max_distance) * n)
//SC O(1)

class Solution {
  public:
  
  bool isPossible(vector<int> & stations,int k, long double diff){
      int stations_used=0;
      for(int i=0;i<stations.size()-1;i++){
          if(stations[i+1]-stations[i]>=diff){
              int number_between=(stations[i+1]-stations[i])/diff;
              if((stations[i+1]-stations[i])/diff ==number_between*diff){
                  number_between--;
              }
              stations_used+=number_between;
          }
      }
      if(stations_used<=k){ // this means we can place infinitely many stations with given max distance
          return true;
      }
      return false; // cannot place with given max distance
  }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        
        
        long double l=0;
        long double h=0;
        for(int i=0;i<stations.size()-1;i++){
          h=  max(h,(long double) stations[i+1]-stations[i]);
        }
        while(h-l>1e-6){ // here we did not do <= because we are dealing with floating point numbers
            // l will never be equal to h the difference will become very small but not zero
            long double mid=l+(h-l)/2.0;
            
            if(isPossible(stations,K,mid)){
                h=mid; // mid is feasible
            }
            else{
                l=mid;
            }
        }
        return h;
        
        
    }
};