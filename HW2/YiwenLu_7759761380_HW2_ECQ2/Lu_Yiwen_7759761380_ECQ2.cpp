#include <iostream>
#include <cmath>
#include <fstream>
#include "Lu_Yiwen_7759761380_ECQ2.h"
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



ComplexNumber::ComplexNumber(double i, double j) //constructor
{
    real = i;
    imag = j;
}
ComplexNumber ComplexNumber::add(ComplexNumber c2) //add complex numbers
{
    double a,b;
    a = this->real + c2.real;
    b = this->imag + c2.imag;
    return ComplexNumber(a,b);
}
ComplexNumber ComplexNumber::squared() //square a complex number
{
    double a, b, temp = real;
    a=(pow(real,2)-pow(imag,2));
    b=(2*temp*imag);
    return ComplexNumber(a,b);
}
double ComplexNumber::abs() // abs a complex number
{
    return sqrt(real*real+imag*imag);
}
void ComplexNumber::prt() // print out the complex number
{
    char sign = (imag>0) ? '+':'-';
    cout<<real<<sign<<(imag>0 ? imag:-imag)<<"i"<<endl;
}
ComplexNumber::~ComplexNumber() { }//destructor



int main()
{
    double cxmin = 0.270, cymin = 0.004, cxmax = 0.271, cymax = 0.005; // coordination of the spot
    for (int i = 1.0; i<=20; i++) // to generate 20 images
    {
        array2D *a = new array2D(400,400);
        int xRes, yRes;
        a->getSize(xRes,yRes);
        if (a == NULL||xRes<0||yRes<0) //error handling
        {
            cerr<<"input resolutions are wrong!"<<endl;
            exit(1);
        }
        cxmin-=0.0003; //for the purpose of zooming out
        cxmax+=0.0003;
        cymin-=0.0003;
        cymax+=0.0003;
        string filename = to_string(i)+".intermediate_fractal.pgm";
        PGMImage *image = new PGMImage(xRes,yRes,filename);
        image->getResolution(xRes,yRes);
        ///////create a blank image (done)////////////

        for(int y=0; y < yRes; y++)
        {
            for(int x=0; x < xRes; x++)
            {
                ComplexNumber c((cxmin + (double)x/(xRes-1)*(cxmax-cxmin)), (cymin + (double)y/(yRes-1)*(cymax-cymin))); //[maps x to cxmin..cxmax][maps y to cymin..cymax]
                ComplexNumber z(0,0);  //initialize
                int maxIter = 255, iter = 0;
                while (iter < maxIter && z.abs() < 2)
                {
                    z = z.squared().add(c);
                    iter++;
                } //end_while: either iter has exceeded maxIter, or abs(z) has exceeded 2
                (z.abs()>= 2)  ? image->setPixel(x,y,iter) : image->setPixel(x,y,0);
            }
        }
        image->writeFile();  //write to an output pgm file
        delete &image;
    }


}
