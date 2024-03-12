// 2540. Minimum Common Value

// Solution 1 using 2 pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0, n1 = nums1.size(), n2 = nums2.size();
        while(l < n1 && r < n2){
            if(nums1[l] == nums2[r]) return nums1[l];
            else if(nums1[l] < nums2[r]) l++;
            else r++;
        }
        return -1;
    }
};

// Solution 2 using hashset
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        for(int num : nums2)
            if(s.count(num)) return num;
        return -1;
    }
};

// Solution 3 using binary search
// Time complexity: O(nlogm)
// Space complexity: O(1)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        for(int num : nums2)
            if(binary_search(nums1.begin(), nums1.end(), num)) return num;
        return -1;
    }
};