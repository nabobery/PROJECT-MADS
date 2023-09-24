// 135. Candy

// Solution1 Greedy and two pass 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), result = 0;
        vector<int> res(n, 1);
        // left to right
        for(int i = 1; i < n;i++){
            // if current rating is greater than left neighbor, then give one more candy
          if(ratings[i] > ratings[i-1]){
                res[i]= res[i-1]+1;
          }  
        }
        // right to left
        for(int i = n-2; i >= 0;i--){
            // if current rating is greater than previous one, then get the max of current and right neighor+1
          if(ratings[i] > ratings[i+1]){
                res[i]= max(res[i], res[i+1]+1);
          }  
        }
        for(auto r : res) result += r;
        return result;
    }
};          

// Solution2 Greedy and one pass
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        // low is the number of continuous decreasing ratings
        // high is the number of continuous increasing ratings
        // max is the maximum number of candies required till now for a child
        // result is the total number of candies
        int result = 1,low = 0,high = 0,max = 0;
        for(int i = 1; i < ratings.size();i++){
            // if current rating is greater than left neighbour, then increase high and reset low
            // and update max and result
            if(ratings[i-1] < ratings[i]){
                high += 1;
                low = 0;
                max = high+1;
                result += max;
            }
            // if current rating is equal to left neighbour, then reset low and high
            // and update result
            else if(ratings[i-1] == ratings[i]){
                low = high = max = 0;
                result++;
            }
            // if current rating is less than left neighbour, then increase low and reset high
            // and update max and result
            else{
                high = 0;
                low += 1;
                result += 1 + low - (max > low);
            }
        }
        return result;
    }
};   