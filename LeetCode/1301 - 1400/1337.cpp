// 1337. The K Weakest Rows in a Matrix
// my naive solution using vector of pairs and custom sort function
// O(m) space and O(nlogn) time solution
class Solution {
public:
    static bool comp(const pair<int,int> &a, const pair<int,int> &b){
        if (a.second < b.second) return true;
        else if(a.second == b.second) return(a.first < b.first);
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair <int,int>> rows;
        int m = mat.size();
        for(int i = 0; i < m;i++){
            int count = 0;
            for(int n : mat[i]){
                if(n) count++;
            }
            rows.push_back(make_pair(i,count));
        }
        sort(rows.begin(),rows.end(),comp);
        vector<int> result;
        for(int i = 0; i < k;i++){
            result.push_back(rows[i].first);
        }
        return result;
    }
};

// using simple sort and appending index of row to the matrix
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        for(int i=0; i < mat.size(); i++){
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> result(k);
        for(int i=0; i < k; i++){
            result[i] = mat[i][n];
        }
        return result;
    }
};

// using max heap(priority queue) and binary search(As soldiers are ahead of civilians => descending order)
// O(m(logn+logk)) time and O(2*k) (For pair of heap) space solution
class Solution {
public:
    // get the number of soldiers in each row by getting the starting zero position
    int binarySearch(vector<int> m){
        int l = 0;
        int h = m.size()-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // use a max_heap with count of soldiers and index as pair
        priority_queue<pair<int,int> > pq;
        vector<int> result;
        for(int i = 0; i < mat.size(); i++){
            // add current row to max heap
            int count = binarySearch(mat[i]);
            pq.push(make_pair(count,i));
            // if heap siz > k pop
            if(pq.size() > k)
                pq.pop();
        }
        // push the heap elements to the result
        for(int i = 0; i<k; ++i)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        // as it's descending order, we need to reverse it to get the ascending order
        reverse(result.begin(),result.end());
        return result;
    }
};
