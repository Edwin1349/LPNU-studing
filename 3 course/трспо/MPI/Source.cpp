#include "mpi.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <iomanip>

#define func(x) 2 * (1/tan(3*x)) - 1/(12*pow(x,2) + 7*x - 5)

int main(int argc, char** argv) {
    double N = 21, b = N*2;
    int ProcNum, ProcRank, RecvRank;
    MPI_Status Status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    for (int i = 0; i < 9; i ++) {
        auto start = std::chrono::system_clock::now();
        double  step_num = floor(N * pow(10, i) / ProcNum);
        double step =  1 / pow(10, i);

        double min = step_num * ProcRank + 1;
        double max;
        if (ProcRank == ProcNum - 1) {
            max = N * pow(10, i) + 1;
        }
        else {
            max = (step_num * (double(ProcRank) + 1) + 1);
        }
        double x = 0;
        for (double j = min; j < max; j++) {
            /*if ((j * step) >=  x) {
                x = (j * step);
            }*/
            //std::cout << j << " " << step << " " << j * step << std::endl;
            func(j * step);
        }

        if (ProcRank == ProcNum - 1) {
            //std::cout << "i=" << i << " x=" << x << std::endl;
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            std::cout << "elapsed time: " << std::fixed << std::setprecision(20) <<  elapsed_seconds.count() << "s\n\n";
        }
    }

    MPI_Finalize();
    return 0;
}