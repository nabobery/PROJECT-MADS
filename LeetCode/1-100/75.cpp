// 75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(3), result(n);
        // first count number of each color of balls
        for(int i = 0; i < n; i++)
            count[nums[i]]++;
        // add the number of balls to find out the ending index
        for(int i = 1; i < 3; i++)
            count[i] += count[i - 1];
        // now fill in the values in the array
        for(int i = n - 1; i >= 0; i--){
            result[count[nums[i]] - 1] = nums[i];
            count[nums[i]]--;
        }
        // now give back the values to orginal array
        for(int i = 0; i < n; i++)
            nums[i] = result[i];
    }
};

