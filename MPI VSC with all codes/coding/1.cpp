#include <mpi.h>
#include<omp.h>
#include<vector>
#include<iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
        MPI_Init(&argc, &argv);

        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        cout << "Total processes = " << size << "\n";

        MPI_Finalize();
        return 0;
}