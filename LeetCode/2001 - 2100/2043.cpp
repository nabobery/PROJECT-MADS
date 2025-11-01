// 2043. Simple Bank System

// Solution 1: Simple and StraightForward Implementation
// Time Complexity: O(1) for each operation
// Space Complexity: O(n)
class Bank {
public:
    vector<long long> accountToBalance;
    int n;
    Bank(vector<long long>& balance) {
        accountToBalance = balance;
        n = balance.size();
    }

    bool isValid(int account) { return (account >= 1 && account <= n); }

    bool hasMoney(int account, long long money) {
        return (accountToBalance[account - 1] >= money);
    }

    void credit(int account, long long money) {
        accountToBalance[account - 1] += money;
    }

    void debit(int account, long long money) {
        accountToBalance[account - 1] -= money;
    }

    bool transfer(int account1, int account2, long long money) {

        if (isValid(account1) && isValid(account2) &&
            hasMoney(account1, money)) {
            credit(account2, money);
            debit(account1, money);
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (isValid(account)) {
            credit(account, money);
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (isValid(account) && hasMoney(account, money)) {
            debit(account, money);
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */