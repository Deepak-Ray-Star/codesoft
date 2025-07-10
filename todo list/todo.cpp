#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const string filename = "tasks.txt";

// Load tasks from file
vector<string> loadTasks() {
    vector<string> tasks;
    string line;
    ifstream file(filename);
    while (getline(file, line)) {
        tasks.push_back(line);
    }
    file.close();
    return tasks;
}

// Save tasks to file
void saveTasks(const vector<string>& tasks) {
    ofstream file(filename);
    for (const string& task : tasks) {
        file << task << endl;
    }
    file.close();
}

// Show all tasks
void showTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    cout << "\nYour To-Do List:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Add a new task
void addTask(vector<string>& tasks) {
    cout << "Enter new task: ";
    cin.ignore(); // Clear input buffer
    string task;
    getline(cin, task);
    tasks.push_back(task);
    saveTasks(tasks);
    cout << "Task added!\n";
}

// Delete a task
void deleteTask(vector<string>& tasks) {
    showTasks(tasks);
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        saveTasks(tasks);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<string> tasks = loadTasks();
    int choice;

    do {
        cout << "\n--- TO-DO LIST MENU ---\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: showTasks(tasks); break;
            case 2: addTask(tasks); break;
            case 3: deleteTask(tasks); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
