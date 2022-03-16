// 567. Permutation in String
// my naive solution based on 438 using sliding window and frequencies
// Time Complexity : O(n + 26(m-n)) and space : O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> count1(26,0), count2(26,0);
        for(int i = 0; i < n; i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        if(count1 == count2) return true;
        for(int i = n; i < m;i++){
            count2[s2[i - n] - 'a']--;
            count2[s2[i] - 'a']++;
            if(count1 == count2) return true;
        }
        return false;
    }
};

// Optimised sliding window and frequencies as we're not checking if vectors are equal again and again
// Time Complexity : O(n + (m-n)) and Space : O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> count1(26,0), count2(26,0);
        for(int i = 0; i < n; i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++)
            if(count1[i] == count2[i]) count++;
        for(int i = n; i < m;i++){
            int r = s2[i] - 'a', l = s2[i-n] - 'a';
            if(count == 26) return true;
            count2[r]++;
            if(count2[r] == count1[r]) count++;
            else if(count2[r] == count1[r] + 1) count--;
            count2[l]--;
            if(count2[l] == count1[l]) count++;
            else if (count2[l] == count1[l] - 1) count--;
        }
        return (count == 26);
    }
};

