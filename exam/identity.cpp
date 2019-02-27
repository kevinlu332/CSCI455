#include <iostream>
#include <math.h>

using namespace std;

double LHS(double angle)
{
    double ans = sin(2*angle);
    return ans;
}
double RHS (double angle)
{
    double ans = 2*sin(angle)*cos(angle);
    return ans;
}

int main()
{
    for (int angle = 0; angle<360; angle++)
    {
        LHS(angle)-RHS(angle)<1e-10 ? cout<<"TRUE" : cout<<"FALSE";
    }
}
