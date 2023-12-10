#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    string Name;
    int PRN;
    struct node *next;
};

class List
{
    struct node *head, *temp;

public:
    List()
    {
        head = NULL;
    }
    struct node *Create(int val, string n);
    void insertEnd();
    void insertBeg();
    int insertAt(int i);
    int deleteFirst();
    int deleteLast();
    int deleteAt(int i);
    int display();
    int count();
};

node *List::Create(int val, string n)
{
    temp = new (struct node);
    if (temp == NULL)
    {
        cout << "Memory Alloc. Failed!" << endl;
        return NULL;
    }
    else
    {
        temp->PRN = val;
        temp->Name = n;
        temp->next = NULL;
        return temp;
    }
}

void List::insertEnd()
{
    string n;
    int val;
    cout << "Enter Name of Secretary: ";
    cin >> n;
    cout << "Enter PRN: ";
    cin >> val;
    temp = Create(val, n);
    node *t = head;
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
        }
        temp->next = NULL;
        t->next = temp;
        cout << "Element Inserted at End!" << endl;
    }
}

void List::insertBeg()
{
    string n;
    int val;
    cout << "Enter Name of President: ";
    cin >> n;
    cout << "Enter PRN: ";
    cin >> val;
    temp = Create(val, n);
    node *t = head;
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
        cout << "We have a new President!" << endl;
    }
}

int List::count()
{
    temp = head;
    int ct = 0;
    while (temp != NULL)
    {
        ct++;
        temp = temp->next;
    }
    cout << "Count= " << ct << endl;
    return ct;
}
int List::insertAt(int i)
{
    int ct = count();
    int val;
    string n;
    if (i <= 0 || i > ct + 2)
    {
        cout << "You have enterd an Invalid Position!";
        return -1;
    }
    else
    {
        if (i == 1)
            insertBeg();
        else if (i == ct + 1)
            insertEnd();
        else
        {
            cout << "Enter Name: ";
            cin >> n;
            cout << "Enter PRN: ";
            cin >> val;
            temp = Create(val, n);
            struct node *t = head;
            while (i - 2)
            {
                t = t->next;
                i--;
            }
            temp->next = t->next;
            t->next = temp;
        }
        return 0;
    }
}

int List::display()
{
    struct node *t = head;
    if (head == NULL)
    {
        cout << "No Pinnacle Club found! :(";
        return -1;
    }
    else
    {
        while (t->next != NULL)
        {
            cout << "Name=> " << t->Name << "\nPRN=> " << t->PRN << endl;
            t = t->next;
        }
        cout << "Name=> " << t->Name << "\nPRN=> " << t->PRN << endl;
    }
    return 0;
}

int List::deleteFirst()
{
    if (head == NULL)
    {
        cout << "Nothing to delete!";
        return -1;
    }
    else
    {
        struct node *t = head;
        head = t->next;
        delete t;
        return 0;
    }
}

int List::deleteLast()
{
    int ct = count();
    if (head == NULL)
    {
        cout << "Nothing to delete!";
        return -1;
    }
    else if (ct == 1)
    {
        delete head;
        head = NULL;
        return 0;
    }
    else
    {
        struct node *t = head;
        while (t->next->next != NULL)
        {
            t = t->next;
        }
        delete t->next;
        t->next = NULL;
        return 0;
    }
}

int List::deleteAt(int i)
{
    int ct = count();
    if (i <= 0 || i >= ct + 2)
    {
        cout << "Please enter correct choice!";
        return -1;
    }
    else if (head == NULL)
    {
        cout << "Linked List is empty!";
        return -1;
    }
    else
    {
        if (i == 1)
        {
            deleteFirst();
        }
        else if (i == ct)
        {
            deleteLast();
        }
        else
        {
            struct node *t = head;
            while (i - 2)
            {
                t = t->next;
                i--;
            }
            struct node *t2 = t->next;
            t->next = t->next->next;
            delete (t2);
        }
        return 0;
    }
}

int main()
{
    char ch;
    List l;
    int ct = l.count();
    do
    {
        cout << "1. Insert President\n2. Insert Secretary\n3.Insert A Member\n4.Display Data\n5.Delete President\n6.Delete Secretary\n7.Delete Member\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            l.insertBeg();
            break;
        case 2:
            l.insertEnd();
            break;
        case 3:
        {
            int i;
            cout << "Enter the position to add: ";
            cin >> i;
            l.insertAt(i);
        }
        break;
        case 4:
            l.display();
            break;
        case 5:
            l.deleteFirst();
            break;
        case 6:
            l.deleteLast();
            break;
        case 7:
        {
            int i;
            cout << "Enter the position to Delete Member: ";
            cin >> i;

            l.deleteAt(i);
        }
        break;
        case 8:
            l.count();
            break;
        default:
            cout << "Invalid Input!";
            break;
        }
        cout << "Do you want to continue?\n";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}