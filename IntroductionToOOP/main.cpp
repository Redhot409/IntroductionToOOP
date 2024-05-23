//doubleroductionToOOP
#include<iostream>
#include<cmath>
using namespace std;

using std::cout;
using std::cin;


class Point // ���  point(��������� ��� �����) - ��� ��� ������
{
	double x,x1,y,y1;

 public:

	 double get_x()const
	 {
		 //x=-2; //must be a modifiable
		 return x;
	  }
	 double get_y()const // ����� get
	 {
		 return y;
	 }

	 void set_x(double x) 
	 {
		 this->x = x; //set �������� �
	 }
	 void set_y(double y)
	 {
		 this->y =y; //set �������� y
	 }
	 void set_x1(double x1)
	 {
		 this->x1 = pow(x1-x,2); //set �������� x1
	 }
	 void set_y1(double y1)
	 {
		 this->y1 = pow(y1-y,2); //set �������� y1
	 }

	// ����� ���������� ���������� �� �����
	 double get_dist(double x, double y)const
	 {
		return sqrt(pow(x,2)+pow(y,2));
	 }

	 //����� ���������� ���������� ����� ����� �������
	 double get_dist_1(double x1, double y1)const
	 {
		 return sqrt(x1 + y1);
	 }
	 void result()
	 {
		 cout << "���������� �� ������������ ����� :" <<get_dist(x,y)<< endl;
	 }
	 void result_1()
	 {
		 cout << "���������� ����� ����� ������� :" << get_dist_1(x1,y1) << endl;
	 }
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;

	Podouble A;// ���������� ���������� ���������� double a
	// �������� ������� � ��������� Podouble
   // �������� ���������� � ��������� Podouble
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;// ������ ������ �� ��������

	Podouble* pA = &A;// ��������� �� ���� ����� A
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