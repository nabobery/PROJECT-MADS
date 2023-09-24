// 1282. Group the People Given the Group Size They Belong To

// Solution 1 using map and vector
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        vector<vector<int>> result;
        for(int i = 0; i < groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        } 
        vector<int> t;
        for(auto it : mp){
            for(int i = 0; i < it.second.size(); i += it.first){
                t.assign(it.second.begin()+i, it.second.begin()+i+it.first);
                result.push_back(t);
                t.clear();
            }
        }
        return result;
    }
};