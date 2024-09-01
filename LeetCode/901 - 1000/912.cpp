// 912. Sort an Array

// Solution 1: Merge Sort
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
    
    void mergeSort(vector<int>& nums, vector<int>& temp, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, temp, l, mid);
        mergeSort(nums, temp, mid + 1, r);
        merge(nums, temp, l, mid, r);
    }
    
    void merge(vector<int>& nums, vector<int>& temp, int l, int mid, int r){
        int i = l, j = mid + 1, k = l;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= r) temp[k++] = nums[j++];
        for(int i = l;i <= r;i++) nums[i] = temp[i];
    }
};

// Solution 2: Heap Sort
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
    
    void heapSort(vector<int>& nums){
        int n = nums.size();
        for(int i = n / 2 - 1;i >= 0;i--) heapify(nums, n, i);
        for(int i = n - 1;i > 0;i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    
    void heapify(vector<int>& nums, int n, int i){
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if(l < n && nums[l] > nums[largest]) largest = l;
        if(r < n && nums[r] > nums[largest]) largest = r;
        if(largest != i){
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
};