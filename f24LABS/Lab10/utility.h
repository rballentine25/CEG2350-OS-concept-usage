#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <vector>
#include <algorithm>

/* struct is like a simpler version of a class? more of a data group
 * than an object. Here Task is defined as a struct with two variables, 
 * string for the name and a bool for completion status. 
 * 	No returns or params since not really a method*/
struct Task {
    std::string name;
    bool completed;
};

/* class Todolist defines the Todolist object class. it has just one private field
 * for the vector of tasks. it also includes method headers for the Todo list 
 * constructor, and all member methods called in run() and main().  */
class TodoList {
private:
    std::vector<Task> tasks;

public:
    TodoList(); // Constructor
    void displayMenu();
    void addTask();
    void markTaskAsCompleted();
    void removeTask();
    void viewTodoList();
    void run();
};

#endif // TODOLIST_H
