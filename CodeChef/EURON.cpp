#include <iostream>
#include <vector>

using namespace std;

long long mergeSortCount(vector<int> &vec) {
    int n = vec.size();
    if (n < 2) {
        return 0;
    }
    int mid = n / 2;
    vector<int> leftCopy(vec.begin(), vec.begin() + mid);
    vector<int> rightCopy(vec.begin() + mid, vec.end());
    long long leftAns = mergeSortCount(leftCopy);
    long long rightAns = mergeSortCount(rightCopy);
    int leftArrPointer = 0;
    int rightArrPointer = 0;
    int actualPointer = 0;
    long long currTotal = 0;
    while (leftArrPointer < leftCopy.size() && rightArrPointer < rightCopy.size()) {
        if (leftCopy[leftArrPointer] <= rightCopy[rightArrPointer]) {
            vec[actualPointer] = leftCopy[leftArrPointer];
            currTotal += rightArrPointer;
            leftArrPointer++;
        } else {
            vec[actualPointer] = rightCopy[rightArrPointer];
            rightArrPointer++;
        }
        actualPointer++;
    }
    while (leftArrPointer < leftCopy.size()) {
        vec[actualPointer++] = leftCopy[leftArrPointer++];
        currTotal += rightArrPointer;
    }
    while (rightArrPointer < rightCopy.size()) {
        vec[actualPointer++] = rightCopy[rightArrPointer++];
    }
    return leftAns + rightAns + currTotal;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    cout << mergeSortCount(vec) << "\n";
    return 0;
}
