#include <iostream>
#include <cmath>

using namespace std;

class point {
public:
	double x;
	double y;
	//  constructor
	point(double x_val, double y_val) : x(x_val), y(y_val) {
		cout << "Making a point object" << endl;
	}
	//  copy constructor
	point(const point& other) : x(other.x), y(other.y) {
		cout << "Making a point object" << endl;
	}
	// destructor
	~point() {
		cout << "Destroying a point object" << endl;
	}
};

//  Option #1
class line1 {
public:
	double slope;
	double intercept;
};

//  Option #2
class line2 {
public:
	point pt1;
	point pt2;
};

//  Option #3
class line3 {
public:
	double x1;
	double y1;
	double x2;
	double y2;
};

double dist(point p1, point p2) {
	double x1 = p1.x, y1 = p1.y,
		x2 = p2.x, y2 = p2.y;
	return sqrt((x2 - x1)*(x2 - x1)
		+ (y2 - y1)*(y2 - y1));
}

ostream& operator<<(ostream& os, point p) {
	os << '(' << p.x << ',' << p.y << ')';
	return os;
}

int main() {
	point my_point(0.0, 0.0);
	point other_point(1.0, 1.0);
	cout << "The distance between " << my_point
		<< " and " << other_point << " is "
		<< dist(my_point, other_point) << endl;
}
