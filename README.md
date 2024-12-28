# **Queue Management System for Ticketing**

**Description**  
A command-line queue management system designed for ticketing operations. This system supports standard and priority ticket management, displays ticket queues, and allows saving/loading ticket data to/from a file. It features a dynamic circular queue implementation for efficient memory usage and scalability.

---

## **Table of Contents**

1. [Features](#features)  
2. [How It Works](#how-it-works)  
3. [Installation](#installation)  
4. [Technologies Used](#technologies-used)  
5. [Future Enhancements](#future-enhancements) 

---

## **Features**

### **1. Ticket Operations**
- **Add Ticket**: Add a new ticket to the queue.  
- **Serve Ticket**: Remove and serve the ticket at the front of the queue.  
- **Priority Ticket**: Add a high-priority ticket to the front of the queue.  

### **2. Queue Management**
- **Peek**: View the next ticket to be served without removing it.  
- **Display All Tickets**: Display the list of all tickets currently in the queue.  

### **3. File Management**
- **Save to File**: Save the current queue state to a file for later use.  
- **Load from File**: Load ticket data from a file to restore the queue state.  

### **4. Dynamic Queue**
- Implements a circular queue with dynamic resizing to handle large ticket volumes efficiently.  

---

## **How It Works**

1. **Menu Options**:  
   - The program displays an intuitive menu where users can choose various operations.  

2. **Ticket Operations**:  
   - Add tickets to the queue with or without priority.  
   - Serve tickets in a FIFO (First In, First Out) manner.  

3. **File Management**:  
   - Save the queue state to a file (`queueData.txt`) with all ticket details.  
   - Reload saved queue data into the program, including ticket order, front/rear positions, and ticket count.  

4. **Dynamic Resizing**:  
   - The queue automatically expands its size when the maximum capacity is reached, ensuring seamless operation.  

---

## **Installation**

Follow these steps to set up and run the queue management system locally:

1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd TicketQueueSystem
   ```

2. Compile the program:
   ```bash
   g++ -o ticket_system main.cpp
   ```

3. Run the program:
   ```bash
   ./ticket_system
   ```

---

## **Example Menu**

```plaintext
--- Ticket Queue Management System ---
1. Add Ticket
2. Serve Ticket
3. Priority Ticket
4. Peek Next Ticket
5. Display all Tickets
6. Save Data to File
7. Load Data from File
8. Exit
Enter your choice:
```

---

## **Technologies Used**

- **Language**: C++  
- **Files**: 
  - `main.cpp` - Implements the main menu and user interactions.  
  - `queue.h` - Defines the queue operations using a dynamic circular queue.  
- **Libraries**: `<iostream>`, `<fstream>`  

---

## **Future Enhancements**

- Add support for VIP ticket categories with custom processing logic.  
- Introduce real-time queue monitoring using graphical output.  
- Integrate a timer to measure average ticket processing time.  
- Implement database storage for ticket data instead of flat files.  

---
