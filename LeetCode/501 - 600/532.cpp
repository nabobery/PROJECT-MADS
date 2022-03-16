// 532. K-diff Pairs in an Array
// my naive solution using sorting and unordered map
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n-1;i++){
            for(int j = i+1; j < n;j++){
                if(nums[j] - nums[i] == k){
                    if(mp.find(nums[i]) == mp.end()){
                        mp[nums[i]] = nums[j];
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return(mp.size());
    }
};

// using hashmap O(n) time and space solution
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // a map that contains frequency of elements
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        int result = 0;
        for(auto itr : mp){
            // if map contains num + k then count++ or k = 0 and there's more than one num
            if(k > 0 && mp.count(itr.first + k) || k == 0 && mp[itr.first] > 1)
                result++;
        }
        return result;
    }
};

// 2 pointer + sort O(nlogn) time and O(1) space solution
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0, n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        for(i,j; i < n && j < n;)
        {
            if(i == j || nums[j]-nums[i] < k)
                j++;
            else
            {
                if(nums[j]-nums[i] == k)
                {
                    result++;
                    j++;
                    for(;j < nums.size();j++)
                        if(nums[j] != nums[j-1])
                            break;
                    if(j==nums.size())
                        return result;
                    j--;
                }
                i++;
                while(i<j and nums[i]==nums[i-1])
                    i++;
            }
        }
        return result;
    }
};

