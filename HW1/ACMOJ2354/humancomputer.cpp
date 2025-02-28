bool F(bool a,bool b){
    if(a==b) return true;
    else return false;
}
bool boolAnd(bool a,bool b){
    if(F(a,b)){
        if(F(a,true)) return true;
        else return false;
    }else{
        return false;
    }
}
bool boolNot(bool a){
    if(F(a,true)) return false;
    else return true;
}