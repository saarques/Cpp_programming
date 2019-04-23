#include <iostream>
using namespace std;

class addTwo{
private:
	int a;
public:
	addTwo(): a(0){}
	void readValue(){
		cin>>a;
	}
	addTwo operator +(addTwo o){
		addTwo temp;
		temp.a = a+o.a;
		return temp;
	}
	void display(){
		cout<<a;
	}
};

int main(){
	addTwo o1, o2, o3;
	o1.readValue();
	o2.readValue();
	o3=o1+o2;
	//o3.add();
	o3.display();
}