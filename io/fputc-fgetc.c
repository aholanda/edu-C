#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char c, str[32], buf[64] = "The name of this file is ";
    int i;

    printf("\n\n Enter the file name: ");

    gets(str); /* dont't use gets in production */

    if (!(fp = fopen(str,"w"))){
        fprintf(stderr, "Could not open file %s.\n", str);
        exit(-1);
    }

    strncat(buf, str, 64);

    for (i=0; buf[i]; i++)
        fputc(buf[i], fp);

    fclose(fp);

    fp = fopen(str,"r");
    while (!feof(fp)) {
        c = fgetc(fp);
        printf("%c",c);
    }

    fclose(fp);

    return 0;
}
