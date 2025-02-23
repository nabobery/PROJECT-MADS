// 1718. Construct the Lexicographically Largest Valid Sequence


// Solution 1: Bruteforce
// Time Complexity: O(n*n!)
// Space Complexity: O(n)
class Solution {
    public:
        vector<int> res;
        bool check_if_valid(vector<int>& vec){
            unordered_set<int> seen;
            for(int i = 0; i < vec.size();i++){
                if(vec[i] == 1){
                    seen.insert(vec[i]);
                    continue;
                }
                else{
                    if(!seen.count(vec[i])){
                        if(i+vec[i] >= vec.size() || vec[i + vec[i]] != vec[i]) return false;
                        seen.insert(vec[i]);
                    }
                }
            }
            return true;
        }
        void helper(int ind, vector<int>& count, vector<int>& curr, int& n){
            if(ind == 2*n -1){
                if(check_if_valid(curr)){
                    if(!res.empty()){
                        res = max(res, curr);
                    }
                    res = curr;
                }
                return;
            }
            for(int i = 0; i < n;i++){
                if((i == 0 && count[i] == 1) || (i !=0 && count[i] == 2)) continue;
                count[i]++;
                curr.push_back(i+1);
                helper(ind+1, count, curr, n);
                count[i]--;
                curr.pop_back();
            }
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> count(n, 0);
            vector<int> curr;
            helper(0, count, curr, n);
            return res;
        }
};

// Solution 2: Optimized Backtracking with Pruning
// Time Complexity: O(n!)
// Space Complexity: O(n)
class Solution {
    public:
        bool helper(vector<int>& seq, vector<bool>& used, int pos, int n) {
            // Base case if we have filled all the positions in the sequence then return true
            if (pos == seq.size())
                return true;
            // if the position is already filled then move to the next position
            if (seq[pos] != 0)
                return helper(seq, used, pos + 1, n);
            // Try to fill the position with the largest number possible so that we can get the lexicographically largest sequence
            for (int num = n; num >= 1; num--) {
                // If the number is already used then skip it
                if (used[num])
                    continue;
                // if number is 1, it occurs only once
                if (num == 1) { 
                    seq[pos] = 1;
                    used[1] = true;
                    // check if we can fill the next position by filling the current position as 1
                    if (helper(seq, used, pos + 1, n))
                        return true;
                    // backtrack
                    seq[pos] = 0;
                    used[1] = false;
                } else {

                    int pos2 = pos + num;
                    // if we can't fill the position with the number at the current position then return false because its out of bounds
                    if (pos2 >= seq.size() || seq[pos2] != 0)
                        continue;
                    // fill the current position and the position at pos2 with the number
                    seq[pos] = num;
                    seq[pos2] = num;
                    used[num] = true;
                    // check if we can fill the next position by filling the current position and pos2 with the number
                    if (helper(seq, used, pos + 1, n))
                        return true;
                    // backtrack
                    seq[pos] = 0;
                    seq[pos2] = 0;
                    used[num] = false;
                }
            }
            return false;
        }
        
        vector<int> constructDistancedSequence(int n) {
            int len = 2 * n - 1;
            vector<int> seq(len, 0);
            vector<bool> used(n + 1, false);
            helper(seq, used, 0, n);
            return seq;
        }
    };