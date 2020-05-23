#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterating over each row of image
    for (int i = 0; i < height; i++)
    {
        //iterating over each pixel
        for (int j = 0; j < width; j++)
        {
            int avg = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen)/3;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue, newred, newgreen, newblue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            blue = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;

            newred = round(0.393 * red + 0.769 * green + 0.189 * blue);
            newblue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            newgreen = round(0.349 * red + 0.686 * green + 0.168 * blue);

            if (newred > 255)
            {
                newred = 255;
            }
            if (newblue > 255)
            {
                newblue = 255;
            }
            if (newgreen > 255)
            {
                newgreen = 255;
            }
            image[i][j].rgbtRed = newred;
            image[i][j].rgbtBlue = newblue;
            image[i][j].rgbtGreen = newgreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int j = 0; j < (width/2); j++)
    {
        for (int i = 0; i < height; i++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int imin, jmin, imax, jmax, sumgreen, sumblue, sumred, count;
    RGBTRIPLE images[height][width];
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            imin = (i-1 < 0)? 0 : i-1 ;
            imax = (i+1 > height-1)? height-1: i+1 ;
            jmin = (j-1 < 0)? 0: j-1 ;
            jmax = (j+1 > width-1)? width - 1: j+1 ;

            sumblue = 0;
            sumred = 0;
            sumgreen = 0;

            for (int k = imin; k <= imax; k++)
            {
                for (int l = jmin; l <= jmax; l++)
                {
                    sumred += image[k][l].rgbtRed;
                    sumgreen += image[k][l].rgbtGreen;
                    sumblue += image[k][l].rgbtBlue;
                }
            }
            count = ((imax-imin)+1) * ((jmax-jmin)+1) ;

            images[i][j].rgbtRed = (round(sumred/count) > 255)? 255: round(sumred/count) ;
            images[i][j].rgbtBlue = (round(sumblue/count)> 255)? 255: round(sumblue/count) ;
            images[i][j].rgbtGreen = (round(sumgreen/count) > 255)? 255: round(sumgreen/count) ;

        }
    }
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[a][b].rgbtRed = images[a][b].rgbtRed;
            image[a][b].rgbtBlue = images[a][b].rgbtBlue;
            image[a][b].rgbtGreen = images[a][b].rgbtGreen;
        }
    }
    return;
}
