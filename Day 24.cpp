// Find the Difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {0};
        for(char c : s) {
            freq[c - 'a']++;
        }
        char ans;
        for(char c : t) {
            freq[c - 'a']--;
            if(freq[c - 'a'] < 0)
                ans = c;
        }
        return ans;
    }
};