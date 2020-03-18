#include <iostream>
#include <set>

using namespace std;

struct RefArg {
    set<int> *data;
};

void RefFuncConst(const set<int> &refConst)
{
    printf("refConst:%p\n", &refConst);
    for (auto x : refConst) {
        cout << x << " ";
    }
    cout << endl;
}

void RefFunc(set<int> &ref)
{
    printf("ref:%p\n", &ref);
    ref.insert(4);
    for (auto x : ref) {
        cout << x << " ";
    }
    cout << endl;
}

void Func(RefArg &elem)
{
    printf("elem.data:%p\n", elem.data);
    const set<int> *tmp = elem.data;
    for (auto x : *tmp) {
        cout << x << " ";
    }
    cout << endl;
    RefFunc(*(elem.data));
    RefFuncConst(*tmp);
}

int main(int argc, char *argv[])
{
    set<int> tmpSet = {1, 2};
    printf("tmpSet:%p\n", &tmpSet);
    RefArg arg;
    arg.data = &tmpSet;
    Func(arg);

    for (auto x : tmpSet) {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : *arg.data) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}