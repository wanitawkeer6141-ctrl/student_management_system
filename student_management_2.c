#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int age;
    char category[20];
    int roll_no;
} student;

int main()
{
    int choice;
    char search[20];
    int found;
    student s1;
    char edit_name[20];
    char delete[20];
    int roll_noo;

    FILE *panda;

    do
    {
        printf("\n===== STUDENT MENU =====\n");
        printf("1. Enter Student Details\n");
        printf("2. Search Student\n");
        printf("3.EDIT\n");
        printf("4.Delete\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            panda = fopen("lion.txt", "a");

            if (panda == NULL)
            {
                printf("Error opening file!\n");
                return 1;
            }

            printf("Enter student name: ");
            scanf("%19s", s1.name);

            do
            {
                printf("Enter student age: ");
                scanf("%d", &s1.age);

                if (s1.age <= 0)
                {
                    printf("Invalid age! Try again.\n");
                }

            } while (s1.age <= 0);

            printf("Enter category: ");
            scanf("%19s", s1.category);

            printf("Enter roll no.:  ");
            scanf("%d", &s1.roll_no);

            fprintf(panda,
                    "Name:%s Age:%d Category:%s ROLL NUMBER:%d\n",
                    s1.name,
                    s1.age,
                    s1.category,
                    s1.roll_no);

            fclose(panda);

            printf("Student record saved successfully!\n");
            break;

        case 2:
            

            panda = fopen("lion.txt", "r");

            if (panda == NULL)
            {
                printf("No records found.\n");
                break;
            }

            printf("Enter name to search: ");
            scanf("%19s", search);

            found = 0;

            while (fscanf(panda,
                          " Name:%19s Age:%d Category:%19s ROLL NUMBER:%d",
                          s1.name,
                          &s1.age,
                          s1.category,
                          &s1.roll_no) == 4)
            {
                if (strcmp(search, s1.name) == 0)
                {
                    printf("\n===== STUDENT FOUND =====\n");
                    printf("Name     : %s\n", s1.name);
                    printf("Age      : %d\n", s1.age);
                    printf("Category : %s\n", s1.category);
                    printf("ROLL NUMBER : %d\n",s1.roll_no);

                    found = 1;
                }
                else
                {
                    printf("No student found");
                    break;
                }
            }
            break;
        case 3:

            printf("Enter student name to edit: ");
            scanf("%19s", edit_name);

            FILE *panda = fopen("lion.txt", "r");
            FILE *temp = fopen("temp.txt", "w");

            while (fscanf(panda,
                          " Name:%19s Age:%d Category:%19s ROLL NUMBER:%d",
                          s1.name,
                          &s1.age,
                          s1.category,&s1.roll_no) == 4)
            {
                if (strcmp(edit_name, s1.name) == 0)
                {
                    found = 1;

                    printf("Enter new name: ");
                    scanf("%19s", s1.name);

                    printf("Enter new age: ");
                    scanf("%d", &s1.age);

                    printf("Enter new category: ");
                    scanf("%19s", s1.category);

                    printf("Enter new Roll number: ");
                    scanf("%d", &s1.roll_no);
                }

                fprintf(temp,
                        "Name:%s Age:%d Category:%s ROLL NUMBER:%d\n",
                        s1.name,
                        s1.age,
                        s1.category,s1.roll_no);
            }

            fclose(panda);
            fclose(temp);

            remove("lion.txt");
            rename("temp.txt", "lion.txt");

            if (found)
            {
                printf("Record updated successfully.\n");
            }
            else
            {
                printf("Student not found.\n");
            }
            if (found == 0)
            {
                printf("No student record found.\n");
                break;
            }

        case 4:
        {
            char delete[20];
            int found = 0;

            printf("Enter name to delete: ");
            scanf("%19s", delete);

            FILE *panda = fopen("lion.txt", "r");
            FILE *temp = fopen("temp.txt", "w");

            if (panda == NULL)
            {
                printf("File not found.\n");
                break;
            }

            while (fscanf(panda,
                          " Name:%19s Age:%d Category:%19s ROLL NUMBER:%d",
                          s1.name,
                          &s1.age,
                          s1.category,
                         &s1.roll_no) == 4)
            {
                if (strcmp(delete, s1.name) == 0)
                {
                    found = 1;
                    continue;
                }

                fprintf(temp,
                        "Name:%s Age:%d Category:%s ROLL NUMBER:%d\n",
                        s1.name,
                        s1.age,
                        s1.category,s1.roll_no);
            }

            fclose(panda);
            fclose(temp);

            remove("lion.txt");
            rename("temp.txt", "lion.txt");

            if (found)
                printf("Student deleted successfully.\n");
            else
                printf("Student not found.\n");

            break;
        }

            fclose(panda);
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}