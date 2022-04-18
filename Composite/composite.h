#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

struct ContainsIntegers
{
    virtual int sum() = 0;
};
struct SingleValue : ContainsIntegers
{
    int value{ 0 };

    SingleValue() = default;

    explicit SingleValue(const int value)
        : value{ value }
    {
    }
    
    SingleValue* begin() { return this; }
    SingleValue* end() { return this + 1; }
    
    int sum() override { return value; }
};

struct ManyValues : vector<int>, ContainsIntegers
{
    void add(const int value)
    {
        push_back(value);
    }
    int sum() override 
    {   
        int count = 0;
        for (auto it = begin(); it < end(); it++) {
            count += *it;
        }
        
        return count;
    }
};

int sum(const vector<ContainsIntegers*> items);