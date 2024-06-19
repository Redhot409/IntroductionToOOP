#include "String.h"

/////-----------------------------------------------//////

////////-----------------------------------------------////////


//#define CONSTRUCTORS_CHECK
#define CAT_CHECK

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