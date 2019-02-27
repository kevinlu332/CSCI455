#ifndef LU_YIWEN_7759761380_ECQ2_H_INCLUDED
#define LU_YIWEN_7759761380_ECQ2_H_INCLUDED


using namespace std;
// IDE: code::block

class array2D
{
protected:
    float **xtable; //set pointer to pointer
    int xRes, yRes;
public:
    array2D(int xResolution,int yResolution);  //constructor

    void getSize(int &xResolution, int &yResolution);  //give xRes and yRes

    void setValue(int x,int y,float val);   //put values into the table

    double getValue(int x, int y);    //get a value from a table location

    ~array2D();

};

class PGMImage:public array2D
{
protected:
    string filename;
public:
    PGMImage(int xResolution, int yResolution, string imageFilename);

    void getResolution(int &xResolution, int &yResolution);  //call parent's method

    void setPixel(int x,int y,float val) ;  //call parent's method

    double getPixel(int x, int y);    //get a value from calling parent's method

    void writeFile();

    ~PGMImage(); //destructor

};

class ComplexNumber
{
private:
    double real;
    double imag;
public:
    ComplexNumber(double i, double j); //constructor

    ComplexNumber add(ComplexNumber c2); //add complex numbers

    ComplexNumber squared(); //square a complex number

    double abs(); // abs a complex number

    void prt(); // print out the complex number

    ~ComplexNumber();//destructor
};

#endif // LU_YIWEN_7759761380_ECQ2_H_INCLUDED
