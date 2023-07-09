// 42. Trapping Rain Water

// O(N) time and O(N) space solution using pre-computed left and right max arrays
// At every index i, the water trapped can be calculated using by the tallest bar to the left and the tallest bar to the right
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        vector<int> left(n), right(n);
        // left[i] = max(height[0], height[1], ..., height[i])
        left[0] = height[0];
        for(int i = 1; i < n;i++){
            left[i] = max(left[i-1], height[i]);
        }
        // right[i] = max(height[i], height[i+1], ..., height[n-1])
        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0;i--){
            right[i] = max(right[i+1], height[i]);
        }
        // the water trapped at index i is min(left[i],right[i]) - height[i]
        for(int i = 0; i < n;i++){
            result += (min(left[i],right[i]) - height[i]);
        }
        return result;
    }
};

// O(N) time and O(N) space solution using a stack
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        stack<int> stk;
        for(int i = 0; i < n;i++){
            // if the current bar is taller than the top of the stack, then we can pop the top of the stack
            while(!stk.empty() && height[i] > height[stk.top()] ){
                int temp = stk.top();
                stk.pop();
                // if the stack is empty, then there is no left bar to the top of the stack so we can't trap any water
                // if the stack is not empty, then the water trapped is bounded by the current bar and the top of the stack
                if(!stk.empty()) result += (i - stk.top()-1)*(min(height[i], height[stk.top()]) - height[temp]);
            }
            // push the current bar to the stack
            stk.push(i);
        }
        return result;
    }
};

// O(N) time and O(1) space solution using two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        int left = 0, right = n-1, leftMax = 0, rightMax = 0;
        while(left < right){
            // if the left bar is shorter than the right bar, then the water trapped is bounded by the left bar
            if(height[left] < height[right]){
                // if the left bar is taller than the left max, then the left max is updated
                if(height[left] > leftMax) leftMax = height[left];
                // if the left bar is shorter than the left max, then the water trapped is bounded by the left max
                else result += (leftMax - height[left]);
                left++;
            }
            // if the right bar is shorter than the left bar, then the water trapped is bounded by the right bar
            else{
                // if the right bar is taller than the right max, then the right max is updated
                if(height[right] > rightMax) rightMax = height[right];
                // if the right bar is shorter than the right max, then the water trapped is bounded by the right max
                else result += (rightMax - height[right]);
                right--;
            }
        }
        return result;
    }
};