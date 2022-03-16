// 2164. Sort Even and Odd Indices Independently
// naive solution
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for(int i = 0; i < nums.size();i++){
            if(i % 2 == 0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int j = 0, k = odd.size()-1;
        for(int i = 0; i < nums.size();i++){
            if(i % 2 == 0){
                nums[i] = even[j];
                j++;
            }
            else{
                nums[i] = odd[k];
                k--;
            }
        }
        return nums;
    }
};

