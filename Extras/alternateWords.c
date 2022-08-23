// Alternate Words

#include<stdio.h>
#include<string.h>

void alternateWords(char* s){
    int len = strlen(s);
    int space = 0;
    for (int i = 0; i < len; i++){
        if(!space){
            if(s[i] == ' '){
                printf(" ");
                space = !space;
                goto end;
            }
            printf("%c", s[i]);
        }
        if(s[i] == ' ')space = !space;
        end: ;
    }
}

int main(){
    char s[] = "India stands for Unity";
    alternateWords(s);
}