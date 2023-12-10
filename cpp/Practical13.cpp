/*
Pizza parlour accepting maximum M orders. Orders are served basis. Order once placed cannot be cancelled.
Write a C++ program to stimulate the system using circular queue using array.
*/
#include <iostream>
#define MAX 15

using namespace std;

class Queue
{
    int Que[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = 0;
    }

    void init();
    void insert(int ch);
    int delet();
    void display();
};

void Queue::init()
{
    int i;
    for (i = 0; i < MAX; i++)
        Que[i] = 0;
}

void Queue::insert(int item)
{
    if (front == (rear + 1) % MAX)
    {
        cout << "Queue is full\n";
    }
    else
    {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;
        Que[rear] = item;
    }
}

int Queue::delet()
{
    int val;
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return 0;
    }
    val = Que[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
        front = (front + 1) % MAX;
    return val;
}

void Queue::display()
{
    int i;
    i = front;
    while (i != rear)
    {
        cout << Que[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << Que[i] << endl;
}

int main()
{
    int i, choice, item;
    char ans = 'y';
    Queue obj;
    obj.init();
    do
    {
        cout << "**********Menu*********" << endl;
        cout << "1.Place Order \n2.Deliver Order \n3.Pending Order" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter order number to be added: ";
            cin >> item;
            obj.insert(item);
            break;
        case 2:
            cout << "The following order number will be deleted: ";
            cout << obj.delet();
            break;
        case 3:
            obj.display();
            break;
        }
        cout << "Do you want to continue editing orders??" << endl;
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');

    return 0;
}