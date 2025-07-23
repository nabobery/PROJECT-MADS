// 81. Search in Rotated Sorted Array II
// my naive O(N) solution
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int n : nums){
            if(n ==  target) return true;
        }
        return false;
    }
};

// Using Binary Search
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(),l;
        int prev = nums[0];
        if(prev == target) return true;
        for(int i = 1; i < n;i++){
            if(nums[i] >= prev){
                prev = nums[i];
                if(prev == target) return true;
            }
            else{
                l = i;
                break;
            }
        }
        int r  = n -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) r = mid - 1;
            else l = mid+ 1;
        }
        return false;
    }
};

