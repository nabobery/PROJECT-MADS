// 2337. Move Pieces to Obtain a String

// Solution 1: Count the number of pieces in order to obtain the target string
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        vector<pair<char, int>> sta, tar;
        for(int i = 0; i < n;i++){
            if(start[i] == 'L') sta.push_back({start[i], i });
            else if(start[i] == 'R') sta.push_back({start[i], i });
        }
        for(int i = 0; i < n;i++){
            if(target[i] == 'L') tar.push_back({target[i], i });
            else if(target[i] == 'R') tar.push_back({target[i], i });
        }
        if(sta.size() != tar.size()) return false;
        for(int i = 0; i < sta.size();i++){
            if(sta[i].first != tar[i].first) return false;
            if(sta[i].first == 'L'){
                if(sta[i].second < tar[i].second) return false;
            }
            else{
                if(sta[i].second > tar[i].second) return false;
            }
        }
        return true;
    }
};