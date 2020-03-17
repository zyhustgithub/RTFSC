#include <iostream>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
    std::set<uint32_t> Sets = {11, 22};  // 新特性，需指明-std=gnu++11
    
    if (Sets.find(11) != Sets.end()) {
        cout << "YES" << endl;
    }
    
    return 0;
}