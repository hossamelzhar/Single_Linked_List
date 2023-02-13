#include "Single_Linked_List.h"


Single_Linked_T** Create_Linked_List(uint32 num)
{
    Single_Linked_T **Lists = NULL;
    uint32 index = 0;
    if(num == 0)
    {
        Lists = NULL;
    }
    else
    {
        Lists = (Single_Linked_T**) calloc(num, sizeof(Single_Linked_T*));

        if(NULL == Lists)
        {
            printf("Failed To Create Linked Lists\n\n");
        }
        else
        {
            printf("%i Linked Lists Created\n\n", num);
            for(index = 0; index < num; index++)
            {
                Lists[index] = NULL;
            }
        }
    }
    return Lists;
}

void Insert_Head_Node(Single_Linked_T **List)
{
    sint32 value = 0;
    Single_Linked_T *TempNode = NULL;
    TempNode = (Single_Linked_T*) calloc(1, sizeof(Single_Linked_T));

    if(NULL != TempNode)
    {
        printf("Enter Node Value : ");
        scanf("%i", &value);
        TempNode->Data = value;

        if(NULL == *List)
        {
            *List = TempNode;
            TempNode->Next = NULL;
        }
        else
        {
            TempNode->Next = *List;
            *List = TempNode;
        }
        printf("Node Inserted At Head Successfully\n");
    }
    else
    {
        printf("Failed To Add New Node\n");
    }
}

void Insert_End_Node(Single_Linked_T *List)
{
    sint32 value = 0;
    Single_Linked_T *TempNode = NULL;
    Single_Linked_T *LastNode = List;

    if(NULL == List)
    {
        printf("Linked List is Empty,\nUse Insert Node At Head\n");
    }
    else
    {

        TempNode = (Single_Linked_T*) calloc(1, sizeof(Single_Linked_T));
        if(NULL != TempNode)
        {
            printf("Enter Node Value : ");
            scanf("%i", &value);
            TempNode->Data = value;

            while(NULL != LastNode->Next)
            {
                LastNode = LastNode->Next;
            }
            LastNode->Next = TempNode;
            TempNode->Next = NULL;
            printf("Node Inserted At End Successfully\n");
        }
        else
        {
            printf("Failed To Add New Node\n");

        }
    }
}

void Insert_Middle_Node(Single_Linked_T *List)
{
    Single_Linked_T *TempNode = NULL;
    Single_Linked_T *MidNode  = List;
    uint32 length = Get_Linked_List_Length(List);
    uint32 TempVal = 0;
    sint32 value = 0;

    if(NULL == List)
    {
        printf("Linked List is Empty,\nUse Insert Node At Head\n");
    }
    else
    {
        TempNode = (Single_Linked_T*) calloc(1, sizeof(Single_Linked_T));
        if(NULL != TempNode)
        {
            printf("Enter Node Value : ");
            scanf("%i", &value);
            TempNode->Data = value;

            if(1 == length)
            {
                printf("There is Only One Node\n");
                List->Next = TempNode;
                TempNode->Next = NULL;
                printf("New Node Added After It\n");
            }
            else
            {
                TempVal = length / 2;
                while(TempVal > 1)
                {
                    MidNode = MidNode->Next;
                    TempVal--;
                }
                TempNode->Next = MidNode->Next;
                MidNode->Next = TempNode;
                printf("Node Added Successfully After Node %i\n", (length / 2));
            }

        }
        else
        {
            printf("Failed To Add New Node\n");
        }
    }

}

