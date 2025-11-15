// 3542. Minimum Operations to Convert All Elements to Zero

// Solution 1: Greedy Approach using Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // 'res' will store the total count of minimum operations.
        int res = 0;
        
        // 'stk' is a monotonic increasing stack.
        // It stores the "levels" of operations we've started.
        // For example, if we have [1, 3, 5], it means we've started an
        // operation for 1, then a nested operation for 3, then a
        // nested operation for 5.
        stack<int> stk;

        for(int i = 0; i < n; i++){
            
            // Case 1: The number is 0.
            if(nums[i] == 0) {
                // A 0 acts as a "hard reset" or a boundary.
                // No operation can cross a 0.
                // Therefore, any operations we were tracking (on the stack)
                // must be finished. The numbers that come after this 0
                // belong to a completely new, independent problem.
                // We clear the stack to signify this reset.
                while(!stk.empty()) {
                    stk.pop();
                }
            } 
            // Case 2: The number is positive.
            else {
                // Subcase 2a: The stack is empty.
                if(stk.empty()){
                    // If the stack is empty, it means we are at the beginning
                    // of a new, independent block (either the start of the
                    // array or just after a 0).
                    // This positive number MUST be cleared by a new operation.
                    res++; // Count this new operation.
                    stk.push(nums[i]); // Push it onto the stack as the "base" level.
                }
                // Subcase 2b: The stack is not empty.
                else {
                    // Subcase 2b-i: The current number is larger than the stack's top.
                    if(nums[i] > stk.top()){
                        // The operation for stk.top() CANNOT clear nums[i].
                        // nums[i] will be part of a new, *nested* subproblem
                        // that starts after stk.top() is cleared.
                        // This requires a new, distinct operation.
                        res++; // Count this new operation.
                        stk.push(nums[i]); // Add this new level to the stack.
                    }
                    // Subcase 2b-ii: The current number is smaller than the stack's top.
                    else if(nums[i] < stk.top()){
                        // This number `nums[i]` is a new minimum for a wider
                        // subarray. It "separates" or "breaks" the chain of
                        // nested operations for all values larger than it.
                        // We must pop all levels that are now "invalidated"
                        // because they are larger than this new minimum.
                        while(!stk.empty() && nums[i] < stk.top()) {
                            stk.pop();
                        }
                        
                        // After popping, we need to check if this `nums[i]`
                        // itself requires a new operation.
                        if(stk.empty() || nums[i] != stk.top()){
                            // We need a new operation if:
                            // 1. `stk.empty()`: We popped everything, so `nums[i]`
                            //    is the new base of a new block. (e.g., [3, 1] -> see 1, pop 3, stack empty, add op for 1)
                            // 2. `nums[i] != stk.top()`: `nums[i]` is not a duplicate
                            //    of the new top. (e.g., [1, 3, 2] -> see 2, pop 3, top is 1. 2 != 1, so add op for 2)
                            res++;
                            stk.push(nums[i]);
                        }
                        // If `nums[i] == stk.top()` (after popping),
                        // it means this number can be cleared by an *existing*
                        // operation level we've already counted. (e.g., [1, 3, 1] -> see 1, pop 3, top is 1. 1 == 1, do nothing.)
                    }
                    // Subcase 2b-iii: `nums[i] == stk.top()`
                    // This number can be cleared by the *same* operation
                    // that clears stk.top(). It does not require a new
                    // operation, so we do nothing.
                }
            }
        }
        
        // The final result is the total number of new operations we had to start.
        return res;
    }
};