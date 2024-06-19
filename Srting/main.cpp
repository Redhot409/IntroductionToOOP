// String
#include<iostream>
using namespace std;


class String

{
	int size;//размер строки в Ѕайтах
	char* str;//јдрес строки в динамической пам€ти
	
public:
	int get_size()const;
	
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	//////////////////////////////////////////////////////////////

	explicit String(int size = 80);
	 
	String(const char str[]);
	String(const String& other);
	~String();

	//				Operators:
	//////////////////////////////////////////////////////////////

	String& operator=(const String& other);

	//           Type-cast operators:
	/////////////////////////////////////////////////////////////


	

	//					Methods:
	/////////////////////////////////////////////////////////////
	
	void print()const;


};
int String::get_size()const
{
	return size;
}

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//				Constructors:
//////////////////////////////////////////////////////////////

String:: String(int size) :size(size), str(new char[size] {})
{

	//this->size = size;
	//this->str = new char[size] {};// {}-убирают мусор
	cout << "DefaultConstructor:\t" << this << endl;
}

String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};// !!!!!!!!!!!!!!!!!! вместо нул€
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::~String()
{
	delete[]this->str;
	cout << "Destructor:\t\t" << this << endl;

}

//				Operators:
//////////////////////////////////////////////////////////////

String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

//           Type-cast operators:
/////////////////////////////////////////////////////////////




//					Methods:
/////////////////////////////////////////////////////////////

void String::print()const
{
	cout << "Obj:\t" << this << "\t";
	cout << "Size:\t" << size << "\t";
	cout << "Addr:\t" << &str << "\t";
	cout << "Str:\t" << str << "\t";
}
std::ostream& operator<<(std::ostream& os,const String& obj)
	{
		return os << obj.get_str();
	}

String operator+(const String& left, const String& right)
{
	String buffer (left.get_size() + right.get_size()-1);// from int to String
	for (int i = 0; i < left.get_size(); i++)
		buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	buffer.print();
	return buffer;
}

#define CONSTRUCTORS_CHECK
//define CAT_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	/*String str;
	str.print();*/

	String str1; // def constr
	String str2(8);//Single-arg constr
	String str3 = "Hello";//Single-arg constr
	String str4(); // «десь не созд объект, а только объфвл€етс€ функци€ str4()
					// котора€ ничего не принимает ивозвращает объект класса "String"
	//str4.print();
	String str5{};// явный вызов конструктора по умолчанию
	String str6{ str3 };//Copy constr

#endif CONSTRUCTORS_CHECK
#ifdef CAT_CHECK
	String str1 = "Hello";
	String str2 = "World";
	str1 = str1;

	cout << str1 << endl;
	cout << str2 << endl;

	//String str3 = str1 + str2;//Copy constructor
	String str3;
	str3 = str1 +" "+ str2;
	//str3.print();
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;//"HelloWorld"
#endif CAT_CHECK
} 