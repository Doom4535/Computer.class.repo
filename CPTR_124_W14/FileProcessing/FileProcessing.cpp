#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
	os << '{';
	int n = v.size();
	if (n > 0) {
		os << v[0];
		for (int i = 1; i < n; i++)
			os << ',' << v[i];
	}
	os << '}';
	return os;
}

vector<int> make_random_vector() {
	int size = rand() % 20;
	vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = rand() % 1000;
	}
	return result;
}

void sort(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int smallest = i;
		for (int j = i + 1; j < n; j++) {
			if (v[j] < v[smallest])
				smallest = j;
		}
		if (i != smallest) {
			int temp = v[i];
			v[i] = v[smallest];
			v[smallest] = temp;
		}
	}
}

void save_vector(const vector<int>& v,
	             string filename) {
	ofstream fout;
	fout.open(filename);
	if (fout.good()) {
		for (int elem : v)
			fout << elem << endl;
		fout.close();
	}
	else
		cout << "Could not save the vector" << endl;
}

vector<int> load_vector(string filename) {
	vector<int> result;
	ifstream fin;
	fin.open(filename);
	if (fin.good()) {
		while (!fin.eof()) {
			int elem;
			fin >> elem;
			if (!fin.eof())
				result.push_back(elem);
		}
		fin.close();
	}
	else
		cout << "Could not load in the vector" << endl;
	return result;
}

int main() {
	srand(time(0));
	vector<int> vec = make_random_vector();
	cout << vec << endl;
	cout << "===============================" << endl;
	save_vector(vec, "vector.data");

	vector<int> vec2;
	vec2 = load_vector("vector.data");
	cout << vec2 << endl;
	
	vector<int> vec3{ 10, 20, 30, 100, 200, 300 };
	ofstream out;
	out.open("new_vector_file.text");
	if (out.good()) {
		out << vec3 << endl;
		out.close();
	}


}