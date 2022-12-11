#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include </home/karima/Downloads/conio2.h>

typedef struct
{
    char phone [50];
    char accountNumber [50];
    char username [50];
    char password [50];
    int balance;
} User;

void connection (MYSQL *conn)
{
    if (mysql_real_connect(conn,
                           "localhost", "root", "19721998","bankdb",
                           0, NULL, 0) == NULL)

    {
        finish_with_error(conn);
    }

    if (mysql_query(conn, "CREATE DATABASE IF NOT EXISTS bankdb"))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

}

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void Register ()
{
    User *user;
    MYSQL *conn=mysql_init(NULL);
    connection(conn);
    system("clear");
    printf("\n ******************* Add New Account ******************* \n");
    printf("\n Enter your account number: \t");
    scanf("%s",user->accountNumber);

    printf("\n Enter your user name: \t");
    scanf("%s",user->username);

    printf("\n Enter your phone number :\t");
    scanf("%s",user->phone);

    printf("\n Enter your password :\t");
    scanf("%s",user->password);

    char query[1024];

    user->balance=0;

    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS users(accountNumber VARCHAR(255)PRIMARY KEY ,username VARCHAR(255),phone VARCHAR(255),password VARCHAR(255), balance INT default 0)"))

    {
        finish_with_error(conn);
    }
    sprintf(query,
            "INSERT INTO users (accountNumber,username,phone,password,balance) VALUES ('%s','%s','%s','%s','%d')",user->accountNumber,user->username,user->phone,user->password,user->balance);
    if (mysql_query(conn,query))
    {
        printf("\n unable to insert data into user table \n");
        finish_with_error(conn);
    }
    mysql_close(conn);
    printf("data inserted successfully \n");
}

void menu()
{
    printf("\n Press 1 for Account Details");
    printf("\n Press 2 for adding fund");
    printf("\n Press 3 for cash withdraw");
    printf("\n Press 4 for online transfer");
    printf("\n Press 5 for changing password \n\n");
}

