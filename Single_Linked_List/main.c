/**
**********************************************************************************************************
* @Project Name         : Single Linked List Implementation                                              *
* @Author Name          : Hossam Masoud Elzhar                                                           *
* @Created Date         : 29/09/2022   00:38:12                                                          *
* @Program Description  : Implementation Of Single Linked List Functions (Insert, Delete, Display,       *
*                                                                 swap, Reverse, Sort, Merge, And More)  *
**********************************************************************************************************
*/


#include "Single_Linked_List.h"



Single_Linked_T **Lists = NULL;
uint32 number_of_lists  = 0;
uint32 user_choice      = 0;
uint32 node_num_1       = 0;
uint32 node_num_2       = 0;
uint32 list_num_1       = 0;
uint32 list_num_2       = 0;
uint32 list_length      = 0;
uint32 list_index       = 0;


int main()
{
    char text[] = "Welcome To The Single Linked List Implementation";
    uint32 text_index = 0;
    printf("\n<----------------------- ");
    Sleep(100);
    while('\0' != text[text_index])
    {
        printf("%c", text[text_index]);
        Sleep(50);
        text_index++;
    }
    Sleep(50);
    printf(" ----------------------->\n\n");
    printf("Enter Number Of Lists You Want To Create : ");
    scanf("%i", &number_of_lists);
    Lists = Create_Linked_List(number_of_lists);
    if(NULL != Lists)
    {
        for(;;)
        {
            printf("==================================================================================================\n");
            printf("| Enter 1 To Insert Node At Head             |  ");
            printf("Enter 3 To Insert Node At Middle                 |\n");
            printf("| Enter 2 To Insert Node At End              |  ");
            printf("Enter 4 To Insert Node After a Specific Node     |\n");
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("| Enter 5 To Delete Node From Head           |  ");
            printf("Enter 8 To Delete a Specific Node                |\n");
            printf("| Enter 6 To Delete Node From End            |  ");
            printf("Enter 9 To Delete a Linked List                  |\n");
            printf("| Enter 7 To Delete Node From Middle         |  ");
            printf("                                                 |\n");
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("| Enter 10 To Display a Linked List          |  ");
            printf("Enter 12 To Display a Specific Node              |\n");
            printf("| Enter 11 To Display The Middle Node        |  ");
            printf("Enter 13 To Reversed Display a Linked List       |\n");
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("| Enter 14 To Swap Two Nodes                 |  ");
            printf("Enter 17 To Sort a Linked List Descending        |\n");
            printf("| Enter 15 To Reverse a Linked List          |  ");
            printf("Enter 18 To Get a Linked List Length             |\n");
            printf("| Enter 16 To Sort a Linked List Ascending   |  ");
            printf("                                                 |\n");
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("| Enter 19 To Remove Duplicated Nodes        |  ");
            printf("Enter 22 To Remove The Nodes With Summation Zero |\n");
            printf("| Enter 20 To Detect The Looping Node        |  ");
            printf("Enter 23 To Merge Two Linked Lists               |\n");
            printf("| Enter 21 To Remove The Loop                |  ");
            printf("Enter 24 To Create Loop (Last Node->Entered Node)|\n");
            printf("==================================================================================================\n");
            printf("                                     |Enter 0 To Exit|\n");
            printf("                                     =================\n");
            printf("User Choice : ");
            scanf("%i", &user_choice);
            switch (user_choice)
            {
                case 0:

                    printf("GoodBye :)\n");
                    exit(1);
                    break;

                case 1:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Insert_Head_Node(&Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 2:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Insert_End_Node(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 3:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Insert_Middle_Node(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 4:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        printf("Enter The Number Of Node :");
                        scanf("%i", &node_num_1);
                        Insert_Node_After(Lists[list_index], node_num_1);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 5:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Delete_Head_Node(&Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 6:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Delete_End_Node(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 7:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Delete_Middle_Node(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 8:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        printf("Enter The Number Of Node :");
                        scanf("%i", &node_num_1);
                        Delete_Specific_Node(Lists[list_index], node_num_1);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 9:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Delete_Linked_List(&Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 10:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Display_Linked_List(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 11:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Display_Middle_Node(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 12:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        printf("Enter The Number Of Node :");
                        scanf("%i", &node_num_1);
                        Display_Specific_Node(Lists[list_index], node_num_1);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 13:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Reversed_Display_Linked_List(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 14:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        printf("Enter The Number Of First Node :");
                        scanf("%i", &node_num_1);
                        printf("Enter The Number Of Second Node :");
                        scanf("%i", &node_num_2);
                        Swap_Two_Nodes(Lists[list_index], node_num_1, node_num_2);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 15:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Reverse_Linked_List(&Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 16:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Sort_Linked_List_Ascending(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 17:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Sort_Linked_List_Descending(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 18:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {

                        list_length = Get_Linked_List_Length(Lists[list_index]);

                        if(0 == list_length)
                        {
                            printf("List(%i) Is Empty\n", list_index);
                        }
                        else
                        {
                            printf("List(%i) = %i\n", list_index, list_length);
                        }

                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 19:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Remove_Duplicated_Nodes(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 20:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        node_num_1 = Detect_Loop(Lists[list_index]);
                        if(NO_LOOPS == node_num_1)
                        {
                            printf("NO Loops In The List\n");
                        }
                        else if(EMPTY == node_num_1)
                        {
                            /*Do NoThing*/
                        }
                        else
                        {
                            printf("The Loop Is In Node %i\n", node_num_1);
                        }
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 21:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Remove_Loop(Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 22:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        Remove_Elements_Sum_Zero(&Lists[list_index]);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 23:

                    printf("Enter First List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_num_1);
                    printf("Enter The List(1) Node Number To Link List(2) To It :");
                    scanf("%i", &node_num_1);
                    printf("Enter Second List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_num_2);
                    printf("Enter The List(2) Node Number To Link It To List(1) :");
                    scanf("%i", &node_num_2);

                    if(((list_num_1 >= 0) && (list_num_1 < number_of_lists))
                    && ((list_num_2 >= 0) && (list_num_2 < number_of_lists)))
                    {
                        Merge_Two_Linked_Lists(&Lists[list_num_1], &Lists[list_num_2], node_num_1, node_num_2);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                case 24:

                    printf("Enter List Number From 0 To %i : ", number_of_lists-1);
                    scanf("%i", &list_index);
                    if((list_index >= 0) && (list_index < number_of_lists))
                    {
                        printf("Enter The Number Of Node :");
                        scanf("%i", &node_num_1);
                        Create_Loop_In_List(Lists[list_index], node_num_1);
                    }
                    else
                    {
                        printf("Invalid Input !!");
                    }
                    break;

                default: printf("Invalid Input !!!\n"); break;
            }
            fflush(stdin);
            getchar();
            fflush(stdin);
            printf("---------------------------------------------\n");
        }
    }


    return 0;
}