void Insert_Node_After(Single_Linked_T *List, uint32 Node_Num)
{
    Single_Linked_T *TempNode = NULL;
    Single_Linked_T *Left_Node  = List;
    uint32 length = Get_Linked_List_Length(List);
    uint32 TempVal = 0;
    sint32 value = 0;

     if(NULL == List)
    {
        printf("Linked List is Empty,\nUse Insert Node At Head\n");
    }
    else
    {
        TempNode = (Single_Linked_T*) calloc(1, sizeof(Single_Linked_T));
        if(NULL != TempNode)
        {

            if(Node_Num > length)
            {
                printf("Node Number Is Out Of Range\n");
                printf("Total Number Of List Elements = %i\n", length);
            }
            else if(0 >= Node_Num)
            {
                printf("Nodes Indexes Starts From 1\n");
            }
            else if(Node_Num == length)
            {
                printf("It Is The Last Node Number\n");
                printf("Enter Node Value : ");
                scanf("%i", &value);
                TempNode->Data = value;

                while(NULL != Left_Node->Next)
                {
                    Left_Node = Left_Node->Next;
                }

                Left_Node->Next = TempNode;
                TempNode->Next  = NULL;
                printf("Node Added To The End\n");
            }
            else
            {
                printf("Enter Node Value : ");
                scanf("%i", &value);
                TempNode->Data = value;
                TempVal = Node_Num;
                while(TempVal > 1)
                {
                    Left_Node = Left_Node->Next;
                    TempVal--;
                }
                TempNode->Next = Left_Node->Next;
                Left_Node->Next = TempNode;
                printf("Node Added After Node %i\n",Node_Num);
            }

        }
        else
        {
            printf("Failed To Add New Node\n");
        }
    }

}


void Delete_Head_Node(Single_Linked_T **List)
{
    if(NULL == *List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        Single_Linked_T *TempNode = *List;
        *List = TempNode->Next;
        free(TempNode);
        TempNode = NULL;
        printf("The First Node Deleted\n");
    }
}

void Delete_End_Node(Single_Linked_T *List)
{
    Single_Linked_T *TempNode = List;
    Single_Linked_T *PrevNode = NULL;
    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        while(NULL != TempNode->Next)
        {
            PrevNode = TempNode;   //PrevNode Always Points To the Previous Node Of The TempNode;
            TempNode = TempNode->Next;
        }
        PrevNode->Next = NULL;
        free(TempNode);
        TempNode = NULL;
        printf("The Last Node deleted\n");
    }
}
void Delete_Middle_Node(Single_Linked_T *List)
{
    Single_Linked_T *TempNode = NULL;
    Single_Linked_T *MidNode  = List;
    uint32 length = Get_Linked_List_Length(List);
    uint32 TempVal = 0;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        if(1 == length)
        {
            printf("There is Only One Node\n");
            printf("Please Use Delete Node From Head Function\n");
        }
        else if(2 == length)
        {
            printf("The Middle Node Is The First Node\n");
            printf("Please Use Delete Node From Head Function\n");
        }
        else
        {
            TempVal = length / 2;
            while(TempVal > 1)
            {
                MidNode = MidNode->Next;
                TempVal--;
            }
            TempNode = MidNode->Next;
            MidNode->Next = TempNode->Next;
            free(TempNode);
            TempNode = NULL;
            printf("Node %i Deleted\n", ((length / 2) + 1));
        }
    }
}

void Delete_Specific_Node(Single_Linked_T *List, uint32 Node_Num)
{
    Single_Linked_T *TempNode = List;
    Single_Linked_T *Left_Node  = NULL;
    uint32 length = Get_Linked_List_Length(List);
    uint32 TempVal = 0;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else if(Node_Num > length)
    {
        printf("Node Number Is Out Of Range\n");
        printf("Total Number Of List Elements = %i\n", length);
    }
    else if(0 >= Node_Num)
    {
        printf("Nodes Indexes Starts From 1\n");
    }
    else if(1 == Node_Num)
    {
        printf("You Try To Delete The First Node\n");
        printf("Please Use Delete Node From Head Function\n");
    }
    else if(Node_Num == length)
    {
        printf("It Is The Last Node\n");

        while(NULL != TempNode->Next)
        {
            Left_Node = TempNode;
            TempNode = TempNode->Next;
        }

        Left_Node->Next = NULL;
        free(TempNode);
        TempNode = NULL;
        printf("The Last Node Deleted\n");
    }
    else
    {
        TempVal = Node_Num;
        while(TempVal > 1)
        {
            Left_Node = TempNode;
            TempNode = TempNode->Next;
            TempVal--;
        }
        Left_Node->Next = TempNode->Next;
        free(TempNode);
        TempNode = NULL;
        printf("Node %ist Deleted\n", Node_Num);
    }

}

