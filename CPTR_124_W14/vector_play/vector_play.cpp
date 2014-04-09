#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_vector_simple(const vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << endl;
}

void print_vector(const vector<int>& v) {
	cout << '{';
	int n = v.size();
	if (n > 0) {
		cout << v[0];
		for (int i = 1; i < n; i++)
			cout << ',' << v[i];
	}
	cout << '}' << endl;
}

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

int count_nonnegatives_1(const vector<int>& v) {
	int n = v.size(), count = 0;
	for (int i = 0; i < n; i++)
		if (v[i] >= 0)
			count++;
	return count;
}

int count_nonnegatives_2(const vector<int>& v) {
	int count = 0;
	for (int elem : v)
		if (elem >= 0)
			count++;
	return count;
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

int main() {
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(-30);
	vec.push_back(40);
	vec.push_back(-50);
	print_vector_simple(vec);
	print_vector(vec);
	cout << vec << " is " << vec << endl;
	cout << "Number of non-negatives: "
		 << count_nonnegatives_1(vec) << endl;
	cout << "Number of non-negatives (alternate): "
		 << count_nonnegatives_2(vec) << endl;

	cout << "------------" << endl;
	vector<int> vec2(5);
	for (int i = 0; i < 5; i++)
		vec2[i] = 100 * (i + 1);
	print_vector_simple(vec2);
	print_vector(vec2);
	cout << vec2 << " is " << vec2 << endl;
	cout << "Number of non-negatives: "
		<< count_nonnegatives_1(vec2) << endl;
	cout << "Number of non-negatives (alternate): "
		<< count_nonnegatives_2(vec2) << endl;

	cout << "------------" << endl;
	vector<int> vec3 { 1000, 2000, 3000, 4000, -7, -3 };
	print_vector_simple(vec3);
	print_vector(vec3);
	cout << vec3 << " is " << vec3 << endl;
	cout << "Number of non-negatives: "
		<< count_nonnegatives_1(vec3) << endl;
	cout << "Number of non-negatives (alternate): "
		<< count_nonnegatives_2(vec3) << endl;

	srand(time(0));
	vector<int> vec4 = make_random_vector();
	cout << vec4 << endl;

	cout << "===============================" << endl;
	for (int i = 0; i < 10; i++) {
		vec4 = make_random_vector();
		cout << ">>> " << vec4
			 << " (" << vec4.size() << ")"
			 << endl;
		sort(vec4);
		cout << "*** " << vec4 << endl;
		cout << "-------" << endl;
	}
}