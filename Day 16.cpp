// Maximum XOR of Two Numbers in an Array

class trieNode {
    public:
    trieNode* left;
    trieNode* right;
    
    trieNode() {
        left = NULL;
        right = NULL;
    }
};

trieNode* build(vector<int>& nums) {
    trieNode* root = new trieNode();
    
    for(int num : nums) {
        trieNode* temp = root;
        for(int i = 31; i >= 0; i--) {
            int curr = num & (1 << i);
            if(curr) {
                if(!temp -> right) {
                    temp -> right = new trieNode();
                }
                temp = temp -> right;
            } else {
                if(!temp -> left) {
                    temp -> left = new trieNode();
                }
                temp = temp -> left;
            }
        }
    }
    
    return root;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = build(nums);
        int ans = 0;
        
        for(int num : nums) {
            trieNode* temp = root;
            int currAns = 0;
            for(int i = 31; i >= 0; i--) {
                int curr = num & (1 << i);
                if(curr) {
                    if(temp -> left) {
                        temp = temp -> left;
                        currAns += (1 << i);
                    } else {
                        temp = temp -> right;
                    }
                } else {
                    if(temp -> right) {
                        temp = temp -> right;
                        currAns += (1 << i);
                    } else {
                        temp = temp -> left;
                    }
                }
            }
            ans = max(ans, currAns);
        }
        
        return ans;
    }
};