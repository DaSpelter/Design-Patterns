#include "composite.h"
#include <iostream>
using namespace std;

int sum(const vector<ContainsIntegers*> items)
{
    int count = 0;
    for (auto k : items) {
        count += k->sum();
    }
    return count;
}
int main()
{ 
    SingleValue a(10);
    ManyValues b;
    b.push_back(1);
    b.push_back(2);
    SingleValue c(3);
    vector<ContainsIntegers*> x;
    x.push_back(&a);
    x.push_back(&b);
    x.push_back(&c);
    cout << sum(x) << endl;
};