#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define NO_LOOPS 0
#define EMPTY   -1

typedef unsigned int uint32;
typedef signed int sint32;

typedef struct Node
{
    struct Node *Next;
    sint32 Data;

}Single_Linked_T;

Single_Linked_T** Create_Linked_List(uint32 num);

void Insert_Head_Node(Single_Linked_T **List);
void Insert_End_Node(Single_Linked_T *List);
void Insert_Middle_Node(Single_Linked_T *List);
void Insert_Node_After(Single_Linked_T *List, uint32 Node_Num);

void Delete_Head_Node(Single_Linked_T **List);
void Delete_End_Node(Single_Linked_T *List);
void Delete_Middle_Node(Single_Linked_T *List);
void Delete_Specific_Node(Single_Linked_T *List, uint32 Node_Num);
void Delete_Linked_List(Single_Linked_T **List);

void Display_Linked_List(Single_Linked_T *List);
void Display_Middle_Node(Single_Linked_T *List);
void Display_Specific_Node(Single_Linked_T *List, uint32 Node_Num);
void Reversed_Display_Linked_List(Single_Linked_T *List);

void Swap_Two_Nodes(Single_Linked_T *List, uint32 Node_Num_1, uint32 Node_Num_2);
void Reverse_Linked_List(Single_Linked_T **List);
void Sort_Linked_List_Ascending(Single_Linked_T *List);
void Sort_Linked_List_Descending(Single_Linked_T *List);
uint32 Get_Linked_List_Length(Single_Linked_T *List);

void Remove_Duplicated_Nodes(Single_Linked_T *List);
uint32 Detect_Loop(Single_Linked_T *List);
void Remove_Loop(Single_Linked_T *List);
void Remove_Elements_Sum_Zero(Single_Linked_T **List);
void Merge_Two_Linked_Lists(Single_Linked_T **List_1, Single_Linked_T **List_2, uint32 Node_Num_1, uint32 Node_Num_2);
void Create_Loop_In_List(Single_Linked_T *List, uint32 NodeNum);

#endif // _SINGLE_LINKED_LIST_H
