// 786. K-th Smallest Prime Fraction

// Solution 1 Brute force by checking a;; fractions and printing the kth largest
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        map<double, pair<int,int>> mp;
        for(int i = 0; i < n-1;i++){
            for(int j =i+1; j < n;j++){
                mp[(double)arr[i] / arr[j]] = {i,j};
            }
        }
        auto it = mp.begin();
        for(int i = 0; i < k-1;i++, it++);
        vector<int> res = {arr[it->second.first], arr[it->second.second]};
        return res;
    }
};

// Solution 2 Binary search
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, r = 1;
        // Binary search for the fraction between l and r
        while(l < r){
            // find mid
            double m = (l+r)/2;
            int cnt = 0;
            double max_f = 0;
            pair<int,int> max_p;
            // count the number of fractions less than m and find the maximum fraction less than m
            // and as it's sorted, the maximum fraction will be the last fraction that is less than m and will be the kth smallest fraction we want
            for(int i = 0, j = 1; i < n-1; i++){
                while(j < n && arr[i] > m * arr[j]) j++;
                cnt += n-j;
                if(j < n && max_f < (double)arr[i] / arr[j]){
                    max_f = (double)arr[i] / arr[j];
                    max_p = {i,j};
                }
            }
            // change bounds based on the count adn return the fraction if the count is equal to k
            if(cnt == k) return {arr[max_p.first], arr[max_p.second]};
            else if(cnt < k) l = m;
            else r = m;
        }
        return {};
    }
};


// Solution 3 using priority queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>> pq;
        for(int i = 0; i < n-1;i++){
            pq.push({(double)arr[i] / arr[n-1], {i,n-1}});
        }
        while(--k){
            auto p = pq.top();
            pq.pop();
            int i = p.second.first, j = p.second.second;
            if(j > i+1) pq.push({(double)arr[i] / arr[j-1], {i,j-1}});
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};