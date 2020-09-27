// Teemo Attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int dur) {
        int ans = 0;
        
        for(int i = 1; i < ts.size(); i++) {
            ans += min(ts[i] - ts[i - 1], dur);
        }
        
        return ts.empty() ? 0 : ans + dur;
    }
};