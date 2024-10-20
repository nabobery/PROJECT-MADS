// 670. Maximum Swap

// Solution 1: Using priority queue
// Time complexity: O(n^2) where n is the number of digits in the number
// Space complexity: O(n)
class Solution {
public:
    int maximumSwap(int num) {
        priority_queue<string> pq;
        string number = to_string(num);
        pq.push(number);
        for(int i = 0; i < number.size()-1;i++){
            for(int j = i+1; j < number.size();j++){
                swap(number[i], number[j]);
                pq.push(number);
                swap(number[i], number[j]);
            }
        }
        return stoi(pq.top());
    }
};

