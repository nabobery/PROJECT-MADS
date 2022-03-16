// 1675. Minimize Deviation in Array
/*
1)For any given configuration of nums the deviation is equal to (maxx - minn)
2)To decrease the deviation either increase the minn or decrease the maxx.
3)Now, Make every number as maximum as possible to eliminate one operation(increase the minn)
4) since every element is as maximum as possible , you can not increase any number further
5)Now we are left with just one operation decrease the maxx
So perform this operation as many times as u can and keep track of the min_deviation
 */
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int maxx = INT_MIN, minn = INT_MAX;
        priority_queue<int> pq;
        for(int num : nums){
            if(num%2) num = num*= 2;
            pq.push(num);
            maxx = max(maxx,num);
            minn = min(minn,num);
        }
        int min_deviation = maxx - minn;
        while(pq.top() % 2 == 0){
            int top = pq.top();
            min_deviation = min(min_deviation, top - minn);
            pq.pop();
            top /= 2;
            minn = min(top,minn);
            pq.push(top); // pushing again the top as we have to minimize the max
        }
        min_deviation = min(min_deviation, pq.top() - minn);
        return min_deviation;
    }
};
