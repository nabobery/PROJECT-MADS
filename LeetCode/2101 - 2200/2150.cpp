// 2150. Find All Lonely Numbers in the Array
// using unordered_map
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(int i = 0; i < nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> result;
        for(auto itr : mp){
            // if(itr.second == 1 && mp.find(itr.first + 1) == mp.end() && mp.find(itr.first - 1) == mp.end()){
            if(itr.second == 1 && !mp.count(itr.first + 1) && !mp.count(itr.first - 1)){
                result.push_back(itr.first);
            }
        }
        return result;
    }
};

//sorting solution
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if((i == 0 || nums[i-1] < nums[i]-1) && (i+1 == n || nums[i+1] > nums[i]+1)) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

