// Sequential Digits

class Solution {
public:
    vector<int> ans;
    
    void helper(int low, int high, int curr) {
        if(curr >= low && curr <= high) {
            ans.push_back(curr);
        }
        if(curr > high)
            return;
        
        int last = curr % 10;
        curr *= 10;
        curr += (last + 1);
        
        if(last != 9)
            helper(low, high, curr);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i <= 9; i++) {
            helper(low, high, i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};