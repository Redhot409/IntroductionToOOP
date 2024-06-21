// Class Fraction
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Fraction;

Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction left, const Fraction right);

#define delimiter "--------------------------"
class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//				Constructors
	/////////////////////////////////////////

	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);

	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//					Operators:
	//////////////////////////////////////////////////

	Fraction& operator=(const Fraction& other);

	Fraction& operator*=(const Fraction& other);

	Fraction& operator /= (const Fraction& other);

	Fraction& operator ++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator --(int);

	             //Type-cast operators:
	////////////////////////////////////////////////////
	
	explicit operator int();
	operator double();

	//				   Methods:
	////////////////////////////////////////////////////
	

	Fraction& reduce();

	Fraction& to_proper();
	Fraction to_improper();

	Fraction inverted()const;

	void print()const;
};
#define COMPARISON_OPERATORS_CHECK

Fraction operator*(Fraction left, Fraction right)

{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction left, const Fraction right)
{
	return left * right.inverted();
}
//         Comparison operators 
//////////////////////////////////////////////////////////////

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();

}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator >(Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator < (Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}

bool operator <=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;

}

bool operator >=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
}


//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define STREAMS_CHECK
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define CONVERSION_TASK_1
#define CONVERSION_TASK_2


std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()); cout << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
// Stream - это поток,
// Ostream- output stream (поток вывода)
// ISTREAM -input stream(поток ввода)
//cin-console stream
//cout - console output
//std- standard namespace
//:: - Scope operator (оператор разрешения видимости-позволяет зайти в пространство имен)
// namespace (пространство имен) как папка, а имя, расположенное в нем, как файл
//:: сам по себе выводит нас в global scope или же в глобальное пространство имен

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 32;
	char buffer[SIZE]{};
	//is >> buffer;
	is.getline(buffer, SIZE);
	int number[3];
	int n = 0;
	const char delimiters[] = "(/) +";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		// Функция strtok разделяет строку на токены
		// Функция strtok () изменяет входную строку!!!
		number[n++] = atoi(pch);
	// Функция atoi - ASCII string to int, принимает строку, и возвращает значение типа int, найденное в этой строке
	//Pointer to Character (указатель на символ)
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1:obj = Fraction(number[0]); break;
	case 2:obj = Fraction(number[0],number[1]); break;
	case 3:obj = Fraction(number[0],number[1],number[2]); break;
	}
	return is;
}
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A; // DefaultConstructor
	A.print();

	Fraction B = 5; //Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();


	Fraction E = D;//Copy-constructor
	E.print();

	Fraction F;
	F = E;//Copy-Assignment
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A / B;
	C.print();
	(C++).print();
	C.print();

	A.print();
	B.print();

	A *= B;
	A.print();

	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	cout << (2 == 3) << endl;
	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;
	cout << (Fraction(1, 3) > Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) < Fraction(5, 10)) << endl;
	cout << (Fraction(1, 3) <= Fraction(5, 11)) << endl;
	cout << (Fraction(1, 3) >= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef STREAMS_CHECK
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь :"; cin >> A;
	cout<< A<< endl;
#endif // STREAMS_CHECK

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;

	Fraction B;
	cout << delimiter << endl;
	B = Fraction(8);
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_TASK_1
	Fraction A(2, 3, 4);
	cout << A << endl;

	double a = A;
	
	cout << a << endl;
	/*int a = A;
	cout << a << endl;*/
#endif // CONVERSION_TASK_1

#ifdef CONVERSION_TASK_2
	Fraction B = 0.333;
	cout << B << endl;

#endif // CONVERSION_TASK_2


}