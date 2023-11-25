// 1424. Diagonal Traverse II

// Solution 1 Naive and Simple
// Group the diagonal elements by their sum of indices
// sort each group by their column index in increasing order
// Where N is the total number of elements in the 2D vector
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    static bool comp(pair<int,int> a, pair<int, int> b){
        return a.second < b.second;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        map<int, vector<pair<int,int>>> mp;
        for(int i = 0; i < nums.size();i++){
            for(int j = 0; j < nums[i].size();j++){
                mp[i+j].push_back({i,j});
            }
        }
        for(auto it : mp){
            sort(it.second.begin(), it.second.end(), comp);
            for(auto p : it.second){
                res.push_back(nums[p.first][p.second]);
            }
        }
        return res;
    }
};

// Solution 2 using HashMap with no sorting
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        unordered_map<int, vector<int>> mp;
        for(int i = nums.size()-1; i >= 0;i--){
            for(int j = 0; j < nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        int sum = 0;
        while(mp.count(sum)){
            for(auto i : mp[sum]){
                res.push_back(i);
            }
            sum++;
        }
        return res;
    }
};


// Solution 3 using BFS
// Time complexity: O(N)
// Space complexity: O(sqrt(N))
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            res.push_back(nums[p.first][p.second]);
            if(p.second == 0 && p.first+1 < nums.size()){
                q.push({p.first+1, p.second});
            }
            if(p.second+1 < nums[p.first].size()){
                q.push({p.first, p.second+1});
            }
        }
        return res;
    }
};
