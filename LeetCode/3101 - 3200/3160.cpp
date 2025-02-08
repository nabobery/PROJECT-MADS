// 3160. Find the Number of Distinct Colors Among the Balls

// Solution 1: using Hashmaps
// Time complexity: O(q)
// Space complexity: O(q)
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> res(q);
        unordered_map<int, int> colors_map, colors;
        for(int i = 0; i < q;i++){
            int b = queries[i][0], c = queries[i][1];
            if(colors.count(b)){
                int prev = colors[b];
                colors_map[prev]--;
                if(colors_map[prev] == 0) colors_map.erase(prev);
            }
            colors[b] = c;
            colors_map[c]++;
            res[i] = colors_map.size();
        }
        return res;
    }
};