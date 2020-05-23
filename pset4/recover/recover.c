#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{

    typedef uint8_t BYTE;
    int number =0;

    if (argc != 2)
    {
        printf("usage: ./recover 'forensic image'\n");
        return 1;

    }

    FILE *f = fopen(argv[1] , "r");

    if (f == NULL)
    {
        printf("File not found/ incompatable\n");
        return 2;
    }


    BYTE *buffer = calloc(512, sizeof(BYTE));
    char *filename;
    filename = malloc(7);
    int count = 0;



    //getting the first start of a jpeg
    do
    {
        number = fread(buffer , sizeof(BYTE), 512, f);

    }while (buffer[0] != 0xff || buffer[1] != 0xd8 || buffer[2] != 0xff || (buffer[3] & 0xf0) != 0xe0);

    sprintf(filename, "%03i.jpg", count);
    count++;
    FILE *fout = fopen(filename, "w");
    fwrite(buffer, sizeof(BYTE), 512, fout);


    while ((number = fread(buffer , sizeof(BYTE), 512, f)) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fclose(fout);
            sprintf(filename, "%03i.jpg", count);
            count++;
            fout = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), 512, fout);
        }
        else
        {
            fwrite(buffer, sizeof(BYTE), 512, fout);

        }


    }

    //writing to the last file
    fwrite(buffer, sizeof(BYTE), number, fout);

    fclose(fout);
    fclose(f);



}
