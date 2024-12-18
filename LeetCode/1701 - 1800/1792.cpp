// 1792. Maximum Average Pass Ratio

// Solution 1 using Priority Queue (Greedy Approach)
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    struct Comparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return (((a.first + 1.0) / (a.second + 1)) - ((double)a.first / a.second)) <
                (((b.first + 1.0) / (b.second + 1)) - ((double)b.first / b.second));
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
        for(auto c: classes)
            pq.push({c[0], c[1]});
        double res = 0;
        while(extraStudents--){ 
            auto top = pq.top();
            pq.pop();
            pq.push({top.first+1, top.second+1});
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            res += double(top.first) / top.second;
        }
        res /= (classes.size());
        return res;
    }
};
