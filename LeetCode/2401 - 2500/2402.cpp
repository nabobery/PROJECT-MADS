// 2402. Meeting Rooms III

// Solution 1 using Priority Queue 
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n, 0);
        priority_queue <int, vector<int>, greater<int> > pq1;
        priority_queue <pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>  pq2;
        for(int i = 0; i < n;i++) pq1.push(i);
        int res = 0, mx = 0;
        for(int i = 0; i < meetings.size();i++){
            while(!pq2.empty() && meetings[i][0] >= pq2.top().first){
                pq1.push(pq2.top().second);
                pq2.pop();
            }
            if(!pq1.empty()){
                int room = pq1.top();
                pq1.pop();
                cnt[room]++;
                pq2.push({meetings[i][1], room});
            }
            else{
                auto temp = pq2.top();
                pq2.pop();
                cnt[temp.second]++;
                pq2.push({temp.first + (meetings[i][1] - meetings[i][0]), temp.second});
            }
        }
        for(int i = 0; i < n;i++){
            if(mx < cnt[i]){
                mx = cnt[i];
                res = i;
            }
        }
        return res;
    }
};

