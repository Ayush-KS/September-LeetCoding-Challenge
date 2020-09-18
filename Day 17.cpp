// Robot Bounded In Circle

class Solution {
public:
    bool isRobotBounded(string inst) {
        int cnt = 0, x = 0, y = 0;
        for(char c : inst) {
            if(c == 'L') {
                (cnt += 3) %= 4;
            } else if(c == 'R') {
                (cnt += 1) %= 4;
            } else {
                if(cnt == 0) {
                    y++;
                } else if(cnt == 1) {
                    x++;
                } else if(cnt == 2) {
                    y--;
                } else {
                    x--;
                }
            }
        }
        
        return (x == 0 && y == 0) || cnt != 0;
    }
};