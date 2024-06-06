#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks allowed

int main() {
  string tasks[MAX_TASKS]; // Array to store tasks
  int numTasks = 0; // Number of tasks currently added

  int choice;

  do {
    cout << "\nTo-Do List Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Remove Task" << endl;
    cout << "3. Display Tasks" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        if (numTasks == MAX_TASKS) {
          cout << "Task list is full!" << endl;
        } else {
          string description;
          cout << "Enter task description: ";
          cin.ignore();
          getline(cin, description); // Use getline to handle spaces
          tasks[numTasks++] = description;
          cout << "Task added successfully!" << endl;
        }
        break;
      case 2:
        if (numTasks == 0) {
          cout << "No tasks to remove!" << endl;
        } else {
          int index;
          cout << "\nEnter the index of the task to remove (0-" << numTasks - 1 << "): ";
          cin >> index;

          if (index >= 0 && index < numTasks) {
            // Shift tasks to remove the selected one
            for (int i = index; i < numTasks - 1; i++) {
              tasks[i] = tasks[i + 1];
            }
            numTasks--;
            cout << "Task removed successfully!" << endl;
          } else {
            cout << "Invalid task index!" << endl;
          }
        }
        break;
      case 3:
        if (numTasks == 0) {
          cout << "No tasks to display!" << endl;
        } else {
          cout << "\nTask List:\n";
          for (int i = 0; i < numTasks; i++) {
            cout << i+1 << ". " << tasks[i] << endl;
          }
        }
        break;
      case 4:
        cout << "Exiting program..." << endl;
        break;
      default:
        cout << "Invalid choice!" << endl;
    }
  } while (choice != 4);

  return 0;
}
