// 941. Valid Mountain Array
// my naive solution
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        int peak = 0;
        for(int i = 1; i < arr.size();i++){
            if(arr[peak] < arr[i]){
                peak = i;
            }
        }
        if(peak == 0 || peak == arr.size()-1)
            return false;
        for(int i = 0; i < peak;i++){
            if(arr[i] >=  arr[i+1])
                return false;
        }
        for(int i = peak; i < arr.size()-1;i++){
            if(arr[i] <= arr[i+1])
                return false;
        }
        return true;
    }
};

// one pass solution
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return false;
        int i = 0;
        while(i+1 < n && arr[i] < arr[i+1])
            i++;
        if(i == 0 || i == n-1)
            return false;
        while(i+1 < n && arr[i] > arr[i+1])
            i++;
        return i == n-1;

    }
};
