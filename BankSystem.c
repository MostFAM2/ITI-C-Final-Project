/*
 *   @File    : BankSystem.c
 *   @Author  : Mostafa Mahmoud
 *   @Date    : 22/12/2022
 *   @Brief   : Implementation of Bank Management System 
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

/* ------------- [Colors Functions Start] ------------- */
/**
  * @brief  :   Function to Change Text color on CMD to RED
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToRED (void)
{
    printf("\033[0;31m");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to YELLOW 
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToYELLOW (void)
{
    printf("\033[0;33m");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to BLACK
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToBLACK (void)
{
    printf("\033[0;30m");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to GREEN
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToGREEN (void)
{
    printf("\033[0;32m");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to BLUE
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToBLUE (void)
{
    printf("\e[1;96m");
}
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to Original
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ResetTxtColor (void)
{
    printf("\033[0m");
}
/* ================================ */
/* ------------- [Colors Functions End] ------------- */

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
        if (0 == strcmp(TempNode->ID , id))
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

		if(0 == strcmp(TempNode->ID,IDCopy))
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
  * @brief  :   Function to Search if Password of Account Found or Not 
  * @param  :   pointer to the address of the head of the list
  * @retval :   flag --> Indication if password exisit or not 
  */
uint8 IsPassFound(struct Node *Head)
{
    struct Node *TempNode = Head ;
    uint8 InPass [20];
    uint8 flag  = 0;


    while (3 > flag)
    {
        TempNode = Head ;
        ChangeTxtToGREEN();
        printf("\nEnter Password of Your Account : ");
        scanf("%s" , InPass);
        fflush(stdin);
        while (NULL != TempNode)
        {
            if (0 == strcmp(TempNode->Pass , InPass))
            {
                break ;
            }
            else
            {
                TempNode = TempNode->NodeLink ;
            }
        }
        if (NULL != TempNode)
        {
            ChangeTxtToGREEN();
            printf("------------- [Welcome Back] ------------- \n\n");
            Sleep(2000);
            break;
        }
        else
        {
            ChangeTxtToRED();
            printf("Wrong Password !!... Try Again \n");
            Sleep(2000);
            flag++;
        }
    }
   return flag ;
}
/* ================================ */

/**
  * @brief  :   Function to Display Password in Stars Form 
  * @param  :   No Input
  * @retval :   PassWord Hidden 
  */
// uint8* StarPassword()
// {
// 	uint8 i = 0;
// 	uint8 ch;
// 	static uint8 H_Pass[11];
// 	while ( (ch = _getch()) != 13 )
// 	{
// 		H_Pass[i] = ch;
// 		i++;
// 		printf("*");
// 	}
// 	H_Pass[i] = '\0';	
// 	return H_Pass;
// }
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
    ChangeTxtToYELLOW();
    uint8 flagSrc  = 0;
    uint8 flagDest = 0;
    uint32 CashToTransfer ;
    uint8 _ID1[15];
    uint8 _ID2[15];
    struct Node *Src_Node ;
    struct Node *Dest_Node ;
    
    while (flagSrc < 3)
    {
        printf("Enter Bank ID :");
        scanf("%s" , _ID1);
        fflush(stdin);
        Src_Node = CurrentNode(_ID1);
        if (NULL == Src_Node)
        {
            ChangeTxtToRED();
            printf("Invalid Bank ID ! ... Try Again \n");
            Sleep(2000);
            flagSrc++ ;
        }
        else
        {
            flagDest = 0;
            while (flagDest < 3)
            {
                ChangeTxtToYELLOW();
                printf("Enter ID of Account You Want To Transfer To : ");
                scanf("%s" , _ID2);
                fflush(stdin);
                Dest_Node = CurrentNode(_ID2);
                if (NULL == Dest_Node)
                {
                    ChangeTxtToRED();
                    printf("Invalid Destination ID ! ... Try Again \n");
                    Sleep(2000);
                    flagDest++ ;
                }
                else
                {
                    ChangeTxtToYELLOW();
                    printf("Enter Amount of Money You Want To Transfer : ");
                    scanf("%i" , &CashToTransfer);
                    fflush(stdin);
                    if ( (0 == strcmp(Src_Node->State , "active")) && (0 == strcmp(Dest_Node->State , "active")) )
                    {
                        if (CashToTransfer > Src_Node->Balance)
                        {
                            ChangeTxtToRED();
                            printf("Amount of Money You Want To Transfer is More than The Actual Balance ! \n");
                            Sleep(3000);
                        }
                        else
                        {
                            ChangeTxtToBLUE();
                            printf("\nSuccessful Transaction Operation \n");
                            Src_Node->Balance = Src_Node->Balance-CashToTransfer ;
                            Dest_Node->Balance = Dest_Node->Balance+CashToTransfer ;
                            printf("Money Transferd Successfully \n");
                            printf("---------------------------- \n");
                            printf("Your New Balance Is \" %u \" \n" , Src_Node->Balance);
                            Sleep(5000);
                            break ;
                        }  
                    }
                    else
                    {
                        ChangeTxtToRED();
                        printf("This Account Is Deactivated ! \n");
                        printf("You Can't Do Any Operation  ! \n");
                        Sleep(3000);
                        break;
                    }
                    break ;
                }
            }
            break ;
        }
    }
}
/* ================================ */

