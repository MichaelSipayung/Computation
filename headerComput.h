//
// Created by zyrex on 8/14/2021.
//

#ifndef COMPUTATION_HEADERCOMPUT_H
#define COMPUTATION_HEADERCOMPUT_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <gsl/gsl_sf_bessel.h>
#define OUT 0
#define IN 1
#define ERR -1
#define MAXLINE 1000
int countLine();
void countWord();
void myArCount();
int power(int,int);
int getline(char[],int);
void copy(char[],char[]);
void testCopy();
int getExline();
void copyEx();
int binarysearch(int,int[],int);
void shellsort(int[],int);
void reverseStr(char[]);
int getNLine(char[],int);
int strindex(char [],char[]);
double atofN(char[]);
void testBessel();
//put here for external variable
#define MAXVAL 100
int sp=0;
double val[MAXVAL];
double pop();
void push(double);
void swap(int[],int ,int);
void qsorts(int [],int,int);
#endif //COMPUTATION_HEADERCOMPUT_H
