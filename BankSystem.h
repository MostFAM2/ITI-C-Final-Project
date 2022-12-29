/*
 *   @File    : BankSystem.h
 *   @Author  : Mostafa Mahmoud
 *   @Date    : 22/12/2022
 *   @Brief   : Implementation of Bank Management System Based on Linked List Data Structure
*/

#ifndef BANKSYSTEM_H_
#define BANKSYSTEM_H_

/* ========================== [Section: Includes] ========================== */
#include "STD_Types.h"
/* ------------------------------------------------------------------------- */

/* =================== [Section: Data Types Declarations] ================== */
struct Node
{
  /* Data Required */
  uint8   Name[100];
  uint8   Addr[100];
  uint8   State[20];
  sint8   ID [20]  ;
  sint8   Pass [20];
  uint8   N_ID [20];
  uint8   G_ID [20];
  uint8   Age      ;
  uint32  Balance  ;

  /* Pointer points to struct (Node) to hold the address of next node */
  struct Node *NodeLink ;           
};
/* ------------------------------------------------------------------------- */

/* ====================== [Section: Helper Functions] ====================== */
/**
  * @brief  :   Function to Check on user ID 
  * @param  :   No Input Parameters 
  * @retval :   Return Check : [0] if ID is not found -- [1] if ID is valid
  */
uint8 CheckID(void);
/* ================================ */

/**
  * @brief  :   Function to Generate Account ID 
  * @param  :   No Input
  * @retval :   Return Loc_ID --> The New Generated ID 
  */
sint8* AccID_Gen();
/* ================================ */

/**
  * @brief  :   Function to Generate Account Password
  * @param  :   No Input
  * @retval :   Return Loc_Pass --> The New Generated Password 
  */
sint8* AccPass_Gen();
/* ================================ */

/**
  * @brief  :   Function to Search on the Account (Node) from the DataBase (List) 
  * @param  :   pointer to Account ID To Search
  * @retval :   TempNode --> struct holds the needed Node
  */
struct Node *CurrentNode(uint8* IDCopy);
/* ================================ */

/**
  * @brief  :   Function to Search if Password of Account Found or Not 
  * @param  :   pointer to the address of the head of the list
  * @retval :   flag --> Indication if password exisit or not 
  */
uint8 IsPassFound(struct Node *Head);
/* ================================ */

/**
  * @brief  :   Function to Display Password in Stars Form 
  * @param  :   No Input
  * @retval :   PassWord Hidden 
  */
// uint8* StarPassword(void);
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to RED
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToRED (void);
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to YELLOW 
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToYELLOW (void);
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to BLACK
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToBLACK (void);
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to GREEN
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToGREEN (void);
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to BLUE
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ChangeTxtToBLUE (void);
/* ================================ */

/**
  * @brief  :   Function to Change Text color on CMD to Original
  * @param  :   No Input Parameter
  * @retval :   No Return
  */
void ResetTxtColor (void);
/* ================================ */
/* ------------------------------------------------------------------------- */

/* =================== [Section: Functions Declarations] =================== */

/**
  * @brief  :   Function to Create new Account (Node) to the DataBase (List) 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void CreateNewAcc(struct Node **Head);
/* ================================ */

/**
  * @brief  :   Function to Open Existing Account (Node) from the DataBase (List) 
  * @param  :   pointer to the address of the head of the list
  * @retval :   No return 
  */
void OpenExisting(struct Node **Head);
/* ================================ */

/**
  * @brief  :   Function to Make Transaction From Account to another Account 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void MakeTransaction(struct Node **Head);
/* ================================ */


/**
  * @brief  :   Function to Make Transaction From Account to another Account 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void MakeTransaction(struct Node **Head);
/* ================================ */

/**
  * @brief  :   Function to Add Balance to an account   
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void AddCash(struct Node **Head);
/* ================================ */

/**
  * @brief  :   Function to Get Cash from user account Balance  
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void GetCash(struct Node **Head);
/* ================================ */

/**
  * @brief  :   Function to Edit on user account Status (Node) from the DataBase (List) 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void ChangeState(struct Node **Head);
/* ================================ */

/**
  * @brief  :   Function to Diplay All Accounts information 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void DisplayAllAcc(struct Node *Head);
/* ================================ */

/**
  * @brief  :   Function to Diplay Account information 
  * @param  :   pointer to Account ID
  * @retval :   No return 
  */
void DisplayAcc(sint8* u8IDCopy);
/* ================================ */

/**
  * @brief  :   Function to Diplay All Accounts information 
  * @param  :   pointer points to the address of the head of the list
  * @retval :   No return 
  */
void ChangePass(struct Node **Head);
/* ================================ */
/* ------------------------------------------------------------------------- */

#endif /* BANKSYSTEM_H_ */
