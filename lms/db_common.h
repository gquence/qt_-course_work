#ifndef DB_COMMON_H
#define DB_COMMON_H
#if 0
#include <vector>
#include <string>

#include <libpq-fe.h>

void queryResOutput(std::vector < std::vector <std::string> > &c);
bool PGDB_insert(std::string v_src, std::string v_fields, std::string v_values)
bool PGDB_update(std::string v_src, std::string v_set, std::string v_where)
bool PGDB_delete(std::string v_src,  std::string v_where);
bool PGDB_select(std::string v_params, std::string v_from, std::string v_where, std::vector < std::vector <std::string> > &res);

#endif
#endif // DB_COMMON_H
