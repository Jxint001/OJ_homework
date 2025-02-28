#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
    //todo
    p = new int*[n];
    for (int i = 0; i < n; ++i) {
        p[i] = nullptr;
    }
}
void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
    //todo
    --x;
    if (p[x] == nullptr) {
        p[x] = new int[18];
        p[x][2] = y;
        p[x][0] = 1;  //已经存了多少个数字
        p[x][1] = 16;  //最多存多少个数字
    } else {    
        int len = p[x][0];
        ++len;
        if (len > p[x][1]) {
            int* vec = new int[2 + p[x][1] * 2];
            for (int i = 2; i < 1 + len; i++) {
                vec[i] = p[x][i];
            }
            vec[1 + len] = y;
            vec[0] = len;
            vec[1] = 2 * p[x][1];
            delete[] p[x];
            p[x] = vec;
        } else {
            p[x][0] = len;
            p[x][1 + len] = y;
        }
    }
}
int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
    //todo
    return p[x - 1][k + 1];
}
void Clear(int **&p,int n){//回收空间
    //todo
    for (int i = 0; i < n; ++i) {
        delete[] p[i];
    }
    delete[] p;
    p = nullptr;
}