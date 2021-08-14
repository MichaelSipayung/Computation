#include "headerComput.h"
int main() {
    printf("Apply to Computation .... \n");
    //myArCount();
    printf("power of (3,2) is \t: %d\n", power(3,2));
    return 0;
}
int countLine(){
    int c,nl;
    nl=0;
    while ((c=getchar())!=EOF){
        if(c=='\n'){
            ++nl;
        }
    }
    return nl;
}
void countWord(){
    int c,nl,nw,nc,state;
    state=OUT;
    nl=0,nc=0,nw=0;
    while((c=getchar())!=EOF){
        ++nc;
        if(c=='\n'){
            ++nl;
        }
        if(c=='\n'||c=='\t'||c==' '){
            state=OUT;
        }
        else if(state==OUT){
            state=IN;
            ++nw;
        }
    }
}
void myArCount(){
    int c,nwhite,nother;
    int ndigit[10];
    nwhite=nother=0;
    for (int j = 0; j <10 ; ++j) {
      ndigit[j]=0;
    }
    printf("input a word, press x to finish? ");
    while(c=getchar()){
        if (c=='x'){ break;}
        if(c>='0'&&c<='9'){
            ++ndigit[c-'0'];
        }
        else if(c==' '|| c=='\n'||c=='\t'){
            ++nwhite;
        }
        else{
            ++nother;
        }
    }
    printf("Digits \t:  ");
    for (int j = 0; j < 10; ++j) {
        printf("%d - ",ndigit[j]);
    }
    printf("\nWhitespace \t: %d\nother \t: %d\n", nwhite,nother);
}
int power(int base,int n){
    int p=1;
    for (int i = 0; i <n ; ++i) {
        p*=base;
    }
    return p;
}

