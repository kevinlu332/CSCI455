#include <iostream>
using namespace std;

//IDE: code::block

float mySqrt(double x); // eg. mySqrt(4) will return 2

 float mySqrt(double x){
 float estimate = 1.0;  //intialize
float newEstimate = x/estimate;
while((newEstimate-estimate)>0.0001 ||(newEstimate-estimate)<-0.0001 ){
    estimate = newEstimate;
    newEstimate=0.5*(estimate+x/estimate);  //update estimate

}
return estimate;
}

int main() {
  double s = mySqrt(5.0);
  cout << s << endl; // expect 2.236
  return 0;
}// main()
