#include <crypt.h>
#include <string>
#include <iostream>

int main(){
    char const *password = "";
    char const *salt = "$6$_$";

    char *hash = crypt(password, salt);
    printf("%s\n", hash);
}
