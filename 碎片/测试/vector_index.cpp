#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<bool> vecBool = {true, false, true};
    bool tmpBool = vecBool[0];
    if (tmpBool) {
        cout << "YES" << endl;
    }
    return 0;
}