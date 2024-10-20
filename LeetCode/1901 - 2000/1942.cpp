// 1942. The Number of the Smallest Unoccupied Chair

// Solution 1: Sorting + Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    struct party_friend{
        int arrival, departure, index;
    };
    static bool customCompare(party_friend a, party_friend b){
        return a.arrival < b.arrival;
    }
    int smallestChair(vector<vector<int>>& times, int targetfriend) {
        int n = times.size(), res = -1, mx = 0;
        vector<party_friend> party_friends(n);
        for(int i = 0; i < n;i++){
            party_friends[i].arrival = times[i][0]; 
            party_friends[i].departure = times[i][1];
            party_friends[i].index = i;
        }
        sort(party_friends.begin(),party_friends.end(), customCompare);
        if(party_friends[0].index == targetfriend) return 0;
        set<int> availablechairs;
        vector<int> chairs(n);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({party_friends[0].departure,party_friends[0].index});
        chairs[party_friends[0].index] = mx++;
        for(int i = 1; i < n;i++){
            while(!q.empty() && q.top().first <= party_friends[i].arrival){
                availablechairs.insert(chairs[q.top().second]);
                q.pop();
            }
            if(!availablechairs.empty()){
                chairs[party_friends[i].index] = *availablechairs.begin();
                availablechairs.erase(*availablechairs.begin());
            }
            else chairs[party_friends[i].index] = mx++;
            if(party_friends[i].index == targetfriend){
                res = chairs[party_friends[i].index];
                break;
            }
            q.push({party_friends[i].departure,party_friends[i].index});
        }
        return res;
    }
};
