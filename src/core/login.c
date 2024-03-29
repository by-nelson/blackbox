#include <stdlib.h>
#include <stdio.h>

#include "../http/box_http.h"
#include "../db/sql_connection.h"
#include "../db/sql_cart.h"

int main(int argc, char **argv, char **env){

    box_http *http = box_new_http("../html/login.html", env);

    box_http_content(http,2, TEXT_HTML,CHARSET_UTF_8);

    if (box_http_logged(http) == USER_LOGGED) {
        
        box_set_class_variables(http, "subheader", "subtitle=Already logged.", 0);
    }
    else if (box_http_has_post(http) == 1) {

        MYSQL *connection = init_sql_connection();
        
        char *email = box_post_param(http, "email");    
        char *password = box_post_param(http, "password");
        
        box_user *user = sql_log_user(connection,email,password);

        
        if (user != NULL) { // credenciales correctas 
                       
            box_http_set_cookie(http, box_user_token(user, NULL));
            box_http_redirect(http, "index.cgi");

            
            if (sql_user_has_cart(connection, user) == 0) {

                box_cart *new_cart = box_cart_fill(sql_max_id(connection) + 1, "-1", email, 0);
                sql_new_cart(connection, new_cart);
                box_destroy_cart(new_cart);
            }
            
        
            box_destroy_user(user);
        }
        else 
            box_set_class_variables(http, "subheader", "subtitle=Wrong credentials.", 0);
        


        close_sql_connection(connection);
    }

    box_set_class_variables(http, "subheader", "subtitle=Login.", 0);

    box_send_headers(http);
    box_send_html(http);

    box_destroy_http(http); 
    return 0;
}
