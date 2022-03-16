// 134. Gas Station
// my naive TLE solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n;i++){
            if(gas[i] < cost[i]){
                continue;
            }
            else{
                int start = i;
                int tank = 0;
                for(int j = start;j < start + n;j++){
                    tank += gas[j%n];
                    tank -= cost[j%n];
                    if(tank < 0){
                        break;
                    }
                }
                if(tank >= 0){
                    return start;
                }
            }
        }
        return -1;
    }
};

// greedy solution
/* Approach :
(i) If car starts at A and can not reach B. Any station between A and B can not reach B.(B is the first station that A can not reach.)
(ii)If the total number of gas is bigger than the total number of cost. (there must be a solution)
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, total = 0, n = gas.size();
        for(int i = 0; i < n;i++){
            if((tank = tank + gas[i] - cost[i])<0){
                start = i +1;
                total += tank;
                tank = 0;
            }
        }
        return (total + tank < 0) ? -1 : start;

    }
};

// another greedy
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i, j, n = gas.size();
        /*
         * If start from i, stop before station x -> no station k from i + 1 to x - 1 can reach x.
         * Bcoz if so, i can reach k and k can reach x, then i reaches x. Contradiction.
         * Thus i can jump directly to x instead of i + 1, bringing complexity from O(n^2) to O(n).
         */
        // start from station i
        for (i = 0; i < n; i += j) {
            int gas_left = 0;
            // forward j stations
            for (j = 1; j <= n; j++) {
                int k = (i + j - 1) % n;
                gas_left += gas[k] - cost[k];
                if (gas_left < 0)
                    break;
            }
            if (j > n)
                return i;
        }

        return -1;
    }
};


