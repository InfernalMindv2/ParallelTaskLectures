#include<iostream>
using namespace std;
int main()
{
	//This is our first program using openmp
	string welcome = "HelloWorld";
	//#pragma omp parallel --> this is our construct that allow our code to  be parallized <3.
	// In this moment ,we don't know how many threads do we have ? but we know that at each run , our os
	// will set the proper number .
	#pragma omp parallel
	{
		cout << "HelloWorld\n";
	}
	return 0;
}

