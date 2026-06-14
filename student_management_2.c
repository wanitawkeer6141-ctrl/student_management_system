#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    int password = 3327;
    int entered_password;
    int found;

    student s1;
    char search[20];
    char edit_name[20];
    char delete_name[20];

    FILE *fp, *temp;

    printf("ENTER PASSWORD: ");
    scanf("%d", &entered_password);

    if (entered_password != password)
    {
        printf("Invalid Password!\n");
        return 0;
    }

    do
    {
        printf("\n========== STUDENT MANAGEMENT ==========\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. View All Students\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            fp = fopen("students.txt", "a");

            if (fp == NULL)
            {
                printf("Error opening file!\n");
                break;
            }

            while (1)
            {
                int valid = 1;

                printf("Enter Name: ");
                scanf("%19s", s1.name);

                for (int i = 0; s1.name[i] != '\0'; i++)
                {
                    if (isdigit(s1.name[i]))
                    {
                        valid = 0;
                        break;
                    }
                }

                if (valid)
                    break;

                printf("Invalid name! Numbers not allowed.\n");
            }

            do
            {
                printf("Enter Age: ");
                scanf("%d", &s1.age);

                if (s1.age <= 0)
                    printf("Invalid age!\n");

            } while (s1.age <= 0);

            printf("Enter Category: ");
            scanf("%19s", s1.category);
            kya_banii:
            printf("Enter Roll Number: ");
            scanf("%d", &s1.roll_no);

            FILE *info;
            student temp;
            int duplicate = 0;

            info = fopen("students.txt", "r");

            if (info != NULL)
            {
                while (fscanf(info,
                              "%19s %d %19s %d",
                              temp.name,
                              &temp.age,
                              temp.category,
                              &temp.roll_no) == 4)
                {
                    if (temp.roll_no == s1.roll_no)
                    {
                        duplicate = 1;
                        break;
                    }
                }

                fclose(info);
            }

            if (duplicate)
            {
                printf("Roll Number already exists!\n");
                goto kya_banii;
                fclose(fp);
                break;
            }

            fprintf(fp,
                    "%s %d %s %d\n",
                    s1.name,
                    s1.age,
                    s1.category,
                    s1.roll_no);

            fclose(fp);

            printf("Student Added Successfully!\n");
        }break;

        case 2:
        {
            fp = fopen("students.txt", "r");

            if (fp == NULL)
            {
                printf("No records found.\n");
                break;
            }

            printf("Enter Name to Search: ");
            scanf("%19s", search);

            found = 0;

            while (fscanf(fp,
                          "%19s %d %19s %d",
                          s1.name,
                          &s1.age,
                          s1.category,
                          &s1.roll_no) == 4)
            {
                if (strcmp(search, s1.name) == 0)
                {
                    printf("\nStudent Found\n");
                    printf("Name: %s\n", s1.name);
                    printf("Age: %d\n", s1.age);
                    printf("Category: %s\n", s1.category);
                    printf("Roll No: %d\n", s1.roll_no);

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Student not found.\n");

            fclose(fp);
            break;
        }

        case 3:
        {
            fp = fopen("students.txt", "r");
            temp = fopen("temp.txt", "w");

            if (fp == NULL)
            {
                printf("No records found.\n");
                break;
            }

            printf("Enter Student Name to Edit: ");
            scanf("%19s", edit_name);

            found = 0;

            while (fscanf(fp,
                          "%19s %d %19s %d",
                          s1.name,
                          &s1.age,
                          s1.category,
                          &s1.roll_no) == 4)
            {
                if (strcmp(edit_name, s1.name) == 0)
                {
                    found = 1;

                    printf("Enter New Name: ");
                    scanf("%19s", s1.name);

                    printf("Enter New Age: ");
                    scanf("%d", &s1.age);

                    printf("Enter New Category: ");
                    scanf("%19s", s1.category);

                    printf("Enter New Roll Number: ");
                    scanf("%d", &s1.roll_no);
                }

                fprintf(temp,
                        "%s %d %s %d\n",
                        s1.name,
                        s1.age,
                        s1.category,
                        s1.roll_no);
            }

            fclose(fp);
            fclose(temp);

            remove("students.txt");
            rename("temp.txt", "students.txt");

            if (found)
                printf("Record Updated Successfully!\n");
            else
                printf("Student Not Found.\n");

            break;
        }
        case 4:
        {

            fp = fopen("students.txt", "r");
            temp = fopen("temp.txt", "w");

            int correct_password = 3327;

        eye:
            printf("ENTER THE PASSWORD: ");
            if (scanf("%d", &entered_password) != 1)
            {
                printf("password show be in digit\n");
                while (getchar() != '\n')
                    ;
                goto eye;
            }

            if (entered_password != correct_password)
            {
                printf("Invalid Password\n");
                goto eye;
            }

            printf("Enter Student Name to Delete: \n");
            scanf("%19s", delete_name);

            found = 0;

            while (fscanf(fp, "%19s %d %19s %d",
                          s1.name,
                          &s1.age,
                          s1.category,
                          &s1.roll_no) == 4)
            {
                if (strcmp(delete_name, s1.name) == 0)
                {
                    found = 1;
                    continue;
                }

                fprintf(temp, "%s %d %s %d\n",
                        s1.name,
                        s1.age,
                        s1.category,
                        s1.roll_no);
            }

            fclose(fp);
            fclose(temp);

            remove("students.txt");
            rename("temp.txt", "students.txt");

            if (found)
                printf("Student Deleted Successfully!\n");
            else
                printf("Student Not Found.\n");
        }
        break;

        case 5:
        {
            fp = fopen("students.txt", "r");

            if (fp == NULL)
            {
                printf("No records found.\n");
                break;
            }

            printf("\n===== ALL STUDENTS =====\n");

            while (fscanf(fp,
                          "%19s %d %19s %d",
                          s1.name,
                          &s1.age,
                          s1.category,
                          &s1.roll_no) == 4)
            {
                printf("\nName      : %s", s1.name);
                printf("\nAge       : %d", s1.age);
                printf("\nCategory  : %s", s1.category);
                printf("\nRoll No   : %d\n", s1.roll_no);
            }

            fclose(fp);
            break;
        }

        case 6:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 6);

    return 0;
}