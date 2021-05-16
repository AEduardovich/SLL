#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

class Solution
{
public:
    ListNode *sortList(struct ListNode *list)
    {
        ListNode *h = list, *n = NULL;
        int tmp;

        while (h != NULL)
        {
            n = h->next;
            while (n != NULL)
            {
                if (n->data > h->data)
                {
                    tmp = n->data;
                    n->data = h->data;
                    h->data = tmp;
                }
                n = n->next;
            }
            h = h->next;
        }
    }
};

void display(struct ListNode *head)
{
    if (head == NULL)
    {
        printf("NULL");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d\n", head->data);
            display(head->next);
            break;
        }
    }
};

void concat(struct ListNode *x, struct ListNode *y)
{
    if (x != NULL && y != NULL)
    {
        if (x->next == NULL)
            x->next = y;
        else
            concat(x->next, y);
    }
    else
    {
        printf("NULL");
    }
};

int main()
{
    Solution sol;
    ListNode *prev, *x, *y, *tmp;
    int s, i;
    printf("Declare the X list size: ");
    scanf("%d", &s);
    x = NULL;
    for (i = 0; i < s; ++i)
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &tmp->data);
        tmp->next = NULL;
        if (x == NULL)
        {
            x = tmp;
        }
        else
        {
            prev->next = tmp;
        }
        prev = tmp;
    }
    printf("Declare the Y list size:");
    scanf("%d", &s);
    y = NULL;
    for (i = 0; i < s; ++i)
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &tmp->data);
        tmp->next = NULL;
        if (y == NULL)
        {
            y = tmp;
        }
        else
        {
            prev->next = tmp;
        }
        prev = tmp;
    }
    concat(x, y);
    sol.sortList(x);
    display(x);
    return 0;
}