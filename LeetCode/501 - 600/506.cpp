// 506. Relative Ranks

// Solution 1 using vector of pairs
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> t(n);
        for(int i = 0; i < n;i++)
            t[i] = {score[i], i};
        sort(t.rbegin(), t.rend());
        vector<string> res(n);
        for(int i = 0; i < n;i++){
            if(i == 0) res[t[i].second] = "Gold Medal";
            else if(i == 1) res[t[i].second] = "Silver Medal";
            else if(i == 2) res[t[i].second] = "Bronze Medal";
            else res[t[i].second] = to_string(i+1);
        }
        return res;
    }
};

// Solution 2 using map
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        map<int,int> t;
        for(int i = 0; i < n;i++)
            t[score[i]] = i;
        vector<string> res(n);
        int rank = 1;
        for(auto it = t.rbegin(); it != t.rend();it++){
            if(rank == 1) res[it->second] = "Gold Medal";
            else if(rank == 2) res[it->second] = "Silver Medal";
            else if(rank == 3) res[it->second] = "Bronze Medal";
            else res[it->second] = to_string(rank);
            rank++;
        }
        return res;
    }
};

// Solution 3 using pbds ordered set and find_by_order
// Time complexity: O(nlogn)
// Space complexity: O(n)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n);
        ordered_set t;
        for(int i = 0; i < n;i++)
            t.insert(score[i]);
        for(int i = 0; i < n;i++){
            int rank = t.order_of_key(score[i]);
            if(rank == 0) res[i] = "Gold Medal";
            else if(rank == 1) res[i] = "Silver Medal";
            else if(rank == 2) res[i] = "Bronze Medal";
            else res[i] = to_string(rank+1);
        }
        return res;
    }
};