// 187. Repeated DNA Sequences
// my naive O(n) space and O(n) time solution
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if(n <= 10) return {};
        unordered_map <string,int> mp;
        for(int i = 0; i <= n-10;i++){
            mp[s.substr(i,10)]++;
        }
        vector<string> result;
        for(auto itr : mp){
            if(itr.second > 1) result.push_back(itr.first);
        }
        return result;
    }
};

// using bit manipulation
// basically we maintain a map from int representing substring of size 10 to count
// we take substring of size 10 and use 3 bits to represent a char
// A is 0101, C is 0103, G is 0107, T is 0124 in octal and  A & 7 = 0001, C & 7 = 0011, G & 7 = 0111, T & 7 = 0100
// 0x3FFFFFFF = 0011 1111 1111 1111 1111 1111 1111 1111
// when we encounter a new letter we left shift by 3 (Ex : 1 to 1000) and then and with 0x3FFFFFFF and then or with the digit.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> mp;
        vector<string> result;
        int i = 0, n = s.size();
        if(n <= 10) return result;
        unsigned t = 0;
        for (int i = 0; i < s.size(); i++)
            if (mp[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
                result.push_back(s.substr(i - 9, 10));
        return result;
    }
};



