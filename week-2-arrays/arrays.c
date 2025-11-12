#include <stdio.h>
#include <string.h>

int string_length(char s[]){
    int n = 0;
    while(s[n] != '\0'){
        n++;
    }

    return n;
}
int main (){
    int scores[3];
    char *s = "ombhor";
    int length = string_length(s);
    printf("length: %d\n" , length);
    char *s2 = "om";
}