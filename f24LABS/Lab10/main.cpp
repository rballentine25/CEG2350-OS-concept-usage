#include "utility.h"

/* main function runs the program. it creates a new todolist object, then 
 * calls TodoList's run method, which is the driver method (calls all other 
 * methods on the Todolist). 
 * 	Returns : int to specify program status. 0 for successful execution
 * 	Params : n/a
 */
int main() {
    TodoList todoList;
    todoList.run();
    return 0;
}
