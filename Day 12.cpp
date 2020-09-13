// Combination Sum III

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int k, int n, int i, vector<int> v) {
        if(k < 0)
            return;
        if(k == 0 && n == 0) {
            ans.push_back(v);
            return;
        }
        for(int j = i; j <= 9; j++) {
            v.push_back(j);
            helper(k - 1, n - j, j + 1, v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(k, n, 1, {});
        return ans;
    }
};