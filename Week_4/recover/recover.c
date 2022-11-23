#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool isjpg(uint8_t buffer[]);

int main(int argc, char *argv[])
{
    // Prompts if user enters more than one file
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Opens file, if not able to then returns error
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int block_size = 512;
    uint8_t buffer[block_size]; // Need to specify the size, keeps all data together
    int counter = 0; // to count # of images

    // create a new file, filename as name of file
    char *filename;
    filename = malloc(8 * sizeof(char)); // 7 + 1 bc need to allocate for nul!

    FILE *img = NULL; // initialize the output file, so I can use it in multiple functions!

    while (fread(buffer, 1, block_size, raw_file) == block_size)
    {
        if (isjpg(buffer) == true)
        {
            if (counter > 0)
            {
                fclose(img); // have to close the files that were open as im going through
            }

            // if new jpg, open new file, start writing to new file, save as new name with counter++
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                return 1;
            }

            fwrite(buffer, 1, block_size, img);

            counter++;

        }

        else
        {
            if (img != NULL)
            {
                // write the next block to current file if img already declared
                fwrite(buffer, 1, block_size, img);
            }

            else
            {
                // keep going until next jpg is found
                continue;
            }
        }
    }

    free(filename);
    fclose(raw_file);
    fclose(img);

    return 0;
}

// boolean test to see if buffer is a jpg file
bool isjpg(uint8_t buffer[])
{
    if (buffer[0] == 0xff)
    {
        if (buffer[1] == 0xd8)
        {
            if (buffer[2] == 0xff)
            {
                if ((buffer[3] & 0xf0) == 0xe0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}