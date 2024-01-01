// 443. String Compression

// Solution 1 Simple Solution
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 1, n = chars.size();
        for(int i = 1; i < n;i++){
            int j = i;
            while(j < n && chars[j] == chars[j-1]){
                j++;
            }
            if(j-i != 0){
                for(char ch : to_string(j-i+1)) chars[res++] = ch;
                if(j < n) chars[res++] = chars[j];
            }
            else chars[res++] = chars[j];
            i = j;
        }
        for(int i = res; i < n;i++) chars.pop_back();
        return res;
    }
};