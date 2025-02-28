#include<iostream>
using std::cout;
using std::endl;
using std::cin;
int ans[200002]={0};
int mond[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool spyear(int a){
    if((a%4==0&&a%100!=0)||a%400==0){
        return true;
    }else return false;
}
int years(int a,int b){
    int days=0;
    for(int i=a;i<=b;++i){
        days+=spyear(i)?366:365;
    }
    return days;
}
int cutfront(int year,int month,int day){
    int days=0;
    for(int i=1;i<=month;++i){
        days+=mond[i];
        days+=(i==2&&spyear(year))?1:0;
    }
    days-=(month==2&&spyear(year))?(mond[month]-day+1):(mond[month]-day);
    return days;
}
int cutback(int year,int month,int day){
    int days=0;
    for(int i=month;i<=12;++i){
        days+=mond[i];
        days+=(i==2&&spyear(year))?1:0;
    }
    days-=day;
    return days;
}
int main(){
    int T,i,j;
    char store[300001][11],ch;
    cin>>T;
    for(i=0;i<2*T;++i){
        for(j=0;j<10;++j){
            cin>>ch;
            if(ch!=' ')store[i][j]=ch;
        }
    }
    int year,month,day,yearx,monthx,dayx;
    for(i=0;i<=2*(T-1);i+=2){
        year=(int(store[i][0])-48)*1000+(int(store[i][1])-48)*100+(int(store[i][2])-48)*10+(int(store[i][3])-48);
        yearx=(int(store[i+1][0])-48)*1000+(int(store[i+1][1])-48)*100+(int(store[i+1][2])-48)*10+(int(store[i+1][3])-48);
        month=(int(store[i][5])-48)*10+(int(store[i][6])-48);
        monthx=(int(store[i+1][5])-48)*10+(int(store[i+1][6])-48);
        day=(int(store[i][8])-48)*10+(int(store[i][9])-48);
        dayx=(int(store[i+1][8])-48)*10+(int(store[i+1][9])-48);
        int w;
        if(year>yearx){
            w=year;year=yearx;yearx=w;
            w=month;month=monthx;monthx=w;
            w=day;day=dayx;dayx=w;
        }else if(yearx==year&&month>monthx){
            w=month;month=monthx;monthx=w;
            w=day;day=dayx;dayx=w;
        }else if(year==yearx&&month==monthx&&day>dayx){
            w=day;day=dayx;dayx=w;
        }
        ans[i]=years(year,yearx)-cutfront(year,month,day)-cutback(yearx,monthx,dayx);
    }
    for(i=0;i<=2*(T-1);i+=2) cout<<ans[i]<<endl;
    return 0;
}