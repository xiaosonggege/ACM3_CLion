//
// Created by xiaosong on 2019/8/25.
//
#include "AOV_dfs.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
AOV_dfs::AOV_dfs(const string &p): path(p) {
    ifstream ifstrm;
    ifstrm.open(this->path, ios::in);
    string s;
    getline(ifstrm, s);
    istringstream istr(s);
    int node_num; //节点名列表元素个数
    istr >> node_num;
    //初始化node_name
    for (int i = 0; i != node_num; ++i)
        node_name.push_back({i+1, 0});
    vector<int> graphrow_init(node_num, 0);
    this->graph.assign(node_num, graphrow_init); //初始化graph
    //构建邻接表矩阵
    while(getline(ifstrm, s)){
        istringstream istr2(s);
        int row, col;
        istr2 >> row >> col;
        this->graph[row-1][col-1] = 1;
    }
    ifstrm.close();
}

AOV_dfs::~AOV_dfs() {}

AOV_dfs::AOV_dfs(const AOV_dfs &a) {
    this->path = a.path;
    this->graph = a.graph;
    this->node_name = a.node_name;
}

AOV_dfs::AOV_dfs(AOV_dfs &&a) {
    this->path = a.path;
    this->graph = a.graph;
    this->node_name = a.node_name;
    a.path.clear();
    a.graph.clear();
    a.node_name.clear();
}

AOV_dfs &AOV_dfs::operator=(const AOV_dfs &a) {
    this->path = a.path;
    this->graph = a.graph;
    this->node_name = a.node_name;
    return *this;
}

AOV_dfs &AOV_dfs::operator=(AOV_dfs &&a) {
    this->path = a.path;
    this->graph = a.graph;
    this->node_name = a.node_name;
    a.path.clear();
    a.graph.clear();
    a.node_name.clear();
    return *this;
}

void AOV_dfs::DFS(int row, vector<int> &stack1, vector<int> &stack2) {
    this->node_name[row].second = 1;
    stack1.push_back(this->node_name[row].first);
    vector<int>::iterator iter = graph[row].begin();
    while (iter != graph[row].end()){
        if (*iter == 1 && !node_name[iter-graph[row].begin()].second)
            this->DFS(iter - graph[row].begin(), stack1, stack2);
        ++iter;
    }
    stack2.push_back(*stack1.erase(stack1.end()-1));
}

ostream & AOV_dfs::DFS_s(ostream &os) {
    vector<int> stack1, stack2;
    for (int i = 0; i != node_name.size(); ++i){
        if (!node_name[i].second){
            this->DFS(i, stack1, stack2);
        }
    }
    for (auto iter = stack2.end()-1; iter >=stack2.begin(); --iter)
        os << *iter << " ";
    os << endl;
    return os;
}
