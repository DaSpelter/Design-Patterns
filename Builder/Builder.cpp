// Builder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ostream>
#include <vector>
using namespace std;

class CodeBuilder
{
public:
    string class_name;
    vector<pair<string, string>> fields;
    CodeBuilder(const string& class_name): class_name{class_name}
    {
        // todo
        //CodeBuilder
    }

    CodeBuilder& add_field(const string& name, const string& type)
    {
        fields.emplace_back(make_pair(name, type));
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        // todo
        os << "class " << obj.class_name << endl;
        os << "{" << endl;
        
        if (obj.fields.size() > 0) {
            for (const auto& f : obj.fields) {
                os <<"    "<< f.second << " " << f.first << ";"<<endl;

            }

        }
        os << "};" << endl;
        return os;

        

    }
};

int main()
{
    auto cb = CodeBuilder{ "Person" }.add_field("name", "string").add_field("age", "int");
    cout <<  cb;
}
