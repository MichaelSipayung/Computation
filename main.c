#include "headerComput.h"
#include "algorit.h"
#include "pointer.c"
#include "sqlite3.h"
//apply extern
int max;
char line[MAXLINE],longest[MAXLINE];
int main(int argc,char *argv[]) {
    printf("Apply to Computation .... \n");
    //myArCount();
    printf("power of (3,2) is \t: %d\n", power(3,2));
    //printf("Test function test copy .... ");
    //testCopy();
    testBessel();
    printf("test macro substitution  .... \n");
    showMax(13,18);
    showMin(13,18);
    pointerTest();
    int aSwap=13;
    int ySwap=90;
    swap_v(&aSwap,&ySwap);
    char pointImp[]="implementasi pointer";
    printf("Total character \t: %d item\n", strlen_p(pointImp));
    printf("Total character \t: %d item\n", strlens(pointImp));
    printf("Command line argument .... \n");
    int iCommand;
    for(iCommand=1;iCommand<argc;iCommand++){
        printf("%s %s",argv[iCommand],(iCommand<argc-1)? " ": "");
    }
    printf("Sqlite version ..... %s \n",sqlite3_libversion());
    callScreen();
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
void showMax(int f,int l){
    printf("max of given two number is \t: %d\n", maxx(f,l));
}
void showMin(int f,int l){
    printf("min of given two number is \t: %d\n", minn(f,l));
}
void pointerTest(){
    int x=12,*y=&x;
    printf("current (x)\t:%d , and (y)\t:%d\n", x,*y);
    *y=18;
    printf("After modify\n");
    printf("current (x)\t:%d , and (y)\t:%d\n", x,*y);
}
void swap_v(int*x,int*y){
    int temp;
    printf("Interchange two value through pointer call ...\n");
    temp=*x;
    *x=*y;
    *y=temp;
    printf("After swap (x)\t: %d\n", *x);
    printf("After swap (y)\t: %d\n", *y);
}
int strlen_p(char*testPointer){
    int len;
    for(len=0;*testPointer!='\0';testPointer++){
        ++len;
    }
    return  len;
}
int strlens(char*s){
    char *p=s;//equivalent call to &s[0]
    while (*p!='\0'){
        p++;
    }
    return p-s; //substract a pointer
}
void moving(char*v[],int i,int j){
    char *temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}
char *month_name(int n){
    static char *name[]={
            "illegal","month",
            "january","february","march","april","may","june",
            "july","august","september","october","november","december"
    };
}
int numcmp(char *s1,char *s2){
    double v1,v2;
    v1= atof(s1);
    v2= atof(s2);
    if(v1<v2){
        return -1;
    }
    else if(v1>v2){
        return 1;
    }
    else{
        return 0;
    }
}
void modifySwap(void *v[],int i,int j){
    void *temp;  //an example for function that return the pointer
    temp =v[i];
    v[i]=v[j];
    v[j]=temp;
}
struct point makePoint(int x,int y){
    struct point temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
void callScreen(){
    screen.pt1 = makePoint(0,0);
    printf("Sizeof screen \t: %d byte \n", sizeof(screen));
}
struct rect canonRect(struct rect r){
    struct rect temp;
    temp.pt1.x= minF(r.pt1.x,r.pt2.x);
    temp.pt1.y= minF(r.pt1.y,r.pt2.y);
    temp.pt2.x= maxF(r.pt1.y,r.pt2.y);
    return temp;
}
struct key *binaryTest(char *word,struct key* tab,int n){
    int cond;
    struct key *low= &tab[0];
    struct key *high = &tab[n];
    struct key *mid;
    while (low<high){
        mid = low +(high-low)/2;
        if((cond= strcmp(word,mid->word))<0){
            high=mid;
        }
        else if(cond>0){
            low =mid+1;
        }
        else{
            return mid;
        }
    }
    return NULL;
}



