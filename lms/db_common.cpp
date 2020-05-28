#include <iostream>
#include "db_common.h"
#if 0

static std::string dbLoginParams = "user=gquence password=aspid0911 dbname=test_db";

bool PGDB_insert(std::string v_src, std::string v_fields, std::string v_values)
{
    std::string query = "INSERT INTO ";
    PGresult* queryRes = NULL;
    PGconn* conn;

    if (v_src.empty() || v_fields.empty() || v_values.empty())
        return false;
    conn = PQconnectdb(dbLoginParams.c_str());
    if(PQstatus(conn) != CONNECTION_OK)
        return false;
    query += v_src;
    query += " (" + v_fields;
    query += ") VALUES (" + v_values + ");";
    queryRes = PQexec(conn, query.c_str());
    if (PQresultStatus(queryRes) != PGRES_COMMAND_OK)
        return false;
    PQclear(queryRes);
    PQfinish(conn);
    conn = NULL;
    return true;
}

bool PGDB_update(std::string v_src, std::string v_set, std::string v_where)
{
    std::string query = "UPDATE  ";
    PGresult* queryRes = NULL;
    PGconn* conn;

    if (v_src.empty() || v_set.empty() || v_where.empty())
        return false;
    conn = PQconnectdb(dbLoginParams.c_str());
    if(PQstatus(conn) != CONNECTION_OK)
        return false;
    query += v_src;
    query += " SET " + v_set;
    query += " WHERE " + v_where + ";";
    queryRes = PQexec(conn, query.c_str());
    if (PQresultStatus(queryRes) != PGRES_COMMAND_OK)
        return false;
    PQclear(queryRes);
    PQfinish(conn);
    conn = NULL;
    return true;
}

bool PGDB_delete(std::string v_src,  std::string v_where)
{
    std::string query = "DELETE FROM ";
    PGresult* queryRes = NULL;
    PGconn* conn;

    if (v_src.empty() || v_where.empty())
        return false;
    conn = PQconnectdb(dbLoginParams.c_str());
    if(PQstatus(conn) != CONNECTION_OK)
        return false;
    query += v_src;
    query += " WHERE " + v_where + ";";
    queryRes = PQexec(conn, query.c_str());
    if (PQresultStatus(queryRes) != PGRES_COMMAND_OK)
        return false;
    PQclear(queryRes);
    PQfinish(conn);
    conn = NULL;
    return true;
}


bool PGDB_select(std::string v_params, std::string v_from, std::string v_where, std::vector < std::vector <std::string> > &res)
{
    std::string query = "SELECT ";
    std::uint32_t nCols = 0, nRows = 0;
    PGresult* queryRes = NULL;
    PGconn* conn;

    if (v_params.empty() || v_from.empty())
        return false;
    conn = PQconnectdb(dbLoginParams.c_str());
    if(PQstatus(conn) != CONNECTION_OK)
        return false;
    query += v_params;
    query += " FROM " + v_from;
    if (!v_where.empty())
        query += " WHERE " + v_where;
    queryRes = PQexec(conn, query.c_str());
    if (PQresultStatus(queryRes) != PGRES_TUPLES_OK && PQresultStatus(queryRes) != PGRES_SINGLE_TUPLE)
        return false;

    nCols = PQnfields(queryRes);
    nRows = PQntuples(queryRes);

    res.resize(nRows + 1);
    res[0].resize(nCols);
    for (uint32_t j = 0; j < nCols; j++)
    {
        res[0][j] = PQfname(queryRes, j);
    }
    for (uint32_t i = 0; i < nRows; i++)
    {
        res[i + 1].resize(nCols);
        for (uint32_t j = 0; j < nCols; j++)
        {
            res[i + 1][j] = PQgetvalue(queryRes, i, j);
        }
    }
    PQclear(queryRes);
    PQfinish(conn);
    conn = NULL;
    return true;
}


void queryResOutput(std::vector < std::vector <std::string> > &c)
{
    for (uint32_t i = 0; i < c.size(); i++)
    {
        for (uint32_t j = 0; j < c[i].size(); j++)
        {
            std::cout  << "\t" << c[i][j] << "\t\t|\t";
        }
        std::cout << std::endl;
    }
}
#endif
