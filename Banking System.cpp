/*
BankingSystem.cpp
Amir Yousef
COP3014-Summer 2010
Project-4 Solution
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void newAccount();           //store a person's account ID, passcode, last name, first name, and balance. 
void deleteAccount();        //delete a person's account ID, passcode, last name, first name, and balance.     
void depositToAccount();     //deposite amount of money to a person's account. 
void balanceInquiry();       //generates information about account or display all when type -1.
void saveToFile();           //save all accounts information in a txt file.
void loadFromFile();         //recall all accounts information from a txt file.
void withdrawFromAccount();  //withdraw amount of money to a person's account.
void Exit();                 //exit the program.
char Menu();                 //to choose operation.
string firstName[' '], lastName[' '];                             //identify the person's name.
double deposit[' '], with_draw[' '], account[' '];                //identify the balance after withdarw and/or deposite. 
int account_no, accountcounter, Account_id[' '], passcode[' '];   //identify the account ID and the passcode.

int main()
{ 
cout << "*** Welcome to the Banking System ***\n\n";
char choice;
do
{
choice = Menu();
switch(choice)
{
case '1' :newAccount(); break;             //create a new account.
case '2' :deleteAccount(); break;          //delete an existing account.
case '3' :balanceInquiry();break;          //check the balance of an account.
case '4' :saveToFile(); break;             //save all accounts information to file.
case '5' :loadFromFile(); break;           //load all accounts information from file.
case '6' :Exit ();break;                   //exist the program.
case '7' :withdrawFromAccount();break;     //withdraw from account.
case '8' :depositToAccount(); break;       //deposite to account.
}
}
while( choice != '6' ); 
return 0;
} 

char Menu()
{
char selection;                            //the user have to pick a number to clear the operation. 
cout << "(1) Add Account\n";
cout << "(2) Delete Account\n";
cout << "(3) Account Inquiry\n";
cout << "(4) Save Accounts to File\n";
cout << "(5) Load Accounts from File\n";
cout << "(6) Exit\n";
cout << "(7) Withdraw Money from an Account\n";
cout << "(8) Deposit Money into an Account\n ";
cout << "\nEnter selection: ";
cin >> selection;
return selection;
}

void newAccount()                                 //add new account.
{
system ("cls");                                   //this will clear the screen.
cout << "Enter the accountID: ";                  //ask user for account ID.
cin >> Account_id[ accountcounter ];              //insert the new account ID.
account[ accountcounter ] = accountcounter;       //add one account to the counter.

cout << "Enter the passcode: ";                   //ask the user to insert a passcode.
cin >> passcode[ accountcounter ];                //add the passcode to the counter.

cout << "Enter the first name: ";                 //ask the user to insert the first name.
cin >> firstName[ accountcounter ];               //add the name to the counter.

cout << "Enter the last name: ";                  //ask the user to insert the last name.
cin >> lastName[ accountcounter ];                //add the name to the counter.

cout << "Enter the starting balance: $";          //ask the user to insert his starting balance.
cin >> deposit[ accountcounter ];                 //add the the starting balance to the counter.


cout << "\nAccount added successfully.\n\n";      //print account added successfully on the screen. 
accountcounter++;                                 //add one more account to the counter.
}

void depositToAccount()                           //deposite to account. 
{
double cash_deposit;
    system ("cls");                               //this will clear the screen.
    cout << "Enter the Account Number: ";         //ask the user to enter his account number.
    cin >> account_no;                            //insert the account number.
    cout << "Enter Amount to Deposit: $";         //ask the user to insert his desposite.
    cin >> cash_deposit;                          //insert the deposite amount.
    deposit[ account_no ] = deposit[ account_no ] + cash_deposit;              //add the deposite to the account balance. 
    cout << "Transaction Approved" << endl << endl;                            //print transaction approved and print the information on screen. 
cout << "Account ID" << setw(13) << "Passcode" << setw(13) << "Last Name" << setw(13) << "First Name" << setw(13) << "Balance" << endl;
cout << "===============================================================" << endl;
cout << setw(10) << account_no << setw(13) << passcode[ account_no ] << setw(13) << lastName[ account_no ] << setw(13) << firstName[ account_no ] << setw(13) << deposit[account_no] - with_draw[account_no] << endl;
cout << endl;
}

void withdrawFromAccount()                        //withdraw from account.
{ system ("cls");                                 //this will clear the screen.
    double withdraw;                              //define withdraw.
    cout << "Enter the Account Number: ";         //ask for the account number.
    cin >> account_no;                            //insert the account number.
    cout << "Enter Amount to Withdraw: $";        //ask for the amount to withdraw.
    cin >> withdraw;                              //insert the amount.
    with_draw[ account_no ] = with_draw[ account_no ] + withdraw;              //the new balance after withdraw.
    cout << "Transaction Approved" << endl << endl;                            //print transaction approved on screen. 
cout << "Account ID" << setw(13) << "Passcode" << setw(13) << "Last Name" << setw(13) << "First Name" << setw(13) << "Balance" << endl;
cout << "===============================================================" << endl;
cout << setw(10) << account_no << setw(13) << passcode[ account_no ] << setw(13) << lastName[ account_no ] << setw(13) << firstName[ account_no ] << setw(13) << deposit[account_no] - with_draw[account_no] << endl;
cout << endl;
    if ( withdraw > deposit[ account_no ] )       //if no enough funds.
    {
    cout<<"\nNo Enough Funds" << endl;            //print no enough funds. 
    } 
    }
    
void balanceInquiry()                             //to check the balance.
{
system ("cls");                                   //this will clear the screen.
cout << "Enter the account ID (-1 for all): ";    //ask for the account ID.  
cin >> account_no;                                //insert the account ID.
cout << endl;
if ( account_no != -1 )                           //if the account number not equal -1 print the account information. 
{                                               
cout << "Account ID" << setw(13) << "Passcode" << setw(13) << "Last Name" << setw(13) << "First Name" << setw(13) << "Balance" << endl;
cout << "===============================================================" << endl;
cout << setw(10) << account_no << setw(13) << passcode[ account_no ] << setw(13) << lastName[ account_no ] << setw(13) << firstName[ account_no ] << setw(13) << deposit[account_no] - with_draw[account_no] << endl;
cout << endl;
}
if ( account_no == -1 )                           //if the account number is equal -1 print all accounts information.
{
cout << "Account ID" << setw(13) << "Passcode" << setw(13) << "Last Name" << setw(13) << "First Name" << setw(13) << "Balance" << endl;
cout << "===============================================================" << endl;
for ( int i = 0; i < accountcounter; i++ )
{
cout << setw(10) << Account_id[ i ] << setw(13) << passcode[ i ] << setw(13) << lastName[ i ] << setw(13) << firstName[ i ] << setw(13) << deposit[ i ] - with_draw[ i ] << endl;
cout << endl;
}
}
}

void Exit()                                      //exit the program.
{
system("cls");                                   //clear th screen.
exit(0);                                         //exit.
}

void saveToFile()                                //save accounts to txt file.
{
system ("cls");                                  //clear the screen.
string fileName;                                 //declare fileName as a string. 
cout << "Enter the filename: ";                  //ask for the file name. 
cin >> fileName;                                 //user will insert the file name.
ofstream outfile("bankaccounts.txt");            //output the information into file named bankaccounts.
outfile << "Account ID" << setw(13) << "Passcode" << setw(13) << "Last Name" << setw(13) << "First Name" << setw(13) << "Balance" << endl;
outfile << "===============================================================" << endl;
for ( int i = 0; i < accountcounter; i++ )
{
outfile << setw(10) << Account_id[ i ] << setw(13) << passcode[ i ] << setw(13) << lastName[ i ] << setw(13) << firstName[ i ] << setw(13) << deposit[ i ] - with_draw[ i ] << endl;
}
outfile.close();
cout << "\nFile " << fileName << ".txt saved successfully.\n" << endl;   //print file saved successfully on the screen. 
}

void loadFromFile()                             //load accounts information from txt file.
{
system ("cls");                                 //clear the screen.
string fileName;                                //declare fileName as a string.
cout << "Enter the filename: ";                 //ask for the file name.
cin >> fileName;                                //insert the file name.
ifstream infile("bankaccounts.txt");            //input stream the file from txt file.
infile.close();                                 //close the stream.
cout << "\nFile " << fileName << ".txt loaded successfully.\n" << endl;   //print file loaded successfully on the screen.
}

void deleteAccount()                            //delete account.
{
system ("cls");                                 //clear the screen.
int account_no;                                 //declare the account number.
cout << "Enter the accountID: ";                //ask for the account ID.
cin >> account_no;                              //insert the account ID.
cout << "\nAccount erased.\n" << endl;          //print account erased. 
}

