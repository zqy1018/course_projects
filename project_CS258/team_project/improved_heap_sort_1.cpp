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
unsigned int s[500005], b[500005], lst;
int l[500005], r[500005], n;

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
void another_percolate_down(){
    int cur = 1, *fa;
    for (; ; ){
        int ch = l[cur];
        if (!ch){
            ch = r[cur];
            if (!ch) {
                *fa = 0;
                break;
            }
            s[cur] = s[ch];
            fa = &r[cur];
            cur = ch;
        }else {
            int rch = r[cur];
            if (!rch){
                s[cur] = s[ch];
                fa = &l[cur];
                cur = ch;
            }else {
                if (s[rch] > s[ch]){
                    s[cur] = s[rch];
                    fa = &r[cur];
                    cur = rch;
                }else {
                    s[cur] = s[ch];
                    fa = &l[cur];
                    cur = ch;
                }
            }
        }
    }
}
void heapify(){
    for (int i = (n >> 1); i >= 1; --i){
        percolate_down(i);
    }
}
void output_test(int siz){
    for (int i = 1; i <= siz; ++i){
        cout << b[i] << endl;
    }
}
void heapsort(){
    heapify();
    for (int i = n; i > 1; --i){
        b[i] = s[1];
        another_percolate_down();
    }
    b[1] = s[1];
    // output_test(n);
}
int main(){
    scanf("%d%u", &n, &lst);
    for (int i = 1; i <= n; ++i){
		s[i] = next_integer(lst), lst = s[i];
        int lch = (i << 1), rch = (i << 1 | 1);
        l[i] = lch <= n ? lch: 0;
        r[i] = rch <= n ? rch: 0;
    }

    /* count time */
    auto start = chrono::steady_clock::now();

    heapsort();

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in microseconds : ";
	cout << chrono::duration_cast<chrono::microseconds>(end - start).count();
	cout << endl;
    return 0;
}