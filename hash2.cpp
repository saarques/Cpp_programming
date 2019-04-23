// hashing for string and others
#include <iostream>
#include <list>
#include <typeinfo>
#include <string>
#include <fstream>

using namespace std;

template<typename T, typename U>
class Hash{
	private:
		int array_length;
		list<pair<T, U> >* main_column;
    public:
    	
	// constructor

	Hash(int length=10)
	{
		array_length = length;
		//create an array
		main_column = new list<pair<T,U> >[array_length];
		// values will be insert in rows(list)	
	}
	int computeHash(T key);
	void addRecord(T key, U object);
	bool hasKey(T key);
	void display();
	void getRecord(T key);
	void replaceRecord(T key, U object);
	int retAL(){
		return array_length;
	}
	list<pair<T, U> >* retcol(){
		return main_column;
	}
		
};


template<typename T, typename U>

class HTWrapper{
	public:
		
		void saveToFile(string filename, Hash<T,U> hcobj);
		void loadFromFile(string filename);
};


template<typename T, typename U>

void HTWrapper<T,U>::saveToFile(string filename, Hash<T,U> hcobj)
{   
	 
	// write to file.
	ofstream fileobj;
	int array_length = hcobj.retAL();
	list<pair<T, U> >*main_column;
	main_column= hcobj.retcol();
	 
	
	fileobj.open(filename.c_str());
	for(int i=0; i<array_length; i++)
	{
		
		typename list<pair<T,U> >::const_iterator it;
		for(it=main_column[i].begin(); it!=main_column[i].end(); ++it)
		{   T key = (*it).first;
			U value = (*it).second;
			
			fileobj<<key<<" "<<value<<endl;
		}
	}	
  	fileobj.close();	
}

template<typename T, typename U>

void HTWrapper<T, U>::loadFromFile(string filename)
{    
	// reading from file and displaying hash table
	ifstream fileobj(filename.c_str());
	Hash<T, U>obj;
	T a;
	U b;
	
	// read and insert
	while(fileobj>>a>>b)
	{
		obj.addRecord(a,b);
	}
	cout<<"Hash Table from file:-"<<endl;
	obj.display();
	
	fileobj.close();
}

template<typename T, typename U>

int Hash<T,U>::computeHash(T key)
{
	if(typeid(key).name()==typeid(string).name())// for string
	{
		int sum = 0;
        for (int k = 0; k < key.length(); k++)
            sum = sum + int(key[k]);
        return  sum % array_length;
		
	}
		
		else// for int and float
		{
			cout<<"Oops... not a string"<<endl;
			
		}	  
		// for character  
}

template<typename T, typename U>

bool Hash<T,U>::hasKey(T key)
{
 	int index = computeHash(key);
		typename list<pair<T, U> >::const_iterator it;
		int count=0;
		for(it=main_column[index].begin(); it!=main_column[index].end(); ++it)
			if((*it).first==key)
			{
				count = 1;
				return true ;
			}
		if(count!=1)
		return false;	
}

template<typename T, typename U>

void Hash<T,U>::addRecord(T key, U object)
{
	int index = computeHash(key);
	// check for existence of key
	bool exist = hasKey(key);
	if(exist)
	cout<<"Duplicate key entries are not allowed."<<endl;
	else
	{
		main_column[index].push_back(make_pair(key, object));
		cout<<"Key -> "<<key<<" is added"<<endl;
	}	
}

template<typename T, typename U>

void Hash<T,U>::getRecord(T key)
{
	bool exist = hasKey(key);
	if(!exist)
	cout<<"Key does not exist"<<endl;
	else
	{
		int index =  computeHash(key);
		typename list<pair< T,U> >::const_iterator it;
		
		for(it=main_column[index].begin(); it!=main_column[index].end(); ++it)
		if((*it).first==key)
		cout<<"Record corresponding to key ' "<<key<<" ' is:-"<<(*it).second<<endl;				
	}
}

template<typename T, typename U>

void Hash<T,U>::replaceRecord(T key, U object)
{   
	bool exist = hasKey(key);
	if(!exist)
	cout<<"Enter a valid Key"<<endl;
	else
	{
		int index = computeHash(key);
		typename list<pair< T,U> >::iterator it;
		
		for(it=main_column[index].begin(); it!=main_column[index].end(); ++it)
			if((*it).first==key)
				(*it).second = object;
	}
	
}


template<typename T, typename U>

void Hash<T,U>::display()
{
// iterate array and print
	for(int i=0; i<array_length; i++)
	{
		cout<<i;
		typename list<pair<T,U> >::const_iterator it;
		for(it=main_column[i].begin(); it!=main_column[i].end(); ++it)
		
			cout<<"-->"<<(*it).second;
		cout<<endl;
	}	
}



int main()
{
	Hash<string, string>rk(5);
	HTWrapper<string, string>save;
	rk.addRecord("ra", "ravi");
	rk.addRecord("k", "kant");
	rk.addRecord("v", "vijay");
	rk.addRecord("k", "thanos");
	rk.addRecord("bq", "negan");

	rk.display();
	//rk.getRecord("v");
	rk.replaceRecord("k", "thanos");
	cout<<"\n"<<endl;
	rk.display();
	save.saveToFile("myfile.txt", rk);
	save.loadFromFile("myfile.txt");
	return  0;
} 