void Delete_Linked_List(Single_Linked_T **List)
{
    Single_Linked_T *TempNode = *List;

    if(NULL == *List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        while(NULL != TempNode)
        {
            *List = TempNode->Next;
            free(TempNode);
            TempNode = *List;
        }
        printf("The Linked List Deleted\n");
    }
}


void Display_Linked_List(Single_Linked_T *List)
{
    Single_Linked_T *TempNode = List;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        printf("Head->");
        while(NULL != TempNode)
        {
            List = TempNode->Next;
            printf(" %i ->",TempNode->Data);
            TempNode = List;
        }
        printf("NULL\n");
    }
}

void Display_Specific_Node(Single_Linked_T *List, uint32 Node_Num)
{
    Single_Linked_T *TempNode = List;
    uint32 length = Get_Linked_List_Length(List);
    uint32 TempVal = 0;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else if(Node_Num > length)
    {
        printf("Node Number Is Out Of Range\n");
        printf("Total Number Of List Elements = %i\n", length);
    }
    else if(0 >= Node_Num)
    {
        printf("Nodes Indexes Starts From 1\n");
    }
    else
    {
        TempVal = Node_Num;
        while(TempVal > 1)
        {
            TempNode = TempNode->Next;
            TempVal--;
        }
        printf("Node %i Value = %i\n", Node_Num, TempNode->Data);
        TempNode = NULL;
    }
}

void Display_Middle_Node(Single_Linked_T *List)
{
    Single_Linked_T *MidNode  = List;
    uint32 length = Get_Linked_List_Length(List);
    uint32 TempVal = 0;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        if(1 == length)
        {
            printf("There is Only One Node\n");

            printf("Its Value = %i\n", MidNode->Data);
        }
        else if(2 == length)
        {
            printf("There is Two Nodes\n");
            printf("In Case Of Even Number Of Nodes, I Print The First middle\n");
            printf("Its Value = %i\n", MidNode->Data);
        }
        else
        {
            if(length & 1) // True If length ODD
            {
                TempVal = (length / 2) + 1;
            }
            else          // length is EVEN
            {
                TempVal = length / 2;
            }
            while(TempVal > 1)
            {
                MidNode = MidNode->Next;
                TempVal--;
            }

            if(length & 1) // True If length ODD
            {
                printf("Node %i Value = %i\n", ((length / 2) + 1), MidNode->Data);
            }
            else          // length is EVEN
            {
                printf("Node %i Value = %i\n", (length / 2), MidNode->Data);
            }

        }
    }
}

void Reversed_Display_Linked_List(Single_Linked_T *List)
{
    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        uint32 length = Get_Linked_List_Length(List);
        sint32 Buffer[length];
        uint32 counter = length - 1;
        while(NULL != List)
        {
            Buffer[counter] = List->Data;
            List = List->Next;
            counter--;
        }
        counter = 0;
        printf("NULL");
        while(counter < length)
        {
            printf("<- %i ", Buffer[counter]);
            counter++;
        }
        printf("<-Head\n");
    }

}


