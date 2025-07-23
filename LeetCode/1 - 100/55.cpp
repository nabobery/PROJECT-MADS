// 55. Jump Game

// greedy O(n) time solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0, n = nums.size();
        for(int i = 0; i < n-1;i++){
            if(nums[i] == 0 && far == i) return false; 
            far = max(far, i + nums[i]);
        }
        return (far >= n-1);
    }
};

// O(n) greedy solution where we go backwards and see if the current index can reach the last index
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJumps = 0, n = nums.size();
        for(int i = n-2; i >= 0;i--){
            minJumps++;
            if(nums[i] >= minJumps) minJumps = 0;
        }
        return (minJumps == 0);
    }
};
