#include "DBConnection.h"
#include <stdexcept>

DBConnection::DBConnection(const char* host, const char* user, const char* password, const char* database, int port)
    : m_host(host), m_user(user), m_password(password), m_database(database), m_port(port), m_mysql(nullptr)
{

}

DBConnection::~DBConnection()
{
    close();
}

bool DBConnection::connect()
{
    m_mysql = mysql_init(nullptr);
    if (!mysql_real_connect(m_mysql, m_host, m_user, m_password, m_database, m_port, nullptr, 0))
    {
        return false;
        //throw std::runtime_error(mysql_error(m_mysql));         //�쳣����
    }
    else {

        mysql_query(m_mysql, "SET NAMES 'GB2312' ");
    }
    return true;
}

void DBConnection::close()
{
    if (m_mysql != nullptr)
    {
        mysql_close(m_mysql);
        m_mysql = nullptr;
    }
}

std::string DBConnection::findData(const char* searchValue, const char* tableName, const char* searchColumnName, const char* returnColumnName)
{
    if (searchValue == NULL)
    {
        return NULL;
    }
    MYSQL* mysql = mysql_init(NULL); // ��ָ���ʼ��Ϊ��Ч�Ķ���
    mysql = getMySQL();
    MYSQL_RES* result;
    MYSQL_ROW row;
    std::string found = "";
    char query[1024] = { '\0' };
    sprintf_s(query, sizeof(query), "SELECT %s FROM %s WHERE %s='%s'", returnColumnName, tableName, searchColumnName, searchValue);
    if (mysql_query(mysql, query) == 0) {
        result = mysql_store_result(mysql);
        if (result != NULL) {
            if (mysql_num_rows(result) > 0) {
                row = mysql_fetch_row(result);
                found = std::string(row[0]);
            }
            mysql_free_result(result);
        }
    }
    return found;
}
