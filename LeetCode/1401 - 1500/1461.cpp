// 1461. Check If a String Contains All Binary Codes of Size K

// Solution 1: Using deque and sliding window to get all substrings of length k and check if they are unique and cover all possible binary codes of size k.
// Time Complexity: O(n * k) where n is the length of the string and k is the size of binary codes.
// Space Complexity: O(2^k) for storing all possible binary codes of size k.
class Solution {
public:
    int convertBinToDec(deque<char>& dq){
        int res = 0;
        for(auto& ch : dq){
            res = (res << 1) | (ch == '1');
        }
        return res;
    }
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n-k+1 < pow(2, k)) return false;
        deque<char> dq(s.begin(), s.begin()+k);
        unordered_set<int> st;
        st.insert(convertBinToDec(dq));
        for(int i = k; i < n;i++){
            dq.pop_front();
            dq.push_back(s[i]);
            st.insert(convertBinToDec(dq));
        }   
        return st.size() == pow(2, k);
    }
};

// Solution 2: Using bit manipulation to generate all possible binary codes of size k and check if they are present in the string.
// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(2^k) for storing all possible binary codes of size k.
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int totalRequired = 1 << k;
        if (n < totalRequired + k - 1) return false;
        vector<bool> seen(totalRequired, false);
        int currentHash = 0;
        int mask = (1 << k) - 1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            currentHash = ((currentHash << 1) & mask) | (s[i] - '0');
            if (i >= k - 1) {
                if (!seen[currentHash]) {
                    seen[currentHash] = true;
                    count++;
                    if (count == totalRequired) return true;
                }
            }
        }
        return count == totalRequired;
    }
};