// 2125. Number of Laser Beams in a Bank

// Solution 1 - two pass with count of beams
// Time complexity: O(NM)
// Space complexity: O(M)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        int cnt[m];
        for(int i = 0; i < m;i++){
            int ones = 0;
            for(char ch : bank[i])
                if(ch == '1') ones++;
            cnt[i] = ones;
        }
        int prev = -1, res = 0;
        for(int i = 0; i < m;i++){
            if(cnt[i] > 0){
                if(prev != -1) res += prev*cnt[i];
                prev = cnt[i];
            }
        }
        return res;
    }
};

// Solution 2 - one pass with count of beams
// Time complexity: O(NM)
// Space complexity: O(1)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        int prev = -1, res = 0;
        for(int i = 0; i < m;i++){
            int ones = 0;
            for(char ch : bank[i])
                if(ch == '1') ones++;
            if(ones > 0){
                if(prev != -1) res += prev*ones;
                prev = ones;
            }
        }
        return res;
    }
};