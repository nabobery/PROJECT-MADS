// 605. Can Place Flowers
// O(n) time and O(1) space
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, result = 0;
        while(i < flowerbed.size()){
            if(flowerbed[i] == 0 &&(i== 0 || flowerbed[i - 1] == 0) &&(i== flowerbed.size() - 1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                result++;
            }
            i++;
        }
        return (result >= n);
    }
};

// optimised O(n) time and O(1) space
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, result = 0;
        while(i < flowerbed.size()){
            if(flowerbed[i] == 0 &&(i== 0 || flowerbed[i - 1] == 0) &&(i== flowerbed.size() - 1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                result++;
            }
            if(result >= n){
                return true;
            }
            i++;
        }
        return false;
    }
};
