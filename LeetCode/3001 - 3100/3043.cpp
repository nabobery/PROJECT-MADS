// 3043. Find the Length of the Longest Common Prefix

// Solution 1 by using hash map
// insert all the prefixes of the numbers in arr1 into a set and then iterate through the numbers in arr2 and check if the prefix is present in the set
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;
        int res = 0;
        for(int num : arr1){
            string curr = "";
            for(char ch : to_string(num)){
                curr += ch;
                s.insert(curr);
            }
        }
        for(int num : arr2){
            string curr = "";
            for(char ch : to_string(num)){
                curr += ch;
                if(s.count(curr)) res = max(res, (int)curr.size());
                else break;
            }
        }
        return res;
    }
};

// Solution 2 by using Trie
// Time complexity: O(n*m)
// Space complexity: O(n*m)

// Trie Node to store the children of the current node in the trie 
// number 0-9 can be stored in the children array
class TrieNode{
public:
    TrieNode* children[10];
    TrieNode(){
        for(int i = 0; i < 10; i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    // insert the number into the trie
    void insert(int num){
        TrieNode* curr = root;
        string s = to_string(num);
        for(char ch : s){
            int idx = ch - '0';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
    }
    // find the longest common prefix of the number with the numbers in the trie
    int findLongestCommonPrefix(int num){
        TrieNode* curr = root;
        string s = to_string(num);
        int res = 0;
        for(char ch : s){
            int idx = ch - '0';
            if(curr->children[idx] == nullptr) break;
            curr = curr->children[idx];
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        // insert all the numbers in arr1 into the trie
        for(int num : arr1){
            trie.insert(num);
        }
        int res = 0;
        // find the longest common prefix of the numbers in arr2 with the numbers in the trie
        for(int num : arr2){
            res = max(res, trie.findLongestCommonPrefix(num));
        }
        return res;
    }
};

