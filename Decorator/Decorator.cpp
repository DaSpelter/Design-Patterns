

#include <iostream>
#include <string>
using namespace std;

struct Flower
{
    virtual string str() = 0;
};

struct Rose : Flower
{
    string str() override {
        return "A rose";
    }
};

struct RedFlower : Flower
{
    Flower&  flower;
    RedFlower(Flower& flower) : flower(flower) {}

    string str() override {
        string str = flower.str();
        if (str.find("blue") != std::string::npos) {
            return str + " and red";
        }
        else {
            return str + " that is red";
        }
    }


};

struct BlueFlower : Flower
{
    Flower&  flower;
    BlueFlower(Flower& flower) : flower(flower) {}

    string str() override {
        string str = flower.str();
        if (str.find("red") != std::string::npos) {
            return str + " and blue";
        }
        else {
            return str + " that is blue";
        }
    }
};

int main()
{
    Rose coon;
    BlueFlower a(coon);
    cout << a.str() << endl;
    RedFlower b(a);
    cout << b.str() << endl;
}