void Swap_Two_Nodes(Single_Linked_T *List, uint32 Node_Num_1, uint32 Node_Num_2)
{
    Single_Linked_T *TempNode_1 = List;
    Single_Linked_T *TempNode_2 = List;
    sint32 TempVal = 0;
    uint32 counter = 0;

    uint32 length = Get_Linked_List_Length(List);

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else if(1 == length)
    {
        printf("There is Only One Node\n");
    }
    else if((Node_Num_1 > length) || (Node_Num_2 > length))
    {
        printf("Node Number Is Out Of Range\n");
        printf("Total Number Of List Elements = %i\n", length);
    }
    else if((0 >= Node_Num_1) || (0 >= Node_Num_2))
    {
        printf("Nodes Indexes Starts From 1\n");
    }
    else
    {
        /*Set TempNode_1 To First Node*/
        counter = Node_Num_1;
        while(counter > 1)
        {
            TempNode_1 = TempNode_1->Next;
            counter--;
        }
        /*Set TempNode_2 To Second Node*/
        counter = Node_Num_2;
        while(counter > 1)
        {
            TempNode_2 = TempNode_2->Next;
            counter--;
        }

        TempVal = TempNode_1->Data;
        TempNode_1->Data = TempNode_2->Data;
        TempNode_2->Data = TempVal;
        printf("Node %i Swapped with Node %i\n", Node_Num_1, Node_Num_2);
    }

}

void Reverse_Linked_List(Single_Linked_T **List)
{
    if(NULL == *List)
    {
        printf("The List Is Empty\n");
    }
    else
    {
        Single_Linked_T *TempNode = *List;
        Single_Linked_T *PrevNode = NULL;
        /**
         * For The First Node Only
         * We Make Its Pointer NULL
         * To Be The New End
         **/
        *List = TempNode->Next;
        TempNode->Next =NULL;
        PrevNode = TempNode;
        TempNode = *List;
        while(NULL != TempNode)
        {
            *List = TempNode->Next;
            TempNode->Next = PrevNode;
            PrevNode = TempNode;
            TempNode = *List;
        }
        /**
         * After The Loop It Must Now TempNode & *List Equal NULL
         * And Stopped At The End Of The List
         * Now Let We Point *List To The PrevNode To Be The New Head
         */
          *List = PrevNode;
          printf("The Linked List Reversed\n");
    }

}

void Sort_Linked_List_Ascending(Single_Linked_T *List)
{
    Single_Linked_T *TempNode_1 = List;
    Single_Linked_T *TempNode_2 = NULL;
    Single_Linked_T *TempAddress = NULL;
    sint32 TempMinVal = 0;
    uint32 flag = 0;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else if(NULL == List->Next)

    {
        printf("There is Only One Node\n");
    }
    else
    {
        while(NULL != TempNode_1)
        {
            TempNode_2 = TempNode_1->Next;
            while(NULL != TempNode_2)
            {
                if((TempNode_1->Data) > (TempNode_2->Data))
                {
                     TempMinVal = (TempNode_2->Data);
                     TempAddress = TempNode_2;
                     flag = 1;
                }

                TempNode_2 = TempNode_2->Next;
            }

            if(flag == 1)
            {
                (TempAddress->Data) = (TempNode_1->Data);
                (TempNode_1->Data) = TempMinVal;
                flag = 0;
            }

            TempNode_1 = TempNode_1->Next;
        }
        printf("The Linked List Sorted Ascending\n");
    }
}

void Sort_Linked_List_Descending(Single_Linked_T *List)
{
    Single_Linked_T *TempNode_1 = List;
    Single_Linked_T *TempNode_2 = NULL;
    Single_Linked_T *TempAddress = NULL;
    sint32 TempMaxVal = 0;
    uint32 flag = 0;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else if(NULL == List->Next)

    {
        printf("There is Only One Node\n");
    }
    else
    {
        while(NULL != TempNode_1)
        {
            TempNode_2 = TempNode_1->Next;
            while(NULL != TempNode_2)
            {
                if((TempNode_1->Data) < (TempNode_2->Data))
                {
                    TempMaxVal = (TempNode_2->Data);
                    TempAddress = TempNode_2;
                    flag = 1;
                }
                TempNode_2 = TempNode_2->Next;
            }

            if(flag == 1)
            {
                (TempAddress->Data) = (TempNode_1->Data);
                (TempNode_1->Data) = TempMaxVal;
                flag = 0;
            }


            TempNode_1 = TempNode_1->Next;
        }
        printf("The Linked List Sorted Descending\n");
    }
}


