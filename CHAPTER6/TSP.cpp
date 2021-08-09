#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

#define INF 987654321
#define MAX_N 8
double dist[MAX_N][MAX_N];

void showPath(vector<int>& path, double currentLength) {
    cout << "경로 결과 =====================" << endl;
    for (int i = 0; i < N - 1; ++i)
        cout << path[i] << " -> ";
    cout << path[N - 1] << endl;
    cout << "length: " << currentLength << endl;
}

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
    if (path.size() == N){
        showPath(path, currentLength);
        return currentLength;
    } 

    double ret = INF;
    for (int next = 0; next < N; ++next) {
        if (visited[next]) continue;
        visited[next] = true;

        int here = path.back();
        path.push_back(next);

        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);

        visited[next] = false;
        path.pop_back();
    }    
    return ret;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    vector<int> path;
    vector<bool> visited(N, false);
    // 알고리즘 내부에서 pop.back()을 사용하여 이전 경로를 확인하므로, 미리 출발도시를 넣어줘야합니다.
    for (int i = 0; i < N; ++i) {
        path.push_back(i);
        visited[i] = true;
        cout << "[" << i << "] 부터 출발한 경우" << endl;
        cout << shortestPath(path, visited, 0.0) << endl;
        cout << endl;
        path.pop_back();
        visited[i] = false;
    }

    return (0);
}