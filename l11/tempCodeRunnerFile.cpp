#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// N is the number of cities
#define N 4

// Function to calculate the minimum cost (lower bound) of edges
int calculateCost(int reducedMatrix[N][N], vector<bool>& visited, int currentCity) {
    int cost = 0;

    // Find the minimum cost edge for each row
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue; // Skip already visited cities

        int minRowCost = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && reducedMatrix[i][j] < minRowCost) {
                minRowCost = reducedMatrix[i][j];
            }
        }
        cost += (minRowCost == INT_MAX ? 0 : minRowCost);
    }

    // Find the minimum cost edge for the column of the current city
    for (int j = 0; j < N; j++) {
        if (!visited[j] && reducedMatrix[currentCity][j] < INT_MAX) {
            cost += reducedMatrix[currentCity][j];
        }
    }

    return cost;
}

// Function to reduce rows and columns and calculate the cost of reduction
int reduceMatrix(int reducedMatrix[N][N], vector<bool>& visited, int currentCity) {
    int cost = 0;

    // Row reduction
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue; // Skip visited cities

        int rowMin = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!visited[j]) {
                rowMin = min(rowMin, reducedMatrix[i][j]);
            }
        }

        if (rowMin != INT_MAX) {
            cost += rowMin;
            for (int j = 0; j < N; j++) {
                if (!visited[j]) {
                    reducedMatrix[i][j] -= rowMin;
                }
            }
        }
    }

    // Column reduction
    for (int j = 0; j < N; j++) {
        if (visited[j]) continue; // Skip visited cities

        int colMin = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                colMin = min(colMin, reducedMatrix[i][j]);
            }
        }

        if (colMin != INT_MAX) {
            cost += colMin;
            for (int i = 0; i < N; i++) {
                if (!visited[i]) {
                    reducedMatrix[i][j] -= colMin;
                }
            }
        }
    }

    return cost;
}

// Recursive function to solve the TSP using Branch and Bound
int tsp(int reducedMatrix[N][N], vector<bool>& visited, int currentCity, int currentCost, int level, int& bestCost) {
    // If all cities are visited, add the cost of returning to the start city
    if (level == N - 1) {
        int finalCost = currentCost + reducedMatrix[currentCity][0];
        bestCost = min(bestCost, finalCost);
        return finalCost;
    }

    // Prune if the current path is already worse than the best solution
    if (currentCost >= bestCost) {
        return INT_MAX;
    }

    // Explore all possible next cities
    for (int i = 0; i < N; i++) {
        if (!visited[i] && reducedMatrix[currentCity][i] < INT_MAX) {
            visited[i] = true;

            int reducedCopy[N][N];
            copy(&reducedMatrix[0][0], &reducedMatrix[0][0] + N * N, &reducedCopy[0][0]);

            int newCost = currentCost + reducedMatrix[currentCity][i] + reduceMatrix(reducedCopy, visited, i);

            tsp(reducedCopy, visited, i, newCost, level + 1, bestCost);

            visited[i] = false;
        }
    }

    return bestCost;
}

int main() {
    // Cost matrix representing distances between cities
    int costMatrix[N][N] = {
        {INT_MAX, 10, 15, 20},
        {10, INT_MAX, 35, 25},
        {15, 35, INT_MAX, 30},
        {20, 25, 30, INT_MAX}
    };

    // Initialize visited array
    vector<bool> visited(N, false);
    visited[0] = true; // Start from city 0

    // Initial best cost as infinity
    int bestCost = INT_MAX;

    // Call the TSP function
    int result = tsp(costMatrix, visited, 0, 0, 0, bestCost);

    cout << "The minimum cost is: " << result << endl;

    return 0;
}
