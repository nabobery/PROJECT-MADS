// 1823. Find the Winner of the Circular Game
// recursive O(n) time and O(n) space solution
/*
This problem can also be solved using Recursion.
If you observe, you can see that we are doing the same activity again and again i.e. deleting every kth element we encounter.
Therefore, we can think towards the recursive approach also.
Intuition : If I have the winner for 'n-1' and 'k'. I can find the winner for 'n' and 'k' by moving on to the next kth person (i.e. f(n) = f(n-1)+k).
Keeping in mind that they are sitting on a round table we have to rotate also (i.e. f(n) = (f(n-1)+k)%n).
 */
class Solution {
public:
    int helper(int n, int k){
        if(n==1) return 0;
        return (helper(n-1,k) +k)%n;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k) +1;  //+1 is for converting 0-based indexing to 1-based indexing
    }
};

// iterative O(n) time and O(1) space solution
class Solution {
public:
    int helper(int n, int k){
        int result = 0; // if there's only one person then he's the winner
        for(int i = 1; i <= n;i++){ // we go from one to n persons and store the winner but it's 0 indexed
            result = (result+k)%i;
        }
        return result;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1; // so convert to 1 indexed here
    }
};
