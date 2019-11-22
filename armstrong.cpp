#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
	int temp, n, count = 0, sum = 0;
	n = atoi(argv[1]);
	temp = n;
	while(temp){
		temp /= 10;
		count += 1;
	}
	temp = n;
	while(temp){
		sum += pow((temp%10), count);
		temp /= 10;
	}
	if(sum == n)
		cout<<"Armstrong Number!";
	else
		cout<<"Not a Armstrong Number.";
	return 0;
}