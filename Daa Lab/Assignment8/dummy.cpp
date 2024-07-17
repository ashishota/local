#include<bits/stdc++.h>

using namespace std;

bool checkArmstrong(int n){
	//Write your code here
	int count_digit=0;
	int q=n;
	while(q>0){
		count_digit++;
		q=q/10;
	}
	int num=0;
	int rem=0;
	q=n;
	while(q>0){
		rem=q%10;
		cout<<rem<<" ";
		cout<<pow(rem,count_digit)<<" ";
		num+=pow(rem,count_digit);
		cout<<num<<" "<<endl;
		q/=10;
	}
	return num==n;
}
int main(){
	if(checkArmstrong(153)==1)
	cout<<"true";
	else
	cout<<"false";
}