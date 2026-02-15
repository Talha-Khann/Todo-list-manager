# 📝 Professional To-Do List Manager - C++

A command-line based task management system with priority levels, completion tracking, and statistics.

## ✨ Features

- **Add Tasks** - Create tasks with custom titles and priority levels
- **View All Tasks** - Display tasks in a formatted table
- **Mark Complete** - Update task status when finished
- **Remove Tasks** - Delete tasks by ID
- **Statistics Dashboard** - View completion summary
- **Priority System** - Low, Medium, High priority levels
- **Input Validation** - Handles invalid inputs safely

## 🎯 How to Use

### Running the Program

#### Windows (PowerShell/CMD)
```bash
g++ todo_manager.cpp -o todo_manager
.\todo_manager.exe
```

#### Mac/Linux
```bash
g++ todo_manager.cpp -o todo_manager
./todo_manager
```

### Menu Options
```
1. Add Task        - Create a new task with priority
2. View Tasks      - See all tasks with status
3. Mark Complete   - Update task as done
4. Remove Task     - Delete a task by ID
5. View Statistics - See completion summary
0. Exit            - Close the application
```

## 🛠️ Technical Details

### Concepts Used
- **Object-Oriented Programming (OOP)** - Classes and objects
- **Data Structures** - Vectors for dynamic storage
- **Input Validation** - Safe input handling with error checking
- **String Manipulation** - Task title management
- **Iterators** - Efficient vector traversal
- **Switch-Case** - Menu control flow

### Libraries Used
- `<iostream>` - Input/output operations
- `<vector>` - Dynamic array for task storage
- `<iomanip>` - Formatted table output
- `<limits>` - Input buffer management
- `<string>` - String data handling

### Class Structure
```
Task Class
├── id (int)
├── title (string)
├── priority (string)
└── completed (bool)

ToDoList Class
├── tasks (vector<Task>)
├── nextID (int)
├── addTask()
├── viewTasks()
├── completeTask()
├── removeTask()
└── statistics()
```

## 📊 Sample Output
```
========================================
        PROFESSIONAL TO-DO MANAGER
========================================

1. Add Task
2. View Tasks
3. Mark Task Complete
4. Remove Task
5. View Statistics
0. Exit

Select option: 2

-------------------------------------------------------------
ID   Task                     Priority    Status    
-------------------------------------------------------------
1    Complete assignment      High        Pending   
2    Buy groceries           Medium      Done      
3    Exercise                Low         Pending   

===== TASK SUMMARY =====
Total Tasks: 3
Completed : 1
Pending   : 2
```

## 🎓 Learning Outcomes

This project demonstrates:
- ✅ Clean OOP design principles
- ✅ Vector container usage
- ✅ User input validation
- ✅ Menu-driven program structure
- ✅ Professional code formatting
- ✅ Error handling techniques

## 🚀 Future Enhancements

Possible improvements:
- [ ] Save tasks to file (persistence)
- [ ] Edit existing tasks
- [ ] Sort by priority or status
- [ ] Due dates for tasks
- [ ] Search functionality
- [ ] Color-coded output

## 👨‍💻 Author

Talha Khan

## 📄 License

This project is open source and available for educational purposes.

---

⭐ If you found this helpful, please star this repository!
