// 169. Majority Element
// using unordered map to keep count and then compare and find majority O(N) space and time
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(int ele : nums){
            mp[ele]++;
        }
        int result, count = 0;
        for(auto itr : mp){
            if(itr.second > count){
                result = itr.first;
                count = itr.second;
            }
        }
        return result;
    }
};

// using sort O(nlogn) time and O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        /*int n = nums.size();
        int result = nums[0],count = 1, temp = nums[0];
        for(int i = 1; i < n;i++){
            if(temp == nums[i]){
                count++;
            }
            else{
                if(count > n/2){
                    result = temp;
                }
                temp = nums[i];
                count = 1;
            }
        }
        if(count > n/2){
            result = temp;
        }
         return result;
         */
        return (nums[nums.size()/2]);
    }
};

// Boyer-Moore Voting Algorithm O(N) time and O(1) space algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, result;
        for(int num : nums){
            if(count == 0){
                result = num;
            }
            count += (num == result) ? 1 : -1;
        }
        return result;
    }
};

