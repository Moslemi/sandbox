#include <random>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main() {
    const int n=1048576;

    vector<float> A;
	vector<float> B;
	vector<float> C;
	A.reserve(n);
	B.reserve(n);
	C.reserve(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
    	B[i] = dis(gen);
    	C[i] = dis(gen);
    }

    auto start = chrono::steady_clock::now();

	#pragma omp parallel for
    for (int i = 0; i < n; i++) {
    	A[i] = B[i] * C[i];
    }

    auto diff = chrono::steady_clock::now() - start;
    cout << "Addition took " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    cout << "A[0]: " << A[0] << ", A[n-1]: " << A[n-1] << endl;
    return 0;
}