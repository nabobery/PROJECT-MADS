// 1700. Number of Students Unable to Eat Lunch

// Solution 1 Simulation using queue
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeroes = 0, ones = 0, res = students.size();
        queue<int> q;
        for(int s : students){
            if(s == 1) ones++;
            else zeroes++;
            q.push(s);
        }
        for(int s : sandwiches){
            while(q.front() != s){
                if((s == 1 && ones==0) || (s == 0 && zeroes == 0)) return res;
                q.push(q.front());
                q.pop();
            }
            q.pop();
            if(s) ones--;
            else zeroes--;
            res--;
        }
        return res;
    }
};

// Solution 2 Simulation without queue
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeroes = 0, ones = 0;
        for(int s : students){
            if(s == 1) ones++;
            else zeroes++;
        }
        for(int s : sandwiches){
            if(s){
                if(ones == 0) return zeroes;
                ones--;
            }
            else{
                if(zeroes == 0) return ones;
                zeroes--;
            }
        }
        return 0;
    }
};
