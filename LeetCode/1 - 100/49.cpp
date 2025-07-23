// 49. Group Anagrams
// my naive TLE solution
class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.size() != t.size()) return false;
        int count[26] = {0};
        for(int i = 0; i < s.size();i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(auto n : count) if(n) return false;
        return true;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 1){
            result.push_back(strs);
            return result;
        }
        unordered_set <string> s;
        for(string str : strs) s.insert(str);
        for(auto it = s.begin(); it != s.end();){
            vector<string> temp;
            string tmp = *it;
            for(string str : strs){
                if(isAnagram(tmp,str)){
                    temp.push_back(str);
                    if(tmp != str) s.erase(str);
                }
            }
            s.erase(it++);
            result.push_back(temp);
        }
        return result;
    }
};

// solution using map and getting count of each character in string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return {strs};
        vector<int> count(26,0);
        map<vector<int>, vector<int>> mp;
        for(int i = 0; i < n;i++){
            for(auto ch : strs[i]){
                count[ch-'a']++;
            }
            mp[count].push_back(i);
            fill(count.begin(), count.end(), 0);
        }
        vector<vector<string>> result;
        vector<string> temp;
        for(auto it : mp){
            for(auto i : it.second){
                temp.push_back(strs[i]);
            }
            result.push_back(temp);
            temp.clear();
        }
        
        return result;
    }
};

// using Sorting and creating a map from sorted string to it's anagrams(vector)
// O(N * LlogL) time and O(N * L) space solution
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1){
            return {{strs[0]}};
        }
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(string str : strs) {
            string temp = str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }
        for(auto itr : mp){
            result.push_back(itr.second);
        }
        return result;
    }
};

// using counting sort O(N * L) time and space solution
class Solution {
public:
    string getKey(string str){
        int count[26] = {0};
        for (char c : str) count[c - 'a']++;
        string key = str;
        for (int i = 0, j = 0; i < 26; ++i)
            while (count[i]-- > 0)
                key[j++] = char(i + 'a');
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1){
            return {{strs[0]}};
        }
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for (const string& str : strs)
            mp[getKey(str)].push_back(str);
        for(auto itr : mp){
            result.push_back(itr.second);
        }
        return result;
    }
};

// Optimized counting sort O(N * L) time and space solution 
class Solution {
public:
    string getKey(const string& str){
        int count[26] = {0};
        for (char c : str) count[c - 'a']++;
        string key = str;
        for (int i = 0, j = 0; i < 26; ++i)
            while (count[i]-- > 0)
                key[j++] = char(i + 'a');
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1){
            return {{strs[0]}};
        }
        vector<vector<string>> result;
        vector<string> temp;
        unordered_map<string,vector<int>> mp;
        for (int i = 0; i < strs.size();i++)
            mp[getKey(strs[i])].push_back(i);
        for(const auto& itr : mp){
            for(auto i : itr.second) temp.push_back(strs[i]);
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }  
};


