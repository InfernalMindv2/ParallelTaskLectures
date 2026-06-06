#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
//Define a variable with a specific amount of points.
long double money = 5000.75;
//Let's see 3 threads to simulate them as people wants to modify our money variable.
const int THREAD_MAX = 3;
// create an array for threads' values,status of operation
long double  ar[THREAD_MAX]={20,3,10};
bool  success[THREAD_MAX];
//set the number of threads in #pragma construct
omp_set_num_threads(THREAD_MAX);

#pragma omp parallel
{
        int id =  omp_get_thread_num();
        //This area ,ONLY ONE THREAD ENTER IT !.
        if(id%2&&money-ar[id]>=0)
	{
		int num = ar[id];
		while(num--)
		{
			#pragma omp atomic
				money--;
		}
		success[id]=1;
	}
	else if(id%2==0)
	{
		int num =ar[id];
		while(num--)
		{
			#pragma omp atomic
				money++;
		}
		success[id]=1;
	}
	else
		success[id]=0;
}
//Iterating all over all threads
for(int i=0;i<THREAD_MAX;i++)
{
        string x;
        if(success[i])
                x="Successfully";
        else
                x="Failed";
        cout << "The status of Thread id " << i <<"is " << x << '\n';
}

}
