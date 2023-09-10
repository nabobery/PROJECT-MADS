// 138. Copy List with Random Pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// My naive solution using Hash map and Recursion
class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        if (mp.find(head) == mp.end())
        {
            mp[head] = new Node(head->val);
            mp[head]->next = copyRandomList(head->next);
            mp[head]->random = copyRandomList(head->random);
        }
        return mp[head];
    }
};

// my naive optimised solution without recursion
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        unordered_map<Node *, Node *> mp;
        Node *ptr = head;
        while (ptr)
        {
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr)
        {
            mp[ptr]->next = mp[ptr->next];
            mp[ptr]->random = mp[ptr->random];
            ptr = ptr->next;
        }
        return mp[head];
    }
};

// 3 pass O(N) solution and O(1) solution
class Solution
{
public:
    // 1) We create new nodes and place them alternatively in the linked list
    // Example A->B->C->D ==> A->A'->B->B'->C->C'->D->D'
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        Node *ptr = head;
        while (ptr)
        {
            Node *temp = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = temp;
            ptr = temp;
        }
        ptr = head;
        // 2) Now we assign the random nodes of the orignal node to new node's random node
        while (ptr)
        {
            if (ptr->random)
                // new-> random = old->random->next which is old random's new node
                ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        // a dummy node
        Node *dummy = new Node(0);
        ptr = dummy;
        // 3) we link the new nodes using dummy head and restore the old linked list
        while (head)
        {
            ptr->next = head->next;
            ptr = ptr->next;
            head->next = head->next->next;
            head = head->next;
        }
        return dummy->next;
    }
};

// 1 pass O(N) solution and O(N) space solution
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        unordered_map<Node *, Node *> mp;
        Node *res = new Node(head->val);
        mp[head] = res;
        Node *ptr = res, *temp = head;
        while (temp->next)
        {
            if (mp.find(temp->next) != mp.end())
            {
                ptr->next = mp[temp->next];
            }
            else
            {
                mp[temp->next] = new Node(temp->next->val);
                ptr->next = mp[temp->next];
            }
            if (temp->random != NULL)
            {
                if (mp.find(temp->random) != mp.end())
                {
                    ptr->random = mp[temp->random];
                }
                else
                {
                    mp[temp->random] = new Node(temp->random->val);
                    ptr->random = mp[temp->random];
                }
            }
            ptr = ptr->next;
            temp = temp->next;
        }
        ptr->random = mp[temp->random];
        return mp[head];
    }
};
