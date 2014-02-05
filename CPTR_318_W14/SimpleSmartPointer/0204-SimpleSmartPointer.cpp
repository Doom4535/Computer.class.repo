//  File:   0204-SimpleSmartPointer.cpp
//  Author: Rick Halterman

#include <iostream>
#include <memory>

using namespace std;

class Widget {
	static int id_source;
	int id;
public:
	Widget(): id(id_source++) {
		cout << "      +++ Creating widget #" << id << " +++" << endl;
	}
	~Widget() {
		cout << "      --- Destroying widget #" << id << " ---" << endl;
	}
	int get_id() const {
		return id;
	}
};

int Widget::id_source = 0;


void no_dangle() {
	cout << "   Entering no_dangle" << endl;
    //  wid is a local object 
	Widget wid;
	cout << "I'm widget #" << wid.get_id() << endl;
	cout << "   Returning from no_dangle" << endl;
}

void dangle() {
	cout << "   Entering dangle" << endl;
    //  wid is a regular pointer
	Widget *wid = new Widget;
	cout << "I'm widget #" << wid->get_id() << endl;
	//delete wid;   //wid will be a dangling pointer without the delete
	cout << "   Returning from dangle" << endl;
}

auto global_wid = shared_ptr<Widget>(new Widget);

void smart_dangle() {
	cout << "   Entering smart_dangle" << endl;
    //  wid is a smart pointer
	auto wid = make_shared<Widget>();
	cout << "I'm widget #" << wid->get_id() << endl;
	cout << "   Returning from smart_dangle" << endl;
}

void shared_experiment() {
	//  Local smart pointer aliases the global smart pointer
	auto wid = global_wid;  
	cout << "Use count for global shared_ptr: " << global_wid.use_count() << endl;
}

int main() {
	cout << "Use count for global shared_ptr: " << global_wid.use_count() << endl;

    //  Make some pointer aliases
	auto w = make_shared<Widget>();
	cout << "Use count for main's w variable: " << w.use_count() << endl;
	auto w2 = w;
	cout << "Use count for main's w variable: " << w.use_count() << endl;
	auto w3 = w;
	cout << "Use count for main's w variable: " << w.use_count() << endl;
	w2 = nullptr;
	cout << "Use count for main's w variable: " << w.use_count() << endl;
	w3 = nullptr;
	cout << "Use count for main's w variable: " << w.use_count() << endl;
	w = nullptr;
	cout << "Use count for main's w variable: " << w.use_count() << endl;

    //  Call no_dangle a few times and note the object construction/destruction
	cout << "Going to call no_dangle (1)" << endl;
	no_dangle();
	cout << "Back in main" << endl;
	cout << "Going to call no_dangle (2)" << endl;
	no_dangle();
	cout << "Back in main" << endl;
	cout << "Going to call no_dangle (3)" << endl;
	no_dangle();
	cout << "Back in main" << endl;

	cout << "------------" << endl;

    //  Call dangle a few times and note the object construction/destruction
	cout << "Going to call dangle (1)" << endl;
	dangle();
	cout << "Back in main" << endl;
	cout << "Going to call dangle (2)" << endl;
	dangle();
	cout << "Back in main" << endl;
	cout << "Going to call dangle (3)" << endl;
	dangle();
	cout << "Back in main" << endl;

	cout << "------------" << endl;

    //  Call smart_dangle a few times and note the object construction/destruction
	cout << "Going to call smart_dangle (1)" << endl;
	smart_dangle();
	cout << "Back in main" << endl;
	cout << "Going to call smart_dangle (2)" << endl;
	smart_dangle();
	cout << "Back in main" << endl;
	cout << "Going to call smart_dangle (3)" << endl;
	smart_dangle();
	cout << "Back in main" << endl;

	shared_experiment();
	cout << "Use count for global shared_ptr: " << global_wid.use_count() << endl;
}
