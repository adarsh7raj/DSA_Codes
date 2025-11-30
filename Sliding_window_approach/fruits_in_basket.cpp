// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

 

// Example 1:

// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
// Example 3:

// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].
 


// brute force approach :
// TC:O(n^2):
// SC: O(n)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxi=0;
         for(int i=0;i<n;i++){
            vector<int>b1;
            vector<int>b2;
            for(int j=i;j<n;j++){
                if(b1.empty() || b1[0]==fruits[j]){
                    b1.push_back(fruits[j]);
                }
                else if(b2.empty() || b2[0]==fruits[j]){
                    b2.push_back(fruits[j]);
                }
                else {
                    break;
                }
            }
            int len=b1.size() + b2.size();
            maxi=max(maxi,len);
         }
         return maxi;
    }
};

// optimal solution : using sliding window approach
// TC:O(n):
//SC:O(k) where k is the number of distinct fruit types (at most 2 here) || where k is the number of distinct fruit types in the map).

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int n=fruits.size();
       int count=0;
        int l=0;
        int r=0;
        while(r<n){
           
        mp[fruits[r]]++;
        if(mp.size()<=2){
            count=max(count,r-l+1);
        }
        else{
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0){
                mp.erase(fruits[l]);
            }
            l++;
        }
        r++;
         
        
    }
    return count;
    }
};

// it is more optimized version of above code
// TC:O(n):
// SC:O(k) where k is the number of distinct fruit types (at most 2 here) || where k is the number of distinct fruit types in the map).


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n = fruits.size();
        int count = 0;
        int l = 0, r = 0;

        while (r < n) {
            mp[fruits[r]]++;
            r++;

            // shrink while we have more than 2 distinct fruits
            while (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            // window [l, r-1] now has at most 2 distinct fruits
            count = max(count, r - l);
        }

        return count;
    }
};
