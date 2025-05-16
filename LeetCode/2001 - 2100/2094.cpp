// 2094. Finding 3-Digit Even Numbers

// Solution 1: Straightforward and Simple
// Time Complexity: O(1000) = O(1)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0), temp(10);
        for(auto &d: digits) cnt[d]++;
        int j;
        vector<int> res;
        for(int i = 100; i < 1000;i+=2){
            bool b = true;
            j = i;
            temp = cnt;
            while(j){
                if(!temp[j%10]){
                    b = false;
                    break;
                }
                temp[j%10]--;
                j /= 10;
            }
            if(b) res.push_back(i);
        }
        return res;
    }
};