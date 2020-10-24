#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <stdlib.h>
#include <math.h>



void dfs1 (int v, std::vector<bool> & used, std::vector<int> & order, std::vector < std::vector<int> > g, std::vector < std::vector<int> > gr) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v, std::vector<bool> & used, std::vector<int> & component, std::vector < std::vector<int> > g, std::vector < std::vector<int> > gr) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

int top_sort(std::vector<int> & order, std::vector<bool> & used, std::vector<int> & component, std::vector < std::vector<int> > g, std::vector < std::vector<int> > gr) {
    int n;
    for (;;) {
        int a, b;
        g[a].push_back (b);
        gr[b].push_back (a);
    }

    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1(i, used, order, g, gr);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2(v, used, component, g, gr);
            component.clear();
        }
    }
}

long long solution(std::vector<std::vector<int>> & nambla){
    std::vector < std::vector<int> > g, gr;
    std::vector<bool> used;
    std::vector<int> order, component;
    top_sort(order, used, component, g, gr);
    
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string NM;
    std::string NK;
    // //assuming that input txt doc is argv[1]
    // std::string inputTxt = argv[1];
    // // output txt doc is argv[2]
    // std::string outputTxt = argv[2];

    // std::ifstream inputFile(inputTxt);
    // std::ofstream outputFile(outputTxt);
    std::vector<std::vector<int>> nambla;

    std::getline(std::cin,NM);
    std::istringstream iss2(NM);
    std::vector<long> e(std::istream_iterator<long>(iss2), {});
    for(int i = 0; i < e[2]; ++i){
        std::getline(std::cin, NK);
        std::istringstream iss3(NK);
        std::vector<long> f(std::istream_iterator<long>(iss3), {}); 
        nambla.emplace_back(f);
    }
    auto sol = solution(nambla);
    // outputFile.close();
    // inputFile.close();

    return 0;
}