

#include <iostream>
#include <memory>
using namespace std;
struct Point
{
    int x{ 0 }, y{ 0 };

    Point() {}

    Point(const int x, const int y) : x{ x }, y{ y } {}
};


struct Line
{
    Point* start, * end;

    Line(Point* const start, Point* const end)
        : start(start), end(end)
    {
    }

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        Point* p1 = new Point(start->x, start->y);

        Point* p2 = new Point(end->x, end->y);

        Line* l = new Line(p1, p2);

        return *l;



    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
