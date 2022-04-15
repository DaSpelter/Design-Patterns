#include <string>
#include <iostream>
using namespace std;

struct Person
{
    int id;
    string name;
};

class PersonFactory
{
    int id = 1;
public:
    Person create_person(const string& name)
    {
        //Person* p = new Person;
        //shared_ptr<Person> p = make_shared<Person>();
        unique_ptr<Person> p = make_unique<Person>();
        p->name = name;
        p->id = id;
        id++;
        return *p;
    }
};

int main()
{
    PersonFactory pf;
    Person p = pf.create_person("Yijing");
    cout << p.name << endl;
    Person pp = pf.create_person("Daniel");
    cout << pp.id << endl;
    


}

