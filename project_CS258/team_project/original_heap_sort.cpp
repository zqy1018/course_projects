#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
inline ui next_integer(ui x){
    /* random sequence generator */
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}
unsigned int s[5000005], lst;
int n;
void percolate_down(int x){
    unsigned int tmp = s[x];
    while ((x << 1) <= n){
        int ch = (x << 1);
        if (ch + 1 <= n && s[ch + 1] > s[ch])
            ++ch;
        if (tmp > s[ch]) break;
        s[x] = s[ch], x = ch;
    }
    s[x] = tmp;
}
void heapify(){
    for (int i = (n >> 1); i >= 1; --i){
        percolate_down(i);
    }
}
void output_test(int siz){
    for (int i = 1; i <= siz; ++i){
        cout << s[i] << endl;
    }
}
void heapsort(){
    heapify();
    int nn = n;
    for (int i = n; i >= 2; --i){
        swap(s[i], s[1]);
        --n;
        percolate_down(1);
    }
    // output_test(nn);
}
int main(int argc, char **argv){
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%u", &lst);
    for (int i = 1; i <= n; ++i){
		s[i] = next_integer(lst), lst = s[i];
    }

    /* count time */
    auto start = chrono::steady_clock::now();

    heapsort();

    auto end = chrono::steady_clock::now();
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	cout << endl;
    return 0;
}