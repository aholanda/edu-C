#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    const float PI = 3.1415;
    float num;

    if((fp = fopen("foo.bin", "wb")) == NULL) {
        fprintf(stderr, "Could not open file %s.\n", "foo.bin");
        exit(-1);
    }

    if(fwrite(&PI, sizeof(float), 1,fp) != 1) /* Escreve a variável pi */
        printf("Erro na escrita do arquivo");

    fclose(fp);

    if((fp = fopen("foo.bin", "rb")) == NULL) {
        fprintf(stderr, "Could not open file %s.", "foo.bin");
        exit(-1);
    }

    if(fread(&num, sizeof(float), 1, fp) != 1) {
        fprintf(stderr, "Could not read file %s.\n", "foo.bin");
        exit(-2);
    }

    printf("\nPI value is: %f", num);

    fclose(fp);

    return 0;
}
