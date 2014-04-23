#include <iostream>
#include "trafficlightlogic.h"

using namespace std;

int main() {
	TrafficLightLogic light;
	cout << light.get_color() << endl;  //  Prints 0
	light.change();
	cout << light.get_color() << endl;  //  Prints 1
	light.change();
	cout << light.get_color() << endl;  //  Prints 2
	light.change();
	cout << light.get_color() << endl;  //  Prints 0
	light.change();
}
