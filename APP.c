/*
 *   @File    : APP.c
 *   @Author  : Mostafa Mahmoud
 *   @Date    : 28/12/2022
 *   @Brief   : The main Application of Bank Management System
*/

/* ========================== [Section: Includes] ========================== */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "STD_Types.h"
#include "BankSystem.h"
/* ------------------------------------------------------------------------- */

/* =================== [Section: Data Types Declarations] ================== */
extern struct Node *Head ;

uint16 AdminPass ;
uint8 AdminName [10] ;

uint8 P_Choise ;
uint8 Admin_Choise  ;
uint8 Client_Choise ;

uint8 AdWindow1 = 1 ;
uint8 AdWindow2 = 1 ;

uint8 ClWindow1 = 1 ;
uint8 ClWindow2 = 1 ;

uint8 PassCheck;
/* ------------------------------------------------------------------------- */

int main (void)
{
    while (1)
    {
        system("cls");
        ChangeTxtToBLUE();
        printf("------------- [Welcome To ITI Bank System] -------------\n");
        printf("--------------------------------------------------------\n");
        printf("Press [1] --> For Admin  \n");
        printf("Press [2] --> For Clients\n");
        printf("Press [0] --> EXIT       \n");
        printf("--------------------------\n");
        printf(">> Your Choise : ");
        scanf("%c" , &P_Choise);
        fflush(stdin);
        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

        if ( '1' == P_Choise )
        {
            AdWindow1 = 1 ;
            ChangeTxtToYELLOW();
            system ("cls");
            printf("--------------------- [Welcome To Admin Window] ---------------------\n");
            printf("---------------------------------------------------------------------\n");
            printf("\nYou Have To Enter Admin UserName and Password To Enter The System \n");
            printf("-----------------------------------------------------------------\n");
            printf("Enter Admin UserName :  ");
            gets(AdminName);
            fflush(stdin);
            printf("Enter Admin Password :  ");
            scanf("%hu" , &AdminPass);
            fflush(stdin);
            /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

            if ( (1234 == AdminPass) && (0 == strcmp(AdminName , "Mostafa")) )
            {
                while(AdWindow1)
                {
                    AdWindow2 = 1 ;
                    system("cls");
                    ChangeTxtToYELLOW();
                    printf("--------------------- [Welcome To Admin Window] ---------------------\n");
                    printf("---------------------------------------------------------------------\n");
                    printf("Press [1] --> To Create New Account   \n");
                    printf("Press [2] --> To Open Existing Account\n");
                    printf("Press [3] --> To Display All Accounts \n");
                    printf("Press [0] --> To Return To Main Menu  \n");
                    printf("------------------------------------\n");
                    printf(">> Your Choise : ");
                    scanf("%c" , &Admin_Choise);
                    fflush(stdin);
                    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

                    while(AdWindow2)
                    {
                        if ('1' == Admin_Choise)
                        {
                            system("cls");
                            ChangeTxtToYELLOW();
                            printf("--------------------- [Welcome To Admin Window] ---------------------\n");
                            printf("---------------------------------------------------------------------\n");
                            CreateNewAcc(&Head);
                            Sleep(10000);
                            break ;
                        }
                        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

                        else if ('2' == Admin_Choise)
                        {
                            system("cls");
                            ChangeTxtToYELLOW();
                            printf("--------------------- [Welcome To Admin Window] ---------------------\n");
                            printf("---------------------------------------------------------------------\n");
                            OpenExisting(&Head);
                            break ;
                        }
                        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

                        else if ('3' == Admin_Choise)
                        {
                            DisplayAllAcc(Head);
                            break;
                        }
                        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

                        else if ('0' == Admin_Choise)
                        {
                            AdWindow1 = 0 ;
                            break;
                        }
                        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

                        else
                        {
                            ChangeTxtToRED();
                            printf("Your Choise Is Out of Range ... Try Again ! \n");
                            Sleep(2000);
                            break ;
                        }
                    }
                }
            }
            else
            {
                ChangeTxtToRED();
                printf("---- [Wrong UserName or Password] ---- \n");
                Sleep(2000);
            }
        }
        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

        else if ( '2' == P_Choise )
        {
            ClWindow1 = 1 ;
            while (ClWindow1)
            {
                ClWindow2 = 1 ;
                PassCheck = 0 ;
                system("cls");
                ChangeTxtToBLUE();
                printf("--------------------- [Welcome To Client Window] ---------------------\n");
                printf("----------------------------------------------------------------------\n");
                printf("Press [1] --> To Make Transaction\n");
                printf("Press [2] --> To Change Account Status\n");
                printf("Press [3] --> To Change Account Paasword \n");
                printf("Press [4] --> To Add Cash to Account\n");
                printf("Press [5] --> To Get Cash from Account \n");
                printf("Press [6] --> To Dispaly Account Info\n");
                printf("Press [0] --> To Return to main menu \n\n");
                printf("--------------------------------------\n");
                printf(">> Your Choise : ");
                scanf("%c" , &Client_Choise);
                fflush(stdin);
                while (ClWindow2)
                {
                    if ('1' == Client_Choise)
                    {
                        system("cls");
                        ChangeTxtToGREEN();
                        printf("--------------------- [Welcome To Client Window] ---------------------\n");
                        printf("----------------------------------------------------------------------\n");
                        PassCheck = IsPassFound(Head);
                        if (3 == PassCheck)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            ChangeTxtToBLUE();
                            printf("--------------------- [Welcome To Client Window] ---------------------\n");
                            printf("----------------------------------------------------------------------\n");
                            MakeTransaction(&Head);
                            break;
                        }
                    }
                    else if ('2' == Client_Choise)
                    {
                        system("cls");
                        ChangeTxtToGREEN();
                        printf("--------------------- [Welcome To Client Window] ---------------------\n");
                        printf("----------------------------------------------------------------------\n");
                        PassCheck = IsPassFound(Head);
                        if (3 == PassCheck)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            ChangeTxtToBLUE();
                            printf("--------------------- [Welcome To Client Window] ---------------------\n");
                            printf("----------------------------------------------------------------------\n");
                            ChangeState(&Head);
                            break;
                        }
                    }
                    else if ('3' == Client_Choise)
                    {
                        system("cls");
                        ChangeTxtToGREEN();
                        printf("--------------------- [Welcome To Client Window] ---------------------\n");
                        printf("----------------------------------------------------------------------\n");
                        PassCheck = IsPassFound(Head);
                        if (3 == PassCheck)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            ChangeTxtToBLUE();
                            printf("--------------------- [Welcome To Client Window] ---------------------\n");
                            printf("----------------------------------------------------------------------\n");
                            ChangePass(&Head);
                            break;
                        }
                    }
                    else if ('4' == Client_Choise)
                    {
                        system("cls");
                        ChangeTxtToGREEN();
                        printf("--------------------- [Welcome To Client Window] ---------------------\n");
                        printf("----------------------------------------------------------------------\n");
                        PassCheck = IsPassFound(Head);
                        if (3 == PassCheck)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            ChangeTxtToBLUE();
                            printf("--------------------- [Welcome To Client Window] ---------------------\n");
                            printf("----------------------------------------------------------------------\n");
                            AddCash(&Head);
                            break;
                        }
                    }
                    else if ('5' == Client_Choise)
                    {
                        system("cls");
                        ChangeTxtToGREEN();
                        printf("--------------------- [Welcome To Client Window] ---------------------\n");
                        printf("----------------------------------------------------------------------\n");
                        PassCheck = IsPassFound(Head);
                        if (3 == PassCheck)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            ChangeTxtToBLUE();
                            printf("--------------------- [Welcome To Client Window] ---------------------\n");
                            printf("----------------------------------------------------------------------\n");
                            GetCash(&Head);
                            break;
                        }
                    }
                    else if ('6' == Client_Choise)
                    {
                        system("cls");
                        ChangeTxtToBLUE();
                        printf("--------------------- [Welcome To Client Window] ---------------------\n");
                        printf("----------------------------------------------------------------------\n");
                        PassCheck = IsPassFound(Head);
                        if (3 == PassCheck)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            ChangeTxtToBLUE();
                            printf("--------------------- [Welcome To Client Window] ---------------------\n");
                            printf("----------------------------------------------------------------------\n");
                            DisplayAcc(Head->ID);
                            break;
                        }
                    }
                    else if ('0' == Client_Choise)
                    {
                        ClWindow1 = 0 ;
                        break ;
                    }
                    else
                    {
                        ChangeTxtToRED();
                        printf("Your Choise Is Out of Range ... Try Again ! \n");
                        Sleep(2000);
                        break ;
                    }
                }
            }
        }
        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

        else if ( '0' == P_Choise )
        {
            system("cls");
            ChangeTxtToRED();
            printf("System Is Closing Now .... \n");
            Sleep(2000);
            system("cls");
            ChangeTxtToBLUE();
            printf("System Is Closed Now ! ... \n  [THANK YOU] ");
            break;
        }
        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

        else
        {
            ChangeTxtToRED();
            printf("Your Choise Is Out of Range ... Try Again ! \n");
            Sleep(2000);
        }
    }
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    return 0 ;
}