void Login ()
{
    User *user;
    int amount;
    char query[1024];
    MYSQL *conn=mysql_init(NULL);
    char continuer;

    MYSQL_ROW mysqlRow;
    MYSQL_ROW mysqlRow2;
    MYSQL_FIELD *mysqlFields;
    int numRows,numRows2;
    unsigned int numFields;
    int trans_mt;
    char accountNumber [50];
    char password [50];

    system("clear");
    connection(conn);
    printf("\n Account number :\t");
    scanf("%s",user->accountNumber);
    printf("\n Password :\t");
    scanf("%s",user->password);

    system("clear");

    sprintf(query,"select * from users where accountNumber=('%s')and password=('%s') ",user->accountNumber,user->password);

    if (mysql_query(conn,query))
    {

        finish_with_error(conn);
    }

    MYSQL_RES *mysqlResult=mysql_store_result(conn);

    if (mysqlResult)
    {
        numRows=mysql_num_rows(mysqlResult);
        numFields=mysql_num_fields(mysqlResult);
        while ((mysqlRow=mysql_fetch_row(mysqlResult)))
        {
            while(mysqlFields= mysql_fetch_field(mysqlResult))

                printf("\t");
            printf("Welcome to BANK SERVICE %s",mysqlRow[1]);
            menu();
            printf("\n +---------------+----------+----------+---------+----------+----------+-------- \t\t\n");

            int choice;
            do
            {

                printf("\n \n Do you want to continue ?  [y/n] : \t ");
                scanf("%s",&continuer);

                do
                {
                    printf("\n\n Please enter your choice : \t");
                    scanf("%d",&choice);

                    int balance;
                    switch(choice)
                    {
                    case 1:
                        printf("Your current balance is Rs : %s \n",mysqlRow[4]);
                        printf("\n account number : %s  \t", mysqlRow[0]);
                        printf("\n username : %s \t",mysqlRow[1]);
                        printf("\n phone number : %s \t",mysqlRow[2]);
                        printf("\n paasword  : %s \t",mysqlRow[3]);

                        printf("\n");
                        fflush(stdout);

                        break;
                    case 2:
                        fflush(stdout);

                        printf("Enter amount to be added : \t");
                        scanf("%d",&balance);

                        sprintf(query,"UPDATE users SET balance=('%d') WHERE accountNumber=('%s')",balance,user->accountNumber);

                        if (mysql_query(conn,query))
                        {
                            printf("\n unable to update data into user table \n");
                            finish_with_error(conn);
                        }
                        printf("You have depostied Rs .%d \n",balance);

                        break;
                    case 3:
                        fflush(stdout);
                        system("clear");
                        printf("Your current balance is Rs : %s \n",mysqlRow[4]);
                        int widhAmnount=atoi(mysqlRow[4]);
                        printf("Enter widhdraw amount : \t");
                        scanf("%d",&amount);
                        if (amount % 500 !=0)
                        {
                            widhAmnount=widhAmnount-amount;
                            sprintf(query,"UPDATE users SET balance=('%d') WHERE accountNumber=('%s')",widhAmnount,user->accountNumber);
                            if (mysql_query(conn,query))
                            {
                                printf("\n unable to update data into user table \n");
                                finish_with_error(conn);
                            }
                            printf("You have withdrawn  Rs .%d \n",amount);
                            printf("\n you have now :%d  \t",widhAmnount);
                        }
                        break;
                    case 4:
                        system("clear");
                        printf("************ TRANSFERRING MONEY ************ \n");

                        for (int i=0; i<80; i++)
                        {
                            printf("-");
                        }

                        int currentmt=atoi(mysqlRow[4]);
                        printf("Your current balance is  : %d \n",currentmt);

                        printf("Enter the account Number in which you want to transfer the money : \t");
                        scanf("%s",&password);

                        printf("\n Enter the amount you want to transfer : \t");
                        scanf("%d",&trans_mt);

                        if (currentmt<trans_mt)
                        {
                            printf("****** You have not sufficient blanace ****** \n");
                        }
                        else
                        {
                            currentmt=currentmt-trans_mt;
                            sprintf(query,"UPDATE users SET balance=('%d') WHERE accountNumber=('%s')",currentmt,user->accountNumber);
                            if (mysql_query(conn,query))
                            {
                                printf("\n unable to update data into user table \n");
                                finish_with_error(conn);
                            }
                            printf("trans_mt is  : %d \n",trans_mt);
                            sprintf(query,"select * from users where accountNumber=('%s')",password);

                            if (mysql_query(conn,query))
                            {

                                finish_with_error(conn);
                            }
                            MYSQL_RES *result2=mysql_store_result(conn);

                            if (result2)
                            {
                                numRows2=mysql_num_rows(result2);
                                while ((mysqlRow2=mysql_fetch_row(result2)))
                                {

                                    printf("\t");
                                    int newbalance=atoi(mysqlRow2[3]);
                                    printf("newbalance is  : %d \n",newbalance);
                                    newbalance=newbalance+trans_mt;
                                    printf("newbalance 2 is  : %d \n",newbalance);

                                    sprintf(query,"UPDATE users SET balance=('%d') WHERE accountNumber=('%s')",newbalance,password);
                                    if (mysql_query(conn,query))
                                    {
                                        printf("\n unable to transfer data into user table \n");
                                        finish_with_error(conn);
                                    }
                                    printf("****** Money Transferred ****** \n");
                                    printf("Your current balance is : %d \n",currentmt);
                                    printf("\n %d You had transferred from your account to : %d \n",trans_mt,currentmt);

                                }
                            }
                        }
                        break;

                    case 5:


                        fflush(stdout);
                        printf("************ CHANGE PASSWORD ************ \n");

                        for (int i=0; i<80; i++)
                        {
                            printf("-");
                        }

                        printf("Enter new password : \t");
                        scanf("%s",&password);

                        sprintf(query,"UPDATE users SET password=('%s') WHERE accountNumber=('%s')",password,user->accountNumber);

                        if (mysql_query(conn,query))
                        {
                            printf("\n unable to update data into user table \n");
                            finish_with_error(conn);
                        }
                        printf("Your password has changed\n",user->password);
                    }
                    break;


                }
                while (choice >=6);
            }
            while(continuer == 'y' ||continuer == 'Y');

        }

    }
    else
    {
        printf("\n Account number or password incorrect \n");
    }
}


void main()
{
    User *user;
    char phone[20];
    char password[20];
    int choice;
    int opt;
    int amount;
    printf("\n\t\t\t -------Welcome to bank system -------");

    printf("\n What do you want to do ?");
    printf("\n\n1. Create a new account");
    printf("\n\n2. Login to your account");

    do
    {
        printf("\n\n Please enter your choice : \t");
        scanf("%d",&opt);
    }
    while(opt>=3);

    if (opt==1)
    {
        Register();

    }
    if (opt==2)
    {
        Login();

    }


}