uint32 Get_Linked_List_Length(Single_Linked_T *List)
{
    uint32 counter = 0;

    if(NULL == List)
    {
        counter = 0;
    }
    else
    {
        while(NULL != List)
        {
            List = List->Next;
            counter++;
        }
    }

    return counter;
}


void Remove_Duplicated_Nodes(Single_Linked_T *List)
{
    Single_Linked_T *TempNode_1 = List;
    Single_Linked_T *TempNode_2 = NULL;
    Single_Linked_T *PrevNode   = NULL;
    uint32 Detector = 0;

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else if(NULL == List->Next)

    {
        printf("There is Only One Node\n");
    }
    else
    {
        while(NULL != TempNode_1)
        {
            TempNode_2 = TempNode_1->Next;
            PrevNode = TempNode_1;
            while(NULL != TempNode_2)
            {
                if((TempNode_1->Data) == (TempNode_2->Data))
                {
                     PrevNode->Next = TempNode_2->Next;
                     free(TempNode_2);
                     TempNode_2 = PrevNode->Next;
                     Detector = 1;
                }
                else
                {
                    PrevNode = TempNode_2;
                    TempNode_2 = TempNode_2->Next;
                }

            }

            TempNode_1 = TempNode_1->Next;
        }
        if(1 == Detector)
        {
            printf("The Duplicated Values Deleted\n");
        }
        else
        {
            printf("There Is No Duplicated Values\n");
        }

    }
}

uint32 Detect_Loop(Single_Linked_T *List)
{
    Single_Linked_T *HoldNode = List;
    Single_Linked_T **Address_Array = (Single_Linked_T**) calloc(1, sizeof(Single_Linked_T*));
    uint32 address_counter = 0;
    sint32 temp_counter = 0;
    uint32 Detector     = 0;
    uint32 loop_node = NO_LOOPS; // Default if there is No Loops

    if(NULL == List)
    {
        printf("The List Is Empty\n");
        loop_node = EMPTY;
    }
    else
    {

        while(NULL != HoldNode)
        {
            *(Address_Array + address_counter) = HoldNode;
            temp_counter = address_counter;
            while(temp_counter >=0)
            {
               if((HoldNode->Next) == (*(Address_Array + temp_counter)))
               {
                   loop_node = temp_counter + 1;
                   Detector = 1;
                   break;
               }
               else
               {
                   loop_node = NO_LOOPS;
                   temp_counter--;
               }
            }


            if(1 == Detector)
            {
                break;
            }
            else
            {
                address_counter++;
                Address_Array = (Single_Linked_T**) realloc(Address_Array, ((address_counter+1) * sizeof(Single_Linked_T*)));
                HoldNode = HoldNode->Next;
            }
        }
    }

    return loop_node;
}


