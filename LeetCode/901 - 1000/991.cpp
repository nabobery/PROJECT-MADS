// 991. Broken Calculator
// my naive O(logn) time and O(1) space solution
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int result = 0;
        // if x > y return the number of decrements(difference between x and y)
        if(startValue > target) return startValue - target;
        // if both are equal return 0
        else if(startValue == target) return result;
        // else when y > x
        else{
            // while x != y, going backwards from target to startValue
            while(target != startValue){
                // if y > x and y is even divide by 2
                if(target > startValue && target % 2 == 0){
                    target /= 2;
                }
                // else increment y if it's odd or less than x
                else{
                    target++;
                }
                result++;
            }
        }
        return result;
    }
};

// recursive approach
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // base case
        if(startValue >= target) return startValue - target;
        // if odd
        if(target & 1)
            return 1 +  brokenCalc(startValue,target + 1);
        // if even
        return 1 +  brokenCalc(startValue, target/2);
    }
};
