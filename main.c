#include "headerComput.h"
//apply extern
int max;
char line[MAXLINE],longest[MAXLINE];
int main() {
    printf("Apply to Computation .... \n");
    //myArCount();
    printf("power of (3,2) is \t: %d\n", power(3,2));
    //printf("Test function test copy .... ");
    //testCopy();
    testBessel();
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
int getline(char s[],int lim){
    int c;
    int j;
    for ( j = 0; j < lim-1 &&(c=getchar())!='x' && c!='\n'; ++j) {
        s[j]=c;
    }
      if(c =='\n'){
          s[j]=c;
          ++j;
      }
      s[j]='\0';

    return j;
}
void copy(char to[],char from[] ){
    int i;
    i=0;
    while ((to[i]=from[i])!='\0'){
        ++i;
    }
}
void testCopy(){
    int len,max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max=0;
    while ((len= getline(line,MAXLINE))>0){
        if(len>max){
            max=len;
            copy(longest,line);
        }
    }
    if(max>0){
        printf("Result, after copy \t: %s", longest);
    }
}
int getExline(){
    //..put extern variable here
    int len;
    extern char line[];
    //all algorithm are equals
    return 0;
}
void copyEx(){
    int i ;
    extern char line[],longest[];
    //all algorithm aare equal as before  ....
}
int binarysearch(int x,int v[],int n){
    int low,high,mid;
    low =0;
    high = n-1;
    while (low<=high){
        mid=(low+high)/2;
        if(x<v[mid]){ //change the interval
            high = mid+1;
        }
        else if(x>v[mid]){ //change the interval
            low = mid+1;
        }
        else{ //found match
            return mid;
        }
    }
    return -1;
}
void shellsort(int v[],int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2){
        for(i=gap;i<n;i++){
            for(j=i-gap;j>=0 &&v[j]>v[j+gap];j-=gap){ //evaluate the element ... (compare related element)
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;
            }
        }
    }
}
void reverseStr(char s[]){
    int c,i,j;
    for(i=0,j= strlen(s)-1;i<j;i++,j--){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
int getNLine(char s[],int lim ){
    int c,i;
    i=0;
    while(--lim>0 && (c=getchar())!='*' && c!='\n'){
        s[i++]=c;
    }
    if(c=='\n'){
        s[i++]=c;
    }
    s[i]=='\0';
    return i;
}
int strindex(char s[],char t[]){
    int i,j,k;
    for(i=0;s[i]!='\0';i++){
        for(j=i,k=0;t[k]!='\0' &&s[j]==t[k];j++,k++){
            //.. not execution
        }
        if(k>0 && t[k]  == '\0'){
            return i;
        }
    }
    return -1;
}
double atofN(char s[]){
    double val,power;
    int i,sign;
    for(i=0; isspace(s[i]);i++);  //stop when meet a space
    sign  = (s[i] =='-'?-1:1);
    if(s[i]=='+'||s[i]=='-'){
        i++;
    }
    for(val=0.0; isdigit(s[i]);i++){
        val=10.0*val+(s[i]-'0');
    }
    if(s[i]=='.'){
        i++;
    }
    for(power=1.0; isdigit(s[i]);i++){
        val=10.0*val+(s[i]-'0');
        power*=10;
    }
    return sign*val/power;
}

void testBessel(){
    printf("Test bessel function .... \n");
    double  x=5.0;
    double y= gsl_sf_bessel_j0(x);
    printf("Bessel function result \t: ");
    printf("j0(%g) = %.18e\n",x,y);
}
double pop(){
    if(sp>0){
        return val[--sp];
    }
    else{
        printf("Sorry stack is still empty .... \n");
        return 0.0;
    }
}

void push(double f){
    if(sp<MAXVAL){
        val[sp++] = f;
    }
    else{
        printf("sorry stack is full , can\'t push ..... \n");
    }
}
void swap(int v[],int i ,int j){
    int temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}
void qsorts(int v[],int left,int right){
    int i,last;
    if(left>=right){
        return;//do nothing if an array contain fewer than two
    }
    swap(v,left,(left+right)/2);
    last=left;
    for(i=left+1;i<=right;i++){ //partition
        if(v[i]<v[left]){
            swap(v,++last,i);
        }
    }
    swap(v,left,last);
    qsorts(v,left,last-1);
    qsorts(v,last+1,right);
}





