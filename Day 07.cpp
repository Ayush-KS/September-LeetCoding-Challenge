// Word Pattern

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mp;
        unordered_map<string, char> ump;
        string temp;
        stringstream check(str);
        int i = 0;
        
        while(getline(check, temp, ' ')) {
            if(ump.find(temp) != ump.end()) {
                if(ump[temp] != pattern[i])
                    return false;
            } else {
                ump[temp] = pattern[i];
            }
            
            if(mp.find(pattern[i]) != mp.end()) {
                if(mp[pattern[i]] != temp)
                    return false;
            } else {
                mp[pattern[i]] = temp;
            }
            i++;
        }
        
        return i == pattern.size();
    }
};