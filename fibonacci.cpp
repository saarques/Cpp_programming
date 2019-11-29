#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fibonacci(int a, int b, int counter){
	if (counter){
		cout<<a+b<< "\n";
		fibonacci(b, a+b, counter-1);
	}
}

int main(){
	int a, b, c;
	cout<<"Enter the first number of the sequence: ";
	cin>>a;
	cout<<"Enter the second number of the sequence: ";
	cin>>b;
	cout<<"Enter the number of times you want to print the sequence: ";
	cin>>c;
	cout<<a<<"\n"<<b<<"\n";
	fibonacci(a, b, c-2);
	return 0;
}