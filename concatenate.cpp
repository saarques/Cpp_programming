#include <bits/stdc++.h>
using namespace std;

int main(){
	char array[] = "Hello", varray[] = "World";
	int count1 = 0, count2 = 0, i = 0;
	while(array[i]!='\0'){
		count1++;
		i++;
	}
	i = 0;
	while(varray[i]!='\0'){
		count2++;
		i++;
	}
	cout<<count1<<" "<<count2<<"\n"<<array<<"\n"<<varray<<endl;
	int a = count1+count2;
	char bingo[a+1];
	for(i = 0; i < a; i++){
		if(i<count1)
			bingo[i] = array[i];
		else
			bingo[i] = varray[i-count1];
	}
	bingo[a]='\0';
	// for(int i=0;i<a;i++){
	// 	cout<<bingo[i]<<" ";
	// }
	cout<<bingo<<endl;
	return 0;
}
