//  Quiz 7 Part 1
#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2;
    if (n1 < n2)
        n3 = 0;
    else if (n1 > 0)
        n3 = 100;
    else
        n3 = -100;
    cout << n3 << endl;
}

////  Quiz 7 Part 2
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n1, n2, n3;
//    cin >> n1 >> n2;
//    if (n1 < n2)
//        n3 = 0;
//    if (n1 > 0)
//        n3 = 100;
//    else
//        n3 = -100;
//    cout << n3 << endl;
//}
