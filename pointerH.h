#ifndef COMPUTATION_POINTERH_H
#define COMPUTATION_POINTERH_H
void pointerTest();
void swap_v(int*,int*);
int strlen_p(char*);
int strlens(char*);
void moving(char*[],int,int);
char *month_name(int);
int numcmp(char *,char*);
void modifySwap(void *v[],int,int);
struct point{
    int x,y;
};
struct point makePoint(int,int);
struct rect{
    struct point pt1; //8 byte
    struct point pt2; //8 byte  ....
};
struct rect screen;
void callScreen();
#define minF(a,b) ((a)<(b) ? (a):(b))
#define maxF(a,b) ((a)>(b) ? (a):(b))
struct rect canonRect(struct rect);
struct rect pointTo,*pointer=&pointTo; //initialized a pointer(struct)
struct key{
    char *word;
    int count;
}keytab[5]={"auto",0,"break",0,"while",0,"for",0};
struct key *binaryTest(char *,struct key*,int );
#endif
