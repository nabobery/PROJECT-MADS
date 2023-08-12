// 350. Intersection of Two Arrays II

// Solution 1
class Solution {
public:
    int count1[1001], count2[1001];
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        memset(count1, 0, sizeof(count1));
        memset(count2, 0, sizeof(count2));
        for(int i = 0; i < n1;i++) count1[nums1[i]]++;
        for(int i = 0; i < n2;i++) count2[nums2[i]]++;
        vector<int> result;
        for(int i =0; i <= 1000;i++){
            for(int j = 0; j < min(count1[i], count2[i]);j++) result.push_back(i);
        }
        return result;
    }
};

// Solution 2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2;
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0; i < n1;i++) mp1[nums1[i]]++;
        for(int i = 0; i < n2;i++) mp2[nums2[i]]++;
        vector<int> result;
        for(auto it : mp1){
            if(mp2.count(it.first)){
                for(int i = 0; i < min(it.second, mp2[it.first]);i++) result.push_back(it.first);
            }
        }
        return result;
    }
};
