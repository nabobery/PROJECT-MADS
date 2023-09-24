// 332. Reconstruct Itinerary

// Solution1 : dfs + priority_queue
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    unordered_map<string, priority_queue <string, vector<string>, greater<string>>> mp;
    void helper(string curr, vector<string>& result){
        while(!mp[curr].empty()){
            string next = mp[curr].top();
            mp[curr].pop();
            helper(next, result);
        }
        result.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp.clear();
        for(auto it : tickets){
            mp[it[0]].push(it[1]);
        }
        vector<string> result;
        helper("JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
};

// Solution2: dfs using stack + vector
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp.clear();
        for(auto it : tickets){
            mp[it[0]].push_back(it[1]);
        }
        for(auto& it : mp){
            sort(it.second.rbegin(), it.second.rend());
        }
        vector<string> result;
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            string curr = st.top();
            if(mp[curr].empty()){
                result.push_back(curr);
                st.pop();
            }
            else{
                st.push(mp[curr].back());
                mp[curr].pop_back();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};