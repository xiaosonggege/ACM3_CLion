#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <omp.h>
using namespace std;
int main() {
    omp_set_num_threads(8);
    int i = 2;
    vector<int> a = {1, 2, 3, 4};
#pragma omp parallel
    {
        cout << "i";
    };

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
                cout << *iter << endl;
        }
#pragma omp section
        {
            for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
                cout << (*iter + 1) << endl;
        }
    }
}
