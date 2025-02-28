#include <algorithm>
#include <cstdint>
#include<iostream>
#include<vector>
#include <string.h>
#include <bitset>
#include <thread>
#include <chrono>
using std::cin,std::cout,std::endl;
typedef uint32_t u32;
// void output(std::vector<int> &a)
// {
//     for(auto &i: a)std::cout<<i<<" ";
//     std::cout<<"\n";
// }

inline u32 nextInteger(u32 x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}
// int* funA(int**) {}

// void addOne(int n[],int size)
// {
// 	for(int i=0;i<size;i++)
// 		n[i]++;
// }


int main()
{
    // int arr[9];
    // int **t;
    // int *value = funA(t);
    // value = arr;
    //cout << nextInteger(1) << endl;
    // std::vector<int> a(9,0);
    // output(a);
    // std::cout<<a.size()<<"\n";
    // a.push_back(8);
    // output(a);
    // a.erase(std::unique(a.begin(),a.end()),a.end());
    // output(a);
    // a.push_back(3);
    // sort(a.begin(),a.end());
    // output(a);
    // std::cout<<std::lower_bound(a.begin(),a.end(),9)-a.begin()<<"\n";
    // char c='a';
    // c=c+2;
    // std::cout<<c<<std::endl;
    // std::cout << "new" << std::endl;
    // int x =  6 & (-6);
    // std::cout << x << std::endl;
    // std::string str = "abc";
    // cin >> str;
    // cout << str <<endl;
    // int out[10];
    // int* i;
    // memset(out,3,sizeof(out));
    // for (i = out; i < out+10; ++i) cout << *i << endl;
    // int value = 10;
    // const int& cref = value;
    // value = 3;
    // cout << cref<< endl;
    // std::string str = "hello";
    // std::string a = str.substr(0,1); 
    // cout << a <<endl;
    // int num[10] = {0,1,2,3,4,5,6,7,8,9};
    // int* p = num;
    // for (int i = 0; i < 10; ++i)  cout << p[i] << endl;
    // int trynum;
    // cin >> trynum;
    // cout << trynum << endl;
    // switch (trynum) {
    //     case 1:
    //     case 1:

    // }
    //switch case 

    // int x;  cin>>x;
    // const int y = x;

    //cout << sizeof(float) << endl;
    // int minm = -1<<30;
    // cout << minm;

    // int v = -5;
    // int a = v >> 31;
    // std::bitset<32> binary (a);
    // cout << a << " " << binary << endl;
    // int r = (v + a) ^ a;
    // cout << r << endl;

    // char c1 = 'a';
    // c1 = c1 + 2;
    // cout << c1 << endl;

    // char c = 'b';
    // cout << c - 'a' + 1 << endl;
    // int num = c - 'a' + 1; 
    // cout << num << endl;
    // c = c - 'a' + 1;
   
    // cout << c << endl;
    // char c1 = 'p',c2='b';
    // cout << c1-c2 << endl;
    // char small = 'a';
    // char big = small - 32;
    // cout << small - 32 << endl;
    // cout << big << endl;

    // char c = '3';
    // cout << c - '0' << endl;
    // c = c - '0';
    // cout << c << endl;

    // cout << "warning!\7" << endl;
    // cout << sizeof(char) << endl;
    // cout << sizeof('a' + 2) << endl;
    // int y = +9;
    // cout << y << endl;
    // char c = 200;
    // cout << int(c) << endl;
    // int x = 1, y = 3;
    // double z1 = static_cast<double>(x)/y;
    // cout << z1 << endl;
    // double z2 = static_cast<double>(x/y);
    // cout << z2 << endl;
    // for ({int i = 0}; i < 9; ++i) {
    //     cout << i;
    // }
    // for (cin >> x; x < 90; cin >> x) {
    //     cout << "t" << endl;
    // }
    // if (cin >> x) {
    //     return 0;
    // } else {
    //     char ch;
    //     cin.clear();
    //     cin.ignore(90);
    //     cin.get(ch);
    //     cout << int(ch) << endl;
    // }

    // cout << 1;
    // int x = 9;
    // //cin >> x;
    //    std::this_thread::sleep_for(std::chrono::seconds(2));
    // cout << "hi" << endl;

    // int x=10;
    // //cin >> x;
    // int arr[x];

    //int arr[10];  cout << arr[10] << endl;

    // char s[] = {'1','2','3','\0'}; cout << s << endl;
    // int arr[] = {10,9,3};  cout << arr << endl;
    // char s[] = "123";
    // cout << sizeof(s) << endl;
    // cout << sizeof(int) << endl;
    // cout << sizeof(int*) << endl;

    // int x = 10;
    // int* p = &x;
    // cout << p[1] << endl;//undefined

    // int arr[2] = {0,1};
    // char c = 1;
    // cout << arr[c];//works

    // char c = 'A';
    // cout << c + 2 << endl;
    // cout << c << endl;

    // const char* str = "a";
    // //str[0] = 'b';
    // cout << str << endl;

    //seg fault
    // char* str = "a";
    // str[0] = 'b';
    // cout << str << endl;

    //ok
    // char str[] = {'a','\0'};
    // str[0] = 'b';
    // cout << str << endl;

    // char s1[] = "zello";
    // char s2[] = "hello";
    // cout << strcmp(s1,s2) << endl;
    // if (-9)  cout << "yes" << endl;

    // char* s1 = new char[10], s2[] = "abcde";
    // if (strcmp(s1,s2) > 0) cout << "yes" << endl;
    // cout << s1[6] << endl;
    // delete[] s1;

    //缓冲区溢出
    // char temp[10],s1[] = "12", s2[] = "3456";
    // strcpy(temp,s1);  strcpy(s1,s2);  strcpy(s2,temp);
    // cout << s1 << endl << s2 << endl;

    // char s[] = "hello";
    // strcpy(s, "12345");
    // cout << s << endl;

    // char s[] = "abc";
    // cout << sizeof(s) << endl;
    // cout << strlen(s) << endl;

    // char*s = new char[100];
    // strcpy(s,"789");
    // cout << s << endl;
    // delete[] s;
    // int a[4]={1,2,3,4};
	// addOne(a+2,2);
	// for(int i=0;i<4;i++)
	// 	cout<<a[i]<<endl;

    // const char *s = "123";
    // //char a[] = "123";
    // char a[] = {'1','2','3','\0'};
    // cout << sizeof(s) << " " << sizeof(a) << endl;    

    // int a = 19;
    // int *const p = &a;
    // int *const q = p;
    // cout << *q << endl;

    // char *s1 = "13";
    // //char s1[] = {'1','2','\0'};
    // char(& p)[3] = s1;
    // cout << sizeof(p) << endl;
    
    // int a = 10;
    // int& p = a;
    // cout << sizeof(p) << endl;

    // int&& rref = 42;  
    // rref = 100;    
    // cout << rref << endl;   //100
    
    // int a = rref;
    // const int b = rref;
    // rref = 90;
    // cout << b << endl;  //100

    // const int a = 10;
    // int*p = a;//wrong
    return 0;
}