/* 368. Largest Divisible Subset */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), max_index = 0;
        sort(nums.begin(), nums.end());
        vector<int> count(n, 1);
        vector<int> prev(n, -1);
        vector<int> result;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(count[i] < count[j] + 1){
                        count[i] = count[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(count[max_index] < count[i]){
                max_index = i;
            }
        }
        int k = max_index;
        while(k >= 0){
            result.push_back(nums[k]);
            k = prev[k];
        }
        return result;
    }
};