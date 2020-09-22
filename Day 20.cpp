// Unique Paths III

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& grid, int count) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == -1)
            return 0;
        
        visited[x][y] = true;
        if(grid[x][y] == 2) {
            visited[x][y] = false;
            return count == 0 ? 1 : 0; 
        }
        if(grid[x][y] != 1)
            count--;
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans += dfs(x + dx[i], y + dy[i], visited, grid, count);
        }
        visited[x][y] = false;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;
        for(vector<int> v : grid) 
            for(int i : v)
                if(i == 0)
                    count++;
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
                    ans += dfs(i, j, visited, grid, count);
                }
            }
        }
        
        return ans;
    }
};