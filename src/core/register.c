#include "stdlib.h"
#include "stdio.h"
#include "../http/box_http.h"
#include "../db/data.h"
#include "../db/sql_connection.h"


int main(int argc, char **argv, char **env){

    box_http *http = box_new_http("../html/register.html", env);

    box_http_content(http,2, TEXT_HTML,CHARSET_UTF_8);

    box_send_headers(http);
    
    if (box_http_has_post(http)==1){
        char * email = box_post_param(http,"email");
        char * pass = box_post_param(http,"password");
        char * confpass = box_post_param(http,"confPass");
        char * name = box_post_param(http,"fullname");
        char * phone = box_post_param(http,"phoneNumber");
        char * address = box_post_param(http,"address");
        

        if (box_same_string(pass,confpass) == 0 ){ //confirm password 
            MYSQL *connection = init_sql_connection(); //initialize conection to database
            box_user * user =  box_user_fill(email,name,"","",pass,address,phone,NULL);
            sql_save_user(connection,user);
            close_sql_connection(connection);
            box_http_redirect(http,"login.cgi");
        }   
    }
    
    box_send_html(http);
    
    box_destroy_http(http);
    
    return 0; 
    /*
       
    gcc -o bin/cookie.cgi  src/core/testCookie.c src/http/box_http.c src/http/box_headers.c  src/html/box_html.c src/html/box_reader.c src/html/box_tags.c src/utils/box_regex.c src/mem/box_array.c src/mem/box_map.c src/mem/box_ntree.c
    */
}

