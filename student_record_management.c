#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");

    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    getchar(); // buffer clear

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);  

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %.2f\n", s.rollNo, s.name, s.marks);

    fclose(fp);
    printf("\nStudent Record Added Successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (fscanf(fp, "%d %s %f", &s.rollNo, s.name, &s.marks) != EOF) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n",
               s.rollNo, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    int roll;
    struct Student s;
    int found = 0;

    FILE *fp = fopen("students.txt", "r");

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d %s %f", &s.rollNo, s.name, &s.marks) != EOF) {
        if (s.rollNo == roll) {
            printf("\nRecord Found\n");
            printf("Roll No: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nRecord Not Found!\n");

    fclose(fp);
}

void deleteStudent()
{
    int roll, found = 0;
    struct Student s;

    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d %s %f",
           &s.rollNo, s.name, &s.marks) != EOF)
    {
        if (s.rollNo != roll)
        {
            fprintf(temp, "%d %s %.2f\n",
                    s.rollNo, s.name, s.marks);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        printf("\nRecord Deleted Successfully!\n");
    else
        printf("\nRecord Not Found!\n");
}

void updateStudent()
{
    int roll, found = 0;
    struct Student s;

    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d %s %f",
           &s.rollNo, s.name, &s.marks) != EOF)
    {
        if (s.rollNo == roll)
        {
            printf("Enter New Name: ");
            scanf("%s", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            found = 1;
        }

        fprintf(temp, "%d %s %.2f\n",
                s.rollNo, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        printf("\nRecord Updated Successfully!\n");
    else
        printf("\nRecord Not Found!\n");
}
int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update student\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                updateStudent();
                break;

            case 6:
                printf("Thank you!\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
