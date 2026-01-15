#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();

    int base = 31;           // prime base
    int mod = 1e9 + 7;       // large prime modulo

    long long patHash = 0;
    long long txtHash = 0;
    long long power = 1;     // base^(m-1)

    // compute base^(m-1)
    for (int i = 0; i < m - 1; i++) {
        power = (power * base) % mod;
    }

    // compute initial hashes
    for (int i = 0; i < m; i++) {
        patHash = (patHash * base + (pat[i] - 'A' + 1)) % mod;
        txtHash = (txtHash * base + (txt[i] - 'A' + 1)) % mod;
    }

    // slide window over text
    for (int i = 0; i <= n - m; i++) {

        // if hash matches, verify characters
        if (patHash == txtHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // compute next window hash
        if (i < n - m) {
            txtHash = (txtHash - (txt[i] - 'A' + 1) * power) % mod;
            txtHash = (txtHash * base + (txt[i + m] - 'A' + 1)) % mod;
            if (txtHash < 0) txtHash += mod;
        }
    }
}

int main() {
    string txt = "ABABCABCAB";
    string pat = "ABC";

    rabinKarp(txt, pat);
    return 0;
}
