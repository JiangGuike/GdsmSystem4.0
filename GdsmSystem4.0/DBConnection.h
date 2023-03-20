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
    /*
        这是一个用于更新或插入数据的函数。该函数会在指定的表中搜索一个指定的值，如果找到了，则会更新相应行中的指定列的值。如果没有找到，则会插入一条新的数据，该数据包含指定的值。

        函数中的参数包括：

        searchValue：要查找的值
        tableName：要更新或插入数据的表的名称
        searchColumnName：要在其中查找searchValue的列的名称
        returnColumnName：要更新或插入数据的列的名称
        writeValue：要写入的新值
        该函数首先检查所有参数是否为空，如果是，则返回false。然后，它会初始化一个MySQL连接，并使用getMySQL函数获取该连接的指针。接下来，它会构建一个SELECT查询，用于查找包含指定searchValue的行，并从result中获取返回的行。
    */
    bool updateData(const char* searchValue, const char* tableName, const char* searchColumnName, const char* returnColumnName, const char* writeValue);

private:
    const char* m_host;
    const char* m_user;
    const char* m_password;
    const char* m_database;
    int m_port;
    MYSQL* m_mysql;
};

