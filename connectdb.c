
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <connectdb.h>
void main()
{

    MYSQL *conn=mysql_init(NULL);

    if(conn==NULL)
    {
        fprintf(stderr,"%s\n",mysql_error);
        exit(1);

    }
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
  if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS users(id INT PRIMARY KEY AUTO_INCREMENT, firstname VARCHAR(255), lastname VARCHAR (255) , email VARCHAR (255), password VARCHAR (255) ")) {
      finish_with_error(conn);
  }


   mysql_close(conn);
  exit(1);
}
void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

   // sprintf(query,"select * from users where accountNumber='123'");

// "select accountNumber,password from users where accountNumber=('%s')",user->accountNumber);
 /* if (mysql_query(conn,query))
   {
    printf("\n unable to connect to your account  \n");
     finish_with_error(conn);
  }
    mysql_close(conn);
    printf("show data successfully \n");
 int status=0;

do {
    MYSQL_RES * result=mysql_store_result(conn);
    if (result==NULL)
    {
      finish_with_error(conn);
    }
    MYSQL_ROW row= mysql_fetch_row(result);
    printf("%s \n",row[0]);
    status=mysql_next_result(conn);
    if (status >0)
    {
      finish_with_error(conn);
    }
    }while(status==0);
    mysql_close(conn);
    exit(0);
    */

      /* if (mysqlStatus)
        {
               finish_with_error(conn);
        }
    else {
        mysqlResult=mysql_store_result(conn);

    }*/
 /*  numRows=mysql_fetch_row(mysqlResult);
    for (int i=0; i<numFields; i++)
    {
     //    printf("fdfdffdfd %s \n",mysqlFields[i]);

        printf("%s \t", mysqlFields[i].name);
    }
   // printf("/n");
    while (mysqlRow=mysql_fetch_row(mysqlResult))
    {
        for(int j=0 ; j<numFields; j++){
            printf("%s \t",mysqlRow[j] ? mysqlRow[j]: "NULL" );

        }
/*
   // printf("/n");

  /*  if (mysqlResult)
    {
        mysql_free_result(mysqlResult);
        mysqlResult=NULL;

    }
    }*/
