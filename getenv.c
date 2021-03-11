/*
   ============================================================================
   Name        : getenv.c
   Author      : Shirase
   Version     : 0.1
   Copyright   :
   Description : Verification of Env Variables
   ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(){

        printf("test\n\n");

        char* s = getenv("PATH");
        printf("PATH :\n%s\n\n",(s!=NULL) ? s : "getenv returned NULL");

        s = getenv("USER");
        printf("USER :\n%s\n\n",(s!=NULL) ? s : "getenv returned NULL");

        s = getenv("PWD");
        printf("PWD :\n%s\n\n",(s!=NULL) ? s : "getenv returned NULL");

        printf("\nend test\n");

        // stop system
        getchar();
        return 0;

}



// Option to get actual PATH
// const char cwd[PATH_MAX];
// if (getcwd(cwd, sizeof(cwd)) != NULL) {
//       printf("\nOpen work in current dir:\n %s\n", cwd);
// } else {
//       perror("getcwd() error");
//     }
