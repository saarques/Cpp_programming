#include <iostream>
#include <list>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
	string a = "bad";
	// if(typeid(a).name()==typeid(string).name())
		// cout<<"True";
	// else
		// cout<<"False";
	int sum = 0;
	for(int i=0; i< a.length(); i++){
		sum = sum + int(a[i]);
		cout<<sum<<endl;
	}
}
// int main(){
//     int i, *p_arr[11], a[5];
//     for (int i = 0; i < 11; i++){
//     	*p_arr[i]=a[5];
//     }
//     for(i=0; i<11;i++){
//     	printf("%d", *p_arr[i]);
//     }
// }
