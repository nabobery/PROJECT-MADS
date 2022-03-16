// 448. Find All Numbers Disappeared in an Array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        bool arr[n];
        for(int i = 0; i < n;i++){
            arr[i] = false;
        }
        for(int i = 0; i < n;i++){
            arr[nums[i] - 1] = true;
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == false){
                result.push_back(i+1);
            }
        }
        return result;
    }
};