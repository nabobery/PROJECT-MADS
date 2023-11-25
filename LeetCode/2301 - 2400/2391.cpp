// 2391. Minimum Amount of Time to Collect Garbage

// Solution 1 - Naive and Simple
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g = -1, m = -1, p = -1, res = 0, sum = 0;
        for(int i = 0; i < garbage.size();i++){
            vector<bool> b(3, false);
            for(auto ch : garbage[i]){
                if(ch == 'G'){
                    if(!b[0]) b[0] = true;
                }
                else if(ch == 'M'){
                    if(!b[1]) b[1] = true;
                }
                else{
                    if(!b[2]) b[2] = true;
                }
            }
            res += garbage[i].size();
            if(b[0]) g = i;
            if(b[1]) m = i;
            if(b[2]) p = i;
        }
        for(int i = 0; i < travel.size();i++){
            if(g == i){
                g = -1;
                res += sum;
            }
            if(m == i){
                m = -1;
                res += sum;
            }
            if(p == i){
                p = -1;
                res += sum;
            }
            sum += travel[i];
        }
        if(g != -1) res += sum;
        if(m != -1) res += sum;
        if(p != -1) res += sum;
        return res;
    }
};

// Solution 2 - Using HashMap and InPlace Prefix Sum
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for (int i = 1; i < travel.size(); i++) {
            travel[i] = travel[i - 1] + travel[i];
        }
        unordered_map<char, int> mp;
        int res = 0;
        for(int i = 0; i < garbage.size();i++){
            for(auto ch : garbage[i]){
                mp[ch] = i;
            }
            res += garbage[i].size();
        }
        string s = "GMP";
        for(auto ch : s){
            if(mp[ch] == 0) continue;
            res += travel[mp[ch] - 1];
        }
        return res;
    }
};
