// 438. Find All Anagrams in a String
// my naive solution TLE
class Solution {
public:
    bool check(string t, string p){
        int count[26] = {0};
        for(int i = 0; t[i] && p[i];i++){
            count[t[i]-'a']++;
            count[p[i]-'a']--;
        }
        for(int i = 0; i < 26;i++){
            if(count[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int m = s.size();
        if(n > m){
            return {};
        }
        else if(n == m){
            if(check(s,p))
                return {1};
            else
                return {};
        }
        else{
            vector<int> result;
            for(int i = 0; i <= m-n;i++){
                string temp = s.substr(i,n);
                if(check(temp,p))
                    result.push_back(i);
            }
            return result;
        }
    }
};

// O(N) time and O(1) space solution by checking frequency of p with frequency of window of s of size p and then pushing
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int m = s.size();
        if(n > m){
            return {};
        }
        vector<int> count_s(26,0), count_p(26,0);
        for(int i = 0; i < n;i++){
            count_s[s[i] - 'a']++;
            count_p[p[i] - 'a']++;
        }
        vector<int> result;
        if(count_s == count_p) result.push_back(0);
        for(int i = n; i < m;i++){
            count_s[s[i - n] - 'a']--;
            count_s[s[i] - 'a']++;
            if(count_s == count_p) result.push_back(i -n +1);
        }
        return result;
    }
};