/**
  * @brief  :   Function to Add Balance to an account   
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void AddCash(struct Node **Head)
{
    ChangeTxtToYELLOW();
    uint8 flag  = 0;
    uint32 CashToAdd ;
    uint8 _ID[15];
    struct Node *TempNode ;
    
    while (flag < 3)
    {
        printf("Enter Bank ID : ");
        scanf("%s" , _ID);
        fflush(stdin);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            ChangeTxtToRED();
            printf("Invalid ID ! ... Try Again \n");
            flag++ ;
        }
        else
        {
            ChangeTxtToYELLOW();
            flag = 0 ;
            printf("Enter Amount of Money You Want To Add : ");
            scanf("%i" , &CashToAdd);
            fflush(stdin);
            if ( (!strcmp(TempNode->State , "active"))  )
            {
                ChangeTxtToGREEN();
                TempNode->Balance = TempNode->Balance+CashToAdd ;
                printf("Successful Deposit Operation \n");
                printf("---------------------------- \n");
                printf("Your New Balance Is \"%u\" \n" , TempNode->Balance);
                Sleep(5000);
                break ;
            }
            else
            {
                ChangeTxtToRED();
                printf("This Account Is Deactivated ! \n");
                printf("You Can't Do Any Operation  ! \n");
                Sleep(3000);
                break ;
            }
        }
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
    ChangeTxtToYELLOW();
    uint8 flag  = 0;
    uint32 CashToGet ;
    uint8 _ID[15];
    struct Node *TempNode ;
    
    while (flag < 3)
    {
        printf("Enter Bank ID : ");
        scanf("%s" , _ID);
        fflush(stdin);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            ChangeTxtToRED();
            printf("Invalid ID ! ... Try Again \n");
            flag++;
        }
        else
        {
            ChangeTxtToYELLOW();
            flag = 0 ;
            printf("Enter Amount of Money You Want To Get : ");
            scanf("%i" , &CashToGet);
            fflush(stdin);
            if ( (0 == strcmp(TempNode->State , "active"))  )
            {
                if (CashToGet > TempNode->Balance)
                {
                    ChangeTxtToRED();
                    printf("Amount of Money You Want To Get is More than The Actual Balance ! \n");
                    Sleep(5000); 
                    break ;
                }
                else
                {
                    ChangeTxtToGREEN();
                    TempNode->Balance = TempNode->Balance-CashToGet ;
                    printf("Successful Operation \n");
                    printf("Your New Balance Is \" %u \" \n" , TempNode->Balance);
                    Sleep(5000);
                    break ;
                }
            }
            else
            {
                ChangeTxtToRED();
                printf("This Account Is Deactivated ! \n");
                printf("You Can't Do Any Operation  ! \n");
                Sleep(3000);
                break ;
            }
        }
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
    uint8 flag  = 0;
    uint8 flag1 = 0 ;
    uint8 _ID[15];
    uint8 _State[15];
    struct Node *TempNode ;
    while (3 > flag1)
    {
        printf("\nEnter Bank ID : ");
        scanf("%s" , _ID);
        fflush(stdin);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            printf("Invalid ID ! ... Try Again \n");
            flag1++ ;
        }
        else
        {
            flag = 0 ;
            while (flag < 3)
            {
                printf("Account Status Is Now %s \n\n" , TempNode->State);
                printf("Enter New Account Status : [Active - Closed]\n");
                gets(_State);
                fflush(stdin);
                if ( (0 == strcmp(_State , "Closed")) )
                {
                    ChangeTxtToRED();
                    strcpy(TempNode->State, "closed");
                    printf("Account Is Now Closed ! \n");
                    Sleep(3000);
                    break ;
                }
                else if ( (0 == strcmp(_State , "Active")) )
                {
                    ChangeTxtToGREEN();
                    strcpy(TempNode->State, "active");
                    printf("Account Is Now Active ! \n");
                    Sleep(3000);
                    break ;
                }
                else
                {
                    ChangeTxtToRED();
                    printf("\nThis Status Is Not Available ... Try Again ! \n");
                    flag++;
                }
            }
            break ;
        }
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


        printf("Please Fill Account Information \n");
        printf("=============================== \n\n");
        fflush(stdin);
        printf("Enter User Name  : ");
        gets(TempNode->Name);
        
        fflush(stdin);
        printf("Enter Address    : ");
        gets(TempNode->Addr);
        
        while (flag != 0)
        {
            ChangeTxtToYELLOW();
            printf("Enter User Age   : ");
            if( (scanf("%u%c", &TempNode->Age , &term) != 2 ) || (term != '\n') )
            {
                ChangeTxtToRED();
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
            ChangeTxtToRED();
            printf("[Note] !!.. Your Age Is Less Than 21 Year\nYou Have to Enter Guardian National ID \n");
            flag = 1 ;
            while (flag != 0)
            {
                ChangeTxtToYELLOW();
                printf("Enter Guardian National ID [Must Be 14 Number] : ");
                scanf("%s" , LocNationalID);
                fflush(stdin);
                strcpy(TempNode->G_ID , LocNationalID);
                if ( 14 != strlen(TempNode->G_ID))
                {
                    ChangeTxtToRED();
                    printf("Invalid Guardian National ID ! ... Try Again \n");
                    printf("Guardian National ID [Must Be 14 Number]\n");
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
                ChangeTxtToYELLOW();
                printf("Enter National ID [Must Be 14 Number] : ");
                scanf("%s" , LocNationalID);
                fflush(stdin);
                strcpy(TempNode->N_ID , LocNationalID);
                if ( 14 != strlen(TempNode->N_ID))
                {
                    ChangeTxtToRED();
                    printf("Invalid National ID ! ... Try Again \n");
                    printf("National ID [Must Be 14 Number]\n");
                }
                else
                {
                    flag = 0 ;
                }
            }            
        }
        ChangeTxtToYELLOW();
        printf("Enter The Balance: ");
        scanf("%i" , &TempNode->Balance);
        fflush(stdin);
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
        printf("Account Created Successfully \nAccount Information \e[1;96m [Save ID & Password For Future Uses]\033[0;33m\n");
        printf("================================================ \n");
        printf("Name            : %s\n" , TempNode->Name);
        printf("Address         : %s\n" , TempNode->Addr);
        printf("Account ID      : %s\n" , TempNode->ID);
        printf("Account Pass    : %s\n" , TempNode->Pass);
        printf("Account Balance : %i\n" , TempNode->Balance);
        printf("Account State   : %s\n" , TempNode->State);
        fflush(stdin);
        fflush(stdout);
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
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void OpenExisting(struct Node **Head)
{
    ChangeTxtToYELLOW();
    struct Node *TempNode ;
    uint8 L1   = 1 ;
    uint8 L2   = 1 ;
    uint8 flag = 0 ;
    uint8 AdminChiose ;
    uint8 _ID[15];

    while (flag < 3)
    {
        ChangeTxtToYELLOW();
        printf("Enter Bank ID :");
        scanf("%s" , _ID);
        fflush(stdin);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            ChangeTxtToRED();
            printf("Invalid ID ! ... Try Again \n");
            Sleep(2000);
            flag++ ;
        }
        else
        {
            ChangeTxtToBLUE();
            system("cls");
            printf("------(Welcome to %s 's Account)------ \n", TempNode->Name);
            printf("--------------------------------------------- \n\n");
            printf("Account ID      : %s\n" , TempNode->ID);
            printf("Account Pass    : %s\n" , TempNode->Pass);
            printf("Account Balance : %i\n" , TempNode->Balance);
            printf("Account State   : %s\n" , TempNode->State);
            printf("========================================== \n");
            Sleep(5000);
            while (L1)
            {
                ChangeTxtToYELLOW();
                L1 = 1 ;
                system("cls");
                printf("------(Welcome to %s 's Account)------ \n", TempNode->Name);
                printf("--------------------------------------------- \n\n");
                printf("Press [1] --> To Make Transaction\n");
                printf("Press [2] --> To Change Account Status\n");
                printf("Press [3] --> To Get Cash from Account\n");
                printf("Press [4] --> To Add Cash to Account \n");
                printf("Press [5] --> To Display Account Info\n");
                printf("Press [0] --> To Return to main menu \n\n");
                printf("--------------------------------------\n");
                printf(">> Your Choise :  ");
                scanf("%c" , &AdminChiose);
                fflush(stdin);
                
                while (L2)
                {
                    if ('1' == AdminChiose)
                    {
                        ChangeTxtToYELLOW();
                        system("cls");
                        printf("------(Welcome to %s 's Account)------ \n", TempNode->Name);
                        printf("--------------------------------------------- \n\n");
                        MakeTransaction(Head) ;
                        break ;
                    }
                    else if ('2' == AdminChiose)
                    {
                        ChangeTxtToYELLOW();
                        system("cls");
                        printf("------(Welcome to %s 's Account)------ \n", TempNode->Name);
                        printf("--------------------------------------------- \n\n");
                        ChangeState(Head) ;
                        break ;
                    }
                    else if ('3' == AdminChiose)
                    {
                        ChangeTxtToYELLOW();
                        system("cls");
                        printf("------(Welcome to %s 's Account)------ \n", TempNode->Name);
                        printf("--------------------------------------------- \n\n");
                        GetCash(Head) ; 
                        break;
                    }
                    else if ('4' == AdminChiose)
                    {
                        ChangeTxtToYELLOW();
                        system("cls");
                        printf("------(Welcome to %s 's Account)------ \n", TempNode->Name);
                        printf("--------------------------------------------- \n\n");
                        AddCash(Head) ; 
                        break;
                    }
                    else if ('5' == AdminChiose)
                    {
                        system("cls");
                        DisplayAcc(TempNode->ID);
                        break;
                    }
                    else if ('0' == AdminChiose)
                    {
                        L1 = 0 ;
                        flag = 8 ;
                        break;
                    }
                    else
                    {
                        ChangeTxtToRED();
                        printf("Invalid Chiose ! ... Try Again \n");
                        Sleep(2000);
                        break;
                    }
                }
            } 
        }
    }
 
}
/* ================================ */

