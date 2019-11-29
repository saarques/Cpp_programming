#include <iostream>
using namespace std;

int fact(int num){
	if (num==1)
		return 1;
	else
		return num*fact(num-1);
}

int main(){
	int a, result;
	cout<<"Enter the number you want the factorial of: ";
	cin>>a;
	result = fact(a);
	cout<<"Factorial of "<<a<<" is: "<<result;
	return 0;
}