// 1361. Validate Binary Tree Nodes

// Solution 1 (BFS)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> indegree(n, 0), outdegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
            {
                indegree[leftChild[i]]++;
                outdegree[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (rightChild[i] != -1)
            {
                indegree[rightChild[i]]++;
                outdegree[i]++;
            }
        }
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0 && outdegree[i] <= 2)
            {
                p = i;
                break;
            }
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(p);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (vis[curr])
                return false;
            vis[curr] = true;
            if (leftChild[curr] != -1)
            {
                if (vis[leftChild[curr]])
                    return false;
                q.push(leftChild[curr]);
            }
            if (rightChild[curr] != -1)
            {
                if (vis[rightChild[curr]])
                    return false;
                q.push(rightChild[curr]);
            }
        }
        for (auto i : vis)
        {
            if (!i)
                return false;
        }
        return true;
    }
};

// Solution 2 (DFS)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
    bool dfs(int curr, vector<int> &leftChild, vector<int> &rightChild, vector<bool> &vis)
    {
        if (vis[curr])
            return false;
        vis[curr] = true;
        if (leftChild[curr] != -1)
        {
            if (!dfs(leftChild[curr], leftChild, rightChild, vis))
                return false;
        }
        if (rightChild[curr] != -1)
        {
            if (!dfs(rightChild[curr], leftChild, rightChild, vis))
                return false;
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> indegree(n, 0), outdegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
            {
                indegree[leftChild[i]]++;
                outdegree[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (rightChild[i] != -1)
            {
                indegree[rightChild[i]]++;
                outdegree[i]++;
            }
        }
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0 && outdegree[i] <= 2)
            {
                p = i;
                break;
            }
        }
        vector<bool> vis(n, false);
        if (!dfs(p, leftChild, rightChild, vis))
            return false;
        for (auto i : vis)
        {
            if (!i)
                return false;
        }
        return true;
    }
};

// Another Version of Solution 2
class Solution
{
public:
    int findRoot(int n, vector<int> &left, vector<int> &right)
    {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());

        for (int i = 0; i < n; i++)
        {
            if (children.find(i) == children.end())
            {
                return i;
            }
        }

        return -1;
    }

    bool dfs(int curr, vector<int> &leftChild, vector<int> &rightChild, vector<bool> &vis)
    {
        if (vis[curr])
            return false;
        vis[curr] = true;
        if (leftChild[curr] != -1)
        {
            if (!dfs(leftChild[curr], leftChild, rightChild, vis))
                return false;
        }
        if (rightChild[curr] != -1)
        {
            if (!dfs(rightChild[curr], leftChild, rightChild, vis))
                return false;
        }
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        int p = findRoot(n, leftChild, rightChild);
        if (p == -1)
            return false;
        vector<bool> visited(n, false);
        if (!dfs(p, leftChild, rightChild, visited))
            return false;
        for (auto i : visited)
            if (!i)
                return false;
        return true;
    }
};

// Solution 3 (Union Find)
// Time complexity: O(n)
// Space complexity: O(n)
class UnionFind
{
public:
    int components;
    int n;
    vector<int> parents;

    UnionFind(int n)
    {
        this->n = n;
        parents = vector(n, 0);
        components = n;

        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
    }

    bool join(int parent, int child)
    {
        int parentParent = find(parent);
        int childParent = find(child);

        if (childParent != child || parentParent == childParent)
        {
            return false;
        }

        components--;
        parents[childParent] = parentParent;
        return true;
    }

    int find(int node)
    {
        if (parents[node] != node)
        {
            parents[node] = find(parents[node]);
        }

        return parents[node];
    }
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        UnionFind uf(n);
        for (int node = 0; node < n; node++)
        {
            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children)
            {
                if (child == -1)
                {
                    continue;
                }

                if (!uf.join(node, child))
                {
                    return false;
                }
            }
        }

        return uf.components == 1;
    }
};