// 2948. Make Lexicographically Smallest Array by Swapping Elements

// Solution 1 using DFS and sorting (Memory Limit Exceeded)
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> res(n);
        vector<vector<int>> adj(n);
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n;i++) vec[i] = {nums[i], i};
        sort(vec.begin(), vec.end());
        int l = 0;
        for(int r = 1; r < n;r++){
            while(l < r && vec[r].first - vec[l].first > limit){
                l++;
            }
            for(int i = l; i < r;i++){
                adj[vec[l].second].push_back(vec[r].second);
                adj[vec[r].second].push_back(vec[l].second);
            }
        }
        unordered_map<int, int> indexToComponent;
        int componentId = 0;
        for (int i = 0; i < n; i++) {
            if (indexToComponent.find(vec[i].second) == indexToComponent.end()) {
                dfs(vec[i].second, adj, indexToComponent, componentId);
                componentId++;
            }
        }

        unordered_map<int, multiset<int>> componentToValues;
        for (int i = 0; i < n; i++) {
            int compId = indexToComponent[vec[i].second];
            componentToValues[compId].insert(vec[i].first);
        }
        for (int i = 0; i < n; i++) {
            int compId = indexToComponent[i];
            int smallestValue = *componentToValues[compId].begin();
            res[i] = smallestValue;
            componentToValues[compId].erase(componentToValues[compId].begin());
        }
        
        return res;
    }
    void dfs(int index, vector<vector<int>>& adj, unordered_map<int, int>& indexToComponent, int componentId) {
        indexToComponent[index] = componentId;
        for (int neighbor : adj[index]) {
            if (indexToComponent.find(neighbor) == indexToComponent.end()) {
                dfs(neighbor, adj, indexToComponent, componentId);
            }
        }
    }
};

// Solution 2 using Smart sorting
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> vec(n); 
        for (int i = 0; i < n; i++) 
            vec[i] = {nums[i], i};
        sort(vec.begin(), vec.end());
        vector<vector<int>> components;
        vector<int> currentComponent;
        currentComponent.push_back(vec[0].second);
        for (int i = 1; i < n; i++) {
            if (vec[i].first - vec[i - 1].first <= limit) {
                currentComponent.push_back(vec[i].second);
            } else {
                components.push_back(currentComponent);
                currentComponent = {vec[i].second};
            }
        }
        components.push_back(currentComponent);
        for (auto& comp : components) 
            sort(comp.begin(), comp.end());
        vector<int> res(n);
        int valueIndex = 0;
        for (const auto& comp : components) {
            for (int index : comp) {
                res[index] = vec[valueIndex].first;
                valueIndex++;
            }
        }
        return res;
    }
};