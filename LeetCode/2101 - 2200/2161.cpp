// 2161. Partition Array According to Given Pivot

// Solution 1: Straight forward using sorting
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size(), cnt = 0;
            vector<int> res(n);
            vector<pair<int,int>> left, right;
            for(int i = 0; i < n;i++){
                if(nums[i] < pivot) left.push_back({i , nums[i]});
                else if(nums[i] == pivot) cnt++;
                else right.push_back({i, nums[i]});
            }
            sort(left.begin(), left.end());
            sort(right.begin(), right.end());
            int p = 0;
            for(auto& it : left) res[p++] = it.second;
            for(int i = 0; i < cnt;i++) res[p++] = pivot;
            for(auto& it : right) res[p++] = it.second;
            return res;
        }
    };

// Solution 2: Using two pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size(), left = 0, cnt = 0, l =0, r, m;
            vector<int> res(n);
            for(int i = 0; i < n;i++){
                if(nums[i] < pivot) left++;
                else if(nums[i] == pivot) cnt++;
            }
            r = left+cnt;
            m = left;
            for(int i = 0; i < n;i++){
                if(nums[i] < pivot) res[l++] = nums[i];
                else if(nums[i] > pivot) res[r++] = nums[i];
                else res[m++] = nums[i];
            }
            return res;
        }
};
