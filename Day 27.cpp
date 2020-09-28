// Evaluate Division

class Solution {
public:
    
    double dfs(string s1, string s2, unordered_map<string, bool>& visited, unordered_map<string, vector<pair<string, double>>>& edges) {
        if(visited[s1]) {
            return -1;
        }
        visited[s1] = true;
        if(s1 == s2 && !edges[s1].empty())
            return 1;
        double ans = -1;
        for(pair<string, double> q : edges[s1]) {
            if(q.first == s2)
                return q.second;
            double smallAns = dfs(q.first, s2, visited, edges);
            
            if(smallAns != -1) {
                ans = smallAns * q.second;
                edges[s1].push_back({s2, ans});
                return ans;
            }
        }
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> output(queries.size());
        
        unordered_map<string, vector<pair<string, double>>> edges;
        double one = 1;
        for(int i = 0; i < values.size(); i++) {
            vector<string> v = equations[i];
            edges[v[0]].push_back({v[1], values[i]});
            edges[v[1]].push_back({v[0], one / values[i]});
        }
        
        for(int i = 0; i < queries.size(); i++) {
            vector<string> v = queries[i];
            unordered_map<string, bool> visited;
            output[i] = dfs(v[0], v[1], visited, edges);
        }
        
        return output;
    }
};