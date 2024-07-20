// 1598. Crawler Log Folder

// Simple and Straightforward Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(string log: logs){
            if(log == "../") count--;
            else if(log != "./") count++;
            if(count < 0) count = 0;
        }
        return count;
    }
};