#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char c;

    if((fp = fopen("foo.txt", "r")) == NULL){
        fprintf(stderr, "Could not open file %s.\n", "foo.txt");
        exit(-1);
    }

    while((c = fgetc(fp) ) != EOF)
        printf("%c", c);

    fclose(fp);

    return 0;
}
