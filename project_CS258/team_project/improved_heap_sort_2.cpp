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

void sift_up(int id){
    unsigned int tmp = s[id];
    while (id >= 1){
        int par = id >> 1;
        if (s[par] > tmp)
            break;
        s[id] = s[par], id >>= 1;
    }
    s[id] = tmp;
}
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
int another_percolate_down(){
    int cur = 1; 
    while ((cur << 1) <= n){
        int ch = (cur << 1);
        if (ch + 1 <= n && s[ch + 1] > s[ch])
            ++ch;
        s[cur] = s[ch];
        cur = ch;
    }
    return cur;
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
    int nn = n;
    heapify();
    for (int i = n; i >= 2; --i){
        unsigned int tmp = s[1];
        int pos = another_percolate_down();
        --n;
        if (pos != i){
            s[pos] = s[i];
            sift_up(pos);
        }
        s[i] = tmp;
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