/**
  * @brief  :   Function to Diplay Account information 
  * @param  :   pointer to Account ID
  * @retval :   No return 
  */
void DisplayAcc(sint8* u8IDCopy)
{
    struct Node *TempNode ;
    uint8 _ID [15] ;
    TempNode = CurrentNode(u8IDCopy);
    ChangeTxtToBLUE();
    printf("Enter Bank ID :");
    scanf("%s" , _ID);
    fflush(stdin);
    if(0 == (strcmp(TempNode->ID , _ID)))
    {
        ChangeTxtToBLUE();
        printf("\n---------- [%s's Account] ----------\n" , TempNode->Name);
        printf("-----------------------------------------\n");
        printf("Name            : %s\n" , TempNode->Name);
        printf("Address         : %s\n" , TempNode->Addr);
        printf("Account ID      : %s\n" , TempNode->ID);
        printf("Account Pass    : %s\n" , TempNode->Pass);
        printf("Account Balance : %i\n" , TempNode->Balance);
        printf("Account State   : %s\n" , TempNode->State);
        printf("============================================\n\n");
        TempNode = TempNode->NodeLink;
        Sleep(10000);
    }
    else
    {
        ChangeTxtToRED();
        printf("\n    .... [No Information To Display] ....\n");
        Sleep(2000);
    }
    system("cls");
}

