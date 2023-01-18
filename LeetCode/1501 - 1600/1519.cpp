// 1519. Number of Nodes in the Sub-Tree With the Same Label

class Solution {
public:
    vector<int> helper(int n,int p, vector<vector<int>>& adj, string& labels, vector<int>& ans){
        vector<int> count(26);
        count[labels[n]-'a'] = 1;
        for(auto c : adj[n]){
            if(c == p) continue;
            vector<int> temp = helper(c,n,adj,labels,ans);
            for(int i = 0; i < 26;i++){
                count[i] += temp[i];
            }
        }
        ans[n] = count[labels[n]-'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> result(n,0);
        helper(0,-1,adj,labels,result);
        return result;
    }
};
