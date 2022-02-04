#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack_que.h"
#include <math.h>

//Program simulates count game
// N guy play roundd
// Start from first, every n is deleted from circle
// Find sequense of deleting players from circle

// structure for linked list forming
typedef struct persNode {
char* nameK;
struct persNode *next;

} PersNode;


PersNode *AddPers(PersNode *Top, char *name1)
{
    PersNode *newel = (PersNode*) malloc(sizeof(PersNode));
    newel->nameK = name1;
    newel->next = Top;
    return newel;
}

void ShowP (PersNode *Top)
{
    int n = 0;
    while (Top){

        printf("%3s\n", Top->nameK);
        Top = Top->next;
        n++;
        if(n>=20) break;
    }
}

void CloseC (PersNode *Top)
{
    PersNode *LastP = Top;


    while (Top->next){

  //      printf("%3s\n", Top->nameK);
        Top = Top->next;

    }
    Top->next = LastP;

}


PersNode * DeletePersC(PersNode*Top, int n, PersNode**PersDeletedStack)
{
    PersNode *First = Top;
    PersNode *D;
    PersNode *Res;


    int i = 0;
    if (Top!=Top->next)
    {
     for (i=0; i<n-2; i++)
    {

        Top = Top->next;

    }
    D = Top->next;
    Top->next = Top->next->next;

    Res = D;

    printf("Deleted: %3s\n\n", Res->nameK);

    *PersDeletedStack = AddPers(*PersDeletedStack,Res->nameK);

    free(D);


    //return Top->next;
    if (Res->nameK!=First->nameK)
        return First; // This way count will be start always at the same person!
    else
        return Top;
    }
    else
    {
        D = Top;
        Res = D;

    printf("Deleted: %3s\n\n", Res->nameK);

    *PersDeletedStack = AddPers(*PersDeletedStack,Res->nameK);

    free(D);
    return NULL;
    }
    return NULL;
}




int main()
{
    system("chcp 1251 >0");
    srand(time(NULL));
    PersNode *CircleP = NULL;
    PersNode *PersDeletedStack = NULL;

    PersDeletedStack = AddPers(PersDeletedStack,"empty");

   int i,x;
   int n = 5;
   CircleP = AddPers(CircleP,"Morgan");
   CircleP = AddPers(CircleP,"Filimon");
   CircleP = AddPers(CircleP,"Steiner");
   CircleP = AddPers(CircleP,"Karambol");
   CircleP = AddPers(CircleP,"Kolombo");

   ShowP(CircleP);

   CloseC(CircleP);

//   ShowP(CircleP);
 //  PersFirstDel = DeletePersC(CircleP,3);
 //  printf("Deleted: %3s", PersFirstDel->nameK);

   while(CircleP)
   {
       CircleP = DeletePersC(CircleP,5,&PersDeletedStack);
     //  ShowP(CircleP);
   }



   printf("Deleted guys stack:\n");
   ShowP(PersDeletedStack);


    return 0;
}
