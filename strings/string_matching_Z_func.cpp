// brute force apporach to find the z array:

#include <iostream>
#include <vector>
using namespace std;

vector<int> computeZArray(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);

    for (int i = 1; i < n; ++i) {
        int j = 0;
        int k = i;
        int count = 0;

        while (k < n) {
            if (s[j] == s[k]) {
                count++;
                j++;
                k++;
            } else {
                break;
            }
        }

        z[i] = count;
    }

    return z;
}


//optimal approach : 
// so the optimal approach is based on the idea that we will copy our z[i] value from the previosly calculated z[i] if the value lies in the range (left,right)
// and suppose if exceeds the range will make it in range and do for the other .
// suppose if it is in the range then we calculate value after the z[i] value to check whether it is in the equal to the value after that if it is we will do z[i]++
// and after that we check whether we have to update our range .
vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i < r){
            z[i] = z[i-l];
        }
        if(i+z[i]>r){
            z[i]=r-i;
        }   

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}


