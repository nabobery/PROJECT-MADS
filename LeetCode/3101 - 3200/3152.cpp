//  3152. Special Array II

// Solution  1 using some kinf of prefix sum + binary search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    bool static comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), start = 0;
        bool prev = nums[0]%2, curr;
        vector<bool> res(q, false);
        vector<pair<int,int>> special_sub;
        for(int i = 1; i < nums.size();i++){
            curr = nums[i]%2;
            if(curr == prev){
                special_sub.push_back({start, i-1});
                start = i;
            }
            else{
                prev = curr;
            }
        }
        special_sub.push_back({start, nums.size()-1});
        for(int i = 0; i < q;i++){
            pair<int,int> p = {queries[i][0], queries[i][1]};
            auto it = upper_bound(special_sub.begin(), special_sub.end(), p, comparePairs);
            if (it != special_sub.begin()) {
                --it;
                if (it->first <= p.first && it->second >= p.second) 
                    res[i] = true; 
            }
        }
        return res;
    }
};