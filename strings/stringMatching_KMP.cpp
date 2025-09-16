#include <iostream>
#include <vector>
using namespace std;

// LPS computation function
vector<int> computeLPS(const string& needle) {
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

// KMP Search function
int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;

    vector<int> lps = computeLPS(needle);
    int i = 0, j = 0;

    while (i < haystack.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        }

       else  {
            if (j != 0) {
                j = lps[j - 1]; // jump to previous match
            } else {
                i++;
            }
        }
    }
    if (j == needle.size()) {
        return i - j; // Found the match
    }

    return -1; // not found
}
