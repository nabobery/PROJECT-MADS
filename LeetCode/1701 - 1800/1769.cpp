// 1769. Minimum Number of Operations to Move All Balls to Each Box

// Solution 1: Using Prefix Sum (left and right)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), curr = 0;
        vector<int> left(n, 0), right(n, 0), res(n, 0);
        curr = (boxes[0] == '1');
        for(int i = 1; i < n;i++){
            left[i] = curr + left[i-1];
            curr += (boxes[i] == '1');
        }
        curr = (boxes[n-1] == '1');
        for(int i = n-2; i >= 0;i--){
            right[i] = curr + right[i+1];
            curr += (boxes[i] == '1');
        }
        for(int i = 0; i < n;i++){
            res[i] = left[i] + right[i];
        }
        return res;
    }
};