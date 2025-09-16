
//optimal solution  : O(n):
vector<int> minPartition(int N)
{
    // code here
    vector<int>currency={1,2,5,10,20,50,100,200,500,2000};
    vector<int>ans;
    sort(currency.begin(),currency.end(), greater<int>());
    int i=0;
    while(N>0){
    if(currency[i]<=N){
        ans.push_back(currency[i]);
        N=N-currency[i];
    }
    else{
        i++;
    }
    }
    return ans;
}