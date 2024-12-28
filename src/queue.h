#include <iostream>
#include <fstream>
using namespace std;

class Queue
{
private:
    int *queue;
    int size;
    int front;
    int rear;
    int capacity;
    int count;
    
    void regrow()
    {
        int newCapacity = capacity * 2;
        int *newQueue = new int[newCapacity];
        
        for (int i = 0; i < size; i++)
        {
            newQueue[i] = queue[(front + i) % capacity];
        }
        
        delete[] queue;
        queue = newQueue;
        front = 0;
        rear = size - 1;
        capacity = newCapacity;
    }
    
public:
    Queue(int initialCapacity = 5)
    {
        capacity = initialCapacity;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
        count = 1;
    }
    
    ~Queue()
    {
        delete[] queue;
    }
    
    void enqueue()
    {
        if (size == capacity)
        {
            regrow();
        }
        rear = (rear + 1) % capacity;
        queue[rear] = count++;
        size++;
        cout << "Ticket " << queue[rear] << " added" << endl;
    }
    
    void priorityEnqueue()
    {
        if (size == capacity)
        {
            regrow();
        }
        front = (front == 0) ? capacity - 1 : front - 1;
        queue[front] = count++;
        size++;
        cout << "Priority ticket " << queue[front] << " added" << endl;
    }
    
    void dequeue()
    {
        if (size == 0)
        {
            cout << "No ticket to serve" << endl;
            return;
        }
        cout << "Ticket " << queue[front] << " served" << endl;
        front = (front + 1) % capacity;
        size--;
    }
    
    void peek()
    {
        if (size == 0)
        {
            cout << "No ticket to display" << endl;
            return;
        }
        cout << "Next ticket: " << queue[front] << endl;
    }
    
    void display()
    {
        if (size == 0)
        {
            cout << "No tickets" << endl;
            return;
        }
        cout << "All tickets: ";
        for (int i = 0; i < size; i++)
        {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
    
    void saveToFile(const string &filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Error saving to file" << endl;
            return;
        }
        
        file << size << " " << front << " " << rear << " " << count << endl;
        for (int i = 0; i < size; i++)
        {
            file << queue[(front + i) % capacity] << " ";
        }
        file.close();
        cout << "Data saved to file: " << filename << endl;
    }
    
    void loadFromFile(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "File does not exist" << endl;
            return;
        }
        
        int newSize, newFront, newRear, newCount;
        file >> newSize >> newFront >> newRear >> newCount;
        
        if (newSize > capacity)
        {
            delete[] queue;
            capacity = newSize;
            queue = new int[capacity];
        }
        
        size = newSize;
        front = newFront;
        rear = newRear;
        count = newCount;
        
        for (int i = 0; i < size; i++)
        {
            file >> queue[(front + i) % capacity];
        }
        file.close();
        cout << "Data loaded from file: " << filename << endl;
    }
};
