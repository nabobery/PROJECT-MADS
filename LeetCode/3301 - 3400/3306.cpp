// 3306. Count of Substrings Containing Every Vowel and K Consonants II

// Solution 1: Sliding window
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    public:
        map<char, int> vowelMap = {
            {'a', 0}, 
            {'e', 1}, 
            {'i', 2}, 
            {'o', 3}, 
            {'u', 4}
        };
        
        long long countOfSubstrings(string word, int k) {
            int n = word.size();
            long long res = 0;
            int l = 0, r = 0;
            int consonants = 0;
            int vowelCnt[5] = {0};
            
            // Precompute nextConsonant: for each index i, store the first index after i that is a consonant (or n if none)
            vector<int> nextConsonant(n, n);
            int nextCon = n;
            for (int i = n - 1; i >= 0; i--) {
                nextConsonant[i] = nextCon;
                if (vowelMap.find(word[i]) == vowelMap.end()) {  // not a vowel
                    nextCon = i;
                }
            }
            
            // Main loop: expand the window by moving r (the right end)
            while (r < n) {
                char ch = word[r];
                if (vowelMap.count(ch)) {
                    vowelCnt[vowelMap[ch]]++;
                } else {
                    consonants++;
                }
                
                // If the window has too many consonants, shrink from the left.
                while (l < n && consonants > k) {
                    char leftChar = word[l];
                    if (vowelMap.count(leftChar))
                        vowelCnt[vowelMap[leftChar]]--;
                    else
                        consonants--;
                    l++;
                }
                
                // Now if the window [l, r] has exactly k consonants and all vowels are present,
                // then every extension of the window with additional vowels (until the next consonant) is valid.
                while (l < n) {
                    bool allVowels = true;
                    for (int i = 0; i < 5; i++) {
                        if (vowelCnt[i] == 0) {
                            allVowels = false;
                            break;
                        }
                    }
                    if (consonants == k && allVowels) {
                        // Count valid substrings ending at any index from r to nextConsonant[r]-1.
                        res += (nextConsonant[r] - r);
                        
                        // Shrink the window from the left and update counts.
                        char leftChar = word[l];
                        if (vowelMap.count(leftChar))
                            vowelCnt[vowelMap[leftChar]]--;
                        else
                            consonants--;
                        l++;
                    } else {
                        break;
                    }
                }
                
                r++;
            }
            
            return res;
        }
};
    