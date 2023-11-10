// 2009. Minimum Number of Operations to Make Array Continuous

// Solution 1 using Binary Search 
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        vector<int> temp;
        for(auto num: unique) temp.push_back(num);
        int n = nums.size(), result = n-1;
        for(int i = 0; i < temp.size();i++){
            int l = i, r = temp.size()-1, target = temp[l]+ n-1, rightend = temp.size();
            while(l <= r){
                int mid = (l + r) / 2;
                if(temp[mid] <= target){
                    l = mid+1;
                }
                else{
                    rightend = mid;
                    r = mid-1;
                }
            }
            result = min(result, n - rightend + i);
        }
        return result;
    }
};

// Solution 2 using Sliding Window and Two Pointers
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        vector<int> temp;
        for(auto num: unique) temp.push_back(num);
        int n = nums.size(), result = n-1;
        int r = 0;
        for(int l = 0; l < temp.size();l++){
            while(r < temp.size() && temp[r] <= temp[l] + n-1) r++;
            result = min(result, n - r + l);
        }
        return result;
    }
};