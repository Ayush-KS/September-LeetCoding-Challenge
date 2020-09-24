// Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int tank = 0;
        int si;
        
        for(int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);
            tank += (gas[i] - cost[i]);
            if(tank < 0) {
                tank = 0;
                si = i + 1;
            }
        }
        
        return total < 0 ? -1 : si;
    }
};