/**
  * @brief  :   Function to Diplay All Accounts information 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void DisplayAllAcc(struct Node *Head)
{
    struct Node *TempNode = Head;

    system("cls");
    ChangeTxtToBLUE();
    printf("-------------- [All Accounts Information] --------------\n");
    if(NULL == TempNode)
    {
        ChangeTxtToRED();
        printf("\n    .... [No Accounts in System Yet] ....\n");
        Sleep(5000);
    }
    else
    {
        ChangeTxtToBLUE();
        while(TempNode != NULL)
        {
            printf("\n---------- [%s's Account] ----------\n" , TempNode->Name);
            printf("-----------------------------------------\n");
            printf("Name            : %s\n" , TempNode->Name);
            printf("Address         : %s\n" , TempNode->Addr);
            printf("Account ID      : %s\n" , TempNode->ID);
            printf("Account Pass    : %s\n" , TempNode->Pass);
            printf("Account Balance : %i\n" , TempNode->Balance);
            printf("Account State   : %s\n" , TempNode->State);
            printf("============================================\n\n");
            TempNode = TempNode->NodeLink;
        }
        if(NULL == TempNode)
        {
            printf("--------------- [End of List] --------------\n");
        }
        Sleep(15000);
    }
    system("cls");
}
/* ================================ */

