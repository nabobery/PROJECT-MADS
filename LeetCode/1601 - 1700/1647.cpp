// 1647. Minimum Deletions to Make Character Frequencies Unique

// Solution 1 by maintaing a visited set
// Time complexity: O(n) As 26log26 = O(1)
// Space complexity: O(n)
class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26,0);
        for(auto ch : s) count[ch - 'a']++;
        sort(count.begin(), count.end(), greater<int>());
        unordered_set<int> st;
        st.insert(count[0]);
        int res = 0;
        for(int i = 1; i < 26;i++){
            while(st.count(count[i]) && count[i] > 0){
                res++;
                count[i]--;
            }
            st.insert(count[i]);
        }
        return res;
    }
};

// Solution 2 without using visited set
// Time complexity: O(n)
// Space complexity: O(n) 
class Solution {
public:
    int minDeletions(string s) {
        // count is used to store the frequency of each character
        vector<int> count(26,0);
        // count the frequency of each character
        for(auto ch : s) count[ch - 'a']++;
        // sort the count vector 
        sort(count.begin(), count.end());
        // res is used to store the minimum number of deletions
        int res = 0;
        // iterate over the count vector from the end
        for(int i = 24; i >= 0;i--){
            // if the current count is 0 then break
            if(count[i] == 0) break;
            // if the current count is greater than or equal to the next count
            if(count[i] >= count[i+1]){
                // then we need to delete the extra characters
                int temp = count[i];
                // we can delete the extra characters by making the current count equal to the next count - 1
                count[i] = max(0, count[i+1] - 1);
                // add the number of deletions to the result
                res += temp - count[i];
            }
        }
        return res;
    }
};

// Solution 3 with priority queue
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> count;
        for(auto ch : s) count[ch]++;
        priority_queue<int> pq;
        for(auto c : count) pq.push(c.second);
        int res = 0;
        while(pq.size() > 1){
            int temp = pq.top();
            pq.pop();
            if(temp == pq.top() && temp != 0){
                pq.push(temp - 1);
                res++;
            }
        }
        return res;
    }
};
