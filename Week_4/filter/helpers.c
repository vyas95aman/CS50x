#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate grey by averaging with float
            gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }

    return;
}

// set max limit as a function, so i dont have to keep repeating code
int limit(int x)
{
    if (x > 255)
    {
        x = 255;
    }

    return x;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // use formulas to convert to sepia. have to round here since sepia are ints
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = limit(sepiaRed);
            image[i][j].rgbtGreen = limit(sepiaGreen);
            image[i][j].rgbtBlue = limit(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE r;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            r = image[i][j];
            image[i][j] = image[i][width - j - 1]; // width - j - 1 bc the last index is not width - 0, it is width - 1 bc start is 0
            image[i][width - j - 1] = r;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];

    // Create copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    // Create blur from data copy and change image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // now iterate AROUND  the [i][j],
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float counter = 0.0;

            for (int x = i - 1; x < i + 2; x++)
            {
                for (int y = j - 1; y < j + 2; y++)
                {
                    if (x < 0 || y < 0 || x >= height || y >= width)
                    {
                        continue;
                    }
                    // use copy to get sums since these don't change!
                    sumRed += image_copy[x][y].rgbtRed;
                    sumGreen += image_copy[x][y].rgbtGreen;
                    sumBlue += image_copy[x][y].rgbtBlue;
                    counter++;
                }
            }
            // assign sum/counter to image values
            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }
    return;
}
