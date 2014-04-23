#include <iostream>
#include <GL/sgl.hpp>

using namespace std;
using namespace sgl;

class MyWindow: public Window {
public:
	MyWindow() :
		Window("My Window", 100, 100, 600, 600,
		0.0, 100.0, 0.0, 100.0) {
	}
	void paint() {
		fill_circle(50, 50, 10);
	}
	void mouse_moved(double x, double y) {
		cout << "x=" << x << ", y=" << y << endl;
	}
};

int main() {
	//  Create a window object
	MyWindow *win = new MyWindow;
	//  Run the graphical application
	win->run();
}