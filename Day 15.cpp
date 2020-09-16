// Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = s.size() - 1;
        while(sz >= 0 && s[sz] == ' ')
            sz--;
        int i = sz;
        while(i >= 0) {
            if(s[i] == ' ')
                break;
            i--;
        }
        return sz - i;
    }
};