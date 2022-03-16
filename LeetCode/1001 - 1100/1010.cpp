// 1010. Pairs of Songs With Total Durations Divisible by 60
// Naive solution (TLE as O(n^2))
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int result = 0;
        for(int i = 0;i < n - 1; i++){
            for(int j = i + 1; j < n;j++){
                if((time[i] + time[j]) % 60 == 0){
                    result++;
                }
            }
        }
        return result;
    }
};

// using array to store mod (not efficient)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int result = 0;
        int mod[60] = {0};
        for(int i = 0; i < n;i++){
            mod[time[i] % 60]++;
        }
        for(int i = 0; i < 31;i++){
            if(i == 0 || i == 30){
                result += ((mod[i])*(mod[i] - 1))/2;
            }
            else{
                result += mod[i]*mod[60-i];
            }
        }
        return result;
    }
};

// a better solution without 2 loops (but not that great time wise)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        int mod[60] = {0};
        for (auto t : time) {
            result += mod[(60 - t % 60) % 60];
            ++mod[t % 60];
        }
        return result;
    }
};

