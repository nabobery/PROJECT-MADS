#include <iostream>
using namespace std;

int main() {
	int t;
	int dragon[3];
	int sloth[3];
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> dragon[0] >> dragon[1] >> dragon[2];
	    cin >> sloth[0] >> sloth[1] >> sloth[2];
	    int sum1 = dragon[0] + dragon[1] + dragon[2];
	    int sum2 = sloth[0] + sloth[1] + sloth[2];
	    if(sum1 > sum2){
	        cout<<"DRAGON\n";
	    }
	    else if(sum2 > sum1){
	        cout<<"SLOTH\n";
	    }
	    else{
	        if(dragon[0] > sloth[0]){
	            cout<<"DRAGON\n";
	        }
	        else if(sloth[0] > dragon[0]){
	            cout<<"SLOTH\n";
	        }
	        else{
	            if(dragon[1] > sloth[1]){
    	            cout<<"DRAGON\n";
    	        }
    	        else if(sloth[1] > dragon[1]){
    	            cout<<"SLOTH\n";
    	        }
    	        else{
    	            cout<<"TIE\n";
    	        }
	        }
	    }
	}
	return 0;
}
