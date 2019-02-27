#include <iostream >
#include <cstdlib>
#include <ctime>
#include <math.h>       /* floor */

using namespace std;

int main()
{

    int N = 10;
    int counter = 0;
    srand(time(NULL));  // seed
    int P1;
    int P2;
    double area;
    while (counter < N)     // for making the random distribution graph
    {
        double x = ((double) rand()) / RAND_MAX * 2; // make 0...2
        double y = ((double) rand()) / RAND_MAX * 2;
        if ((x <= 1.0 && y <= sqrt(1.0 - double(pow(x, 2))) || x <= 1.0 && (2.0 - y) <= sqrt(1.0 - double(pow(x, 2))))
        {
            P1 += 1;
        }
        if ((x > 1.0 && y <= sqrt(1.0 - double(pow(x, 2))) || x > 1.0 && (2.0 - y) <= sqrt(1.0 - double(pow(x, 2))))
        {
            P1 += 1;
        }
        else
        {
            P2 += 1;
            counter++;   // gets to the next loop
        }
    }
    area = P2/(P1+P2)*4.0;
    cout<<"the yellow part of the area is "<<area;

}
