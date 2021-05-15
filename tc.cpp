#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

int display(struct Node* head) {
    if(head == NULL) {
        printf("NULL\n");
    }
    else {
        printf("%d\n", head->data);
        display(head->next);
    }
}

void concat(struct Node *x, struct Node *y) {
    if(x != NULL && y != NULL) {
        if(x->next == NULL)
            x->next = y;
        else 
            concat(x->next, y);
    }
    else {
        printf("NULL");
    }
};


int main() {

    struct Node *prev, *x, *y, *tmp;
    int s,i;
    printf("declare the X list:");
    scanf("%d", &s);
    x = NULL;
    for(i = 0; i < s; i++) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &tmp->data);
        tmp->next = NULL;
        if(x == NULL) {
            x = tmp;
        }
        else {
            prev->next = tmp;
        }
        prev = tmp;
    }
    printf("declare the Y list:");
    scanf("%d", &s);
    y = NULL;
    for(i = 0; i < s; ++i) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &tmp->data);
        tmp->next = NULL;
        if(y == NULL) {
            y = tmp;
        }
        else {
            prev->next = tmp;
        }
        prev = tmp;
    }
    concat(x,y);
    display(x);
    return 0;
}