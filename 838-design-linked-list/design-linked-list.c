#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node * next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList * First = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    First->val = 0;
    First->next = NULL;
    return First;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    int value = 0;
    int icnt = 0;

    MyLinkedList * temp = obj->next;

    while(temp != NULL)
    {
        icnt++;
        temp = temp->next;
    }

    if((index >= icnt) || (index < 0))
    {
        return -1;
    }

    temp = obj->next ;

    for(i = 0;i < index;i++)
    {
        temp = temp->next;
    }   

    value = temp->val;

    return value;
}

void myLinkedListAddAtHead(MyLinkedList * obj, int val) {
    MyLinkedList * newn = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    newn->val = val;
    newn->next = NULL;

    newn->next = obj->next;
    obj->next = newn;
}

void myLinkedListAddAtTail(MyLinkedList * obj, int val) {
    MyLinkedList * newn = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    newn->val = val;
    newn->next = NULL;
    MyLinkedList * temp = obj;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newn;
    temp = newn;
}

void myLinkedListAddAtIndex(MyLinkedList * obj,int index,int val) {
    int icnt = 0;
    int i = 0;
    MyLinkedList * temp = obj -> next;
    
    while(temp != NULL)
    {
        icnt++;
        temp = temp->next;
    }

    if(index > icnt || index < 0)
    {
        return;
    }

    if(index == icnt)
    {
        myLinkedListAddAtTail(obj,val);
        return;
    }

    MyLinkedList * newn = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    newn->val = val;
    newn->next = NULL;
    temp = obj;

    for(i = 0;i < index && temp->next != NULL;i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;
    
}

// void Display(MyLinkedList * Head)
// {
//     while(Head != NULL)
//     {
//         printf("|%d|->",Head->val);
//         Head = Head->next;
//     }
//     printf("\n");
// }

void myLinkedListDeleteLastIndex(MyLinkedList* obj) {

    MyLinkedList * temp = obj;
    MyLinkedList * temp2 = NULL;

    if(temp->next == NULL)
    {
        free(temp);
        return;
    }

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);

    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int i = 0;
    int icnt = 0;
    MyLinkedList * temp = obj -> next;
    MyLinkedList * temp2 = NULL;

    while(temp != NULL)
    {
        icnt++;
        temp = temp->next;
    }

    if(index > icnt || index < 0)
    {
        return;
    }

    if(index == icnt)
    {
        // myLinkedListDeleteLastIndex(obj);
        return;
    }

    temp = obj;

    if(temp->next == NULL)
    {
        free(temp);
        return;
    }

    for(i = 0;i < index && temp->next->next != NULL;i++)
    {
        temp = temp->next;
    }

    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList * temp = NULL;

    while(obj != NULL)
    {
        temp = obj;
        obj = obj->next;
        free(temp);
    }

    obj = NULL;
}

// int main()
// {
//     MyLinkedList * obj = myLinkedListCreate();
//     int iRet = 0;

//     myLinkedListAddAtHead(obj, 1);
//     myLinkedListAddAtHead(obj, 2);
//     myLinkedListAddAtTail(obj,3);
//     myLinkedListAddAtTail(obj,4);
//     myLinkedListAddAtIndex(obj,3,5);
//     myLinkedListAddAtIndex(obj,7,6);    
//     myLinkedListAddAtIndex(obj,1,15); 
//     myLinkedListAddAtIndex(obj,8,16);
//     myLinkedListAddAtIndex(obj,0,17);
//     Display(obj->next);

//     iRet = myLinkedListGet(obj,3);

//     printf("%d\n",iRet);

//     myLinkedListDeleteAtIndex(obj,3);
//     Display(obj->next);

//     iRet = myLinkedListGet(obj,3);

//     printf("%d\n",iRet);

//     myLinkedListFree(obj);
//     obj = NULL;

//     if(obj != NULL)
//     {
//         printf("Obj is Not NULL\n");
//         Display(obj);
//     }
    
//     return 0;
// }