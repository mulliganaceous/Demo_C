#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

float hex_to_float(int hex_number[]){
long i=0;
scanf("%[^\n]", hex_number);

for(i=0; hex_number[i]!='\0'; i++){
    if(hex_number[i]==0){
        hex_number[i]=0000;
    }
    if(hex_number[i]==1){
        hex_number[i]=0001;
    }
    if(hex_number[i]==2){
        hex_number[i]=0010;
    }
    if(hex_number[i]==3){
        hex_number[i]=0011;
    }
    if(hex_number[i]==4){
        hex_number[i]=0100;
    }
    if(hex_number[i]==5){
        hex_number[i]=0101;
    }
    if(hex_number[i]==6){
        hex_number[i]=0110;
    }
    if(hex_number[i]==7){
        hex_number[i]=0111;
    }
    if(hex_number[i]==8){
        hex_number[i]=1000;
    }
    if(hex_number[i]==9){
        hex_number[i]=1001;
    }
    if(hex_number[i]=='a' || hex_number[i]=='A'){
        hex_number[i]=1010;
    }
    if(hex_number[i]=='b' || hex_number[i]=='B'){
        hex_number[i]=1011;
    }
    if(hex_number[i]=='c' || hex_number[i]=='C'){
        hex_number[i]=1100;
    }
    if(hex_number[i]=='d' || hex_number[i]=='D'){
        hex_number[i]=1101;
    }
    if(hex_number[i]=='e' || hex_number[i]=='E'){
        hex_number[i]=1110;
    }
    if(hex_number[i]=='f' || hex_number[i]=='F'){
        hex_number[i]=1111;
    }
}