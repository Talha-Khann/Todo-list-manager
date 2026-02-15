#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

// Core task structure storing all task information
class Task {
public:
    int id;
    string title;
    string priority;
    bool completed;

    Task(int i, string t, string p) {
        id = i;
        title = t;
        priority = p;
        completed = false;
    }
};

// Main manager handling all to-do operations
class ToDoList {
private:
    vector<Task> tasks;
    int nextID = 1;

    // Safe integer input helper
    int safeInput() {
        int value;
        cin >> value;

        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter number again: ";
            cin >> value;
        }

        return value;
    }

public:

    void header() {
        cout << "\n========================================\n";
        cout << "        PROFESSIONAL TO-DO MANAGER\n";
        cout << "========================================\n";
    }

    void addTask() {
        string title;
        int choice;
        string priority;

        cout << "\nEnter task title: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, title);

        cout << "Priority (1=Low, 2=Medium, 3=High): ";
        choice = safeInput();

        if(choice == 1) priority = "Low";
        else if(choice == 2) priority = "Medium";
        else priority = "High";

        tasks.push_back(Task(nextID++, title, priority));
        cout << "\nTask added successfully.\n";
    }

    void viewTasks() {
        if(tasks.empty()) {
            cout << "\nNo tasks available.\n";
            return;
        }

        cout << "\n-------------------------------------------------------------\n";
        cout << left << setw(5) << "ID"
             << setw(25) << "Task"
             << setw(12) << "Priority"
             << setw(10) << "Status\n";
        cout << "-------------------------------------------------------------\n";

        for(auto &t : tasks) {
            cout << left << setw(5) << t.id
                 << setw(25) << t.title
                 << setw(12) << t.priority
                 << setw(10) << (t.completed ? "Done" : "Pending") << "\n";
        }
    }

    void completeTask() {
        cout << "\nEnter task ID to mark complete: ";
        int id = safeInput();

        for(auto &t : tasks) {
            if(t.id == id) {
                t.completed = true;
                cout << "Task marked as completed.\n";
                return;
            }
        }

        cout << "Task not found.\n";
    }

    void removeTask() {
        cout << "\nEnter task ID to remove: ";
        int id = safeInput();

        for(auto it = tasks.begin(); it != tasks.end(); ++it) {
            if(it->id == id) {
                tasks.erase(it);
                cout << "Task removed successfully.\n";
                return;
            }
        }

        cout << "Task not found.\n";
    }

    void statistics() {
        int done = 0;

        for(auto &t : tasks)
            if(t.completed) done++;

        cout << "\n===== TASK SUMMARY =====\n";
        cout << "Total Tasks: " << tasks.size() << endl;
        cout << "Completed : " << done << endl;
        cout << "Pending   : " << tasks.size() - done << endl;
    }
};

// Program control loop with safe input handling
int main() {
    ToDoList app;
    int choice;

    do {
        app.header();

        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Mark Task Complete";
        cout << "\n4. Remove Task";
        cout << "\n5. View Statistics";
        cout << "\n0. Exit";

        cout << "\n\nSelect option: ";
        cin >> choice;

        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter number: ";
            cin >> choice;
        }

        switch(choice) {
            case 1: app.addTask(); break;
            case 2: app.viewTasks(); break;
            case 3: app.completeTask(); break;
            case 4: app.removeTask(); break;
            case 5: app.statistics(); break;
            case 0: cout << "\nExiting safely... Goodbye!\n"; break;
            default: cout << "\nInvalid choice.\n";
        }

    } while(choice != 0);

    return 0;
}
