
#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student s[100];
int n = 0;

void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[n].rollNo);

    printf("Enter Name: ");
    scanf("%s", s[n].name);

    printf("Enter Marks: ");
    scanf("%f", &s[n].marks);

    n++;
    printf("Student Added Successfully!\n");
}

void displayStudents() {
    int i;

    if(n == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n===== Student Records =====\n");

    for(i = 0; i < n; i++) {
        printf("\nStudent %d", i + 1);
        printf("\nRoll No: %d", s[i].rollNo);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

void searchStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++) {
        if(s[i].rollNo == roll) {
            printf("\nStudent Found!");
            printf("\nName: %s", s[i].name);
            printf("\nMarks: %.2f\n", s[i].marks);
            found = 1;
        }
    }

    if(found == 0) {
        printf("\nStudent Not Found!\n");
    }
}

void updateStudent() {
    int roll, i;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++) {
        if(s[i].rollNo == roll) {

            printf("Enter New Name: ");
            scanf("%s", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record Updated Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

void deleteStudent() {
    int roll, i, j;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++) {
        if(s[i].rollNo == roll) {

            for(j = i; j < n - 1; j++) {
                s[j] = s[j + 1];
            }

            n--;
            printf("Record Deleted Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

void sortStudents() {
    int i, j;
    struct Student temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            if(s[i].marks < s[j].marks) {

                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("Students Sorted by Marks!\n");
}

int main() {

    int choice;

    while(1) {

        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students by Marks\n");
        printf("7. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

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
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                sortStudents();
                break;

            case 7:
                printf("Exiting Program...");
                return 0;

            default:
                printf("Invalid Choice!");
        }
    }
}
