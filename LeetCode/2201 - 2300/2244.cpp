// 2244. Minimum Rounds to Complete All Tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto task : tasks) mp[task]++;
        int rounds = 0;
        for(auto itr : mp){
            if(itr.second < 2) return -1;
            else{
                rounds += itr.second/3;
                if(itr.second % 3 != 0) rounds++;
            }
        }
        return rounds;
    }
};