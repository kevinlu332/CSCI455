#include <iostream >
#include <cstdlib>
#include <ctime>
#include <math.h>       /* floor */
using namespace std;

// IDE name: Code::block
void printStars(int n)    //print stars function
{
    for(int i=0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
}/// printStars()

int main()
{

    int N = 1000;
    int counter = 0;
    int a0=0, a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0;
    int nAsterisks=0; // initialize
    srand(time(NULL));  // seed
    while (counter<N)   // for making the random distribution graph
    {
        double r = ((double)rand())/RAND_MAX; // make 0...1
        if (floor(r*10)<1)
            a0++;
        else if (floor(r*10)<2)
            a1++;
        else if (floor(r*10)<3)
            a2++;
        else if (floor(r*10)<4)
            a3++;
        else if (floor(r*10)<5)
            a4++;
        else if (floor(r*10)<6)
            a5++;
        else if (floor(r*10)<7)
            a6++;
        else if (floor(r*10)<8)
            a7++;
        else if (floor(r*10)<9)
            a8++;
        else
            a9++;  // binning 10 bins
        counter++;   // gets to the next loop
    }
    cout<<"For making the random distribution graph:"<<endl;
    cout<<"N = "<<N<<endl;  //cout N
    cout<<"Sum of a0 to a9 is equal to "<<a0+a1+a2+a3+a4+a5+a6+a7+a8+a9<<endl;  // cout the sum of a0 to a9
    nAsterisks= floor(100*a0/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a1/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a2/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a3/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a4/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a5/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a6/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a7/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a8/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a9/N);
    printStars(nAsterisks);    // print stars for each bin

    ///////////////////////////////////////
    counter = 0;
    a0=0, a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0;
    nAsterisks=0;  // initialize
    srand(time(NULL));  //seed
    while (counter<N)  // for making the triangle distribution graph
    {
        double r1 = ((double)rand())/RAND_MAX;
        double r2 = ((double)rand())/RAND_MAX;
        double r = 0.5*(r1+r2);
        if (floor(r*10)<1)
            a0++;
        else if (floor(r*10)<2)
            a1++;
        else if (floor(r*10)<3)
            a2++;
        else if (floor(r*10)<4)
            a3++;
        else if (floor(r*10)<5)
            a4++;
        else if (floor(r*10)<6)
            a5++;
        else if (floor(r*10)<7)
            a6++;
        else if (floor(r*10)<8)
            a7++;
        else if (floor(r*10)<9)
            a8++;
        else
            a9++;  //binning
        counter++;
    }
    cout<<"For making the triangle distribution graph:"<<endl;
    cout<<"N = "<<counter<<endl;   //cout N
    cout<<"Sum of a0 to a9 is equal to "<<a0+a1+a2+a3+a4+a5+a6+a7+a8+a9<<endl;  //cout sum of a0....a9
    nAsterisks= floor(100*a0/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a1/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a2/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a3/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a4/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a5/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a6/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a7/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a8/N);
    printStars(nAsterisks);
    nAsterisks= floor(100*a9/N);
    printStars(nAsterisks);

}

