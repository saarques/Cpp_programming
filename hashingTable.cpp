#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
#include <fstream>

using namespace std;

template <typename T, typename U>

class Hash{
private:
	int array_length;
	list <pair<T, U>>*main_column;
public:

	// Constructor
	Hash(){
		cout<<"Bingo!"<<endl;
	}
	Hash(int length){
		array_length = length;
		main_column = new list<pair<T, U>>[array_length];
	}

	int computeHash(T key);
	void addRecord(T key, U object);
	void replaceRecord(T key, U object);
	bool hasKey(T key);
	void display();
	void getRecord(T key);
	int retAL(){
		return array_length;
	}
	list<pair<T, U>>* retcol(){
		return main_column;
	}
};

template <typename T, typename U>

class HTWrapper{
public:
	void saveToFile(string filename, Hash<T, U> htobj);
	void loadFromFile(string filename);
};


template <typename T, typename U>
void HTWrapper<T, U>::saveToFile(string filename, Hash<T, U> mahobj){
	// write in file
	ofstream fileobj;
	int array_length = mahobj.retAL();
	list<pair<T, U>>*main_column;
	main_column = mahobj.retcol();

	fileobj.open(filename.c_str());
	for(int i=0; i<array_length; i++){
		typename list<pair<T, U>>::const_iterator it;
		for(it = main_column[i].begin(); it!=main_column[i].end(); it++){
			T key = (*it).first;
			U value = (*it).second;

			fileobj<<key<<" "<<value<<endl;
		}
	}
	fileobj.close();
}

template <typename T, typename U>
void HTWrapper<T, U>::loadFromFile(string filename){
	ifstream fileobj(filename.c_str());
	Hash<T, U> obj;
	T a;
	U b;

	while(fileobj>>a>>b){
		obj.addRecord(a, b);
	}
	cout<<"Hash Table from the given file is:-"<<endl;
	obj.display();
	fileobj.close();
}


template <typename T, typename U>
int Hash<T, U>:: computeHash(T key){
	if(typeid(key).name()==typeid(string).name()){
		int sum = 0;
		for(int i = 0; i<key.length(); i++)
			sum = sum + int(key[i]);
		return sum % array_length;
	}
	else
		cout<<"Not a legit entry! :(";
}

template <typename T, typename U>
bool Hash<T, U>:: hasKey(T key){
	int index = computeHash(key);
	typename list<pair<T, U>>::const_iterator it;
	int count = 0;
	for(it = main_column[index].begin(); it!=main_column[index].end(); ++it){
		if((*it).first == key){
			count = 1;
			return true;
		}
		if(!count)
			return false;
	}
}

template <typename T, typename U>
void Hash<T, U>::addRecord(T key, U object){
	int index = computeHash(key);
	bool exist = hasKey(key);
	if(exist)
		cout<<"Duplicates not allowed!";
	else{
		main_column[index].push_back(make_pair(key, object));
		cout<<"key->"<<key<<" is added."<<endl;
	}
}

template <typename T, typename U>
void Hash<T, U>::display(){
	for(int i =0; i < array_length; i++){
		cout<<i;
		typename list<pair<T, U>>::const_iterator it;
		for(it = main_column[i].begin(); it!=main_column[i].end(); ++it){
			cout<<"->"<<(*it).second;
		}
		cout<<endl;
	}
}
int main(){
	Hash <string, string>boom(5);
	HTWrapper<string, string>save;
	boom.addRecord("sim", "data");
	boom.addRecord("ping", "pong");
	boom.addRecord("doom", "day");
	boom.display();

	save.saveToFile("myfile.txt", boom);
	save.loadFromFile("myfile.txt");
	return 0;
}