#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include<string.h>
#include </home/karima/Downloads/conio2.h>
#pragma comment (lib,"libmysql.lib");

typedef struct
{
    char phone [50];
    char accountNumber [50];
    char username [50];
    char password [50];
    float balance;
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
    system("Color 57");
    // textbackground(RED);
    printf("\n ******************* Add New Account ******************* \n");
    printf("\n Enter your account number: \t");
    scanf("%s",user->accountNumber);

    printf("\n Enter your phone number :\t");
    scanf("%s",user->phone);

    printf("\n Enter your password :\t");
    scanf("%s",user->password);

    char query[1024];

    user->balance=0;

    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS users(accountNumber VARCHAR(255)PRIMARY KEY ,phone VARCHAR(255),password VARCHAR(255), balance Float default 0)"))

    {
        finish_with_error(conn);
    }
    sprintf(query,
            "INSERT INTO users (accountNumber,phone,password,balance) VALUES ('%s','%s','%s','%d')",user->accountNumber,user->phone,user->password,user->balance);
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
    printf("\n Press 1 for balance inquiry");
    printf("\n Press 2 for adding fund");
    printf("\n Press 3 for cash withdraw");
    printf("\n Press 4 for online trnasfer");
    printf("\n Press 5 for changing password \n\n");
}

void Login ()
{
    User *user;
    int amount;
    char query[1024];
    MYSQL *conn=mysql_init(NULL);
    connection(conn);
    system("clear");

    printf("\n Account number :\t");
    scanf("%s",user->accountNumber);

    printf("\n Password :\t");
    scanf("%s",user->password);
    MYSQL_ROW mysqlRow;
    MYSQL_FIELD *mysqlFields;
    my_ulonglong numRows;
    unsigned int numFields;

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
        // printf("number of rows=%d number of fields=%d \n",numRows,numFields);
        while ((mysqlRow=mysql_fetch_row(mysqlResult)))
        {
            while(mysqlFields= mysql_fetch_field(mysqlResult))

                //print column heards
                //  printf(" %s \t\t",mysqlFields->name );
                printf("\t");
            printf("Welcome to %s",mysqlRow[1]);
            menu();
            printf("\n +---------------+----------+----------+---------+----------+----------+-------- \t\t\n");
            // ShowBalance();
            int choice;
            do
            {
                printf("\n\n Please enter your choice : \t");
                scanf("%d",&choice);
            }
            while(choice>=6);
            switch(choice)
            {
            case 1:
                printf("Your current balance is Rs : %s \n",mysqlRow[3]);
                break;
            case 2:
                printf("Enter amount to be added : \t");
                scanf("%d",&amount);
                sprintf(query,"Update users set balance ('%d') where accountNumber=('%s') ",amount,user->accountNumber);
                if (mysql_query(conn,query))
                {
                    printf("\n unable to update data into user table \n");
                    finish_with_error(conn);
                }
                printf("data inserted successfully \n");

            break;
        }
    }
}
else
{
    printf("\n Account number or password incorrect \n");
}
}


void ShowBalance()
{
    User *user;
    char query[1024];
    MYSQL *conn=mysql_init(NULL);
    connection(conn);
    system("clear");
    MYSQL_ROW mysqlRow;
    MYSQL_FIELD *mysqlFields;
    int numRows;
    unsigned int numFields;
    MYSQL_RES *mysqlResult=mysql_store_result(conn);

    sprintf(query,"select * from users where accountNumber=('%s') ",user->accountNumber);

    if (mysql_query(conn,query))
    {
        finish_with_error(conn);
    }

    if (mysqlResult)
    {
        numRows=mysql_num_rows(mysqlResult);
        numFields=mysql_num_fields(mysqlResult);
        // printf("number of rows=%d number of fields=%d \n",numRows,numFields);
        printf("\n +---------------+----------+----------+---------+----------+----------+-------- \t\t\n");

        while ((mysqlRow=mysql_fetch_row(mysqlResult)))
        {

            printf("\t");
            printf("Welcome to %s",mysqlRow[3]);
            // menu();
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
    char cont='y';

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
        //  ShowBalance();

    }
    //while (choice!=5)


}
