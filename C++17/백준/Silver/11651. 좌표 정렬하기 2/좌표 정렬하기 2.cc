#include <iostream>
#include <algorithm>
using namespace std;

struct Point{
    int x, y;
};

bool cmp(const Point &a, const Point &b){
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

int main(){
    int N;
    cin >> N;

    Point point[N];
    for (int i = 0; i < N; i++){
        cin >> point[i].x >> point[i].y;
    }

    sort(point, point + N, cmp);

    for (int i = 0; i < N; i++){
        cout << point[i].x << ' ' << point[i].y << '\n';
    }

    return 0;
}