/*
 *   @File    : BankSystem.c
 *   @Author  : Mostafa Mahmoud
 *   @Date    : 22/12/2022
 *   @Brief   : Implementation of Bank Management System Based on Linked List Data Structure
*/

/* ========================== [Section: Includes] ========================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "BankSystem.h"
/* ------------------------------------------------------------------------- */

/* ===================== [Section: Data Declaration] ======================= */
struct Node *Head = NULL ;
/* ------------------------------------------------------------------------- */

/* ====================== [Section: Helper Functions] ====================== */

/**
  * @brief  :   Function to Generate Account Password
  * @param  :   No Input
  * @retval :   Return Loc_Pass --> The New Generated Password 
  */
sint8* AccPass_Gen()
{
    uint32 i  ;
    sint32 Rand = 0 ;

    srand((sint32)(time(NULL)));
    sint8 Nums[] = "0123456789";
    sint8 lett[] = "abcdefghijklmnoqprstuvwyzx";
    sint8 LETT[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    static sint8 Loc_Pass[6];
    Rand = rand() % 3;

    for (i = 0 ; i < 6 ; i++) 
    {
  
        if (Rand == 1) 
        {
            Loc_Pass[i] = Nums[rand() % 10];
            Rand = rand() % 3;
        }
        else if (Rand == 2) 
        {
            Loc_Pass[i] = LETT[rand() % 26];
            Rand = rand() % 3;
        }
        else 
        {
            Loc_Pass[i] = lett[rand() % 26];
            Rand = rand() % 3;
        }
    }
	return Loc_Pass ;
}
/* =============================== */


/**
  * @brief  :   Function to Generate Account ID 
  * @param  :   No Input
  * @retval :   Return Loc_ID --> The New Generated ID 
  */
sint8* AccID_Gen()
{    
    sint32 i ;                   
    srand((sint32)(time(NULL)));        /* New ID Every Time We call this Function */
    sint8 Num[] = "0123456789";         /* Array of Nums that will form the ID */
    static sint8 Loc_ID[10];            /* To Store The ID */
    for (i = 0 ; i < 10 ; i++) 
	{
		Loc_ID[i] = Num[rand() % 10];   
    }
	return Loc_ID ;
}
/* ============================================= */

/**
  * @brief  :   Function to Check on user ID 
  * @param  :   No Input Parameters 
  * @retval :   Return Check : [0] if ID is not found -- [1] if ID is valid
  */
uint8 CheckID(void)
{
    struct Node *TempNode = Head ;
    uint8 id[10];
    uint8 flag = 0 ;
    
    printf("Enter Account ID : ");
    scanf("%s" , id);

    while (NULL != TempNode)
    {
        if (!strcmp(TempNode->ID , id))
        {
            flag = 1 ;
            break;
        }
        else
        {
            TempNode = TempNode->NodeLink ;
        }
    }
    return flag ;
}
/* ================================ */

/**
  * @brief  :   Function to Search on the Account (Node) from the DataBase (List) 
  * @param  :   pointer to Account ID To Search
  * @retval :   TempNode --> struct holds the needed Node
  */
struct Node *CurrentNode(uint8* IDCopy)
{
	struct Node *TempNode = Head ;
	uint8 flag = 0;

	while(NULL != TempNode)
	{

		if(!strcmp(TempNode->ID,IDCopy))
		{
			flag = 1;
			return TempNode;
		}
		else 
		{
			TempNode = TempNode->NodeLink;
		}
	}
	if (flag == 0) 
    { 
        return NULL; 
    }
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to RED
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToRED (void)
{
    printf("\033[0;31m  \n");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to YELLOW 
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToYELLOW (void)
{
    printf("\033[0;33m  \n");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to BLACK
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToBLACK (void)
{
    printf("\033[0;30m  \n");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to GREEN
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToGREEN (void)
{
    printf("\033[0;32m  \n");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to BLUE
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToBLUE (void)
{
    printf("\033[0;34m  \n");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to Original
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ResetTxtColor (void)
{
    printf("\033[0m  \n");
}
/* ================================ */


/* ------------------------------------------------------------------------- */

/* ==================== [Section: Functions Definition] ==================== */

/**
  * @brief  :   Function to Make Transaction From Account to another Account 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void MakeTransaction(struct Node **Head)
{
    uint8 flagSrc  = 1;
    uint8 flagDest = 1;
    uint32 CashToTransfer ;
    uint8 _ID[15];
    struct Node *Src_Node ;
    struct Node *Dest_Node ;
    
    while (flagSrc != 0)
    {
        printf("\nEnter Bank ID :");
        scanf("%s" , _ID);
        Src_Node = CurrentNode(_ID);
        if (NULL == Src_Node)
        {
            printf("Invalid Bank ID ! ... Try Again \n");
        }
        else
        {
            flagSrc = 0 ;
        }
    }
    
    while (flagDest != 0)
    {
        printf("Enter ID of Account You Want To Transfer To : ");
        scanf("%s" , _ID);
        Dest_Node = CurrentNode(_ID);
        if (NULL == Dest_Node)
        {
            printf("Invalid Destination ID ! ... Try Again \n");
        }
        else
        {
            flagSrc = 0 ;
        }
    }

    printf("\nEnter Amount of Money You Want To Transfer : ");
    scanf("%i" , &CashToTransfer);

    if ( (!strcmp(Src_Node->State , "active")) && (strcmp(Dest_Node->State , "active")) )
    {
        if (CashToTransfer > Src_Node->Balance)
        {
            printf("Amount of Money You Want To Transfer is More than The Actual Balance ! \n");
        }
        else
        {
            printf("\nSuccessful Transaction Operation \n");
            Src_Node->Balance = Src_Node->Balance-CashToTransfer ;
            Dest_Node->Balance = Dest_Node->Balance+CashToTransfer ;
            printf("\nMoney Transferd Successfully \n");
            printf("---------------------------- \n");
            printf("\nYour New Balance Is \" %u \" \n" , Src_Node->Balance);
        }
    }
    else
    {
        printf("This Account Is Deactivated ! \n");
    }
    Sleep(5000);
}
/* ================================ */

/**
  * @brief  :   Function to Add Balance to an account   
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void AddCash(struct Node **Head)
{
    uint8 flag  = 1;
    uint32 CashToAdd ;
    uint8 _ID[15];
    struct Node *TempNode ;
    
    while (flag != 0)
    {
        printf("\nEnter Bank ID :");
        scanf("%s" , _ID);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            printf("Invalid ID ! ... Try Again \n");
        }
        else
        {
            printf("\nEnter Amount of Money You Want To Add : ");
            scanf("%i" , &CashToAdd);

            if ( (!strcmp(TempNode->State , "active"))  )
            {
                TempNode->Balance = TempNode->Balance+CashToAdd ;
                printf("Successful Deposit Operation \n");
                printf("---------------------------- \n");
                printf("Your New Balance Is \" %u \" \n" , TempNode->Balance);
            }
            else
            {
                printf("This Account Is Deactivated ! \n");
            }
            flag = 0 ;
        }
        Sleep(5000);
    }
}
/* ================================ */

/**
  * @brief  :   Function to Get Cash from user account Balance  
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void GetCash(struct Node **Head)
{
    uint8 flag  = 1;
    uint32 CashToGet ;
    uint8 _ID[15];
    struct Node *TempNode ;
    
    while (flag != 0)
    {
        printf("Enter Bank ID :");
        scanf("%s" , _ID);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            printf("Invalid ID ! ... Try Again \n");
        }
        else
        {
            printf("Enter Amount of Money You Want To Get : ");
            scanf("%i" , &CashToGet);

            if ( (!strcmp(TempNode->State , "active"))  )
            {
                TempNode->Balance = TempNode->Balance-CashToGet ;
                printf("Successful Operation \n");
                printf("Your New Balance Is \" %u \" \n" , TempNode->Balance);
            }
            else
            {
                printf("This Account Is Deactivated ! \n");
            }
            flag = 0 ;
        }
        Sleep(5000);
    }
}
/* ================================ */

/**
  * @brief  :   Function to Edit on user account Status (Node) from the DataBase (List) 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void ChangeState(struct Node **Head)
{
    uint8 flag  = 1;
    uint8 _ID[15];
    struct Node *TempNode ;
    while (flag != 0)
    {
        printf("Enter Bank ID :");
        scanf("%s" , _ID);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            printf("Invalid ID ! ... Try Again \n");
        }
        else
        {
            strcpy(TempNode->State, "closed");
            printf("Account Is Now Deactivated ! \n");
            flag = 0 ;
        }
        Sleep(5000);
    }
}
/* ================================ */

/**
  * @brief  :   Function to Create new Account (Node) to the DataBase (List) 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void CreateNewAcc(struct Node **Head)
{
    uint8 LocNationalID[15];
    static sint8 *Gen_Pass;
    static sint8 *Gen_ID;
    uint8 flag = 1 ;
    uint8 term ;
    struct Node *TempNode = NULL ;
    struct Node *LastNode = NULL ;

    TempNode = (struct Node *)malloc(sizeof(struct Node)); 

    Gen_Pass = AccPass_Gen();
    Gen_ID = AccID_Gen();
    strcpy(TempNode->Pass , Gen_Pass);
    strcpy(TempNode->ID , Gen_ID);

    if (NULL != TempNode)
    {
        // ^Getting info from the user and save it^
        TempNode->NodeLink = NULL ;

        strcpy(TempNode->State, "active");



        fflush(stdin);
        printf("Enter Name       : ");
        gets(TempNode->Name);
        
        fflush(stdin);
        printf("Enter Address    : ");
        gets(TempNode->Addr);
        
        while (flag != 0)
        {
            printf("Enter Age        : ");
            if( (scanf("%u%c", &TempNode->Age , &term) != 2 ) || (term != '\n') )
            {
                printf("Invaild !! ... Try Again \n");
                fflush(stdin);
            }
            else
            {
                flag = 0 ;
            }
        }

        fflush(stdin);

        if (21 > TempNode->Age)
        {
            flag = 1 ;
            while (flag != 0)
            {
                printf("\nYou have to enter the Guardian National ID \n");
                printf("============================================= \n");
                printf("Enter National ID: ");
                scanf("%s" , LocNationalID);
                strcpy(TempNode->G_ID , LocNationalID);
                if ( 14 != strlen(TempNode->G_ID))
                {
                    printf("Invalid National ID ! ... Try Again \n");
                }
                else
                {
                    flag = 0 ;
                }
            }

        }
        else
        {   
            flag = 1 ;
            while (flag != 0)
            {
                printf("Enter National ID: ");
                scanf("%s" , LocNationalID);
                strcpy(TempNode->N_ID , LocNationalID);
                if ( 14 != strlen(TempNode->N_ID))
                {
                    printf("Invalid National ID ! ... Try Again \n");
                }
                else
                {
                    flag = 0 ;
                }
            }            
        }
        printf("Enter Balance    : ");
        scanf("%i" , &TempNode->Balance);

        // ^Check if there is other users in DataBase or this is first user^
        /* DataBase is Empty */
        if (NULL == *Head)
        {
            *Head = TempNode ;       /* Head of DataBaase points to this user data as it is first user */
        }
        /* DataBase is not Empty */
        else
        {
            LastNode = *Head ;       /* save Head of DataBase into another variable to make itration on it */

            while (NULL != LastNode->NodeLink)
            {
                /* check if NodeLink Points to Null --> to find the last item in DataBase */
                LastNode = LastNode->NodeLink ;
            }
            LastNode->NodeLink = TempNode ;
        }
        system("cls");
        printf("Account Created Successfully \nAnd This is Account Information: \n");
        printf("Name         : %s\n" , TempNode->Name);
        printf("Address      : %s\n" , TempNode->Addr);
        printf("Account ID   : %s\n" , TempNode->ID);
        printf("Account Pass : %s\n" , TempNode->Pass);
        printf("Account State: %s\n" , TempNode->State);
    }
    else
    {
        /* 
         *Do Nothing 
         */
    }
}
/* ================================ */

/**
  * @brief  :   Function to Open Existing Account (Node) from the DataBase (List) 
  * @param  :   pointer to the address of the head of the list
  * @retval :   No return 
  */
void OpenExisting(struct Node **Head)
{
    struct Node *TempNode ;
    uint8 L1   = 0 ;
    uint8 L2   = 0 ;
    uint8 flag = 1;
    uint8 AdminChiose = 0 ;
    uint8 _ID[15];

    while (flag < 4)
    {
        printf("Enter Bank ID :");
        scanf("%s" , _ID);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            printf("Invalid ID ! ... Try Again \n");
            flag++ ;
        }
        else
        {
            system("cls");
            printf(" ------(Welcome %s )------ \n", TempNode->Name);
            printf(" --------------------- \n\n");
            printf("Account ID   : %s\n" , TempNode->ID);
            printf("Account Pass : %s\n" , TempNode->Pass);
            printf("Account State: %s\n" , TempNode->State);
            Sleep(3000);
            flag = 8 ;
        }
    }
    if (flag == 8)
    {
        while (1 != L2)
        {
            system("cls");
            printf(" ------(Welcome)------ \n");
            printf(" --------------------- \n\n");
            printf(" Press [1] --> To Make Transaction\n");
            printf(" Press [2] --> To Change Account Status\n");
            printf(" Press [3] --> To Get Cash \n");
            printf(" Press [4] --> To Deposit in Account \n");
            printf(" Press [0] --> To Return to main menu \n\n");
            printf(" Your Choise :  ");
            scanf("%u" , &AdminChiose);
            switch (AdminChiose)
            {
                case 1 : MakeTransaction(Head) ; break;
                case 2 : ChangeState(Head)     ; break;
                case 3 : GetCash(Head)         ; break;
                case 4 : AddCash(Head)         ; break;
                case 0 : L2 = 1 ; L1 = 5;      ; break;
                default:
                printf("Invalid Chiose ! ... Try Again \n");
                break;
            }
        } 
    }
    else
    {
        Sleep(1000);
    }
    
}
/* ================================ */








/* Function used for Debugging */
void Display_All_Nodes(struct Node **Head)
{
    struct Node *TempNode = *Head;

        printf("-> %s  \n", TempNode->Pass);
        printf("-> %s  \n", TempNode->Name);
        printf("-> %s  \n", TempNode->Addr);
        printf("--> %s \n" , TempNode->ID);
        printf("-> %s  \n", TempNode->State);
        printf("-> %i  \n", TempNode->Age);
        printf("-> %i  \n", TempNode->Balance);
        

}
