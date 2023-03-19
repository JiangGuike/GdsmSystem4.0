#pragma once
#include <mysql.h>
#include <string>


class DBConnection
{
public:
    DBConnection(const char* host, const char* user, const char* password, const char* database, int port = 3306);
    ~DBConnection();
    bool connect();
    void close();
    MYSQL* getMySQL() const { return m_mysql; } 
   /*简单的MySQL查找确定函数的封装，该函数可以在数据库中查找特定字符，并返回所需的其他属性值
    DBConnection& dbConnection: 一个DBConnection对象的引用，用于连接到MySQL数据库。
    const char* searchValue: 需要查找的字符。
    const char* tableName: 要查询的表名。
    const char* searchColumnName: 要在其中查找searchValue的列名。
    const char* returnColumnName: 所需返回的列名。
    该函数将返回查找到的数据属性的值。如果在数据库中没有找到匹配的数据，则返回0。
    */
    std::string findData( const char* searchValue, const char* tableName, const char* searchColumnName, const char* returnColumnName);

private:
    const char* m_host;
    const char* m_user;
    const char* m_password;
    const char* m_database;
    int m_port;
    MYSQL* m_mysql;
};

