//optimal solution : TC O(3n)
// Compare Version Numbers
// You are given two version numbers as strings version1 and version2.

// A version number consists of numbers separated by dots (.), e.g., "1.01.3" or "1.0.0".

// Compare the two versions:

// Return 1 if version1 > version2

// Return -1 if version1 < version2

// Return 0 if version1 == version2

// Rules:

// Leading zeros should be ignored ("01" == "1").

// Missing parts are treated as 0 ("1.0" == "1").

// Example

// Input:

// version1 = "1.01", version2 = "1.001"


// Output:

// 0


// Explanation:

// "01" and "001" are treated as 1.

// Both versions are equal.

// Input:

// version1 = "1.0.1", version2 = "1"


// Output:

// 1


// Explanation:

// "1.0.1" > "1.0.0" → return 1.

// Intuition

// Each version is split into numbers by ..

// Compare corresponding numbers one by one.

// If one version is shorter, treat missing numbers as 0.

// Stop comparison as soon as a difference is found.

// Algorithm

// Split version1 and version2 into integer parts using . as separator.

// Store the numbers in two vectors ver1 and ver2.

// If vectors have different lengths, append 0s to the shorter one.

// Compare the vectors element by element:

// If ver1[i] > ver2[i] → return 1

// If ver1[i] < ver2[i] → return -1

// If equal, continue

// If all elements are equal → return 0.
class Solution {
    public:
        int compareVersion(string version1, string version2) {
        vector<int>ver1;
        vector<int>ver2;
        string current="";
        int a=01;
        int b=001;
       if(a==b){
        cout<<"equal";
       }
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                ver1.push_back(stoi(current));
                current="";
            }
            else{
      current=current+version1[i];
            }
        }
    if (!current.empty()) {
        ver1.push_back(stoi(current));
    }
    current="";
    
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'){
                ver2.push_back(stoi(current));
                current="";
            }
            else{
      current=current+version2[i];
            }
        }
    if (!current.empty()) {
        ver2.push_back(stoi(current));
    }
    
    
    
    if(ver1.size()>ver2.size()){
        int times=ver1.size()-ver2.size();
        for(int i=0;i<times;i++){
            ver2.push_back(0);
        }
    }
    if(ver2.size()>ver1.size()){
        int times=ver2.size()-ver1.size();
        for(int i=0;i<times;i++){
            ver1.push_back(0);
        }
    }
    
    for(int i=0;i<ver1.size();i++){
    if(ver1[i]==ver2[i]){
        continue;
    }
    else if(ver1[i]>ver2[i]){
        return 1;
    }
    else{
        return -1;
    }
    }
    
    return 0;
        }
    };