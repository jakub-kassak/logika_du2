#include <vector>
#include "lphelper.hpp"
using std::vector;

double cchi_ilp(vector<vector<int>>& graph){
    return 0.;
}

double cchi_bnb(vector<vector<int>>& graph){
    return .1;
}





#include <iostream>
#include <chrono>

using graph = vector<vector<int>>;
using std::cin;
using std::cout;
using std::endl;

int main() {
    int T;
    cin >> T;


    for (int i = 0; i < T; ++i) {
        graph g;
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int u, v, w;
            cin >> u >> v >> w;
            g.emplace_back(vector<int>({u, v, w}));
        }

        auto start = std::chrono::high_resolution_clock::now();
        auto result = cchi_bnb(g);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

        cout << "n=" << n << ", result=" << result << ", duration=" << duration.count() << endl;
    }

    return 0;
}