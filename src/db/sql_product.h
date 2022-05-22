#ifndef SQL_PRODUCT_H
#define SQL_PRODUCT_H

#include "sql_connection.h"
#include "../domain/box_product.h"

extern box_product  *sql_get_product(MYSQL *connection, int id);
extern box_products *sql_get_products(MYSQL *connection);

extern int sql_get_products_count(MYSQL *connection);
extern int sql_save_product(MYSQL *connection, box_product *product);

#endif