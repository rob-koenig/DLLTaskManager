# Doubly Linked List Task Manager
---
### Overview
This project implements a task manager using a doubly linked list (DLL). The task manager allows users to add, remove, and rearrange tasks efficiently. The project includes multiple operations that manipulate tasks based on priority and duration.

### Files
- MainDLL.cpp - Contains the main function and handles user interaction.
- TaskManager.cpp/.hpp - Manages task input and provides an interface for task management.
- Task.cpp/.hpp - Defines the Task class, which represents individual tasks.
- DNode.hpp - Defines the DNode class, representing a node in the doubly linked list.
- DNode.cpp - Contains function definitions for DNode.
- DLL.hpp - Declares the DLL class, which implements the doubly linked list.
- DLL.cpp - Contains function definitions for the DLL class.

### Implementation
##### DNode Class (DNode.cpp)
- Implement constructor definitions.
#####DLL Class (DLL.cpp)
- Constructors
- Default constructor
- Copy constructor
- Task Manipulation Methods
- void push(string, int, int, int): Adds a new task to the list.
- Task* pop(): Removes and returns the first task.
- int remove(int): Removes a task based on its ID.
- void moveUp(int): Moves a task up the list.
- void moveDown(int): Moves a task down the list.
- void changePriority(int, int): Changes a task's priority.
- void listDuration(int*, int*, int): Retrieves total duration for a given priority.
- void printReverse(): Prints the task list in reverse order.
- void printList(int): Prints tasks of a specified priority.
- void addTime(int, int): Increases a task’s duration.
 -void removeTime(int, int): Decreases a task’s duration.
##### Destructor
- Properly cleans up memory allocated for the doubly linked list.

### Use
- Once downloaded, open a terminal or command prompt in the project directory.
- Compile the program using a C++ compiler:
  `g++ -o task_manager MainDLL.cpp TaskManager.cpp Task.cpp DNode.cpp DLL.cpp -std=c++11`
- Run the compiled program:
  `./task_manager`
- Modify MainDLL.cpp to change the input task file as needed.
- Follow the prompts to test the task manager functionalities.
