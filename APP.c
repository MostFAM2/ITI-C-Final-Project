#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "STD_Types.h"
#include "BankSystem.h"

extern struct Node *Head ;

int main (void)
{
    uint8 Choise1;
    uint8 AdminChoise;
    uint8 ClientChoise;
    uint8 M1 ;
    uint8 W1 ;
    uint8 W2 ;
    uint8 W3 ;
    uint8 W4 ;

    uint8 AdminUserName [15];
    uint16 AdminPass ;
    uint8 Adminflag = 0 ;

    uint8 Clientflag = 0 ;
    uint8 ClientCheck = 0 ;

    while (1)
    {
        system("cls");
        ChangeTxtToRED();
        printf(" ------------------- [ Welcome ] ------------------- \n");
        ChangeTxtToBLUE();
        printf("Press [1] --> Admin \n");
        printf("Press [2] --> Client \n");
        printf("-------------------- \n\n");
        printf("Your Choise : ");
        scanf("%u" , &Choise1);
        fflush(stdin);
        switch (Choise1)
        {
            case 1 :
            while(1 != W1 || Adminflag < 3)
            {
                system("cls");
                printf(" ------------------- [ Admin Window ] ------------------- \n");
                printf(" -------------------------------------------------------- \n\n");
                fflush(stdin);
                printf("Enter User Name : ");
                gets(AdminUserName);
                printf("Enter PassWord  : ");
                scanf("%u" , &AdminPass);
                if ( (strcmp(AdminUserName , "Mostaf")) && (1234 == AdminPass))
                {
                    system("cls");
                    ChangeTxtToRED();
                    printf(" ------------------- [ Admin Window ] ------------------- \n");
                    printf(" -------------------------------------------------------- \n\n");
                    printf(" Press [1] --> To Create New Account \n");
                    printf(" Press [2] --> To Open Existing Account \n");
                    printf(" Press [0] --> To Exit the System \n");
                    printf(" ------------------------ \n\n");
                    printf("Your Choise : ");
                    scanf("%u" , &AdminChoise);
                    fflush(stdin);
                    
                    system("cls");
                    printf("------------------- [ Admin Window ] ------------------- \n");
                    printf("-------------------------------------------------------- \n\n");
                    switch(AdminChoise)
                    {
                        case 1 : 
                            ChangeTxtToGREEN();
                            CreateNewAcc(&Head);
                            Sleep(10000);
                            system("cls");
                            break;
                        case 2 :
                            ChangeTxtToYELLOW();
                            OpenExisting(&Head);  
                            Sleep(3000);
                            break;
                        case 0 : 
                            exit(0);
                            system("cls");                
                            break;
                        default: 
                            printf("Choise out of Range ! \n"); 
                            break;
                            
                    }
                }
                else
                {
                    printf("Wrong User Name or Password ... Try Again \n");
                    Adminflag++;
                }
            }
            break;

            case 2 :
                while ( (3 > Clientflag) || (1 != W2) )
                {
                    system("cls");
                    ChangeTxtToBLUE();
                    printf(" ------------------- [ Client Window ] ------------------- \n");
                    printf(" -------------------------------------------------------- \n\n");
                    ClientCheck = CheckID();
                    if (1 == ClientCheck)
                    {
                        while (1 != W2)
                        {
                            printf(" ------(Welcome)------ \n");
                            printf(" --------------------- \n\n");
                            printf(" Press [1] --> To Make Transaction\n");
                            printf(" Press [2] --> To Change Account Status\n");
                            printf(" Press [3] --> To Get Cash \n");
                            printf(" Press [4] --> To Deposit in Account \n");
                            printf(" Press [0] --> To Return to main menu \n\n");
                            printf(" Your Choise :  ");
                            scanf("%u" , &ClientChoise);
                            switch (ClientChoise)
                            {
                                case 1 : MakeTransaction(&Head) ; break;
                                case 2 : ChangeState(&Head)     ; break;
                                case 3 : GetCash(&Head)         ; break;
                                case 4 : AddCash(&Head)         ; break;
                                case 0 : W2 = 1 ;              ; break;
                                default:
                                printf("Invalid Chiose ! ... Try Again \n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("This ID Is Not Found In Oyr System ! \n");
                        Clientflag++;
                        Sleep(2000);
                        system("cls");
                    }
                } 
            break;
               
            break;

            default:
                printf("\n! Your Choise Is out of Range ! ... Try Again \n");
                Sleep(2000);
                W1 = 1 ;
            break;
        }
        
        
    }
    return 0 ;
}



