#include "helpers.h"
#include <math.h>

int cap(int n);

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //defining a convolutional matrix
    int G[3][3] = {{-1,0,1},
                {-2,0,2},
                {-1,0,1}};

    //making a copy of image matrix
    RGBTRIPLE copy[height][width];

    int imax, imin, jmax, jmin, gxred, gxblue, gxgreen, gyred, gyblue, gygreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imax = i+1;
            imin = i-1;
            jmax = j+1;
            jmin = j-1;

            gxred = 0;
            gxblue = 0;
            gxgreen = 0;
            gyred = 0;
            gyblue = 0;
            gygreen = 0;

            int red = 0, blue = 0, green = 0;

            for (int p = imin, a = 0; p <= imax && a < 3; a++, p++)
            {
                for (int q = jmin, b = 0; q <= jmax && b < 3; b++, q++)
                {
                    if(p > height-1 || p < 0 || q > width-1 || q < 0)
                    {
                        gxred += 0;
                        gxblue += 0;
                        gxgreen += 0;

                        gyred += 0;
                        gyblue += 0;
                        gygreen += 0;
                    }
                    else
                    {
                        gxred += (image[p][q].rgbtRed * G[a][b]);
                        gyred += (image[p][q].rgbtRed * G[b][a]);

                        gxblue += (image[p][q].rgbtBlue * G[a][b]);
                        gyblue += (image[p][q].rgbtBlue * G[b][a]);

                        gxgreen += (image[p][q].rgbtGreen * G[a][b]);
                        gygreen += (image[p][q].rgbtGreen * G[b][a]);
                    }
                }
            }

            red = cap(round(sqrt( ((double)gxred * (double)gxred) + ((double)gyred * (double)gyred) )));

            blue = cap(round(sqrt( ((double)gxblue * (double)gxblue) + ((double)gyblue * (double)gyblue) )));

            green = cap(round(sqrt( ((double)gxgreen * (double)gxgreen) + ((double)gygreen *(double)gygreen) )));


            copy[i][j].rgbtRed = red;
            copy[i][j].rgbtBlue = blue;
            copy[i][j].rgbtGreen = green;
        }
    }

    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtRed = copy[x][y].rgbtRed;
            image[x][y].rgbtBlue = copy[x][y].rgbtBlue;
            image[x][y].rgbtGreen = copy[x][y].rgbtGreen;
        }
    }
    return;
}


int cap(int n)
{
    if (n > 255)
    {
        n = 255;
    }

    if (n < 0)
    {
        n = 0;
    }

    return n;
}