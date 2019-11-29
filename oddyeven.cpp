#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter number: ";
	cin>>n;
	if ((n & 1)==0)
		cout<<"Even number";
	else
		cout<<"Odd number";
	return 0;
}