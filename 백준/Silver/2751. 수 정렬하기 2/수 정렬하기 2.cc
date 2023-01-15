#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N; // 힙에 있는 자료의 개수
int heap[1000001]; // 힙 배열

void push(int v)
{
    heap[++N] = v;
    for (int i = N;i > 1;i /= 2) {
        if (heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
        }
        else break;
    }
}

void pop()
{
    swap(heap[1], heap[N]);
    heap[N--] = 0;
    int i = 1;
    while (i * 2 <= N) {
        if (heap[i] <= heap[i * 2] && (i * 2 + 1 > N || heap[i] <= heap[i * 2 + 1]))
            break;
        if (i * 2 + 1 > N || heap[i * 2] < heap[i * 2 + 1]) {
            swap(heap[i], heap[i * 2]);
            i = i * 2;
        }
        else {
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
        }
    }

}

int top()
{
    return heap[1];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int v; cin >> v;
        push(v);
    }
    for (int i = 1;i <= n;i++) {
        cout << top() << "\n";
        pop();
    }
    return 0;
}