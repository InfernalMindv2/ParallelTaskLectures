#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
        //First,We define constant for simplicity : The number of all needed threads
        const int THREAD_SIZE = 5;
        // This method invoke our  constrct(omp parallel) to set the number of threads =  5
        omp_set_num_threads(THREAD_SIZE);
        bool ok =1;
        #pragma omp parallel
        {
		if(ok)
		{
			//Here just to ensure that we successfully set the THREADSIZE correctly
			ok=0;
			int actualnum = omp_get_num_threads();
			cout << "To ensure our program takes the parameter properly \n "
			<< "MYTHREADS = " << THREAD_SIZE << "\n" << "The actual size = " << actualnum << '\n' ;
		}
                //Here , we get the id of thread to print in a nice way .
                int id =omp_get_thread_num();
                cout << "Hello, I'm thread id : " << id << '\n';
        }
        return 0;
}
