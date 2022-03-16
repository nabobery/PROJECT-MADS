// 228. Summary Ranges
// my naive solution using stack O(n) time and O(n) space
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        if(n == 0) return result;
        else if(n == 1){
            result.push_back(to_string(nums[0]));
            return result;
        }
        stack<int> stk;
        stk.push(nums[0]);
        for(int i = 1; i < n;i++){
            if(stk.top() + 1 == nums[i]){
                stk.push(nums[i]);
            }
            else{
                string end = to_string(stk.top());
                while(stk.size() != 1){
                    stk.pop();
                }
                string start = to_string(stk.top());
                stk.pop();
                if(start == end) result.push_back(start);
                else{
                    start += "->";
                    start += end;
                    result.push_back(start);
                }
                stk.push(nums[i]);
            }
        }
        if(stk.empty()) return result;
        else{
            string end = to_string(stk.top());
            while(stk.size() != 1){
                stk.pop();
            }
            string start = to_string(stk.top());
            stk.pop();
            if(start == end) result.push_back(start);
            else{
                start += "->";
                start += end;
                result.push_back(start);
            }
        }
        return result;
    }
};

// O(1) space solution by looking if the forward element is 1 greater than the previous element
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()) return result;
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i + 1 == nums.size() || nums[i] + 1 != nums[i+1]){
                string temp = to_string(nums[s]);
                if(i != s) temp += "->" + to_string(nums[i]);
                result.push_back(temp);
                s = i + 1;
            }
        }
        return result;
    }
};

