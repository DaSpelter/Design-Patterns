

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 struct WordToken
    {
        string word;
        bool capitalize;
        WordToken(string word) : word(word) { capitalize = false; }
    };
struct Sentence
{   
    vector<WordToken*> words;

    

    Sentence(const string& text)
    {
        std::string delimiter = " ";
        string s = text;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            WordToken* temp = new WordToken(token);
            words.push_back(temp);
            s.erase(0, pos + delimiter.length());
        }
        token = s.substr(0, pos);
        WordToken* temp = new WordToken(token);
        words.push_back(temp);
        s.erase(0, pos + delimiter.length());
    }

    WordToken& operator[](size_t index)
    {
        return *words[index];
    }

    string str() const
    {
        string out;
        for (auto v : words) {
            string temp = v->word;
            if (v->capitalize) {
                std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            }
            out = out + temp + " ";
        }
        return out;
    }
};

int main()
{
    Sentence sentence("Hello you little coon");
    sentence[1].capitalize = true;
    cout << sentence.str() << endl;
}
