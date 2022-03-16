// 849. Maximize Distance to Closest Person
// my naive solution using group by zero approach O(n) time and O(1) space (most efficient)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int dist = 0;
        int result = 0;
        int n = seats.size();
        for(int i = 0; i < n;i++){
            if(seats[i] == 1){
                dist = 0;
            }
            else{
                dist++;
                result = max(result, (dist+1)/2);
            }
        }
        for(int i = 0; i < n;i++){
            if(seats[i] == 1){
                result = max(result,i);
                break;
            }
        }
        for(int i = n-1; i >=0;i--){
            if(seats[i] == 1){
                result = max(result,n-1-i);
                break;
            }
        }
        return result;
    }
};

// using two pointer approach O(n) time and O(1) space
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int result = 0;
        int n = seats.size();
        int prev = -1, curr = 0;
        for(int i = 0; i < n;i++){
            if(seats[i] == 1){
                prev = i;
            }
            else{
                while(curr < n && seats[curr] == 0 || curr < i)
                    curr++;
                int left = prev == -1 ? n : i - prev;
                int right = curr == n ? n : curr - i;
                result = max(result,min(left,right));
            }
        }
        return result;
    }
};

// using arrays to keep track of left and right O(n) time and space
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int result = 0;
        int n = seats.size();
        vector<int> left(n,n);
        vector<int> right(n,n);
        for(int i = 0; i < n;i++){
            if(seats[i] == 1){
                left[i] = 0;
            }
            else if (i > 0)
                left[i] = left[i-1] + 1;
        }
        for(int i = n-1; i >= 0;i--){
            if(seats[i] == 1){
                right[i] = 0;
            }
            else if (i  < n-1)
                right[i] = right[i+1] + 1;
        }
        for(int i = 0; i < n;i++){
            if(seats[i] == 0)
                result = max(result, min(left[i],right[i]));
        }
        return result;
    }
};
