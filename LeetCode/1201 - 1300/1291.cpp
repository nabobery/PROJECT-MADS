// 1291. Sequential Digits
// my naive solution
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int num;
        for(int i = 1; i < 9;i++){
            num = i;
            int j = i;
            while(num < low && j < 10){
                j++;
                if(j < 10){
                    num *= 10;
                    num += j;
                }
            }
            while(num >= low && num <= high && j < 10){
                j++;
                result.push_back(num);
                num *= 10;
                num += j;
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};

