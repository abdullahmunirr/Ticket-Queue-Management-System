#include "queue.h"

int main()
{
    Queue ticketQueue;
    
    while (true)
    {
        cout << endl << "--- Ticket Queue Management System ---" << endl;
        cout << "1. Add Ticket" << endl;
        cout << "2. Serve Ticket" << endl;
        cout << "3. Priority Ticket" << endl;
        cout << "4. Peek Next Ticket" << endl;
        cout << "5. Display all Tickets" << endl;
        cout << "6. Save Data to File" << endl;
        cout << "7. Load Data from File" << endl;
        cout << "8. Exit" << endl;
        
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        
        if (cin.fail() || choice < 1 || choice > 8)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter a number between 1 and 8" << endl;
            continue;
        }
        
        switch (choice)
        {
            case 1:
                ticketQueue.enqueue();
                break;
            case 2:
                ticketQueue.dequeue();
                break;
            case 3:
                ticketQueue.priorityEnqueue();
                break;
            case 4:
                ticketQueue.peek();
                break;
            case 5:
                ticketQueue.display();
                break;
            case 6:
                ticketQueue.saveToFile("queueData.txt");
                break;
            case 7:
                ticketQueue.loadFromFile("queueData.txt");
                break;
            case 8:
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
