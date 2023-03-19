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
   /*�򵥵�MySQL����ȷ�������ķ�װ���ú������������ݿ��в����ض��ַ����������������������ֵ
    DBConnection& dbConnection: һ��DBConnection��������ã��������ӵ�MySQL���ݿ⡣
    const char* searchValue: ��Ҫ���ҵ��ַ���
    const char* tableName: Ҫ��ѯ�ı�����
    const char* searchColumnName: Ҫ�����в���searchValue��������
    const char* returnColumnName: ���践�ص�������
    �ú��������ز��ҵ����������Ե�ֵ����������ݿ���û���ҵ�ƥ������ݣ��򷵻�0��
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

