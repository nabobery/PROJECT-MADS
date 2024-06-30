// 1482. Minimum Number of Days to Make m Bouquets

// Solution 1 using Binary Search
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    int numberOfBouqets(vector<int>& bloomDay, int day, int m){
        int res = 0,cur = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cur++;
                if(cur == m){
                    res++;
                    cur = 0;
                }
            }
            else cur = 0;
        }
        return res;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n/k) return -1;
        int l = 0, r = 1e9 + 1;
        while(l <= r){
            int mid = (l+r)/2;
            int bouqets = numberOfBouqets(bloomDay,mid,k);
            if(bouqets >= m) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
        
// Cleaner Solution 1 without using a separate function and setting r as max day
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n/k) return -1;
        int l = 0, r = *max_element(bloomDay.begin(),bloomDay.end());
        while(l < r){
            int mid = (l+r)/2;
            int bouqets = 0, cur = 0;
            for(int i = 0; i < n; i++){
                if(bloomDay[i] <= mid){
                    cur++;
                    if(cur == k){
                        bouqets++;
                        cur = 0;
                    }
                }
                else cur = 0;
            }
            if(bouqets >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

