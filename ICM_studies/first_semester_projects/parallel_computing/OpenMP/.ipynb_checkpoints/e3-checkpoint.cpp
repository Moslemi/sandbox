#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int main () {

    vector<int> numbers;
    int histogram[101] = {};

    string line;
    ifstream myfile ("numerki");
    if (myfile.is_open()){  
        while ( getline (myfile,line) ){
            numbers.push_back(stoi(line));
        }
        myfile.close();
    }

    auto start = chrono::steady_clock::now();

    #pragma omp parallel for reduction(+:histogram[:101])
    for (int i = 0; i < numbers.size(); i++) {
        histogram[numbers[i]] += 1;
    }

    auto diff = chrono::steady_clock::now() - start;
    cout << "Addition took " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

  for (int i = 0; i < 101; i++) {
    cout << histogram[i] << endl;
  }
  
  return 0;
}