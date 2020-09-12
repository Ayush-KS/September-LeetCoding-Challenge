// Maximum Product Subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans, imin, imax;
        ans = imin = imax = nums[0];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < 0)
                swap(imin, imax);
            
            imin = min(nums[i], imin*nums[i]);
            imax = max(nums[i], imax*nums[i]);
            
            ans = max(ans, imax);
        }
        
        return ans;
    }
};