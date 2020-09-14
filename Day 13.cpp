// Insert Interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty() || intervals[0][0] > newInterval[1]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        } else if(intervals[intervals.size() - 1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> op;
        int lo = -1, hi = -1;
        
        for(int i = 0; i < intervals.size(); i++) {
            vector<int> v = intervals[i];
            if(i < intervals.size() && newInterval[0] > intervals[i][1] && newInterval[1] < intervals[i + 1][0]) {
                intervals.insert(intervals.begin() + i + 1, newInterval);
                return intervals;
            }
            if(v[1] < newInterval[0]) {
                op.push_back(v);
            } else if(v[0] > newInterval[1]) {
                if(lo != -1) {
                    op.push_back({lo, hi});
                    lo = -1;
                }
                op.push_back(v);
            } else {
                if(lo == -1) {
                    lo = min(v[0], newInterval[0]);
                } 
                hi = max(newInterval[1], v[1]);
            }
        }
        
        if(lo != -1) {
            op.push_back({lo, hi});
            lo = -1;
        }
        
        return op;
    }
};