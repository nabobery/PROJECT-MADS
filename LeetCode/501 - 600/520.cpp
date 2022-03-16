// 520. Detect Capital
// my naive solution
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int temp =  word[0];
        bool flag1 = (temp >= 65 && temp <= 90);
        temp = word[n-1];
        bool flag2 = (temp >= 65 && temp <= 90);
        if(!flag1 && flag2){
            return false;
        }
        for(int i = 1; i < n - 1;i++){
            int temp = word[i];
            if(flag1 && flag2){
                if(temp >= 97 && temp <= 122)
                    return false;
            }
            else if(!flag1 && !flag2){
                if(temp >= 65 && temp <= 90)
                    return false;
            }
            else if(flag1 && !flag2){
                if(temp >= 65 && temp <= 90)
                    return false;
            }
        }
        return true;

    }
};

// efficient time wise solution by checking first 2 digits
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (isupper(word[0]) && isupper(word[1])) {
            for (int i = 2; i < n; i++) {
                if (islower(word[i])) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < n; i++) {
                if (isupper(word[i])) {
                    return false;
                }
            }
        }
        return true;
    }
};

