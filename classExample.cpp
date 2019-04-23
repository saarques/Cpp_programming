#include <iostream>
using namespace std;

class Drop{
	private:
	     int data1, data2;
    public:
    	Drop(): data1(4), data2(3){cout<<"Nada es Impossible\n";}
        int values(){
            cout<<data1<<'\n';
            return data2;
        }
};

int main(){
	Drop a1;
	int a2;
	cout<<"Hello Boss\n";
    a2=a1.values();
    cout<<a2;
    return 0;
}