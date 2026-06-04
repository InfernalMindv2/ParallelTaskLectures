#include<iostream>
using namespace std;
int main()
{
//First , we define the total number of steps in our approximated formula  pi which is N
const int MAX =100000;
//Afterward, we need to know the value of step
long double step =1.0/(long double)MAX,sum=0;
//Iterate all  steps 
for(int i=0;i<MAX;i++)
{
	//Calculate the delta x and f(deltax) : width and height formula
	//add  to sum variable
	long double x = (i+0.5)*step;
	sum+=4.0/(1.0+x*x);

}
//Instead of  do it in each for loop , we take factor and after all iteration in loop , we multiple all sum *step
cout << step*sum;
}

