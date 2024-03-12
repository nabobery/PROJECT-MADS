// 721. Accounts Merge

// SImple and Naive Solution 1 using DFS 
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    void dfs(string u, unordered_map<string,vector<string>>& adj, unordered_set<string>& visited, vector<string>& path){
        visited.insert(u);
        path.push_back(u);
        for(auto v : adj[u]){
            if(!visited.count(v)) dfs(v, adj, visited, path);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_map<string,vector<string>>> mp;
        for(auto account : accounts){
            int n = account.size();
            string name = account[0];
            if(account.size() == 2)
                mp[name][account[1]] = {};
            for(int i = 1;i < n-1;i++){
                for(int j = i+1;j < n;j++){
                    mp[name][account[i]].push_back(account[j]);
                    mp[name][account[j]].push_back(account[i]);
                }
            }
        }
        vector<vector<string>> res;
        for(auto it : mp){
            auto adj = it.second;
            unordered_set<string> visited;
            for(auto u : adj){
                if(!visited.count(u.first)){
                    vector<string> temp;
                    dfs(u.first, adj, visited, temp);
                    if(!temp.empty()){
                        sort(temp.begin(), temp.end());
                        temp.insert(temp.begin(), it.first);
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;  
    }
};


// Solution 2 using BFS (Optimized because we're not connecting all the nodes to each other)
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                emailToName[account[i]] = name;
                if (i == 1) continue;
                graph[account[i]].push_back(account[i - 1]);
                graph[account[i - 1]].push_back(account[i]);
            }
        }
        unordered_set<string> visited;
        vector<vector<string>> res;
        for (const auto& [email, name] : emailToName) {
            if (visited.count(email)) continue;
            visited.insert(email);
            vector<string> emails = {email};
            queue<string> q;
            q.push(email);
            while (!q.empty()) {
                const string u = q.front();
                q.pop();
                for (const string& v : graph[u]) {
                    if (visited.count(v)) continue;
                    visited.insert(v);
                    emails.push_back(v);
                    q.push(v);
                }
            }
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), name);
            res.push_back(emails);
        }
        return res;
    }
};

// Solution 3 using Union Find
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class UnionFind {
public:
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u, int v) {
        parent[find(u)] = find(v);
    }
private:
    vector<int> parent;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, int> emailToID;
        int id = 0;
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                const string& email = account[i];
                emailToName[email] = name;
                if (!emailToID.count(email)) 
                    emailToID[email] = id++;
            }
        }
        UnionFind uf(id);
        for (const auto& account : accounts) {
            const int u = emailToID[account[1]];
            for (int i = 2; i < account.size(); ++i) {
                const int v = emailToID[account[i]];
                uf.unite(u, v);
            }
        }
        unordered_map<int, vector<string>> idToEmails;
        for (const auto& [email, id] : emailToID) {
            const int root = uf.find(id);
            idToEmails[root].push_back(email);
        }
        vector<vector<string>> res;
        for (auto& [id, emails] : idToEmails) {
            vector<string> account = {emailToName[emails[0]]};
            sort(emails.begin(), emails.end());
            account.insert(account.end(), emails.begin(), emails.end());
            res.push_back(account);
        }
        return res;
    }
};