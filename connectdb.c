
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
