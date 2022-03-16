// 1557. Minimum Number of Vertices to Reach All Nodes
// my naive solution (include nodes that don't have any incoming edges)
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        unordered_set<int> s;
        for(vector<int> v : edges){
            s.insert(v[1]);
        }
        for(int i = 0; i < n; i++){
            if(s.find(i) == s.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};
