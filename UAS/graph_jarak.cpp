#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tipeS {
    struct tipeS* Left;
    int INFO;  // Corrected data type to int
    struct tipeS* Right;
} simpul;

simpul* P, * FIRST, * LAST, * PVertex, * PEdge, * Q, * R, * S;
simpul* PointS[9];

pair<vector<int>, int> ShortestPath(int A[9][9], int start, int dest) {
    vector<int> dist(9, INT_MAX), visited(9, false), parent(9, -1);

    dist[start] = 0;

    for (int i = 0; i < 9; i++) {
        int minDist = INT_MAX, minIndex = -1;

        for (int j = 0; j < 9; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = true;

        for (int j = 0; j < 9; j++) {
            if (A[minIndex][j] != 0 && !visited[j]) {
                int altDist = dist[minIndex] + A[minIndex][j];
                if (altDist < dist[j]) {
                    dist[j] = altDist;
                    parent[j] = minIndex;
                }
            }
        }
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    return { path, dist[dest] };
}

pair<vector<int>, int> LongestPath(int A[9][9], int start, int dest) {
    vector<int> dist(9, INT_MIN), visited(9, false), parent(9, -1);

    dist[start] = 0;

    for (int i = 0; i < 9; i++) {
        int maxDist = INT_MIN, maxIndex = -1;

        for (int j = 0; j < 9; j++) {
            if (!visited[j] && dist[j] > maxDist) {
                maxDist = dist[j];
                maxIndex = j;
            }
        }

        if (maxIndex == -1) break;

        visited[maxIndex] = true;

        for (int j = 0; j < 9; j++) {
            if (A[maxIndex][j] != 0 && !visited[j]) {
                int altDist = dist[maxIndex] + A[maxIndex][j];
                if (altDist > dist[j]) {
                    dist[j] = altDist;
                    parent[j] = maxIndex;
                }
            }
        }
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    return { path, dist[dest] };
}

string PrintPath(const vector<int>& path, int A[9][9], int cost) {
    string result;
    for (size_t i = 0; i < path.size(); ++i) {
        result += static_cast<char>(path[i] + 'A');
        if (i != path.size() - 1) {
            result += " (" + to_string(A[path[i]][path[i + 1]]) + ") -> ";
        }
    }
    result += "\nTotal Jarak: " + to_string(cost);
    return result;
}

int main() {
    int A[9][9] = {
      {0,5,3,2,0,0,0,0,0},
      {0,0,0,3,2,0,0,0,0},
      {0,0,0,0,0,0,4,0,0},
      {0,4,5,0,5,6,0,0,0},
      {0,0,0,0,0,3,0,5,0},
      {0,0,3,0,0,0,6,0,8},
      {0,0,0,0,0,0,0,0,7},
      {0,0,0,0,4,6,0,0,7},
      {0,0,0,0,0,0,9,0,0}
    };
    char NmS[10] = "ABCDEFGHI";
    int I, J;

    //Simpul Vertex yang pertama
    I = 0; J = 0;
    P = new simpul;
    P->INFO = I;  // Corrected initialization
    FIRST = P;
    LAST = P;
    P->Left = NULL;
    P->Right = NULL;
    PointS[0] = P;
    printf("%c", P->INFO + 'A');
    printf(" alamat %p", (void*)PointS[0]);

    //Simpul Vertex yang berikutnya
    for (I = 1; I <= 8; I++) {
        P = new simpul;
        P->INFO = I;  // Corrected initialization
        LAST->Left = P;
        LAST = LAST->Left;
        P->Left = NULL;
        P->Right = NULL;
        PointS[I] = P;
        printf("\n%c", P->INFO + 'A');
        printf(" alamat = %p", (void*)PointS[I]);
    }

    //Simpul Edge untuk semua Vertex
    printf("\n");
    Q = FIRST;
    for (I = 0; I <= 8; I++) {
        R = Q;
        printf("\nVertex %c", Q->INFO + 'A');
        for (J = 0; J <= 8; J++) {
            if (A[I][J] != 0) {
                P = new simpul;
                P->INFO = A[I][J];
                R->Right = P;
                P->Left = PointS[J];
                printf(" berhubungan dengan %c,", P->Left->INFO + 'A');
                printf(" dengan bobot = %d. ", P->INFO);
                P->Right = NULL;
                R = P;
            }
        }
        Q = Q->Left;
    }

    cout << endl;

    pair<vector<int>, int> shortestPathResult = ShortestPath(A, 0, 8);
    pair<vector<int>, int> longestPathResult = LongestPath(A, 0, 8);

    cout << "\nJarak Terpendek Dari A ke I: " << PrintPath(shortestPathResult.first, A, shortestPathResult.second) << endl;
    cout << "Jarak Terpanjang Dari A ke I: " << PrintPath(longestPathResult.first, A, longestPathResult.second) << endl;

    return 0;
}
