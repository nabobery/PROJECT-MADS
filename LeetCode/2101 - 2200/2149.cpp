// 2149. Rearrange Array Elements by Sign
// naive solution using 2 vectors
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> result;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size();i++){
            if(i % 2 == 0){
                result.push_back(pos[i/2]);
            }
            else{
                result.push_back(neg[i/2]);
            }
        }
        return result;
    }
};

// using 2 pointers
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int pos = 0;
        int neg = 1;
        for(auto curr : nums){
            if(curr > 0){
                result[pos] = curr;
                pos += 2;
            }
            else{
                result[neg] = curr;
                neg += 2;
            }
        }
        return result;
    }
};

