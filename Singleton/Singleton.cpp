

#include <iostream>
#include <functional>
using namespace std;

struct SingletonTester
{
    template <typename T>
    bool is_singleton(function<T* ()> factory)
    {
        auto a = factory();
        auto b = factory();
        return a == b;
    }
};

int main()
{
   
}

