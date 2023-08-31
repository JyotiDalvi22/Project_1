#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a task
struct Task
{
    char name[50];
    char deadline[20];
    struct Task *next;
};

// Global pointer to the first task in the list
struct Task *head = NULL;

// Function to add a task
void add_task(const char *name, const char *deadline)
{
    struct Task *new_task = (struct Task *)malloc(sizeof(struct Task));
    strcpy(new_task->name, name);
    strcpy(new_task->deadline, deadline);
    new_task->next = head;
    head = new_task;
}

// Function to display all tasks
void display_tasks()
{
    printf("Tasks:\n");
    struct Task *current = head;
    while (current != NULL)
    {
        printf("Task: %s, Deadline: %s\n", current->name, current->deadline);
        current = current->next;
    }
}

int main()
{
    int choice;
    char name[50], deadline[20];

    do
    {
        printf("\nTask Manager Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter task name: ");
            scanf("%s", name);
            printf("Enter task deadline: ");
            scanf("%s", deadline);
            add_task(name, deadline);
            printf("Task added!\n");
            break;
        case 2:
            display_tasks();
            break;
        case 3:
            printf("Exiting Task Manager.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    // Free memory (in a real application, you would need to free all allocated memory)
    struct Task *current = head;
    while (current != NULL)
    {
        struct Task *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}