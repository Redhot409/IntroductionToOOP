#include "String.h"

///////////////////////////////////////////////////////
//////   ����������� ������ (Class definition)   //////
///////////////////////////////////////////////////////

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

String::String(int size) :size(size), str(new char[size] {})
{

	//this->size = size;
	//this->str = new char[size] {};// {}-������� �����
	cout << "DefaultConstructor:\t" << this << endl;
}

String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};// !!!!!!!!!!!!!!!!!! ������ ����
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
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);// from int to String
	for (int i = 0; i < left.get_size(); i++)
		buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	buffer.print();
	return buffer;
}

/////////////////////////////////////////////////////////////////
//////   ����� ����������� ������ (Class definition end)   //////
/////////////////////////////////////////////////////////////////