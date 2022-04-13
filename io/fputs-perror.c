#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char str[64];

    if((fp = fopen("foo.txt","w")) == NULL) {
        fprintf(stderr, "Could not open file %s.\n", "foo.txt");
        exit(-1);
    }

    do {
        printf("\nEnter a new string. Press <Enter> to finish: ");
        gets(str);

        fputs(str, fp);
        putc('\n', fp);

        if(ferror(fp)) {
            perror("Erro na gravacao");
            fclose(fp);
            exit(1);
        }
    } while (strlen(str) > 0);

    return 0;
}
