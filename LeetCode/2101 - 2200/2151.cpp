// 2151. Maximum Good People Based on Statements
// my solution using bitset
class Solution {
public:
    int powers[15] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
    bool isValid(vector<vector<int>>& statements,int i, int n){
        for(int j = 0; j < n;j++){
            if((i & powers[j]) == 0){
                continue;
            }
            for(int k = 0; k < n;k++){
                if(statements[j][k] == 2)
                    continue;
                if(statements[j][k] != ((i & powers[k]) >> k))
                    return false;
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int assum = pow(2,n);
        int currGood;
        int maxGood;
        for(int i = 0; i < assum;i++){
            bitset<15> temp(i);
            currGood = temp.count();
            if(currGood <= maxGood){
                continue;
            }
            if(isValid(statements,i,n)){
                maxGood = currGood;
            }
        }
        return maxGood;
    }
};

// solution using bit manipulation
class Solution {
public:
    int powers[15] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
    bool isValid(vector<vector<int>>& statements,int i, int n){
        for(int j = 0; j < n;j++){
            if((i & powers[j]) == 0){
                continue;
            }
            for(int k = 0; k < n;k++){
                if(statements[j][k] == 2)
                    continue;
                if(statements[j][k] != ((i & powers[k]) >> k))
                    return false;
            }
        }
        return true;
    }
    int count(int n){
        int result = 0;
        while (n > 0) {
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int assum = pow(2,n);
        int currGood;
        int maxGood = 0;
        for(int i = 0; i < assum;i++){
            currGood = count(i);
            if(currGood <= maxGood){
                continue;
            }
            if(isValid(statements,i,n)){
                maxGood = currGood;
            }
        }
        return maxGood;
    }
};
