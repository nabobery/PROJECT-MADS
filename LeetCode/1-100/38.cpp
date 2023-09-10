// 38. Count and Say

// Solution 1: Using 2 helper functions
class Solution {
public:
    void helper1(string n, vector<pair<char,int>>& vec){
        char prev = n[0];
        int cnt = 1;
        for(int i = 1; i < n.size();i++){
            if(prev == n[i]) cnt++;
            else{
                vec.push_back({prev, cnt});
                cnt = 1;
            }
            prev = n[i];
        }
        if(cnt != 0) vec.push_back({prev, cnt});
    }
    string helper2(vector<pair<char,int>>& vec){
        string res = "";
        for(auto it : vec){
            res += to_string(it.second);
            res += it.first;
        }
        return res;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        vector<pair<char,int>> vec;
        string res = "1";
        for(int i = 2; i <= n;i++){
            helper1(res, vec);
            res = helper2(vec);
            vec.clear();
        }
        return res;
    }
};

// Solution 2: Using 0 helper functions
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = "1";
        for(int i = 2; i <= n;i++){
            vector<pair<char,int>> vec;
            char prev = res[0];
            int cnt = 1;
            for(int j = 1; j < res.size();j++){
                if(prev == res[j]) cnt++;
                else{
                    vec.push_back({prev, cnt});
                    cnt = 1;
                }
                prev = res[j];
            }
            if(cnt != 0) vec.push_back({prev, cnt});
            res = "";
            for(auto it : vec){
                res += to_string(it.second);
                res += it.first;
            }
        }
        return res;
    }
};

// Solution 3: Using no memory and using delimiter
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = "1";
        for(int i = 2; i <= n;i++){
            res += '#';
            string temp = "";
            int cnt = 1;
            for(int j = 1; j < res.size();j++){
                if(res[j] == res[j-1]) cnt++;
                else{
                    temp += to_string(cnt);
                    temp += res[j-1];
                    cnt = 1;
                }
            }
            res = temp;
        }
        return res;
    }
};