#include <iostream>
#include <cmath>
#include <fstream>
#include "Lu_Yiwen_7759761380_Q2.h"
using namespace std;
// IDE: code::block


array2D::array2D(int xResolution,int yResolution)  //constructor
{
    xRes = xResolution;
    yRes = yResolution;
    xtable = new float*[yRes]; // a ("column") array to hold 'float *' type pointers
    for(int i=0; i < yRes; i++)
    {
        xtable[i] = new float[xRes];  // each element of the above array points to a 'row' of xRes elements
    }
}
void array2D::getSize(int &xResolution, int &yResolution)  //give xRes and yRes
{
    xResolution = xRes;  // give values to the stack is needed
    yResolution = yRes;
}
void array2D::setValue(int x,int y,float val)   //put values into the table
{
    xtable[y][x] = val;  //y first, not x first
}
double array2D::getValue(int x, int y)    //get a value from a table location
{
    return xtable[y][x];   //y first, not x first
}
array2D::~array2D()
{
    for (int i=0; i<yRes; i++)
    {
        delete[] xtable[i];
    }
    delete[] xtable;
}


PGMImage::PGMImage(int xResolution, int yResolution, string imageFilename):array2D(xResolution, yResolution)
{
    xRes = xResolution;
    yRes = yResolution;
    filename = imageFilename;
}
void PGMImage::getResolution(int &xResolution, int &yResolution)  //call parent's method
{
    array2D::getSize(xResolution,yResolution);
}
void PGMImage::setPixel(int x,int y,float val)   //call parent's method
{
    array2D::setValue(x,y,val);
}
double PGMImage::getPixel(int x, int y)    //get a value from calling parent's method
{
    return (array2D::getValue(x,y));   //y first, not x first
}
void PGMImage::writeFile()
{
    ofstream Image(filename); // output image file we're creating

    // header
    Image << "P2" << endl;
    Image << xRes << " " << yRes << endl; // how many columns, how many rows
    Image << 255 << endl; // largest pixel value we'll be outputting (below)

    // pixel data
    for(int i=0; i<yRes; i++)
    {
        for(int j=0; j<xRes; j++)
        {
            Image << getPixel(j, i) << " ";
        }// next column
        Image << endl;
    }// next row
    // all done!
    Image.close();
}
PGMImage::~PGMImage() //destructor
{
    for (int i=0; i<yRes; i++)
    {
        delete[] xtable[i];
    }
    delete[] xtable;
}

int main()
{
    array2D *a = new array2D(320,240);
    int xRes, yRes;
    a->getSize(xRes,yRes);
    if (a == NULL||xRes<0||yRes<0)  //error handling
    {
        cerr<<"input resolutions are wrong!"<<endl;
        exit(1);
    }


    PGMImage *image = new PGMImage(xRes,yRes,"test.pgm");
    image->getResolution(xRes,yRes);
    for(int i=0; i < yRes; i++)
    {
        for(int j=0; j < xRes; j++)
        {
            image->setPixel(j,i,100); // constant value of 100 at all locations
        }
    }
    image->writeFile(); //write an output file pgm

    delete &a;
    delete &image;
}
