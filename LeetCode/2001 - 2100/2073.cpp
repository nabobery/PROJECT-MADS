// 2073. Time Needed to Buy Tickets


// Solution 1 using the fact that all the people before kth position will buy tickets equal to minimum of tickets[k] and tickets[i] and all the people after kth position will buy tickets equal to minimum of tickets[k]-1 and tickets[i]
// Time complexity: O(n)
// Space complexity: O(1) 
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        for(int i = 0; i < tickets.size();i++){
            if(i <= k) res += min(tickets[k], tickets[i]);
            else{
                if(tickets[i] >= tickets[k]) res += tickets[k]-1;
                else res += tickets[i];
            }
        }
        return res;
    }
};