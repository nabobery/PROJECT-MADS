// 1. Two Sum
// naive sol
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n -1;i++){
            for(int j = i+1; j < n;j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

// using sort and binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        int low = 0;
        int high = n -1;
        int index1;
        int index2;
        while(low < high){
            if(v[low].first + v[high].first == target){
                index1 = v[low].second;
                index2 = v[high].second;
                break;
            }
            if(v[low].first + v[high].first < target){
                low++;
            }
            if(v[low].first + v[high].first > target){
                high--;
            }
        }
        return {index1,index2};
    }
};

// using hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map <int,int> map;
        int index1;
        int index2;
        for(int i = 0; i < n;i++){
            if(map.find(target - nums[i]) != map.end()){
                index1 = map[target - nums[i]];
                index2 = i;
                break;
            }
            else{
                map[nums[i]] = i;
            }
        }
        return {index1,index2};
    }
};


