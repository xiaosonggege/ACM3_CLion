#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <omp.h>
#include <memory>
#include <fstream>
#include <sstream>
#include "AOV_dfs.h"
using namespace std;
int main() {
    string p = "/home/xiaosong/桌面/text";
    shared_ptr<AOV_dfs> a = make_shared<AOV_dfs>(p);
    a->DFS_s(cout);
    return 0;
}
