// 1446. Consecutive Characters
// My naive solution
class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        vector<int> power(n,0);
        int max = 0;
        int j;
        for(int i = 0; i < n;i++){
            char temp = s[i];
            j = i;
            while(temp == s[j]){
                power[i]++;
                j++;
            }
            if(power[i] > max){
                max = power[i];
            }
        }
        return max;
    }
};

// space optimised solution 
class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int Max = 0;
        int count  = 0;
        char prev = ' ';
        for(int i = 0; i < n;i++){
            char temp = s[i];
            if(temp == prev){
                count++;
            }
            else{
                count = 1;
                prev = temp;
            }
            Max = max(count,Max);        
        }
        return Max;
    }
};