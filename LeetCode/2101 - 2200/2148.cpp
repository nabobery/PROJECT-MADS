// 2148. Count Elements With Strictly Smaller and Greater Elements
class Solution {
public:
    int countElements(vector<int>& nums) {
        int Min = nums[0], Max = nums[0];
        for(int i = 1; i < nums.size();i++){
            if(nums[i] > Max){
                Max = nums[i];
            }
            if(nums[i] < Min){
                Min = nums[i];
            }
        }
        int result= 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] > Min && nums[i] < Max){
                result++;
            }
        }
        return result;
    }
};

