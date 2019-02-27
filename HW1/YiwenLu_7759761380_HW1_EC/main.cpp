#include <iostream >
#include <cstdlib>
#include <ctime>
#include <math.h>       /* floor */
using namespace std;
// IDE: Code::block

void printStars(int n) {
  for(int i=0;i < n;i++) {
    cout << "*";
  }
  cout << endl;
}/// printStars()

    int main(){
    int N =0;
    int a0=0, a1=0, a2=0, a3=0, a4=0, a5=0, a6=0, a7=0, a8=0, a9=0;
    int nAsterisks=0;
    srand(time(NULL));
    double shapeParameter = 3.6;  // assume a ( the shapeparameter) is 3.6
    double largestVal = -10000000.0, smallestVal = 10000000.0;  //initial two boundaries
    while (N<900){  // for making the random distribution graph
    double r = ((double)rand())/RAND_MAX;
    double x = 1.0/(pow(r, 1.0/shapeParameter));
    if (x>largestVal) largestVal = x;  //to get the upper boundary
    if (x<smallestVal) smallestVal = x;  //to get the lower boundary
    N++;
    }

    N=0;
    srand(time(NULL));
    while (N<900){  // for making the random distribution graph
    double r = ((double)rand())/RAND_MAX;
    double p = 1.0/(pow(r, 1.0/shapeParameter));  //generate a Pareto value 'p'
    double pNorm = (p - smallestVal)/(largestVal - smallestVal); // 0..1

       if (floor(pNorm*10)<1) a0++;
  else if (floor(pNorm*10)<2) a1++;
  else if (floor(pNorm*10)<3) a2++;
  else if (floor(pNorm*10)<4) a3++;
  else if (floor(pNorm*10)<5) a4++;
  else if (floor(pNorm*10)<6) a5++;
  else if (floor(pNorm*10)<7) a6++;
  else if (floor(pNorm*10)<8) a7++;
  else if (floor(pNorm*10)<9) a8++;
  else                        a9++;  //binning to ten bins
      N++;
    }
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
printStars(nAsterisks);    // printing stars for each bin
    }
