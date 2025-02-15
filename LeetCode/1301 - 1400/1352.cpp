// 1352. Product of the Last K Numbers

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

// Solution 1 using prefix product
// Time complexity: O(1) for add and O(100) for getProduct
// Space complexity: O(100*n) where n is the number of add operations
class ProductOfNumbers {
    public:
        vector<unordered_map<int,int>> res;
        ProductOfNumbers() {
    
        }
        
        void add(int num) {
            unordered_map<int,int> curr;
            if(!res.empty()) curr = res.back();
            curr[num]++;
            res.push_back(curr);
        }
        
        int getProduct(int k) {
            int s = res.size();
            unordered_map<int,int> prev, curr = res[s-1];
            if(s-k-1 >= 0) prev = res[s-k-1]; 
            if(curr[0] - prev[0] > 0) return 0;
            int res = 1;
            for(auto& it: curr){
                res *= pow(it.first, it.second-prev[it.first]);
            }
            return res;
        }
};

// Solution 2 using prefix product (using vector) and clear prefix when 0 is added
// Time complexity: O(1) for add and O(100) for getProduct
// Space complexity: O(100*n) where n is the number of add operations
class ProductOfNumbers {
    public:
        vector<int> res;
        ProductOfNumbers() {
            res.push_back(1);
        }
        
        void add(int num) {
            if(num == 0){
                res.clear();
                res.push_back(1);
            }else{
                res.push_back(res.back()*num);
            }
        }
        
        int getProduct(int k) {
            int s = res.size();
            if(s <= k) return 0;
            return res[s-1]/res[s-k-1];
        }
};
