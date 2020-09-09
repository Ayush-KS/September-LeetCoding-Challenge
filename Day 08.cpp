// Sum of Root To Leaf Binary Numbers

class Solution {
public:
    int ans = 0;
    
    void helper(TreeNode* root, int curr) {
        if(!root)
            return;
        curr *= 2;
        curr += root -> val;
        if(!root -> left && !root -> right) {
            ans += curr;
            return;
        }
        if(root -> left) 
            helper(root -> left, curr);
        if(root -> right)
            helper(root -> right, curr);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
};