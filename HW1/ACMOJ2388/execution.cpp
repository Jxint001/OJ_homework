#include <iostream>
#include <sstream>
#include <cstring>
#include<string>
#include <vector>
#include<algorithm>
struct book{
    int start_time;
    int end_time;
    int name;
}books[101];
enum place{ FRONT, BACK, LIST, ERROR}instruction;
place Parse(const std::string,int& filename);
int length(int);
bool cmp(book a,book b);
int main()
{
    std::string command;
    int filename,i=0;
    int time=0;
    while(std::getline(std::cin,command)){
        if(command.empty()){
            time+=1;
        }
        else{
            instruction=Parse(command,filename);
            switch(instruction){
                case FRONT://只有执行完前台才有可能进行下面命令
                    if(filename<5000) std::cout<<filename<<std::endl; 
                    time+=length(filename);
                    break;
                case BACK:
                    books[i].start_time=time;
                    books[i].end_time=time+length(filename);
                    books[i].name=filename;
                    i+=1;
                    time+=1;
                    break;
                case LIST:
                    std::sort(books,books+i,cmp);
                    for(int j=0;j<i;++j){
                        if(books[j].end_time>time) std::cout<<books[j].name<<" "<<"back"<<" "<<books[j].end_time-time<<std::endl;
                    }
                    time+=1;
                    break;
                default:break;
            }
        }
    }
    return 0;
}
place Parse(const std::string command, int& filename) 
{
    std::istringstream iss(command);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens[0][0] == '.' && tokens[0][1] == '/') {
        filename = std::stoi(tokens[0].substr(2));
        if (tokens.size() >= 2 && tokens[1][0] == '&') {
            return BACK;
        } else {
            return FRONT;
        }
    } else if (tokens[0][0] == 'l') {
        return LIST;
    } 
    return ERROR;
}
int length(int a)
{
    if(a<4000) return 30;
    else return a/10;
}
bool cmp(book a,book b)
{
    if(a.end_time!=b.end_time) return a.end_time<b.end_time;
    else return a.start_time<b.start_time;
}