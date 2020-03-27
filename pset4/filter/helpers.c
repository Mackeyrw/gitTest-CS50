#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gray = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gray = round(round(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaBlue = 0;
    int sepiaGreen = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE hold[height][width];
    int counter = 1;


    for (int i = 0; i < floor(width / 2); i++)
    {
        for (int j = 0; j < height; j++)
        {
            hold[j][i] = image[j][i];
            image[j][i] = image[j][width - counter];
            image[j][width - counter] = hold[j][i];
        }

        counter++;
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE hold[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i > 0 && i < (height - 1) && j > 0 && j < (width - 1))
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j +
                                                 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i
                                                         - 1][j - 1].rgbtRed) / 9);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j +
                                                   1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen
                                                   + image[i - 1][j - 1].rgbtGreen) / 9);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j +
                                                  1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                                                  image[i - 1][j - 1].rgbtBlue) / 9);
            }

            if (i == 0 && j == 0)
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i +
                                                 1][j].rgbtRed) / 4);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i +
                                                   1][j].rgbtGreen) / 4);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i +
                                                  1][j].rgbtBlue) / 4);
            }

            if (i == 0 && j == (width - 1))
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i][j -
                                                 1].rgbtRed) / 4);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i][j -
                                                   1].rgbtGreen) / 4);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i][j -
                                                  1].rgbtBlue) / 4);
            }

            if (i == (height - 1) && j == (width - 1))
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i -
                                                 1][j].rgbtRed) / 4);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i -
                                                   1][j].rgbtGreen) / 4);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i -
                                                  1][j].rgbtBlue) / 4);
            }

            if (i == (height - 1) && j == 0)
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j +
                                                 1].rgbtRed) / 4);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j +
                                                   1].rgbtGreen) / 4);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j +
                                                  1].rgbtBlue) / 4);
            }

            if (i == 0 && j > 0 && j < (width - 1))
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i +
                                                 1][j].rgbtRed + image[i +
                                                         1][j - 1].rgbtRed + image[i][j -
                                                                 1].rgbtRed) / 6);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i +
                                                   1][j].rgbtGreen + image[i +
                                                           1][j - 1].rgbtGreen + image[i][j -
                                                                   1].rgbtGreen) / 6);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i +
                                                  1][j].rgbtBlue + image[i +
                                                          1][j - 1].rgbtBlue + image[i][j -
                                                                  1].rgbtBlue) / 6);
            }

            if (i > 0 && i < (height - 1) && j == (width - 1))
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j
                                                 - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed) / 6);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j
                                                   - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 6);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j
                                                  - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 6);
            }

            if (i == (height - 1) && j > 0 && j < (width - 1))
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j +
                                                 1].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed) / 6);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j +
                                                   1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 6);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j +
                                                  1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 6);
            }

            if (i > 0 && i < (height - 1) && j == 0)
            {
                hold[i][j].rgbtRed = round(round(image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j +
                                                 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed) / 6);
                hold[i][j].rgbtGreen = round(round(image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j +
                                                   1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6);
                hold[i][j].rgbtBlue = round(round(image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j +
                                                  1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6);
            }
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = hold[i][j];
        }
    }

    return;
}
