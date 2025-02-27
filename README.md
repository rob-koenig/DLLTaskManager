# Doubly Linked List Task Manager

Overview

This project implements a task manager using a doubly linked list (DLL). The task manager allows users to add, remove, and rearrange tasks efficiently. The project includes multiple operations that manipulate tasks based on priority and duration.

Files

Provided Files

MainDLL.cpp - Contains the main function and handles user interaction.

TaskManager.cpp/.hpp - Manages task input and provides an interface for task management.

Task.cpp/.hpp - Defines the Task class, which represents individual tasks.

DNode.hpp - Defines the DNode class, representing a node in the doubly linked list.

DNode.cpp - Contains function definitions for DNode (to be implemented by the user).

DLL.hpp - Declares the DLL class, which implements the doubly linked list.

DLL.cpp - Contains function definitions for the DLL class (to be implemented by the user).

Example Task Files - Two example task lists for testing purposes.

Implementations Required

DNode Class (DNode.cpp)

Implement constructor definitions.

DLL Class (DLL.cpp)

Constructors

Default constructor

Copy constructor

Task Manipulation Methods

void push(string, int, int, int): Adds a new task to the list.

Task* pop(): Removes and returns the first task.

int remove(int): Removes a task based on its ID.

void moveUp(int): Moves a task up the list.

void moveDown(int): Moves a task down the list.

void changePriority(int, int): Changes a task's priority.

void listDuration(int*, int*, int): Retrieves total duration for a given priority.

void printReverse(): Prints the task list in reverse order.

void printList(int): Prints tasks of a specified priority.

void addTime(int, int): Increases a task’s duration.

void removeTime(int, int): Decreases a task’s duration.

Destructor

Properly cleans up memory allocated for the doubly linked list.

Testing and Validation

Steps for Testing

Add at least two tasks and print after each addition.

Remove at least two tasks and print after each removal.

Move tasks up multiple times, ensuring:

One case where priority changes.

One case where the first task moves to the end.

Move tasks down multiple times, ensuring:

One case where priority changes.

One case where the last task moves to the top.

Retrieve total duration for a specified priority.

Print tasks of a specific priority.

Change a task’s priority and verify the update.

Print the list in reverse order to verify the prev pointers.

Testing Output Comparison

Compare program output to provided sample test outputs.

Use CLion’s built-in “Compare to Clipboard” feature or external diff tools like diff or WINDIFF.

Submission Guidelines

Submit all provided and modified files excluding the original ZIP file.

Ensure code follows best practices:

Include both contributors’ names in comments.

Use meaningful variable names.

Maintain consistent indentation and spacing.

The code will be graded based on:

75 points for implementation.

9 points for code quality.

16 points for execution and test case correctness.

Notes

Do not modify function headers.

The TaskManager class handles file input.

Ensure proper memory management to avoid leaks.

Test thoroughly before submission to pass the autograder.
