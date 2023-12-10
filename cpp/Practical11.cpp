/*Write functions to add job and delete job from queue*/
#include <iostream>
#define MAX 10

class Queue
{
    int data[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return rear == MAX - 1;
    }

    void enqueue(int x)
    {
        if (!isFull())
        {
            data[++rear] = x;
        }
        else
        {
            std::cout << "Queue is overflow!!!" << std::endl;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            return data[++front];
        }
        else
        {
            std::cout << "Queue is underflow!!!" << std::endl;
            return -1; // Signifies an invalid dequeue
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            std::cout << "\nQueue contains: ";
            for (int i = front + 1; i <= rear; ++i)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "\nQueue is empty!" << std::endl;
        }
    }
};

int main()
{
    Queue obj;
    int ch, x;

    do
    {
        std::cout << "\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\nEnter your choice: ";
        std::cin >> ch;

        switch (ch)
        {
        case 1:
            std::cout << "\nEnter data: ";
            std::cin >> x;
            obj.enqueue(x);
            break;

        case 2:
            std::cout << "\nDeleted Element = " << obj.dequeue() << std::endl;
            obj.display();
            break;

        case 3:
            obj.display();
            break;

        case 4:
            std::cout << "\nExiting Program....." << std::endl;
            break;

        default:
            std::cout << "\nInvalid choice!" << std::endl;
            break;
        }
    } while (ch != 4);

    return 0;
}
