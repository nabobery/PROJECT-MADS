// 875. Koko Eating Bananas
//Brute force sol Time : O(k*n) where n is number of piles and k is result
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int result = 1;

        while(true){
            int hours = 0;
            for(int pile : piles){
                hours += (pile/result) + (pile % result != 0);
                if(hours > h){
                    break;
                }
            }
            if(hours <= h){
                return result;
            }
            else{
                result += 1;
            }
        }
    }
};

// using Binary search Time : O(nlogk)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(),piles.end());
        while(left < right){
            int hours = 0;
            int mid = (left + right)/2;
            for(int pile : piles){
                hours += (pile/mid) + (pile % mid != 0);
                /*if(hours > h){
                    break;
                }*/
            }
            if(hours <= h){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};

