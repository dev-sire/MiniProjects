#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    string dueDate;
};
vector<Task> tasks; 
// Function prototypes
void addTask();
void removeTask();
void viewTasks();

int main() {
    int choice;
    do {
        cout << "\nTo-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                viewTasks();
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
void addTask() {
    Task newTask;
    cout << "Enter task name: ";
    getline(cin, newTask.name); 
    cout << "Enter due date (YYYY-MM-DD): ";
    getline(cin, newTask.dueDate);
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}
void removeTask() {
    if (tasks.empty()) {
        cout << "No tasks to remove!" << endl;
        return;
    }
    int taskIndex;
    cout << "Enter the index of the task to remove (0-" << tasks.size() - 1 << "): ";
    cin >> taskIndex;
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks to display!" << endl;
        return;
    }
    cout << "\nTask List:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << "Task " << i << ": " << tasks[i].name << " (Due: " << tasks[i].dueDate << ")" << endl;
    }
}