#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isKeyword(string word)
{
    string keywords[] = {"int", "float", "double", "char", "if", "else",
                         "while", "for", "return", "void", "main", "cout"};

    for (int i = 0; i < 12; i++)
    {
        if (word == keywords[i])
            return true;
    }
    return false;
}

bool isOperator(string word)
{
    string operators[] = {"+", "-", "*", "/", "=", "==", "<", ">", "<<", ">>"};

    for (int i = 0; i < 10; i++)
    {
        if (word == operators[i])
            return true;
    }
    return false;
}

bool isPunctuation(string word)
{
    string punctuation[] = {"(", ")", "{", "}", ";", ","};

    for (int i = 0; i < 6; i++)
    {
        if (word == punctuation[i])
            return true;
    }
    return false;
}

bool isNumber(string word)
{
    if (word.empty())
        return false;

    for (int i = 0; i < word.length(); i++)
    {
        if (!isdigit(word[i]))
            return false;
    }
    return true;
}

bool isIdentifier(string word)
{
    if (word.empty())
        return false;

    if (!isalpha(word[0]) && word[0] != '_')
        return false;

    for (int i = 1; i < word.length(); i++)
    {
        if (!isalnum(word[i]) && word[i] != '_')
            return false;
    }

    if (isKeyword(word))
        return false;

    return true;
}

bool isQuote(string word)
{
    return word == "\"";
}

string readStringConstant(ifstream &file)
{
    string token;
    string str = "\"";

    while (file >> token)
    {
        if (token == "\"")
        {
            str += "\"";
            break;
        }
        str += " " + token;
    }

    return str;
}

void classifyToken(string token)
{
    if (isKeyword(token))
        cout << token << " : Keyword" << endl;

    else if (isOperator(token))
        cout << token << " : Operator" << endl;

    else if (isPunctuation(token))
        cout << token << " : Punctuation" << endl;

    else if (isNumber(token))
        cout << token << " : Number" << endl;

    else if (isIdentifier(token))
        cout << token << " : Identifier" << endl;

    else
        cout << token << " : Unknown" << endl;
}

int main()
{
    ifstream file("myFile.txt");

    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string token;

    while (file >> token)
    {
        if (isQuote(token))
        {
            string str = readStringConstant(file);
            cout << str << " : String Constant" << endl;
        }
        else
        {
            classifyToken(token);
        }
    }

    file.close();
    return 0;
}
