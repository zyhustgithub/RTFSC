#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    double d = 50.99;
    double D = 50;
    if ((int)d == (int)D) {
        cout << "YES" << endl;
    }
    return 0;
}