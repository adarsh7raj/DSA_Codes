//optimal solution : 



#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class KarpRabin {
private:
    const int PRIME = 101;
                                                                                 
    double calculateHash(const string& str) {
        double hash = 0;
        for (int i = 0; i < str.length(); ++i) {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    double updateHash(double prevHash, char oldChar, char newChar, int patternLength) {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash += newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }
      
public:
    int search(const string& text, const string& pattern) {
        int patternLength = pattern.length();


        if (patternLength == 0 || patternLength > text.length()) return ;

        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substr(0, patternLength));

        for (int i = 0; i <= text.length() - patternLength; ++i) {
            if ((textHash == patternHash) ) { // float comparison with epsilon
                if (text.substr(i, patternLength) == pattern) {
                    cout << "Pattern found at index " << i << endl;
                    return i;
                }
            }

            if (i < text.length() - patternLength) {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }
    }
};
