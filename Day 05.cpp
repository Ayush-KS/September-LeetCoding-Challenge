// All Elements in Two Binary Search Trees

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if(!root)
            return;
        
        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> first, second, output;
        inorder(root1, first);
        inorder(root2, second);
        int i = 0;
        int j = 0;
        while(i < first.size() && j < second.size()) {
            if(first[i] < second[j]) {
                output.push_back(first[i++]);
            } else {
                output.push_back(second[j++]);
            }
        }
        
        while(i < first.size()) {
            output.push_back(first[i++]);
        }
        while(j < second.size()) {
            output.push_back(second[j++]);
        }
        
        return output;
    }
};