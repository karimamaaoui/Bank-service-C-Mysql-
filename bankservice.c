#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include<string.h>
#pragma comment (lib,"libmysql.lib");
typedef struct  {
    char phone [50];
    char accountNumber [50];
    char username [50];
    char password [50];
    char balance[50];
}User;

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
    char phone [50];
    char accountNumber [50];
    char username [50];
    char password [50];
    int balance;

    User *user;
     MYSQL *conn=mysql_init(NULL);
    connection(conn);
    system("clear");


    printf("\n Enter your account number: \t");
    scanf("%s",user->accountNumber);

    printf("\n Enter your phone number :\t");
    scanf("%s",user->phone);

    printf("\n Enter your password :\t");
    scanf("%s",user->password);

  //  printf("\n Enter your balance :\t");
    //scanf("%d",user->balance);

    char query[1024];

 //   printf("\n Enter your balaance :\t");
  //  scanf("%d",user->balance);

    //user->balance=0;

   if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS users(accountNumber VARCHAR(255)PRIMARY KEY ,phone VARCHAR(255),password VARCHAR(255), balance INT default 0)"))

   {
      finish_with_error(conn);
  }
 /* if (mysql_query(conn, "INSERT INTO users(accountNumber,phone,password,balance) VALUES ('%s','%s','%s','%d')")) {
      finish_with_error(conn);
  }*/
  //if (mysql_query(conn, "INSERT INTO users (accountNumber,phone,password,balance) VALUES('" +user->accountNumber+"','"+user->phone+"','"+user->password+"','"+user->balance+"')"))
 sprintf(query,
 "INSERT INTO users (accountNumber,phone,password,balance) VALUES ('%s','%s','%s','%d')",user->accountNumber,user->phone,user->password,&user->balance);
  if (mysql_query(conn,query))

// if (mysql_query(conn, "INSERT INTO users(accountNumber) VALUES (accountNumber)"))
    {
    printf("\n unable to insert data into user table \n");
     finish_with_error(conn);
  }
    mysql_close(conn);
    printf("data inserted successfully \n");
}
void Login () {
    User *user;

}

void main(){
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
    do{
        printf("\n\n Please enter your choice : \t");
        scanf("%d",&opt);
    }while(opt>=3);

    if (opt==1)
    {
        Register();

    }
    if (opt==2)
    {
        Login();
    }
    //while (choice!=5)


}
