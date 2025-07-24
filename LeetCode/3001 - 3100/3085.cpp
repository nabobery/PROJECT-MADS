// 3085. Minimum Deletions to Make String K-Special

// Solution 1: Greedy using Sorting and Sliding Window (WA)
// Time Complexity O(n + 26log26) = O(n)
// Space Complexity O(26) = O(1)
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char& ch : word) freq[ch - 'a']++;
        int res = 0, l = 0, r;
        sort(freq.begin(), freq.end());
        for(l = 0; l < 26;l++)
            if(freq[l]) break;   
        for(int r = l+1; r < 26;r++){
            int diff = freq[r] - freq[l];
            if(diff > k){
                // remove left or decrease right
                if(freq[l] >= (diff - k)){
                    freq[r] -= (diff - k);
                    res += (diff - k);
                }
                else{
                    while(diff > k){
                        res += freq[l];
                        l++;
                        diff = freq[r] - freq[l];
                        if(diff > k && freq[l] >= (diff - k)){
                            freq[r] -= (diff - k);
                            res += (diff - k);
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Solution 2: Greedy using Counting (AC)
// Time Complexity O(n + 26) = O(n)
// Space Complexity O(26) = O(1)
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char& ch : word) freq[ch - 'a']++;
        int res = word.size(), curr = 0;
        // select x as the minimum frequency and calculate the number of deletions needed 
        for(auto x: freq){
            if(!x) continue;
            curr = 0;
            for(auto y : freq){
                if(y){
                    // if y is less than x, we have to delete y characters because they are less than x
                    if(y < x) curr += y;
                    // if y is greater than x + k, we have to delete (y - x - k) characters so that y - x <= k (and the least we can delete is y -x -k)
                    else if(y > x + k) curr += (y-x-k);
                }
            }
            res = min(res, curr);
        }
        return res;
    }
};