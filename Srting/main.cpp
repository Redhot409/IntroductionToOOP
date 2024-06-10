// String
#include<iostream>
using namespace std;


class String

{
	int size;//размер строки в Байтах
	char* str;//Адрес строки в динамической памяти
	
public:

	//				Constructors:
	//////////////////////////////////////////////////////////////

	String(int size = 80)
	{

		this->size = size;
		this->str = new char[size] {};// {}-убирают мусор
		cout << "DefaultConstructor:\t" << this << endl;
	}
	 
	 String(char* str,int size)
	{
		this->size = size;
		this->str = new char[size];
		for (int i = 0; i <= size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0; i <= size; i++)
		{
			this->str[i] =other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;

	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this << endl;

	}

	//				Operators:
	//////////////////////////////////////////////////////////////

	String& operator=(const String& other)
	{
		this->size = other.size;
		this->str = new char[size];
		
		for (int i = 0; i <= size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//           Type-cast operators:
	/////////////////////////////////////////////////////////////


	

	//					Methods:
	/////////////////////////////////////////////////////////////
	
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}


};

void main()
{
	setlocale(LC_ALL, "");

	/*String str;
	str.print();*/

	String str1 = "Hello";
	//String str2 = "World";
	cout << str1 << endl;
	//cout << str2 << endl;

	//String str3 = str1 + str2;
	//cout << str3 << endl;//"HelloWorld"
}