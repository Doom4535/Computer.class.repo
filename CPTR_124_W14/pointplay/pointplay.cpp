#include <iostream>
#include <cmath>

using namespace std;

class point {
public:
	double x;
	double y;
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
	point my_point;
	my_point.x = 0.0;
	my_point.y = 0.0;
	point other_point;
	other_point.x = 1.0;
	other_point.y = 1.0;
	cout << "The distance between " << my_point
		<< " and " << other_point << " is "
		<< dist(my_point, other_point) << endl;
}
