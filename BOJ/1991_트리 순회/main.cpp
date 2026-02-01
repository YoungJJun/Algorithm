#include <iostream>
#include <vector>
using namespace std;
struct node {
    char value;
    char left;
    char right;

    node(int v, char l, char r) {
        value = v;
        left = l;
        right = r;
    }
};

void f1(vector<node> &v, char cur) {
    if (cur == '.') return;

    cout<<cur;
    f1(v, v[cur-65].left);
    f1(v, v[cur-65].right);
}

void f2(vector<node> &v, char cur) {
    if (cur == '.') return;

    f2(v, v[cur-65].left);
    cout<<cur;
    f2(v, v[cur-65].right);
}

void f3(vector<node> &v, char cur) {
    if (cur == '.') return;

    f3(v, v[cur-65].left);
    f3(v, v[cur-65].right);
    cout<<cur;
}

int main() {

    int N;
    cin>>N;
    vector<node> v(N, node('A', '.', '.'));

    for (int i = 0; i < N; i++) {
        char a,b,c;
        cin>>a>>b>>c;

        v[a-65].value = a;
        v[a-65].left = b;
        v[a-65].right = c;
    }

    f1(v, 'A');
    cout<<'\n';
    f2(v,'A');
    cout<<'\n';
    f3(v,'A');

}