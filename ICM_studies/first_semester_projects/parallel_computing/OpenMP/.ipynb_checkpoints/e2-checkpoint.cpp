#include <random>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main() {
    const int n=1024;
    float sum = 0;

    vector<float> A;

    A.reserve(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        A[i] = dis(gen);
    }

    auto start = chrono::steady_clock::now();

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        A[i] *= A[i];
    }

	for (int i = 0; i < n; i++) {
    	sum += A[i];
    }

    float norm = sqrt(sum);

    auto diff = chrono::steady_clock::now() - start;
    cout << "Addition took " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << "Norm: " << norm << endl;
    return 0;
}