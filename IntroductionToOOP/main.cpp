//doubleroductionToOOP
#include<iostream>
#include<cmath>
using namespace std;

using std::cout;
using std::cin;


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
		 this->y =y; //set значение y
	 }
	 void set_x1(double x1)
	 {
		 this->x1 = pow(x1-x,2); //set значение x1
	 }
	 void set_y1(double y1)
	 {
		 this->y1 = pow(y1-y,2); //set значение y1
	 }

	// Метод нахождения расстояния до точки
	 double get_dist(double x, double y)const
	 {
		return sqrt(pow(x,2)+pow(y,2));
	 }

	 //Метод нахождения расстояния между двумя точками
	 double get_dist_1(double x1, double y1)const
	 {
		 return sqrt(x1 + y1);
	 }
	 void result()
	 {
		 cout << "Расстояние до произвольной точки :" <<get_dist(x,y)<< endl;
	 }
	 void result_1()
	 {
		 cout << "Расстояние между двумя точками :" << get_dist_1(x1,y1) << endl;
	 }
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;

	Podouble A;// напоминает объявление переменной double a
	// Создание объекта А структуры Podouble
   // Создание экземпляра А структуры Podouble
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;// прямой доступ по значению

	Podouble* pA = &A;// указатель на нашу точку A
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	
	A.set_x(6);
	A.set_y(3);
	A.set_x1(3);
	A.set_y1(19);
	A.result();
	A.result_1();

	
}