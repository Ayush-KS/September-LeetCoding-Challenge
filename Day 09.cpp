// Compare Version Numbers

class Solution {
public:
    int compareVersion(string v1, string v2, int i = 0, int j = 0) {
        if(i >= v1.size() && j >= v2.size())
            return 0;
        int num1 = 0, num2 = 0;
        while(i < v1.size() && v1[i] != '.') {
            num1 *= 10;
            num1 += (v1[i] - '0');
            i++;
        }
        
        while(j < v2.size() && v2[j] != '.') {
            num2 *= 10;
            num2 += (v2[j] - '0');
            j++;
        }
        
        if(num1 > num2) {
            return 1;
        } else if(num2 > num1) {
            return -1;
        } else {
            return compareVersion(v1, v2, i + 1, j + 1);
        }
    }
};