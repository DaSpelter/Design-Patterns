

#include <iostream>
#include <string>
using namespace std;

struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct VectorRenderer :Renderer
{
    string what_to_render_as() const  override
    {
        return "lines";
    }
};
struct RasterRenderer :Renderer
{
    string what_to_render_as() const override
    {
        return  "pixels";
    }
};

//Triangle(RasterRenderer()).str() // returns "Drawing Triangle as pixels"
struct Shape
{
    Renderer& renderer;
    string name;
    Shape(Renderer& renderer) : renderer{ renderer } {
        
    }
    virtual void str() = 0;
};

struct Triangle : Shape
{
    Triangle(Renderer& renderer) : Shape(renderer)
    {
        Shape::name = "Circle";
    }
    void str() {
        cout << "Drawing " << name << " as " << renderer.what_to_render_as() << endl;
    }

};

struct Square : Shape
{
    Square(Renderer& renderer) :Shape(renderer)
    {
        Shape::name = "Square";
    }
    void str() {
        cout << "Drawing " << name << " as " << renderer.what_to_render_as() << endl;
    }
};


// imagine e.g. VectorTriangle/RasterTriangle etc. here

int main()
{
    VectorRenderer vec;
    RasterRenderer ras;
    Square(vec).str();
    Triangle(ras).str();
}
