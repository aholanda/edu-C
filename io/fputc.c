#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char str[64];
    int i;

    if((fp = fopen("foo.txt","w")) == NULL) {
        fprintf(stderr, "Could not open file %s.\n", "foo.txt");
        exit(-1);
    }
    printf("Enter the word(s) to be written: ");
    gets(str); /* don't use gets() in production */

    for(i=0; str[i]; i++)
        fputc(str[i], fp);

    fclose(fp);

    return 0;
}
