// Word Break

class node {
    public:
    vector<node*> children;
    bool isTerminal;
    
    node() {
        children.resize(26, NULL);
        isTerminal = false;
    }
};

void insert(node* root, string s, int i) {
    if(i == s.size()) {
        root -> isTerminal = true;
        return;
    }
    if(!(root -> children[s[i] - 'a']))
        root -> children[s[i] - 'a'] = new node;
    insert(root -> children[s[i] - 'a'], s, i + 1);
}

class Solution {
public:
    
    bool find(node* root, node* curr, string s, int i, vector<int>& dp) {
        
        if(!curr)
            return false;
        
        if(curr == root && (dp[i] != -1))
            return dp[i];
        
        int ans = 0;
        
        if(i == s.size())
            return curr -> isTerminal;
        
        if(curr -> isTerminal && find(root, root, s, i, dp))
            ans = 1;
        
        ans |= find(root, curr -> children[s[i] - 'a'], s, i + 1, dp);
        
        if(curr == root)
            dp[i] = ans;
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& dict) {
        node* root = new node;
        for(string word : dict)
            insert(root, word, 0);
        vector<int> dp(s.size() + 1, -1);
        return find(root, root, s, 0, dp);
    }
};