/**
  * @brief  :   Function to Diplay All Accounts information 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void ChangePass(struct Node **Head)
{
    ChangeTxtToGREEN();
    uint8 flag  = 0;
    uint8 flag1  = 0;
    uint8 NewPass [20] ;
    uint8 _ID[15];
    struct Node *TempNode ;
    
    while (flag < 3)
    {
        ChangeTxtToGREEN();
        printf("Enter Bank ID  : ");
        scanf("%s" , _ID);
        fflush(stdin);
        TempNode = CurrentNode(_ID);
        if (NULL == TempNode)
        {
            ChangeTxtToRED();
            printf("Invalid ID ! ... Try Again \n");
            flag++;
        }
        else
        {
            if ( (0 == strcmp(TempNode->State , "active")) )
            {
                while (3 > flag1)
                {
                    ChangeTxtToGREEN();
                    printf("Enter New Password [Must Be 6 Digits] : ");
                    gets(NewPass);
                    fflush(stdin);
                    if (6 == strlen(NewPass))
                    {
                        ChangeTxtToBLUE();
                        strcpy(TempNode->Pass , NewPass);
                        printf("Password Changed Successfully \n");
                        printf("New Password Is : %s \n", TempNode->Pass);
                        ChangeTxtToRED();
                        printf("SAVE IT !!.. \n");
                        ChangeTxtToGREEN();
                        Sleep(5000);
                        flag = 8 ;
                        break ;
                    }
                    else
                    {
                        ChangeTxtToRED();
                        printf("Invalid !!.. New Password [Must Be 6 Digits] \n");
                        flag1++;
                        Sleep(2000);
                    }
                }
                
            }
            else
            {
                ChangeTxtToRED();
                printf("This Account Is Deactivated ! \n");
                printf("You Can't Do Any Operation  ! \n");
                Sleep(3000);
                break ;
            }
        }
    }
}
/* ================================ */


