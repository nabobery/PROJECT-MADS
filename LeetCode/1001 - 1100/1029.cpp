// 1029. Two City Scheduling
/* naive O(nlogn) time and O(n) space solution
 we first calculate the cost to travel to City A and calculate the difference when we travel to city B instead of A . We get the differences
 and sort them. now, we choose the least differences greedily(first n persons) as it implies that traveling to city B is better than
 travelling to city A (cost wise) for that person and for other persons travelling to city A is better. This will then give us the
 minimum cost.*/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n =  costs.size();
        int result = 0;
        vector<int> diff;
        for(vector<int> v : costs){
            result += v[0];
            diff.push_back(v[1] - v[0]);
        }
        sort(diff.begin(),diff.end());
        for(int i = 0; i < n/2;i++){
            result += diff[i];
        }
        return result;
    }
};


// O(nlogn) time and O(1) space solution (optimised without using space)
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return(a[1] < b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n =  costs.size();
        int result = 0;
        for(vector<int>& v : costs){
            result += v[0];
            v[1] -= v[0];
        }
        sort(costs.begin(),costs.end(),comp);
        for(int i = 0; i < n/2;i++){
            result += costs[i][1];
        }
        return result;
    }
};