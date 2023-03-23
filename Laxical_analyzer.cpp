#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

// Function to check if a given string is a keyword
bool isKeyword(string str)
{
    string keywords[4] = {"if", "else", "for", "while"};

    for (int i = 0; i < 4; i++)
        if (str.compare(keywords[i]) == 0)
            return true;

    return false;
}

// Function to detect syntax
void syntaxDetect(string input)
{
    // Initializing variables
    int i = 0;
    char currentChar = input[0];

    while (i < input.length())
    {
        // Check for identifier or keyword
        if (isalpha(currentChar) || currentChar == '_')
        {
            string identifier = "";
            identifier += currentChar;
            i++;

            while (isalpha(currentChar = input[i]) || isdigit(currentChar) || currentChar == '_')
            {
                identifier += currentChar;
                i++;
            }

            if (isKeyword(identifier))
                cout << identifier << " is a keyword." << endl;
            else
                cout << identifier << " is an identifier." << endl;
        }

        // Check for numerical constant
        else if (isdigit(currentChar))
        {
            string num = "";
            num += currentChar;
            i++;

            while (isdigit(currentChar = input[i]))
            {
                num += currentChar;
                i++;
            }

            cout << num << " is a numerical constant." << endl;
        }

        // Check for operators
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '%' || currentChar == '=' || currentChar == '>' || currentChar == '<' || currentChar == '!' || currentChar == '&' || currentChar == '|' || currentChar == '^' || currentChar == '~' || currentChar == '?')
        {
            string op = "";
            op += currentChar;
            i++;

            if (currentChar == '=')
            {
                if (input[i] == '=')
                {
                    op += currentChar;
                    i++;
                }
            }

            cout << op << " is an operator." << endl;
        }

        // Check for punctuation
        else if (currentChar == ',' || currentChar == ';' || currentChar == ':' || currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}' || currentChar == '[' || currentChar == ']')
        {
            string punct = "";
            punct += currentChar;
            i++;

            cout << punct << " is a punctuation symbol." << endl;
        }

        // Ignore spaces
        else if (currentChar == ' ')
            i++;

        // Invalid character
        else
        {
            cout << "Invalid character: " << currentChar << endl;
            i++;
        }

        // Get the next character
        currentChar = input[i];
    }
}

// Main function
int main()
{
    // Getting input from user
    string input;
    cout << "Enter a statement: ";
    getline(cin, input);

    // Detecting syntax
    syntaxDetect(input);

    return 0;
}
