

#include <iostream>
#include <vector>
using namespace std;
struct Square
{
    int side{ 0 };


    explicit Square(const int side)
        : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    SquareToRectangleAdapter(const Square& square)
    {
        rectangle = new Square(square.side);
    }
    int width() const override { return rectangle->side; }
    int height() const override { return rectangle->side; }
    
    Square* rectangle;
};

int main()
{
    std::cout << "Hello World!\n";
}

