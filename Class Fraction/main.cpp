// Class Fraction
#include<iostream>
using namespace std;
class Fraction;

Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction left, const Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const // get-methods
	{
		return integer;
	}
	int get_numerator()const 
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)// set-methods
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this-> denominator= denominator;
	}

	//				Constructors

	Fraction()
	{

		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//					Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator /= (const Fraction & other)
	{
		return *this = *this / other;
	}

	Fraction& operator ++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator --(int)//�������� ��������� ������ ���� ��� ��������� int
	{
		Fraction old = *this;
		integer--;//����� ����� �������� ������.
		return old;// ���������� �� ����� ������ ������ ����
	}

	//				Methods:


	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;//Greatest Common Divesor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction to_improper()
	{
		numerator += integer * denominator;
		integer= 0;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
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
#define STREAMS_CHECK


std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())cout << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
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


	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
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
	//cout << A << endl;
	cin >> "������� ������� ����� :" >> A >> endl;
#endif // STREAMS_CHECK

}