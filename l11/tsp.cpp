#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>

using namespace std;

class TSPSolver {
    int N;
    vector<vector<int> > cost;
    double final_res;
    vector<int> final_path;
    vector<bool> visited;

public:
    TSPSolver(vector<vector<int> > cost_matrix) {
        cost = cost_matrix;
        N = cost.size();
        final_res = DBL_MAX;
        final_path.resize(N + 1);
        visited.resize(N, false);
    }

    void copyToFinal(vector<int>& curr_path) {
        for (int i = 0; i < N; i++) {
            final_path[i] = curr_path[i];
        }
        final_path[N] = curr_path[0];
    }

    int firstMin(int i) {
        int min = INT_MAX;
        for (int k = 0; k < N; k++) {
            if (cost[i][k] < min && i != k)
                min = cost[i][k];
        }
        return min;
    }

    int secondMin(int i) {
        int first = INT_MAX, second = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;

            if (cost[i][j] <= first) {
                second = first;
                first = cost[i][j];
            } else if (cost[i][j] <= second && cost[i][j] != first) {
                second = cost[i][j];
            }
        }
        return second;
    }

    void TSPRec(double curr_bound, double curr_weight, int level, vector<int>& curr_path) {
        if (level == N) {
            if (cost[curr_path[level - 1]][curr_path[0]] != 0) {
                double curr_res = curr_weight + cost[curr_path[level - 1]][curr_path[0]];

                if (curr_res < final_res) {
                    copyToFinal(curr_path);
                    final_res = curr_res;
                }
            }
            return;
        }

        for (int i = 0; i < N; i++) {
            if (cost[curr_path[level - 1]][i] != 0 && !visited[i]) {
                double temp = curr_bound;
                curr_weight += cost[curr_path[level - 1]][i];

                if (level == 1)
                    curr_bound -= ((firstMin(curr_path[level - 1]) + firstMin(i)) / 2.0);
                else
                    curr_bound -= ((secondMin(curr_path[level - 1]) + firstMin(i)) / 2.0);

                if (curr_bound + curr_weight < final_res) {
                    curr_path[level] = i;
                    visited[i] = true;

                    TSPRec(curr_bound, curr_weight, level + 1, curr_path);
                }

                curr_weight -= cost[curr_path[level - 1]][i];
                curr_bound = temp;

                fill(visited.begin(), visited.end(), false);
                for (int j = 0; j <= level - 1; j++)
                    visited[curr_path[j]] = true;
            }
        }
    }

    void solve() {
        vector<int> curr_path(N + 1, -1);
        double curr_bound = 0.0;
        fill(visited.begin(), visited.end(), false);

        for (int i = 0; i < N; i++)
            curr_bound += (firstMin(i) + secondMin(i));

        curr_bound = curr_bound / 2.0;

        visited[0] = true;
        curr_path[0] = 0;

        TSPRec(curr_bound, 0.0, 1, curr_path);

        cout << "Minimum cost: " << final_res << endl;
        cout << "Path taken: ";
        for (int i = 0; i <= N; i++) {
            cout << final_path[i];
            if (i != N)
                cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    vector<vector<int> > cost_matrix = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };

    TSPSolver tsp(cost_matrix);
    tsp.solve();

    return 0;
}
