#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student data
struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function declarations
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();
int isDuplicate(int roll);  // New function

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Delete Student by Roll No\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to check if a roll number already exists
int isDuplicate(int roll) {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;
    char line[200];

    if (fp == NULL) return 0;

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,%[^,],%f", &s.roll, s.name, &s.marks) == 3) {
            if (s.roll == roll) {
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

// Function to add a student
void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");

    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    if (isDuplicate(s.roll)) {
        printf("Roll number already exists! Please enter a different roll number.\n");
        fclose(fp);
        return;
    }

    printf("Enter name: ");
    getchar(); // clear leftover newline
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove trailing newline

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d,%s,%.2f\n", s.roll, s.name, s.marks);
    fclose(fp);

    printf("Student record added successfully!\n");
}

// Function to view all students
void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");
    char line[200];
    int isEmpty = 1;

    if (fp == NULL) {
        printf("No student records found. File does not exist.\n");
        return;
    }

    printf("\n--- All Student Records ---\n\n");
    printf("Roll No | Name                      | Marks\n");
    printf("--------|---------------------------|--------\n");

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,%[^,],%f", &s.roll, s.name, &s.marks) == 3) {
            isEmpty = 0;
            printf("%-8d| %-26s| %.2f\n", s.roll, s.name, s.marks);
        }
    }

    if (isEmpty) {
        printf("No records to display.\n");
    }

    fclose(fp);
}

// Function to search a student by roll number
void searchStudent() {
    struct Student s;
    int roll, found = 0;
    char line[200];

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,%[^,],%f", &s.roll, s.name, &s.marks) == 3) {
            if (s.roll == roll) {
                printf("\nStudent Found:\n");
                printf("Roll No: %d\n", s.roll);
                printf("Name   : %s\n", s.name);
                printf("Marks  : %.2f\n", s.marks);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

// Function to delete a student by roll number
void deleteStudent() {
    struct Student s;
    int roll, found = 0;
    char line[200];

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,%[^,],%f", &s.roll, s.name, &s.marks) == 3) {
            if (s.roll == roll) {
                found = 1;
                continue; // skip this line (i.e., delete)
            } else {
                fprintf(temp, "%d,%s,%.2f\n", s.roll, s.name, s.marks);
            }
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student record deleted successfully.\n");
    else
        printf("Student not found.\n");
}
