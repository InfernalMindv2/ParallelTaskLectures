#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0)
            std::cout << "Need at least 2 processes\n";
        MPI_Finalize();
        return 0;
    }
    if (rank == 0) {
        int x = 10;
        MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        MPI_Recv(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Final result = " << x << "\n";
    }

    else if (rank == 1) {
        int x;
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        x = x * 2;

        MPI_Send(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    

    MPI_Finalize();
}