// Largest Number

class Solution {
public:
    static bool comp(int x, int y) {
        string s1 = to_string(x);
        string s2 = to_string(y);
        
        return s1 + s2 > s2 + s1;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for(int i : nums) {
            ans += to_string(i);
        }
    
        return ans[0] == '0' ? "0" : ans;
    }
};