// Largest Time for Given Digits

class Solution {
public:
    string ans = "";
    void helper(vector<int>& nums, int i = 0) {
        if(i == nums.size()) {
            if(nums[0] > 2)
                return;
            if(nums[0] == 2) {
                if(nums[1] > 3)
                    return;        
            }
            if(nums[2] > 5)
                return;

            string curr = "";
            for(int i : nums)
                curr += to_string(i);
            if(ans == "" || ans < curr)
                ans = curr;
            return;
        }
        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    string largestTimeFromDigits(vector<int>& nums) {
        helper(nums);
        return ans == "" ? ans : ans.substr(0, 2) + ":" + ans.substr(2);
    }
};