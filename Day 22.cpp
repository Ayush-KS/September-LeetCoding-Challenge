// Majority Element II

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1, n2, c1, c2;
        n1 = n2 = -1;
        c1 = c2 = 0;
        
        for(int i : nums) {
            if(n1 == i)
                c1++;
            else if(n2 == i)
                c2++;
            else if(c1 == 0) {
                n1 = i;
                c1 = 1;
            } 
            else if(c2 == 0) {
                n2 = i;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        c1 = c2 = 0;
        
        for(int i : nums) {
            if(i == n1)
                c1++;
            else if(i == n2)
                c2++;
        }
        
        vector<int> op;
        if(c1 > nums.size()/3)
            op.push_back(n1);
        if(c2 > nums.size()/3)
            op.push_back(n2);
        
        return op;
    }
};