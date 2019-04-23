#include <iostream>
#include <string.h>

using namespace std;

class student{
	private:
		int age, year;
		string name, stream;
	public:
		void getName();
		void getAge();
		void getStream();
		void getYear();
		void displayDetails();
		void getDetails();
};

void student :: getDetails(){
	getAge();
	getName();
	getYear();
	getStream();
}
void student :: getName(){
	cout<<"Enter your name: ";
	// getline(cin, name);
	cin>>name;
}

void student :: getAge(){
	cout<<"Enter your Age: ";
	cin>>age;
}

void student :: getStream(){
	cout<<"Enter your Stream: ";
	// getline(cin, stream);
	cin>>stream;
}

void student :: getYear(){
	cout<<"Enter your current study year: ";
	cin>>year;
}

void student :: displayDetails(){
	cout<<"StudentName    StudentAge    StudentStream    StudentYear"<<endl;
	cout<<name<<'    '<<age<<'    '<<stream<<'    '<<year<<endl;
}

int main(){
	student Tarun, Adarsh, Rohan;
	Tarun.getDetails();
	Adarsh.getDetails();
	Rohan.getDetails();

	Tarun.displayDetails();
	Adarsh.displayDetails();
	Rohan.displayDetails();
}