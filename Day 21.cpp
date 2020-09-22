// Car Pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        unordered_map<int, int> mp;
        
        int dist = 0;
        
        for(vector<int>& v : trips) {
            mp[v[1]] += v[0];
            mp[v[2]] -= v[0];
            dist = max(dist, v[2]);
        }
        int curr = 0;
        
        for(int i = 0; i <= dist; i++) {
            curr += mp[i];
            if(curr > capacity)
                return false;
        }
        
        return true;
    }
};