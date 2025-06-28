# Mini-Project
# 📝 Student Record Management System in C

This is a simple **mini project** in C that allows you to manage student records using a file-based system. It is a menu-driven console application that lets the user add, view, search, and delete student data stored in a text file.

---

## 🚀 Features

- ✅ Add student records (roll number, name, marks)
- 📃 View all student records in a formatted table
- 🔍 Search for a student by roll number
- 🗑️ Delete a student record by roll number
- 🛡️ Prevents duplicate roll number entries
- 📂 File I/O based storage (`students.txt`)

---

## 📁 File Structure

- `students.txt`: Stores all student records in comma-separated format
- `main.c` (or `student_management.c`): Contains the full program logic

---

## 📦 How to Compile & Run

```bash
# Compile
gcc student_management.c -o student_mgmt

# Run
./student_mgmt

---
## 🛠 Functions Used

| Function Name     | Purpose                       |
| ----------------- | ----------------------------- |
| `addStudent()`    | Adds a new student to file    |
| `viewStudents()`  | Displays all student records  |
| `searchStudent()` | Searches by roll number       |
| `deleteStudent()` | Deletes record by roll number |
| `isDuplicate()`   | Checks for duplicate roll no. |

---
## 📚 Topics Covered

- ✅ **C Structures**
- ✅ **File Handling (Text File)**
- ✅ **Menu-Driven Programming**
- ✅ **String Parsing with `sscanf`**
- ✅ **Looping and Conditionals**
---

