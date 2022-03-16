// Introductory Problems : Gray Code
#include "iostream"
using namespace std;

void printGray(int arr[], int n){
    cout<<arr[0];
    for(int i = 1;i < n;i++){
        int temp = arr[i] ^ arr[i-1];
        cout<<temp;
    }
    cout<<"\n";
}

void generateBinary(int n, int arr[], int i){
    if(i == n){
        printGray(arr,n);
        return;
    }
    arr[i] = 0;
    generateBinary(n,arr,i+1);
    arr[i] = 1;
    generateBinary(n,arr,i+1);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    generateBinary(n,arr,0);
    return 0;
}

