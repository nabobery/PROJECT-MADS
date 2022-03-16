// 454. 4Sum II
// using 2 unordered_maps O(n^2) time and O(n^2) space solution
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int,int> mp1;
        unordered_map <int,int> mp2;
        int n = nums1.size();
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                int sum1 = nums1[i] + nums2[j];
                mp1[sum1]++;
                sum1 = nums3[i] + nums4[j];
                mp2[sum1]++;
            }
        }
        int result = 0;
        for(auto itr : mp1){
            int temp = itr.first;
            temp *= -1;
            if(mp2.find(temp) != mp2.end()){
                result += (mp2[temp])*itr.second;
            }
        }
        return result;
    }
};

// using 1 ordered map O(n^2) time + O(n^2) space
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp;
        int n = nums1.size();
        for(int i : nums1){
            for(int j : nums2){
                mp[i+j]++;
            }
        }
        int result = 0;
        for(int i : nums3){
            for(int j : nums4){
                result += mp[-(i+j)];
            }
        }
        return result;
    }
};

//  1 unordered_map solution
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int result = 0;
        unordered_map<int,int> mp;
        for (auto &it1: nums1)
            for (auto &it2:nums2)
                mp[it1+it2]++;

        for(auto &it3: nums3)
            for(auto &it4:nums4)
                if(mp.count(0-it3-it4)) result += mp[0-it3-it4];
        return result;
    }
};