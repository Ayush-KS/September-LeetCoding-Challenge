// Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int arr[10] = {0};
        for(char c : secret) {
            arr[c - '0']++;
        }
        
        int cows = 0, bulls = 0;
        for(int i = 0; i < min(secret.size(), guess.size()); i++) {
            if(secret[i] == guess[i]) {
                arr[secret[i] - '0']--;
                bulls++;
                guess[i] = 'a';
            }
        }
        for(int i = 0; i < guess.size(); i++) {
            if(guess[i] != 'a' && arr[guess[i] - '0']) {
                arr[guess[i] - '0']--;
                cows++;
            }
        }
        
        string op = to_string(bulls) + "A" + to_string(cows) + "B";
        return op;
    }
};