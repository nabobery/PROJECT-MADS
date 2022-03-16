// 973. K Closest Points to Origin
// My Naive sol
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> result;
        vector<vector<int>> tmp;
        for(int i = 0; i < n; i++){
            int temp = pow(points[i][0], 2) + pow(points[i][1], 2);
            tmp.push_back({temp, i});
        }
        sort(tmp.begin(),tmp.end());
        for(int i = 0; i < tmp.size() && k > 0; i++){
            result.push_back(points[tmp[i][1]]);
            k--;
        }
        return result;  
    }
};

// Using custom sort(great space wise  but bad time wise) 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),[&](vector<int>& a, vector<int>& b) {
            int d1 = pow(a[0], 2) + pow(a[1], 2);
            int d2 = pow(b[0], 2) + pow(b[1], 2);
            return d1 < d2;
        });  
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

// Using Modified Binary Search (good time wise but avg space wise)
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Precompute the Euclidean distance for each point,
        // define the initial binary search range,
        // and create a reference list of point indices
        vector<double> distances;
        vector<int> remaining;
        double low = 0, high = 0;
        for (int i = 0; i < points.size(); i++) {
            distances.push_back(euclideanDistance(points[i]));
            high = max(high, distances[i]);
            remaining.push_back(i);
        }
                
        // Perform a binary search of the distances
        // to find the k closest points
        vector<int> closest;
        while (k) {
            double mid = low + (high - low) / 2;
            vector<vector<int>> result = splitDistances(remaining, distances, mid);
            vector<int>& closer = result[0]
            vector<int>& farther = result[1];
            if (closer.size() > k) {
                // If more than k points are in the closer distances
                // then discard the farther points and continue
                remaining.swap(closer);
                high = mid;
            } else {
                // Add the closer points to the answer array and keep
                // searching the farther distances for the remaining points
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                low = mid;
            }
        }
        
        // Return the k closest points using the reference indices
        vector<vector<int>> answer;
        for (int index : closest) {
            answer.push_back(points[index]);
        }
        return answer;
    }
    
private:
    vector<vector<int>> splitDistances(vector<int>& remaining, vector<double>& distances,
                                       double mid) {
        // Split the distances around the midpoint
        // and return them in separate vectors
        vector<vector<int>> result(2);
        vector<int> &closer = result[0], &farther = result[1];
        for (int index : remaining) {
            if (distances[index] <= mid) {
                closer.push_back(index);
            } else {
                farther.push_back(index);
            }
        }
        return result;
    } 
    
    double euclideanDistance(vector<int>& point) {
        // Calculate and return the Euclidean distance
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
};