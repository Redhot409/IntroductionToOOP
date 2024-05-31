//Fraction
#include<iostream>
using namespace std;
using std::cout;
using std::cin;

class Fraction
{
	int num;// numerator - целое число в числителе дроби
	int den;// denominator целое число в знаменателе дроби

public:

	int get_num()const // get-method
	{
		
		return num;
	}
	int get_den()const 
	{
		return num;
	}

	void set_num(int num)
	{
		this->num = num; //set-method num
	}
	void set_den(int den)
	{
		this->den = den; 
	}

	Fraction()
	{
		num = 0;
		den = 1;
		cout << "DefaultConstructor \t\t" << this << endl;
	}
	Fraction(int num, int den)
	{
		this->num = num;
		this->den = den;
		cout << "Constructor with parameters: \t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor \t\t" << this << endl;
	}

	//Methods :
	////////////////////////////////////


	void print()const
	{
		cout << this << ":numerator - " << num <<"/" << den << "\t-denominator " << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	
	Fraction A;
	A.print();
	

	
	



}