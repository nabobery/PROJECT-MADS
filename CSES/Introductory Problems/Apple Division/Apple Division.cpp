// Introductory Problems : Apple Division
#include "iostream"
#include "cstdlib"
#include "algorithm"
using namespace std;

// using recursion,we go through all sets and consider two possibilities for each element to include or not to include then find min difference
long long int findMin(int arr[], int n, long long int sum, long long int total){
    if(n == 0)
        return abs((total - sum) - sum);
    return min(findMin(arr,n-1,sum,total), findMin(arr,n-1,sum+arr[n-1],total));
}
// Note : we can use dp too

int main(){
    int n;
    cin >> n;
    int arr[n];
    long long int sum = 0;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    cout<<findMin(arr,n,0,sum);
    return 0;
}

/* wrong naive greedy solution
    long long int sum = 0;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    long long int req = sum/2;
    sort(arr,arr+n);
    long long int sum1 = 0;
    for(int i = n - 1; i >=0; i--){
        if(req - arr[i] >= 0){
            sum1 += arr[i];
            req -= arr[i];
        }
    }
    long long int result = sum - 2*(sum1);
    cout<<result<<"\n";
    */