void Remove_Loop(Single_Linked_T *List)
{
    Single_Linked_T *HoldNode = List;
    Single_Linked_T **Address_Array = (Single_Linked_T**) calloc(1, sizeof(Single_Linked_T*));
    uint32 address_counter = 0;
    sint32 temp_counter = 0;
    uint32 Detector     = 0;
    uint32 loop_node = NO_LOOPS; // Default if there is No Loops

    if(NULL == List)
    {
        printf("The List Is Empty\n");
    }
    else
    {

        while(NULL != HoldNode)
        {
            *(Address_Array + address_counter) = HoldNode;
            temp_counter = address_counter;
            while(temp_counter >=0)
            {
               if((HoldNode->Next) == (*(Address_Array + temp_counter)))
               {
                   HoldNode->Next = NULL;
                   loop_node = temp_counter + 1;
                   Detector = 1;
                   break;
               }
               else
               {
                   loop_node = NO_LOOPS;
                   temp_counter--;
               }
            }


            if(1 == Detector)
            {
                break;
            }
            else
            {
                address_counter++;
                Address_Array = (Single_Linked_T**) realloc(Address_Array, ((address_counter+1) * sizeof(Single_Linked_T*)));
                HoldNode = HoldNode->Next;
            }
        }

        if(NO_LOOPS == loop_node)
        {
            printf("There Is No Loops\n");
        }
        else
        {
            printf("The Loop Founded In Node %i, And Removed\n", loop_node);
        }
    }

}

void Remove_Elements_Sum_Zero(Single_Linked_T **List)
{
    Single_Linked_T *HolderNode = *List;
    Single_Linked_T *MoverNode = NULL;
    Single_Linked_T *PrevHolder = HolderNode;
    Single_Linked_T *PrevMover = NULL;
    uint32 Detector = 0;


    if(NULL == *List)
    {
        printf("The List Is Empty\n");
    }
    else if(NULL == (*List)->Next)

    {
        printf("There is Only One Node\n");
    }
    else
    {
        while(NULL != HolderNode)
        {
            MoverNode = HolderNode->Next;
            PrevMover = HolderNode;
            while(NULL != MoverNode)
            {
                if(((HolderNode->Data) + (MoverNode->Data)) == 0)
                {
                     printf("HolderNode->Data + MoverNode->Data = %i + %i\n",HolderNode->Data ,MoverNode->Data);
                    /*Free The Second Node In Summation*/
                     PrevMover->Next = MoverNode->Next;
                     free(MoverNode);
                     MoverNode = PrevMover->Next;
                     /*Free The First Node In Summation*/
                     if(HolderNode == *List)
                     {
                         printf("HolderNode == *List\n");
                         *List = HolderNode->Next;
                         free(HolderNode);
                         HolderNode = *List;
                     }
                     else
                     {
                         printf("HolderNode != *List\n");
                         PrevHolder->Next = HolderNode->Next;
                         free(HolderNode);
                         HolderNode = PrevHolder->Next;
                     }

                     Detector = 1; //Found Two Elements with sum zero

                }
                else
                {
                    PrevMover = MoverNode;
                    MoverNode = MoverNode->Next;
                }

            }
            if(NULL != HolderNode)
            {
                PrevHolder = HolderNode;
                HolderNode = HolderNode->Next;
            }
        }
        if(1 == Detector)
        {
            printf("Summation Zero Elements Deleted\n");
        }
        else
        {
            printf("No Elements With Summation Zero\n");
        }

    }
}

