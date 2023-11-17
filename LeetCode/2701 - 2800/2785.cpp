// 2785. Sort Vowels in a String

// Solution 1 Using Pointers and Hashmap
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> mp = {{'A', 0},{'E', 1},{'I', 2},{'O', 3},{'U', 4},{'a', 5},{'e', 6},{'i', 7},{'o', 8},{'u', 9}};
        string vowels = "AEIOUaeiou";
        vector<int> count(10, 0);
        for(auto i : s){
            if(mp.count(i))
                count[mp[i]]++;
        }
        int p = 0;
        for(int i = 0; i < s.size();i++){
            if(mp.count(s[i])){
                while(count[p] <= 0) p++;
                s[i] = vowels[p];
                count[p]--;
                if(count[p] <= 0) p++;
            }
        }
        return s;
    }
};

// Solution 2 Using Sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

class Solution {
public:
    bool isVowel(char c){
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string sortVowels(string s) {
        string temp = "";
        for(auto i : s){
            if(isVowel(i))
                temp += i;
        }
        sort(temp.begin(), temp.end());
        int p = 0;
        for(int i = 0; i < s.size();i++){
            if(isVowel(s[i])){
                s[i] = temp[p];
                p++;
            }
        }
        return s;
    }
};

