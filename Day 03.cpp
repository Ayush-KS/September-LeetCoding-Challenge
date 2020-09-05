// Repeated Substring Pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string newS = (s + s).substr(1, 2*s.size() - 2);
        return newS.find(s) != -1;
    }
};