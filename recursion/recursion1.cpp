#include <iostream>
using namespace std;
void name_function(int n,string name ){
    cout<<name<<endl;
    if(n>1){

        name_function(n-1,"adarsh");
    }

}

int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    name_function(n,"adarsh");

}