
#include <iostream>
#include <string>

using namespace std;

class Person
{
friend class ResponsiblePerson;
int age;
public:
    Person(int age) : age(age) {}

    int get_age() const { return age; }
    void set_age(int age) { this->age = age; }

    string drink() const { return "drinking"; }
    string drive() const { return "driving"; }
    string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{   
    public:

    ResponsiblePerson(const Person& person) : person(person) {}

    string drink() const 
    {
        if (person.get_age() >= 18) {
            return person.drink();
        }
        else {
            return "too young";
        }
    }
    string drive() const 
    {

        if (person.get_age() >= 16) {
            return person.drive();
        }
        else {
            return "too young";
        }
    }
    string drink_and_drive() const  { return "dead"; }

    int get_age() const { return person.age; }
    void set_age(int age) { person.age = age; }


private:
    Person person;
};


int main()
{
    Person* a = new Person(15);
    ResponsiblePerson* b = new ResponsiblePerson(*a);
    cout << a->drive() << endl;
    cout << b->drink() << endl;
}
