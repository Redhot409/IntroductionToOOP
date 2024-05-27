//introductionToOOP
#include<iostream>
#include<cmath>
using namespace std;

using std::cout;
using std::cin;

#define delimeter "\n------------------------------------------\n"

class Point // где  point(структура или класс) - это тип данных
{
	double x,x1,y,y1;

 public:

	 double get_x()const
	 {
		 //x=-2; //must be a modifiable
		 return x;
	  }
	 double get_y()const // метод get
	 {
		 return y;
	 }

	 void set_x(double x) 
	 {
		 this->x = x; //set значение х
	 }
	 void set_y(double y)
	 {
		 this->y = y; //set значение y
	 }

	 //    Constructors:

	 Point()
	 {
		 x = y = 0;
		 cout << "DefaultConstructor \t\t" << this << endl;
	 }
	 Point(double x)
	 {
		 this->x = x;
		 this->y = 0;
		 cout << "1ArgConstructor: \t" << this << endl;
	 }

	 Point(const Point& other)
	 {
		 this->x =other. x;
		 this->y = other.y;
		 cout << "CopyConstructor: \t" << this << endl;
	 }
	 Point(double x,double y)
	 {
		 this->x = x;
		 this->y = y;
		 cout << "Constructor: \t" << this << endl;
	 }

	 ~Point()
	 {
		 cout << "Destructor \t\t" << this << endl;
	 }

	 //        Operators:

	 Point& operator=(const Point& other)
	 {
		 this->x = other.x;
		 this->y = other.y;
		 cout << "CopyAssignment:\t\t" << this << endl;
		 return *this;
	 }

	 
		 //Methods :
	 double distance(const Point& other)const
	 {
		 double x_distance = this->x - other.x;// this x это обращение к точке А, other.y -обращение к точке В
		 double y_distance = this->y - other.y;// this y это обращение к точке А, other.y -обращение к точке В
		 double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		 return distance;
	 }

	 void print()const
	 {
		 cout << this <<":X= " << x << "\tY= " << y << endl;
	 }
};

double distance(const Point& A,const Point& B)
{
	double x_distance = A.get_x()- B.get_x();// this x это обращение к точке Аб, other.y -обращение к точке В
	double y_distance = A.get_y() - B.get_y();// this y это обращение к точке Аб, other.y -обращение к точке В
	//sqrt(x_distance * x_distance + y_distance * y_distance);
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
#define ASSIGNMENT_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;

	Point A;// напоминает объявление переменной double a
	// Создание объекта А структуры Podouble
   // Создание экземпляра А структуры Podouble
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;// прямой доступ по значению

	Point* pA = &A;// указатель на нашу точку A
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;


	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки А до точки В :" << A.distance(B) << endl; //вызов метода класса Point
	cout << delimeter << endl;
	cout << "Расстояние от точки B до точки A :" << B.distance(A) << endl;// вызов метода класса Point
	cout << delimeter << endl;
	cout << "Расстояние между точками А и В:" << distance(A, B) << endl; // вызов функции
	cout << delimeter << endl;
	cout << "Расстояние между точками B и A:" << distance(B, A) << endl; // вызов функции 
	cout << delimeter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;// default consrtuctor
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	//Point A(2, 3);//Constructor
//Point B;	 // Default constructor
//B = A;		//  Copy assignment
//B.print();

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimeter << endl;
	A = B = C = Point(2, 3);
	cout << delimeter<<endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

}

