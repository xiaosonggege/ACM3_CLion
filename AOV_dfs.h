//
// Created by xiaosong on 2019/8/25.
//

#ifndef ACM3_CLION_AOV_DFS_H
#define ACM3_CLION_AOV_DFS_H
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
using namespace std;
class AOV_dfs{
private:
    string path; //文件读取路径
    vector<vector<int>> graph; //AOV邻接表矩阵
    vector<pair<int, int>> node_name;
public:
    AOV_dfs() = default;
    AOV_dfs(const string&);
    ~AOV_dfs();
    AOV_dfs(const AOV_dfs&);
    AOV_dfs(AOV_dfs&&);
    AOV_dfs &operator=(const AOV_dfs&);
    AOV_dfs &operator=(AOV_dfs&&);
    void DFS(int row, vector<int> &, vector<int> &);
    ostream & DFS_s(ostream &);
};
#endif //ACM3_CLION_AOV_DFS_H
