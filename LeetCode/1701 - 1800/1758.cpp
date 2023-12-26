// 1758. Minimum Changes To Make Alternating Binary String

// Solution 1 getting the minimum of both the final string possibilities
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minOperations(string s) {
        int res0 = 0, res1 = 0;
        for(int i = 0; i < s.size();i++){
            if(i%2){
                if(s[i] == '0') res0++;
                else res1++;
            }
            else{
                if(s[i] == '1') res0++;
                else res1++; 
            }
        }
        return min(res0, res1);
    }
};