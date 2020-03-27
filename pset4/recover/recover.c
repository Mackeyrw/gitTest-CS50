#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("One file only!");

        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Not a useable file");
        return 1;
    }

    int counter = 0;
    char filename[] = "000.jpg";
    FILE *img = NULL;
    unsigned char bytes[512];

    while (fread(bytes, 512, 1, file) == 1)
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            if (img == NULL)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(bytes, 512, 1, img);
                counter++;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(bytes, 512, 1, img);
                counter++;
            }
        }
        else
        {
            if (img != NULL)
            {
                fopen(filename, "a");
                fwrite(bytes, 512, 1, img);
            }
        }
    }

    fclose(img);
    fclose(file);
    return 0;
}
