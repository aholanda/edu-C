#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char str[64];

    if((fp = fopen("foo.txt","w+")) == NULL) {
        fprintf(stderr, "Could not open file %s.\n", "foo.txt");
        exit(-1);
    }
    printf("Enter the word(s) to be written: ");
    gets(str); /* don't use gets() in production */

    fputs(str, fp);

    fflush(fp);

    fseek(fp, 0L, SEEK_SET); /* == rewind() */

    while (fgets(str, 100, fp) != NULL)
        printf("%s", str);

    fclose(fp);

    return 0;
}
