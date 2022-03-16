// 347. Top K Frequent Elements
// my naive O(nlogn) time and O(n) space solution
class Solution {
public:
    static bool cmp(pair<int, int>& a,pair<int, int>& b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> result;
        for(int num : nums){
            mp[num]++;
        }
        vector<pair<int,int>> temp;
        for(pair<int,int> p : mp){
            temp.push_back(p);
        }
        sort(temp.begin(),temp.end(),cmp);
        for(auto itr : temp){
            if(k > 0) result.push_back(itr.first);
            else break;
            k--;
        }
        return result;
    }
};

