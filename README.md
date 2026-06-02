# Student Record Management System

A simple **Student Record Management System** developed in **C Language** using **Structures** and **File Handling**. This project allows users to manage student records through a menu-driven interface.

## Features

* Add New Student Record
* Display All Student Records
* Search Student by Roll Number
* Update Student Information
* Delete Student Record
* Store Data Permanently Using File Handling

## Technologies Used

* C Programming Language
* Structures
* File Handling
* Functions

## Project Structure

```
Student-Record-System/
│
├── main.c
├── students.txt
└── README.md
```

## How It Works

The program stores student information including:

* Roll Number
* Name
* Marks

All records are saved in `students.txt` and can be accessed, modified, searched, or deleted through the menu options.

## Menu Options

1. Add Student
2. Display Students
3. Search Student
4. Delete Student
5. Update Student
6. Exit

## Compilation and Execution

Compile the program:

```bash
gcc main.c -o student
```

Run the program:

```bash
./student
```

For Windows:

```bash
student.exe
```

## Learning Concepts

This project demonstrates:

* Structures in C
* User Defined Functions
* File Handling (`fopen`, `fclose`, `fprintf`, `fscanf`)
* Data Management
* Menu Driven Programming

## Future Enhancements

* Grade Calculation
* Sorting Student Records
* Percentage Calculation
* Binary File Storage
* Password Protection

## Author

Developed as a learning project to practice C Programming and File Handling concepts.
