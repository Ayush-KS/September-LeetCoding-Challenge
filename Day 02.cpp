// Contains Duplicate III

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long int> st;
        
        if(t < 0)
            return false;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > k)
                st.erase(nums[i - k - 1]);
            auto it = st.lower_bound((long long int)nums[i] - t);
            if(it != st.end() && (*it - nums[i] <= t)) {
                return true;
            }
            st.insert(nums[i]);
        }
        
        return false;
    }
};