#include<bits/stdc++.h>
using namespace std;

void kadanes_algo(int arr[],int n){
	int sum = 0;
	int maxi = INT_MIN;
	for(int i=0; i<n; i++){
		sum += arr[i];
		maxi = max(sum,maxi);
		if(sum<0) sum =0;
	}
	
	cout<<maxi;
	
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	kadanes_algo(arr,n);
}
