// 349. Intersection of Two Arrays

// Solution 1 using Hash set
// Time complexity: O(n + m)
// Space complexity: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int num : nums1) s.insert(num);
        vector<int> res;
        for(int num : nums2){
            if(s.count(num)){
                s.erase(num);
                res.push_back(num);
            }
        }
        return res;
    }
};

// Solution 2 using two pointers and sorting
// Time complexity: O(nlogn + mlogm)
// Space complexity: O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                if(res.empty() || res.back() != nums1[i]) res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return res;
    }
};