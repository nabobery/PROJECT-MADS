#include <iostream>
using namespace std;

int arr[100000];

void print(int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void xored(int n, int x){
    int temp_xor = 0;
    for(int i = 0; i < n - 1;i++){
        temp_xor ^= i;
    }
    temp_xor ^= x;
    if(temp_xor < (n - 1)){
        arr[n-1] = 131072 + temp_xor;
        if(temp_xor == 0){
            arr[1] += 131072;
            print(n);
            arr[1] = 1;
        }
        else{
            arr[0] += 131072;
            print(n);
            arr[0] = 0;
        }
        arr[n-1] = n-1;
    }
    else if(temp_xor > 500000){
        arr[0] = temp_xor & 393216;
        arr[n-1] = temp_xor - arr[0];
        print(n);
        arr[0] = 0;
        arr[n-1] = n-1;
    }
    else{
        arr[n-1] = temp_xor;
        print(n);
        arr[n-1] = n-1;
    }
}


int main() {
	int t,n,x;
	cin >> t;
	for(int i = 0; i < 100000;i++){
	    arr[i] = i;
	}
	for(int i = 0; i < t;i++){
	    cin >> n >> x;
	    xored(n,x);
	}
	return 0;
}
