#ifndef STACK_QUE_H_INCLUDED
#define STACK_QUE_H_INCLUDED

#define Error 0x7FFF


// structure for linked list forming
typedef struct node {
int data;
struct node *next;

} Node;

// Add function for stack forming
Node *Add(Node *Top, int d)
{
    Node *newel = (Node*) malloc(sizeof(Node));
    newel->data = d;
    newel->next = Top;
    return newel;
}

// Show elements in linked list structure
void Show (Node *Top)
{
    while (Top){
        if (Top->next) printf("%3d", Top->data);
        else printf("%3d\n", Top->data);
        Top = Top->next;

    }
}

// Deleting element (depends of type of structure FIFO or LIFO)
// If you want to delete custom number element than use DeletX function
int Delete (Node **Top)
{
    int d;
    if ((*Top)!=NULL)
    {
        d = (*Top)->data;
        Node *temp = *Top;
        *Top = (*Top)->next;
        free(temp);
    }
    else {(printf("Error!!"));
    d = Error;
    }
    return d;

}


// Add element using queue type - FIFO
Node *Add_Q(Node *Top, int d)
{
    Node *newel = (Node*)malloc(sizeof(Node));
    newel->data = d;
    newel->next = NULL;

    if (Top==NULL) return newel;
    Node *temp = Top;
    while (temp->next)
        temp = temp->next;
    temp->next = newel;
    return Top;

}

// Search element with x data
Node * Search1(Node *Top, int a)
{
    while(Top)
    {
        if (Top->data==a) return Top;
        Top = Top->next;
    }
    return NULL;
}


// answering if there is element with x data in list
Node * Search2(Node *Top, int a)
{
    while(Top)
    {
        if (Top->data==a) return 1;
        Top = Top->next;
    }
    return 0;
}

// Search element that is before element with x data
Node * Search3(Node *Top, int a)
{
    if (Top->data ==a) return Top;
    while(Top->next)
    {
        if (Top->next->data==a) return Top;
        Top = Top->next;
    }
    return NULL;
}


// this func is searching for last element a
 Node * Search3_5(Node *Top, int a)
{
    Node *result;

    while(Top->next!=NULL)
    {

  //      printf("Hello");
        if (Top->next->data==a)
            {result = Top;

            }
        Top = Top->next;

    }

    return result;
}


// Adding element before element with x data
Node * AddB(Node *Top, int x, int a)
{
    Node * S = Search3(Top, x);
    Node * S1;
    if (S) { Node *newelem = (Node*)malloc(sizeof(Node));
    newelem->data = a;
    if (S==Top) {newelem->next=Top;
                return newelem;}
    else {S1 = S->next;
    S->next = newelem;
    newelem->next = S1;
    }
                }

    return Top;

}


// Adding element after element with x data
void AddA(Node *Top, int x, int a)
{
    Node * S = Search1(Top,x);
    Node *S1;
    if (S) { Node *newelem = (Node*)malloc(sizeof(Node));
    newelem->data = a;
    S1 = S->next;
    S->next = newelem;
    newelem->next = S1;
    }

}

Node * DeleteX(Node*Top, int x)
{
    Node *S = Search3(Top,x);
    Node *D;
    if (S) {if (S==Top&&S->data==x)
        {
            D = Top;
            Top = Top->next;
            free(D);
        }
        else {
            D = S->next;
            S->next = S->next->next;
            free(D);

        }
        return Top;


        }
        return Top;
}

Node * DeleteAX(Node *Top, int x)
{
    Node *S = Search1(Top, x);
    Node *D;
    if (S&&S->next) {
        D = S->next;
        S->next = S->next->next;
        free(D);
        return Top;
    }
    return Top;
}

// This is function for IDZ1. Deletes all elements between element x
Node * DeleteBetweenFL(Node*Top, int x)
{
    Node *Sf = Search1(Top,x);    //  first n element when i tried to use Search3... no way
    Node *Sl = Search3_5(Top,x);    // before last n element

    Node *D;
    if (Sf && Sl) {if (Sf==Top&&Sf->data==x)
        {
            while(Top->next!=Sl)
            {D = Top;
            Top = Top->next;
            free(D);}
            Top = Sl;
        }
        else {

            while(Sf->next!=Sl->next)
           {
            D = Sf->next;
            Sf->next = Sf->next->next;
            free(D);
           }

        }
        return Top;


        }
        return Top;
}



#endif // STACK_QUE_H_INCLUDED
