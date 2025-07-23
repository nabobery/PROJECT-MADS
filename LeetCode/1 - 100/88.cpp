// 88. Merge Sorted Array

// Solution 1 with O(m+n) memory and time
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        unordered_map<int,int> mp;
        while(p1 < m && p2 < n){
            if(nums1[p1] <= nums2[p2]){
                mp[p1+p2] = nums1[p1];
                p1++;
            }
            else{
               mp[p1+p2] = nums2[p2];
                p2++; 
            }
        }
        if(p1 < m){
            while(p1 < m){
                mp[p1+p2] = nums1[p1];
                p1++;
            }
        }
        if(p2 < n){
            while(p2 < n){
                mp[p1+p2] = nums2[p2];
                p2++;
            }
        }
        for(int i = 0; i < nums1.size();i++) nums1[i] = mp[i];
    }
};

// Solution 2 with O(1) memory and O(m+n) time
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else nums1[k--] = nums2[j--];
        }
    }
};