void Merge_Two_Linked_Lists(Single_Linked_T **List_1, Single_Linked_T **List_2, uint32 Node_Num_1, uint32 Node_Num_2)
{
    Single_Linked_T *TempNode_1 = *List_1;
    Single_Linked_T *NextNode   =  NULL;
    Single_Linked_T *TempNode_2 = *List_2;
    Single_Linked_T *PrevNode   =  NULL;
    uint32 TempVal = 0;

    uint32 length_1 = Get_Linked_List_Length(*List_1);
    uint32 length_2 = Get_Linked_List_Length(*List_2);
    /*NoThing To Do if List(1) And List(2) Are Both Empty, Or List(2) Empty*/
    if(((NULL == *List_1) && (NULL == *List_2)) || (NULL == *List_2))
    {
        printf("The List (1) AND (2) Are Empty, OR List(2) Empty\n");
    }
    else if((Node_Num_1 > length_1) || (Node_Num_2 > length_2))
    {
        printf("Node %i OR Node %i Or Both Are Out Of Rang\n", Node_Num_1, Node_Num_2);
    }

    /*List(1) Can Be NULL, But Not List(2), At Least List(2) Must Have One Node*/
    else if((Node_Num_1 < 0) || (Node_Num_2 <= 0))
    {
        printf("Node Indexes Start From 1\n");
    }
    else
    {
        /**
         * Hold The Required Node in List(1) in *TempNode_1
         * To Link List (2) To It
         * And The Next Node in *NextNode
         * To Use It To Free The Remaining Nodes In List (1)
         */
        TempVal = Node_Num_1;
        while(TempVal > 1)
        {
            TempNode_1 = TempNode_1->Next;
            TempVal--;
        }
        NextNode = TempNode_1->Next;

        /**
         * Hold The Required Node in List(2) in *TempNode_2
         * To Link It To List (1)
         * And The Previous Node in *PrevNode
         * To Use It To Free The Remaining Nodes In List (2)
         */
        TempVal = Node_Num_2;
        PrevNode = TempNode_2; /*This useful in case there is only one Node in List(2)*/
        while(TempVal > 1)
        {
            PrevNode = TempNode_2;
            TempNode_2 = TempNode_2->Next;
            TempVal--;
        }


        /*Linking List(2) To Empty List(1)*/
        if(NULL == *List_1)
        {
            *List_1 = TempNode_2;
        }
        /*Linking List(2) To None Empty List(1)*/
        else
        {
            TempNode_1->Next = TempNode_2;
        }

        /*Free The Remaining Nodes in List(1), Its New Head Is *NextNode Pointer*/
        while(NULL != NextNode)
        {
            TempNode_1 = NextNode;
            NextNode = NextNode->Next;
            free(TempNode_1);
        }

        /*Free The Remaining Nodes in List(2), Its Head Is *List_2 Pointer And Its New End Is *PrevNode Pointer*/
        if(1 == Node_Num_2)
        {
            *List_2 = NULL;
        }
        else
        {
            TempNode_2 = *List_2;
            while(TempNode_2 != PrevNode)
            {
                TempNode_2 = TempNode_2->Next;
                free(*List_2);
                *List_2 = TempNode_2;
            }
            /*The Node That pointed By *PrevNode Is Still Not Freed*/
            free(PrevNode);
        }


        /*NULL The Free Pointers*/
        *List_2    = NULL;
        TempNode_1 = NULL;
        TempNode_2 = NULL;
        NextNode   = NULL;
        PrevNode   = NULL;

        printf("The Two Lists Merged, Node %i from List(2) ", Node_Num_2);
        printf("Linked Up To Node %i in List(1)\n", Node_Num_1);
    }
}

void Create_Loop_In_List(Single_Linked_T *List, uint32 NodeNum)
{
    Single_Linked_T *TempNode = List;
    Single_Linked_T *LastNode = List;
    uint32 TempVal = NodeNum;
    uint32 length = Get_Linked_List_Length(List);
    if(NULL == List)
    {
        printf("List Is Empty\n");
    }
    else if(NodeNum > length)
    {
        printf("Node Number Is Out Of Range\n");
        printf("Total Number Of List Elements = %i\n", length);
    }
    else if(NodeNum <= 0)
    {
        printf("Node Indexes Start From 1\n");
    }
    else
    {
        /*Make LastNode Hold The Last Node In List To Make It Loop To The Required Node*/
        while(NULL != LastNode->Next)
        {
            LastNode = LastNode->Next;
        }
        /*Hold The Required Node To Make Last Node Points To It (Make Loop To It)*/
        while(TempVal > 1)
        {
            TempNode = TempNode->Next;
            TempVal--;
        }

        /*Now Make The Loop From Last Node To The Required Node*/
        LastNode->Next = TempNode;
        if(NodeNum == length)
        {
            printf("Loop Created: Last Node -> Last Node\n");
        }
        else
        {
            printf("Loop Created: Last Node -> Node %i\n", NodeNum);
        }


    }
}
