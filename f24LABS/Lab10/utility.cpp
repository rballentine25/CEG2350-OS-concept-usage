#include "utility.h"

/* Function: TodoList()
 * default constructor for TodoList class
 * 	Returns : n/a
 * 	Params : n/a
 */
TodoList::TodoList() {}

/* Function: displayMenu
 * outputs the options menu to standard output using cout
 *	Returns : void
 * 	Params : n/a
 * */
void TodoList::displayMenu() {
    std::cout << "\n===== To-Do List Menu =====" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Mark Task as Completed" << std::endl;
    std::cout << "3. Remove Task" << std::endl;
    std::cout << "4. View To-Do List" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

/*Function: addTask
 * Adds a new task to the tasks vector. Creates a new task object and prompts
 * for user input for the task name, and initalizes the task as not completed. 
 * Outputs a completion message after task is added to task vector.
 * 	Returns : void
 * 	Params : n/a
 */
void TodoList::addTask() {
    Task newTask;
    std::cout << "Enter task name: ";
    std::getline(std::cin, newTask.name);
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added to the to-do list." << std::endl;
}

/* Function: markTaskAsCompleted
 * Creates a string for the task name and prompts user for input for the task
 * to be marked completed. creates an iterator to search vector for the input name
 * and if the iterator returned true, the task is marked as completed. otherwise, 
 * an error message is given
 * 	Returns : void
 * 	Params : n/a 
 */
void TodoList::markTaskAsCompleted() {
    std::string taskName;
    std::cout << "Enter task name to mark as completed: ";
    std::getline(std::cin, taskName);

    auto it = std::find_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.name == taskName;
    });

    if (it != tasks.end()) {
        it->completed = true;
        std::cout << "Task marked as completed." << std::endl;
    } else {
        std::cout << "Task not found in the to-do list." << std::endl;
    }
}

/* removeTask function does pretty much the same thing as markCompleted, except if 
 * the task is found it is removed from the vector instead of being marked completed. 
 * 	Returns : void
 * 	Params : none
 */
void TodoList::removeTask() {
    std::string taskName;
    std::cout << "Enter task name to remove: ";
    std::getline(std::cin, taskName);

    auto it = std::find_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.name == taskName;
    });

    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task removed from the to-do list." << std::endl;
    } else {
        std::cout << "Task not found in the to-do list." << std::endl;
    }
}

/* viewTodoList prints a header to output and iterates over the tasks vector 
 * to print all the tasks to output. this includes whether each task is marked 
 * as completed.
 * 	Returns : void
 * 	Params : n/a
 */
void TodoList::viewTodoList() {
    std::cout << "\n===== To-Do List =====" << std::endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". " << tasks[i].name << " - " << (tasks[i].completed ? "Completed" : "Not Completed") << std::endl;
    }
}

/* run is the loop function to process input. it uses a always-true while loop with 
 * a switch statement (with breaks). first calls displayMenu() to display choices, then 
 * prompts for input. next, it uses a switch statement to process user input and call
 * the corresponding methods (addTask, markAsCompleted, removeTask, viewTodoList). 
 * While loop can be exited by entering 5 as input. 
 * 	Returns : void
 * 	Params : n/a
 */
void TodoList::run() {
    int choice;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markTaskAsCompleted();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                viewTodoList();
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 5." << std::endl;
        }
    }
}
