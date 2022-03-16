#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n;i++){
	    cin >> arr[i];
	}
	long long int result = 0;
	sort(arr, arr + n);
	for(int i = 0; i < n;i++){
	    long long int temp = (long long int)arr[i]*(n - i);
	    result = max(result, temp);
	}
	cout<<result<<"\n";
	return 0;
}
