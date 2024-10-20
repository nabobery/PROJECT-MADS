// 1405. Longest Happy String

// Solution 1: Simulation using priority queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        string res;
        vector<int> count(3, 0);
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int ind = it.second - 'a';
            if(count[ind] >= 2){
                if(!pq.empty()){
                    auto it2 = pq.top();
                    pq.pop();
                    pq.push(it);
                    ind = it2.second - 'a';
                    count[ind]++;
                    for(int i = 0; i < 3;i++)
                        if(i != ind) count[i] = 0;
                    res += it2.second;
                    if(it2.first-1 != 0)
                        pq.push({it2.first-1, it2.second});
                }
                else break;
            }
            else{
                count[ind]++;
                for(int i = 0; i < 3;i++)
                    if(i != ind) count[i] = 0;
                res += it.second;
                if(it.first-1 != 0)
                    pq.push({it.first-1, it.second});
            }
        }
        return res;
    }
};
