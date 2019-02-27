#include <iostream>
#include <cmath>
using namespace std;
// IDE: code::block

class array2D
{
protected:
    float **xtable; //set pointer to pointer
    int xRes, yRes;
public:   //interface to create and to be public
    array2D(int xResolution,int yResolution)  //constructor
    {
        xRes = xResolution;
        yRes = yResolution;
        xtable = new float*[yRes]; // a ("column") array to hold 'float *' type pointers
        for(int i=0; i < yRes; i++)
        {
            xtable[i] = new float[xRes];  // each element of the above array points to a 'row' of xRes elements
        }
    }
    void getSize(int &xResolution, int &yResolution)  //give xRes and yRes
    {
        xResolution = xRes;  // give values to the stack is needed
        yResolution = yRes;

    }
    void setValue(int x,int y,float val)   //put values into the table
    {
        xtable[y][x] = val;  //y first, not x first

    }

    double getValue(int x, int y)    //get a value from a table location
    {
        return xtable[y][x];   //y first, not x first
    }
    ~array2D()  //deconstruction
    {
        for (int i=0; i<yRes; i++)
        {
            delete[] xtable[i];
        }
        delete[] xtable;
    }
};

int main()
{
    array2D *a = new array2D(320,240);
    int xRes, yRes;
    a->getSize(xRes,yRes);

    for(int i=0; i < yRes; i++)
    {
        for(int j=0; j < xRes; j++)
        {
            a->setValue(j,i,100); // constant value of 100 at all locations
        }
    }
    for(int i=0; i < yRes; i++)// output
    {
        for(int j=0; j < xRes; j++)
        {
            cout << a->getValue(j,i) << " ";
        }
        cout << endl;
    }

    delete &a;
}
