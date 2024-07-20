// 2751. Robot Collisions

// Solution 1 using sorting, Stack and Simulation
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> res;
        vector<pair<int, int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }
        sort(robots.begin(), robots.end());
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            int pos = robots[i].first;
            int idx = robots[i].second;
            if (directions[idx] == 'L') {
                // if top robot is moving right we collide
                // As we are moving from left or right, we are only interested in the current robots moving left as they are the ones that can collide with the robots moving right
                while (!st.empty() && directions[st.top().second] == 'R' && healths[st.top().second] < healths[idx]) {
                    st.pop();
                    healths[idx] -= 1;
                }
                if(!st.empty() && directions[st.top().second] == 'R'){
                    if(healths[st.top().second] == healths[idx]){
                        healths[st.top().second] = 0;
                        healths[idx] = 0;
                        st.pop();
                    }
                    else{
                        healths[idx] = 0;
                        healths[st.top().second] -= 1;
                    }
                }
            }
            if(healths[idx] > 0) st.push({pos, idx});
        }
        while(!st.empty()){
            positions[st.top().second] = -1;
            st.pop();
        }
        for(int i = 0; i < n; i++){
            if(positions[i] == -1) res.push_back(healths[i]);
        }
        return res;
    }
};