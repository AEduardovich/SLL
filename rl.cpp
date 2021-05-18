#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

string to_str(int s)
{
    ostringstream tmp;
    tmp << s;
    return tmp.str();
};

struct ListNode
{
    int data;
    ListNode *next;
};

int simplify(int v)
{
    int len = to_str(v).size();
    int num[len];

    int val = v / 10;
    int total = v / val;

    int mod = v % 10;
    int ans = 0;
    int tmp = 0;

    for (int i = 0; i < len; ++i)
    {
        num[i] = to_str(v)[i] - '0';
    }

    if (mod == 0)
    {
        ans = total;
    }
    else
    {
        for (int i = 1; i < len; ++i)
            tmp += num[i];
            ans = num[0] * 10 + tmp;
    }

    return ans;
};

class Solution
{
public:
    ListNode *rotateList(struct ListNode **head, int k)
    {
        //0 <= k <= 2 * 10^9;
        ListNode *prev = NULL, *last = *head;
        int iter = simplify(k);
        while (iter > 0)
        {
            iter--;
            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }

            last->next = *head;

            prev->next = NULL;

            *head = last;
        }
    }
};

void removeLastNode(struct ListNode *head)
{
    ListNode *h = head, *n = NULL;
    while (h->next != NULL)
    {
        n = h;
        h = h->next;
    }

    n->next = NULL;
};

void reverseList(struct ListNode *head)
{
    ListNode *prev = head, *n = NULL;
    int tmp;

    while (prev != NULL)
    {
        n = prev->next;
        while (n != NULL)
        {
            tmp = prev->data;
            prev->data = n->data;
            n->data = tmp;
            n = n->next;
        }
        prev = prev->next;
    }
};

void render(struct ListNode *head)
{
    if (head != NULL)
    {
        printf("%d\n", head->data);
        render(head->next);
    }
    else
    {
        printf("NULL");
    }
};

int main()
{
    Solution sol;
    ListNode *p, *tmp, *node;
    int s, i;
    printf("Declare the List size:");
    scanf("%d", &s);
    node = NULL;
    for (i = 0; i < s; ++i)
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &tmp->data);
        tmp->next = NULL;
        if (node == NULL)
        {
            node = tmp;
        }
        else
        {
            p->next = tmp;
        }
        p = tmp;
    }
    sol.rotateList(&node, 1000000000);
    render(node);
    return 0;
}
