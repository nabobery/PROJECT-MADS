// 2246. Longest Path With Different Adjacent Characters

class Solution {
public:
    int result = 1;
    int helper(int n,vector<vector<int>>& children, string& s){
        int l1 = 0,l2 = 0;
        for(auto c : children[n]){
            int l3 = helper(c,children,s);
            if(s[n] == s[c]) continue;
            if(l3 > l1){
                l2 = l1;
                l1  = l3;
            }
            else if(l3 > l2){
                l2 = l3;
            }
        }
        result = max(result, l1 + l2 + 1);
        return l1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for(int i = 1; i < n;i++){
            children[parent[i]].push_back(i);
        }
        helper(0,children, s);
        return result;
    }
};
