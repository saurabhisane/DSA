#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct penacle
{
    int prn;
    char name[20];
    struct penacle *next;
};

struct penacle *Insert_Members(struct penacle *head)
{
    if (head == NULL)
        return head;
    printf("\n*****************************************************  Insert At Begining    *****************************************************************************************\n");
    struct penacle *temp, *p;
    temp = (struct penacle *)malloc(sizeof(struct penacle));
    printf("Enter the PRN of the Member.....!!!!\n");
    scanf("%d", &temp->prn);
    printf("Enter the Name of the member...!!\n");
    scanf("%s", temp->name);
    p = head;
    temp->next = head->next;
    head->next = temp;
    head = p;
    display(head);
    return head;
}

struct penacle *Delete_president(struct penacle *head)
{
    if (head == NULL)
        return head;
    printf("\n*****************************************************  President Deleted    *****************************************************************************************\n");
    struct penacle *p;
    p = head;
    head = head->next;
    free(p);
    return head;
}

struct penacle *Delete_secretary(struct penacle *head)
{
    if (head == NULL)
        return head;
    printf("\n*****************************************************  President Secretary    *****************************************************************************************\n");
    struct penacle *p, *q;
    p = head;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

struct penacle *Delete_Member(struct penacle *head, int data)
{
    if (head == NULL)
        return head;
    printf("\n*****************************************************  President Member    *****************************************************************************************\n");
    printf("Given Member Deleted\n");
    struct penacle *p, *q;

    p = head;
    while (p->prn != data)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    return head;
}
int display_Total_no_of_Members(struct penacle *head)
{
    int count = 0;
    if (head == NULL)
        return count;
    printf("\n*****************************************************  President Member    *****************************************************************************************\n");

    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
void display(struct penacle *head)
{
    if (head == NULL)
        return;

    printf("\n*****************************************************  Penacle Club   *****************************************************************************************\n");
    struct penacle *rn;
    rn = head;
    while (rn != NULL)
    {
        printf("\nThe prn is :- %d\nThe Name of the Member is %s\n", rn->prn, rn->name);
        rn = rn->next;
    }
}
void display_all_members(struct penacle *head)
{
    printf("\n*****************************************************  Penacle Club   *****************************************************************************************\n");
    struct penacle *f = head;

    int count = 0;
    while (f != NULL)
    {
        count++;
        f = f->next;
    }
    f = head;
    f = f->next;
    for (int i = 1; i < count; i++)
    {
        printf("\nThe prn is :- %d\nThe Name of the Member is %s\n", f->prn, f->name);
    }
}

void Reverse(struct penacle *head)
{

    printf("\n*****************************************************  Penacle Club   *****************************************************************************************\n");
    struct penacle *p;
    p = head;
    if (head == NULL)
    {
        return;
    }
    Reverse(head->next);

    printf("\nThe prn is :- %d\nThe Name of the Member is %s\n", head->prn, head->name);
    head = p;
}

int main()
{
    printf("\n***************************************************** Welcome To Penacle Club   *****************************************************************************************\n");
    printf("\n                                           president and Secreatary of the penacle club\n");
    struct penacle *president;
    president = (struct penacle *)malloc(sizeof(struct penacle));
    president->prn = 1214;
    strcpy(president->name, "saurabh");
    president->next = NULL;

    struct penacle *secretary;
    secretary = (struct penacle *)malloc(sizeof(struct penacle));
    secretary->prn = 1324;
    strcpy(secretary->name, "Sarvesh");
    secretary->next = NULL;

    president->next = secretary;
    int ch, y, data1, count;
    display(president);
    while (1)
    {
        printf("\n*****************************************************  Main  Menu     *****************************************************************************************\n");
        printf("1. Insert Members\n2. Delete president\n3. Delete Secretary\n4. Delete Members\n5. Total No of the Members\n6. Display All Members\7. Reverse\n8. Display\n9.Exit\n");
        printf("***************************************************************************************************************************************************************\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            president = Insert_Members(president);
            break;

        case 2:
            president = Delete_president(president);
            break;

        case 3:
            president = Delete_secretary(president);
            break;
        case 4:
            printf("Enter the prn which you wnant to delete ??\n");
            scanf("%d", &data1);
            president = Delete_Member(president, data1);
            break;
        case 5:
            count = display_Total_no_of_Members(president);
            printf("The total no of Members are %d", count);
            break;
        case 6:
            display_all_members(president);
            // printf("The total no of Members are %d", count);
            break;
        case 7:
            Reverse(president);
            break;
        case 8:
            display(president);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Input!!\n");
            break;
        }
    }

    return 0;
}
