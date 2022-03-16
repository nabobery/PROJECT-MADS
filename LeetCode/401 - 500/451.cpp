// 451. Sort Characters By Frequency
// my naive O(nlogn) time and O(n) space solution
class Solution {
public:
    static bool cmp(pair<char, int>& a,pair<char, int>& b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        vector<pair<char,int>> temp;
        for(pair<char,int> p : mp){
            temp.push_back(p);
        }
        sort(temp.begin(),temp.end(),cmp);
        int j = 0;
        for(auto itr : temp){
            for(int i = 0; i < itr.second;i++){
                s[j+i] = itr.first;
            }
            j += itr.second;
        }
        return s;
    }
};

