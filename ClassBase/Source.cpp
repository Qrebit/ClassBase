#include <iostream>

using namespace std;

#define tab "\t"

class Point {
	
	double x;
	double y;
public:
	Point(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;
		cout << "Default Const:\t" << this << endl;
	}
	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConst:\t" << this << endl;
	}
	~Point() {
		cout << "Dest:\t" << this << endl;
	}

	Point& operator=(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point operator+(const Point& other)const {
		return Point(this->x + other.x, this->x + other.x);
	}
	Point operator-(const Point& other)const {
		return Point(this->x - other.x, this->x - other.x);
	}
	Point operator*(const Point& other)const {
		return Point(this->x * other.x, this->x * other.x);
	}
	Point operator/(const Point& other)const {
		return Point(this->x/other.x, this->x/other.x);
	}

	void print() {
		cout << x << tab << y  << endl;
	}

	double distance(Point& other) {
		return sqrt((other.x-this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y));
	}
};

double distance(Point A, Point B) {
	return A.distance(B);
}
//Не перезагружал Операторы вне класса. Знаю как и понимаю но не уверен нужно было или нет.
void main() {
	setlocale(LC_ALL, "Rus");
	Point A;
	Point B(6, 8);
	Point C = A - B;
	cout << distance(A,B) << endl;
	C.print();
}