// 502. IPO

// Solution 1 using Sorting and Priority Queue

// Time Comlexity: O(NlogN)
// Space Complexity: O(N)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), res = w, p = 0;
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n;i++) vec[i] = {capital[i], profits[i]};
        sort(vec.begin(), vec.end());
        priority_queue<int> pq;
        while(p < n && k > 0){
            while(p < n && res >= vec[p].first){
                pq.push(vec[p].second);
                p++;
            }
            if(pq.empty()) break;
            res += pq.top();
            pq.pop();
            k--;
        }
        while(k > 0 && !pq.empty()){
            res += pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};

// Cleaner Solution 1
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), res = w, p = 0;
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n;i++) vec[i] = {capital[i], profits[i]};
        sort(vec.begin(), vec.end());
        priority_queue<int> pq;
        while(k > 0){
            while(p < n && res >= vec[p].first){
                pq.push(vec[p].second);
                p++;
            }
            if(pq.empty()) break;
            res += pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};


// Solution 2 using Sorting and Multiset (Not Efficient as Priority Queue)
// Time Comlexity: O(NlogN)
// Space Complexity: O(N)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), res = w, p = 0;
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n;i++) vec[i] = {capital[i], profits[i]};
        sort(vec.begin(), vec.end());
        multiset<int> ms;
        while(p < n && k > 0){
            while(p < n && res >= vec[p].first){
                ms.insert(vec[p].second);
                p++;
            }
            if(ms.empty()) break;
            res += *ms.rbegin();
            ms.erase(ms.find(*ms.rbegin()));
            k--;
        }
        while(k > 0 && !ms.empty()){
            res += *ms.rbegin();
            ms.erase(ms.find(*ms.rbegin()));
            k--;
        }
        return res;
    }
};