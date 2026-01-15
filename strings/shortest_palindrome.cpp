
// brute force approach
//TC: O(n^2)
//SC: O(n)
class Solution {
public:
bool isPalindrome(string & temp){
int left=0;
int right=temp.size()-1;
while(left<=right){
    if(temp[left]!=temp[right]){
        return false;
    }
    left++;
    right--;
}
return true;

}

    string shortestPalindrome(string s) {
        int n=s.size();
        string reversed_str=s;
       int right=s.size()-1;
       int left=0;
        string temp=s;
        while(right>0){
       
        if(isPalindrome(temp)){
            return temp;
        } 
        temp.insert(left,1,s[right]);
        left++;
        right--;
        }
        return temp;
    }
};

//optimal solution using kmp
//TC: O(n)
//SC: O(n)


// 🧠 1. First, understand the problem deeply

// Shortest Palindrome
// You are allowed to add characters only at the front of the string.

// So the key question becomes:

// ❓ How much of the string is already a palindrome from the beginning?

// If a large prefix of s is already a palindrome, then:

// We only need to add the remaining characters (from the end) in front.

// 🧠 2. Brute force thinking (what we want to avoid)

// A naive idea would be:

// Keep checking if s[0…i] is a palindrome

// For every prefix, check palindrome → O(n²)

// ❌ Too slow.

// So we ask:

// Can we find the longest palindromic prefix in O(n)?

// 🧠 3. Key observation (the “aha” moment)

// A palindrome means:

// prefix of s == reverse(prefix of s)


// So if we reverse the string:

// s      = a b c d
// rev(s) = d c b a


// Then the palindromic prefix of s is exactly the:

// longest prefix of s that matches a prefix of rev(s)

// ⚠️ But positions are different — so we need a trick.

// 🧠 4. The clever trick (core idea)

// We create a new string:

// temp = s + '#' + reverse(s)


// Why?

// # ensures no false matching across boundaries

// Now the problem becomes:

// Find the longest prefix of temp that is also a suffix of temp

// That is EXACTLY what the LPS array (KMP) gives us.

// 🧠 5. Why KMP / LPS works here
// What does LPS tell us?

// lps[i] =
// 👉 length of the longest proper prefix which is also a suffix ending at i

// So:

// lps[last index]


// gives us:

// Length of the longest prefix of s that matches the suffix of reverse(s)

// Which means:

// ✅ Longest palindromic prefix of s

// 🧠 6. Final construction logic

// Let:

// num = lps[last]


// Then:

// s[0…num-1] is already palindrome

// The remaining part is s[num…end]

// So:

// Take those remaining characters

// Reverse them

// Add them in front

// Which is why we do:

// rev.substr(0, s.size() - num) + s

// 🧠 7. Thought process in ONE LINE

// “Find the longest palindromic prefix →
// use reverse + KMP →
// only add what’s missing in front.”



class Solution {
public:
vector<int> computeLPS(string & needle) {
    int n = needle.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}


    string shortestPalindrome(string s) {
      
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+'#'+rev;      
        vector<int> lps = computeLPS(temp);
        int n=lps.size();
        int num=lps[n-1];
        return rev.substr(0,s.size()-num)+s;

        
    }
};

