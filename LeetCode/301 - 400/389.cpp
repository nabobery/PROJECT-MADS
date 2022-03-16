// 389. Find the Difference
// using sorting
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size() == 0) return t[0];
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i = 0; i < s.size();i++){
            if(s[i] != t[i])
                return t[i];
        }
        return t[s.size()];
    }
};

// using 2 arrays
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size() == 0) return t[0];
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i = 0; i < s.size();i++){
            count1[s[i] - 'a']++;
            count2[t[i] - 'a']++;
        }
        count2[t[s.size()] - 'a']++;
        int i;
        for(i = 0; i < 26;i++){
            if(count1[i] != count2[i]){
                break;
            }
        }
        char ch = i + 'a';
        return ch;
    }
};

// using sum
class Solution {
public:
    char findTheDifference(string s, string t) {
        int a = 0, b= 0;
        for(char c : s)
            a += c;
        for(char c : t)
            b +=c ;
        return (b-a);
    }
};

// using xor and bit manipulation
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for(char c : s)
            result ^= c;
        for(char c : t)
            result ^= c ;
        return result;
    }
};

