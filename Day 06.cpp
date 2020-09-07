// Image Overlap

class Solution {
public:
    
    int helper(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y) {
        int n = A.size();
        int ans = 0;
        
        for(int i = x; i < n; i++) {
            for(int j = y; j < n; j++) {
                ans += (A[i][j] & B[i - x][j - y]);
            }
        }
        
        return ans;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B, bool flag = false) {
        int n = A.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, helper(A, B, i, j));
            }
        }
        
        return flag ? ans : max(largestOverlap(B, A, true), ans);
    }
};