// array_of_structure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct student
    {
        int roll;
        char name[25];
        float marks;
    };

    int n, i = 0;
    struct student *ptr, s;
    ptr = &s;

    printf("Enter the number of students\n");
    scanf("%d", &n);

    ptr = (struct student *)malloc(n * sizeof(struct student));

    for (i = 0; i < n; i++)
    {
        printf("Enter the details of student %d\n", (i + 1));
        printf("Enter Roll No:\n");
        scanf("%d", &(ptr + i)->roll);
        printf("Enter Name:\n");
        scanf("%s", (ptr + i)->name);
        printf("Enter Marks:\n");
        scanf("%f", &(ptr + i)->marks);
    }

    for (i = 0; i < n; i++)
    {
        printf("The details of student %d\n", (i + 1));
        printf("Roll No: %d\n", (ptr + i)->roll);
        printf("Name: %s\n", (ptr + i)->name);
        printf("Marks: %.2f\n", (ptr + i)->marks);
    }

    return 0;
}