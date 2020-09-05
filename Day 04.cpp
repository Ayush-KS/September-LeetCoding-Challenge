// Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[26];
        int n = s.size();
        for(int i = 0; i < n; i++) {
            arr[s[i] - 'a'] = i;
        }
        
        vector<int> op;
        int currMax = 0;
        int start = -1;
        
        for(int i = 0; i < n; i++) {
            currMax = max(currMax, arr[s[i] - 'a']);
            if(currMax == i) {
                op.push_back(i - start);
                start = i;
                currMax = 0;
            }
        }
        
        return op;
    }
};