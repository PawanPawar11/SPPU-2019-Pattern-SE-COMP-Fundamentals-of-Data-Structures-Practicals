#include <iostream>
#include <string.h>

using namespace std;

class stack
{
public:
    int max;
    char st[25];
    int top;
    stack()
    {
        top = -1;
    }
    void push(char);
    char pop();
    int isempty();
    int isfull();
};
class str
{
    stack stobj;
    char inputstr[25], rev[25];

public:
    void readstr();
    void convertstr();
    void revsstr();
    void checkpal();
};

int stack::isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int stack::isfull()
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}

void stack::push(char val)
{
    if (!isfull())
    {
        top++;
        st[top] = val;
    }
    else
        cout << "\n Stack is full" << endl;
}

char stack::pop()
{
    char ch;
    if (!isempty())
    {
        ch = st[top];
        top--;
    }
    else
        cout << "\n Stack is empty!";
    return ch;
}

void str::readstr()
{
    int count = 0;
    cout << "\nEnter your string: ";
    cin.get(inputstr, 25);
}

void str::convertstr()
{
    char tempstr[25];
    int j = 0;

    for (int i = 0; inputstr[i] != '\0'; i++)
    {
        if (inputstr[i] >= 65 && inputstr[i] <= 90)
        {
            tempstr[j] = inputstr[i] + 32;
            j++;
        }
        else if (inputstr[i] >= 97 && inputstr[i] <= 122)
        {
            tempstr[j] = inputstr[i];
            j++;
        }
    }
    tempstr[j] = '\0';
    strcpy(inputstr, tempstr);
    cout << "Converted string is: " << inputstr << endl;
}

void str::revsstr()
{
    for (int i = 0; inputstr[i] != '\0'; i++)
    {
        stobj.push(inputstr[i]);
    }
    int i = 0;
    while (!stobj.isempty())
    {
        rev[i] = stobj.pop();
        i++;
    }
    rev[i] = '\0';
    cout << "Reverse string is: " << rev << endl;
}

void str::checkpal()
{
    if (strcmp(inputstr, rev) == 0)
        cout << "\nString is Palindrome \n\n";
    else
        cout << "\nString is not Palindrome\n\n";
}

int main()
{
    str obj;
    obj.readstr();
    cout << endl;
    obj.convertstr();
    cout << endl;
    obj.revsstr();
    obj.checkpal();
    return 0;
}
