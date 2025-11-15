// 3234. Count the Number of Substrings With Dominant 

// Solution 1: Intelligent Sliding Window
// Time Complexity: O(N*sqrt(N))
// Space Complexity: O(N)
// The idea is to use a sliding window approach to count valid substrings.
// we know that for a substring to be valid, it must follow the condition:
// number of '1's >= number of '0's^2 and we know that n0 + n1 = length of substring
// thus we can derive that length of substring >= n0^2 + n0 which means the maximum number of '0's in a valid substring is bounded by sqrt(N)
// thus for each fixed left pointer, we can find the right pointer such that the length condition is satisfied
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, n = s.size(), ind = 0, zeroes;
        // pre compute zero indices
        vector<int> zeroIndices;
        for(int i = 0; i < n;i++){
            if(s[i] == '0') zeroIndices.push_back(i);
        }
        zeroes = zeroIndices.size();
        // fix left pointer and find appropriate right pointer
        for(int l = 0; l < n;l++){
            // move ind to point to the first zero index >= l
            if(ind < zeroes && l > zeroIndices[ind]) ind++;
            // case 1: no zeroes in substring (k = 0)
            int r = (ind < zeroes) ? zeroIndices[ind] - 1 : n-1;
            res += (r-l+1);
            // case 2: k >= 1 zeroes in substring
            for(int k = 1; k*k <= n;k++){
                // if there are not enough zeroes left, break
                if(ind + k -1 >= zeroes) break;
                // find the valid range for right pointer
                // rStart is the index of the k-th zero from ind
                // rEnd is the index before the (k+1)-th zero from ind or
                int rStart = zeroIndices[ind+k-1], rEnd =  (ind+k < zeroes) ? zeroIndices[ind+k] - 1 : n-1;
                // [l,r] is valid if r - l + 1 >= k*k + k  => r >= l + k*k + k -1
                int validRStart = max(rStart, l + k*k + k -1);
                // add the number of valid substrings for this k
                if(validRStart <= rEnd) res += (rEnd - validRStart + 1);
            }
        }
        return res;
    }
};