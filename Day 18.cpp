// Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int currMin = INT_MAX;
        for(int i:prices) {
            profit = max(profit, i - currMin);
            currMin = min(currMin, i);
        }
        return profit;
    }
};