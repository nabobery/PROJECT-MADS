// 2709. Greatest Common Divisor Traversal

// Solution 1 by making a graph using prime factors and check if graph is connected using DFS
// Time Complexity: O(n * sqrt(m))
// Space Complexity: O(n + m)

class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size(), mx = -1;
        if (n == 1)
            return true;
        unordered_set<int> s;
        for (int num : nums)
        {
            // if num is 1, then there can be pairs that don't have gcd > 1 so return false
            if (num == 1)
                return false;
            s.insert(num);
        }
        // finding max and removing duplicates from nums
        vector<int> vec;
        for (int num : s)
        {
            mx = max(mx, num);
            vec.push_back(num);
        }
        // find all primes till mx
        vector<bool> prime(mx + 1, true);
        vector<int> primes;
        for (int i = 2; i * i <= mx; i++)
        {
            if (prime[i])
                for (int j = i * i; j <= mx; j += i)
                    prime[j] = false;
        }
        for (int i = 2; i <= mx; i++)
            if (prime[i])
                primes.push_back(i);
        // sort vec and make a map of prime factors of each number
        sort(vec.begin(), vec.end());
        unordered_map<int, vector<int>> mp;
        for (int num : vec)
            for (int pr : primes)
                if (num % pr == 0)
                    mp[pr].push_back(num);
        // make a graph using prime factors and check if graph is connected using DFS
        unordered_set<int> visited;
        unordered_map<int, vector<int>> graph;
        for (auto i : mp)
        {
            for (int j = 1; j < i.second.size(); j++)
            {
                graph[i.second[0]].push_back(i.second[j]);
                graph[i.second[j]].push_back(i.second[0]);
            }
        }
        function<void(int)> dfs = [&](int u)
        {
            visited.insert(u);
            for (int v : graph[u])
                if (!visited.count(v))
                    dfs(v);
        };
        dfs(vec[0]);
        for (int i : vec)
            if (!visited.count(i))
                return false;
        return true;
    }
};

// Solution 2 by making a mapping between prime factors and numbers and numbers to prime factors and check if graph is connected using DFS
// Time Complexity: O(n * sqrt(m))
// Space Complexity: O(n + m)

class Solution
{
public:
    unordered_map<int, vector<int>> primes, indices;
    void dfs(int i, vector<bool> &visited, unordered_map<int, bool> &visitedprimes)
    {
        if (visited[i])
            return;
        visited[i] = true;
        for (int p : indices[i]){
            if (visitedprimes[p]) continue;
            visitedprimes[p] = true;
            for (int j : primes[p]){
                if(visited[j]) continue;
                dfs(j, visited, visitedprimes);
            }
        }
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return true;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = 2; j * j <= num; j++){
                if(num % j == 0){
                    primes[j].push_back(i);
                    indices[i].push_back(j);
                    while(num % j == 0) num /= j;
                }
            }
            if(num > 1){
                primes[num].push_back(i);
                indices[i].push_back(num);
            }
        }
        vector<bool> visited(n, false);
        unordered_map<int, bool> visitedprimes;
        dfs(0, visited, visitedprimes);
        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
           

// Solution 3 using Union Find
// Time Complexity: O(n * sqrt(m))
// Space Complexity: O(n + m)

class Solution
{
public:
    vector<int> parent, componentsizes;
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void join(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px != py){
            if(componentsizes[px] < componentsizes[py]) swap(px, py);
            parent[py] = px;
            componentsizes[px] += componentsizes[py];
        }
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        parent.resize(n);
        componentsizes.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        unordered_map<int, int> visited;
        for (int i = 0; i < n; i++){
            int num = nums[i];
            if(num == 1) return false;
            vector<int> primes;
            for (int j = 2; j * j <= num; j++){
                if (num % j == 0) primes.push_back(j);
                while (num % j == 0) num /= j;
            }
            if (num > 1) primes.push_back(num);
            for(int p : primes){
                if(visited.count(p)){
                    join(i, visited[p]);
                } else 
                    visited[p] = i;
            }
        }
        return componentsizes[find(0)] == n;
    }
};

// TODO: Optimise using Sieve of Eratosthenes