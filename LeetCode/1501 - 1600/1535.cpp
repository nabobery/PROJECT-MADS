// 1535. Find the Winner of an Array Game

// Solution 1 using Simulation using Deque
// Time Complexity = O(n) 
//Space Complexity = O(n)
// if k >= n then the winner will be the maximum element in the array because it will be the winner of all the rounds at arr[0]
// else we will use a deque to simulate the game
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), curr_win = arr[0], win_count = 0;
        if(k >= n) return *max_element(arr.begin(), arr.end());
        deque<int> dq; 
        for(int i = 1; i < n;i++) dq.push_back(arr[i]);
        while(win_count != k){
            int c = dq.front();
            if(c > curr_win){
                dq.push_back(curr_win);
                dq.pop_front();
                curr_win = c;
                win_count = 1;
            }
            else{
                win_count++;
                dq.pop_front();
                dq.push_back(c);
            }
        }
        return curr_win;
    }
};

// Solution 2 using Simulation using Queue
// Time Complexity = O(n)
// Space Complexity = O(n)
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElem = arr[0], curr_win = arr[0], win_count = 0;
        queue<int> q;
        for(int i = 1; i < arr.size(); i++){
            maxElem = max(maxElem, arr[i]);
            q.push(arr[i]);
        }
        if(k >= arr.size()) return maxElem;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            if(c > curr_win){
                q.push(curr_win);
                curr_win = c;
                win_count = 1;
            }
            else{
                q.push(c);
                win_count++;
            }
            if(win_count == k || curr_win == maxElem) break;
        }
        return curr_win;
    }
};
    
// Solution 3 using Simulation without using Queue
// Time Complexity = O(n)
// Space Complexity = O(1)
// When an element comes after maxElem, it doesn't matter if it is pushed to the back of the queue or not because it will never be the winner.
// When an element comes before maxElem, it doesn't matter if it is pushed to the back of the queue or not because it will never be the winner.
// So, We don't need to use a queue to simulate the game. 
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElem = arr[0], curr_win = arr[0], win_count = 0;
        if(k >= arr.size()) return *max_element(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++){
            maxElem = max(maxElem, arr[i]);
            if(arr[i] > curr_win){
                curr_win = arr[i];
                win_count = 1;
            }
            else win_count++;
            if(win_count == k) break;
        }
        return curr_win;
    }
};