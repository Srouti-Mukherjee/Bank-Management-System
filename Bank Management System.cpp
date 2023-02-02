#include<stdio.h>
#include<conio.h>
#include<stdlib.h>    //header file for exit()

int list(); //declaring function list()
void deposit();
void withdraw();
void transfer();
void checkDetail();
int TotalAmount=1000,Amount,Amo,Tr,TotalDeposit=0,TotalWith=0,TotalTr=0;//initialize the variables to 0,so that there cannot be any garbage value
int main()
{
    while(1)
    {
    switch(list())  //calling the list() within the switch()and the function will perform 2 jobs as mentioned below
    //and what the list function will do.It will return any value from 1-5.So make 5 cases,and the code within the switch will be repeated again and again depending on the user's choice,so to make infinite loop putting the switch() inside the while loop.
    {
    case 1:
    
          deposit();
          //adding the total deposited Amount
          TotalDeposit=TotalDeposit+Amount;
          break;
    
    case 2:
    
          withdraw();
          if(Amo<=TotalAmount)
          TotalWith+=Amo;  //but in this case if Amo>TotalAmount then withdraw is not possible but Amo will get added with TotalAmount.But this is wrong.So have to use if condition.
          break;
    
    case 3:
    
         transfer();
    if(Tr<=TotalAmount)
    TotalTr+=Tr;
    break;
    
    case 4:
    
    checkDetail();
    break;
    
    case 5:
    //since the switch() is in infinite while loop so have to keep an exit option.
    exit(0);    //exit(0) means deliberately want to terminate the program.
    //if any invalid number comes then for that have to use default
    default:
    printf("INvalid choice");
    }
    }
}
//now I'll have to create a function named list() bcz I need options of deposit,withdrawal,transfer,balance enquiry
int list()   //since the choice that will be returned is of int type so the list() function should also be of int datatype
//this list() function has 2 job:-1.to print the menu 2.to return the choice entered by the user.
{
    int choice;
    //we'll write here the 4 conditions
    printf("\n1.Deposit Amount: ");
    printf("\n2.Withdraw Amount: ");
    printf("\n3.Transfer Amount: ");
    printf("\n4.Check Detail: ");
    printf("\n5.Exit");   //to come out of the infinite loop.
    printf("\nEnter your choice: "); //means user have to choose one option out of 5.
    scanf("%d",&choice);
    //when we'll call this list() function so what I'll need the choice that user has inputted.That choice I need.That is why we'll have to return choice,as the choice variable has the choice that user has inputted.So we'll have to return the choice variable
    return(choice);
}
void deposit()
{
    printf("Enter the total amount you want to deposit: ");
    scanf("%d",&Amount);
    //after the deposit the previous amount i.e here TotalAmount will increase
    TotalAmount=TotalAmount+Amount;
}
void withdraw()
{
    //if one wants to withdraw then how much amount?
    printf("Enter the amount you wish to withdraw: ");
    scanf("%d",&Amo);
    if(Amo<=TotalAmount)       //as the amount to be withdrawn must be equal to or less than the total amount.If so the amount withdrawn will be subtracted from the total amount else please enter a less amount
    TotalAmount-=Amo;
    else
    printf("\nPlease enter less amount.");
}
void transfer()
{
    printf("Enter the amount you want to transfer: ");
    scanf("%d",&Tr);
    if(Tr<=TotalAmount)
    TotalAmount=TotalAmount-Tr;
    else
    printf("\nEnter a less amount.Transfer is not possible.");
}
void checkDetail()
{
    printf("\nTotal Amount:%d",TotalAmount);
    printf("\nTotal deposited amount:%d",TotalDeposit);// means suppose 1st time deposited 100 then 300, so the value of the Amount variable keeps changing.So the total amount deposited is not stored.So we need to take another variable that will keep on adding the amount deposited.As user has choice to deposit and withdraw as many times as he wishes.
    printf("\nTotal withdrawn amount:%d",TotalWith);
    printf("\nTotal amount transfered:%d",TotalTr);
}
