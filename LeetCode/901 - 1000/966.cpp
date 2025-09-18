// 966. Vowel Spellchecker

// Solution 1: Using Hashmaps and Hashsets
// Time Complexity: O(N + M) where N is the number of words in wordlist and M is the number of queries
// Space Complexity: O(N)
// 1 set to keep track of exact match
// 1 map to keep track of capitalization first match
//  for vowel errors, we use a map to check if consonants are in the same order and are present in the wordlist
class Solution {
public:
    string toLowercase(string str) {
        transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c) { return tolower(c); });
        return str;
    }

    string convertToHash(string str){
        string res;
        for(char&ch : str){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') res += '#';
            else res += ch;
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exactMatches(wordlist.begin(), wordlist.end());                            
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> hashStrings;
        int q = queries.size();
        vector<string> res(q);
        for(auto& word: wordlist){
            string low = toLowercase(word);
            if(!caseInsensitive.count(low)) caseInsensitive[low] = word;
            string hash = convertToHash(low);
            if(!hashStrings.count(hash)) hashStrings[hash] = word;
        }
        // follow precedence and store result
        for(int i = 0; i < q;i++){
            string result, query = queries[i];
            string low =  toLowercase(query), hash = convertToHash(low);
            if(exactMatches.count(query)) result = query; 
            else if(caseInsensitive.count(low)) result = caseInsensitive[low];
            else if(hashStrings.count(hash)) result = hashStrings[hash];
            res[i] = result;
        }
        return res;
    }
};