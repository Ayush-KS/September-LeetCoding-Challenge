// Subarray Product Less Than K

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0)
            return 0;
        int n = nums.size();
        int ans = 0;
        int left = 0, right = 0;
        long long int curr = 1;
        
        while(right < n) {
            curr *= nums[right];
            while(left <= right && curr >= k) {
                int diff = right - left;
                ans += diff;
                curr /= nums[left++];
            }
            right++;
        }
        long long int diff = right - left;
        ans += (((diff)*(diff + 1)) / 2);
        
        return ans;
    }
};