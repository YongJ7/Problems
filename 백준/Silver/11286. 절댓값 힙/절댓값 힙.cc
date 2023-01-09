#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N; // 힙에 있는 자료의 개수
int heap[100001]; // 힙 배열

bool cmp(int a, int b)
{
    // a < b
    if (abs(a) != abs(b)) return abs(a) < abs(b);
    return a < b;
}

void push(int v)
{
    heap[++N] = v;
    for (int i = N;i > 1;i /= 2) {
        if (cmp(heap[i], heap[i/2])) {
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
        // if (heap[i] <= heap[i*2] && (i*2+1 > N || heap[i] <= heap[i*2+1]))
        // cmp(heap[i*2], heap[i]) ===> heap[i*2] < heap[i]
        // !cmp(heap[i*2], heap[i]) ==> heap[i*2] >= heap[i]
        if (!cmp(heap[i*2], heap[i]) && (i * 2 + 1 > N || !cmp(heap[i*2+1], heap[i])))
            break;
        if (i * 2 + 1 > N || cmp(heap[i*2], heap[i*2+1])) {
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
    for (int i = 0;i < n;i++) {
        int v; cin >> v;
        if (v != 0) {
            push(v);
        }
        else {
            if (N == 0) cout << "0\n";
            else {
                cout << top() << '\n';
                pop();
            }
        }
    }
    return 0;
}