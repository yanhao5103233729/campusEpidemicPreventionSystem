#include<string.h>
#include<iomanip>
int ResetWideSrting(wchar_t *remaintobeclear,int size){
    memset(remaintobeclear,0,size);
    return 0;
}

int ResetString(char *remaintobeclear,int size){
    memset(remaintobeclear,0,size);
    return 0;
}