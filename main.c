//
//  main.c
//  artificialintelegence1
//
//  Created by Joseph Phillips on 10/25/16.
//  Copyright © 2016 Joseph Phillips. All rights reserved.
///*0**-pawn , 1**-king,2**-queen,3**-bishop,4**-knight,5**-rook*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int run = 1;

int curTurn = 0;

int curPiece = 0;

/*9 - 16 = pawns,  11=rook, 21=knight, 31=bishop, 41=queen, 51=king, 61=bishop, 71=knight 81=k*/
int BlackX[16] =    { 1,    2,    3,    4,    5,    6,    7,    8,          1,    2,    3,    4,    5,    6,    7,    8};
int BlackY[16] =    { 1,    1,    1,    1,    1,    1,    1,    1,          2,    2,    2,    2,    2,    2,    2,    2};
char *pieces[16] = {"*ro","*kn","*bi","Q*U","K*I","bi*","kn*","ro*",      "pa1","pa2","pa3","pa4","pa5","pa6","pa7","pa8"};
int Scoring[16] =  {  5,    3,    3,    9,    9,    3,    3,    5,          1,    1,    1,    1,    1,    1,    1,    1};
int WhiteX[16] =    { 1,    2,    3,    4,    5,    6,    7,    8,          1,    2,    3,    4,    5,    6,    7,    8};
int WhiteY[16] =    { 8,    8,    8,    8,    8,    8,    8,    8,          7,    7,    7,    7,    7,    7,    7,    7};


int Score[64] = {0,0,0,0,0,0,0,0
                ,0,0,0,0,0,0,0,0
                ,0,0,0,0,0,0,0,0
                ,0,0,0,0,0,0,0,0
                ,0,0,0,0,0,0,0,0
                ,0,0,0,0,0,0,0,0
                ,0,0,0,0,0,0,0,0
                ,0,0,0,0,0,0,0,0};

typedef struct pos pos;
struct pos{
    int x;
    int y;
    
};

int contains(char* team, int x ,int y){
    int i;
    
    if(0== strcmp(team, "black")){
        for(i=0;i<16;i++){
            if(BlackX[i]== x && BlackY[i]== y){ return 1;break;};
        }
        
    }
    if(0== strcmp(team, "white")){
        for(i=0;i<16;i++){
            if(WhiteX[i]== x && WhiteY[i]== y){ return 1;break;};
        }
    }
    
    return 0;

};


int calcScore(){
    return 0;
}

int coordToBoardPos(x,y){
    int num;
    num = ((y-1)*8)+x;
/*    printf("%d",num); */
    return num;
};

int BoardPosToYCoord(num){
    int y;
    
    y = (int)floor(num/8)+1;
   /* printf("%d",y); */
    return y;
};

int BoardPosToXCoord(num){
    int y;
    int x;
    
    y = (int)floor(num/8)+1;
    x = num - ((y-1)*8)+1;
   /* printf("%d",x); */
    return x;
};

int coordToNum(x,y){
    int num;
    num = x*10+y;
/*    printf("%d",num); */
    return num;
};

int numToXCoord(num){
    int x;
    
    x = (int)floor(num/10);
  /*  printf("%d",x); */
    return x;
};

int numToYCoord(num){
    int x;
    int y;
    
    x = (int)floor(num/10);
    y = num-(x*10);
    
   /* printf("%d",y); */
    return y;
};






int coordScore(x,y){
    return 0;
}


int tileStat(x,y){
    int i = 0;
    
    if(x < 0 || x > 8 || y < 0 || y > 0){
        return -1;
    }
    for(i=0;i > 15;i++){
    
        if(BlackX[i] == x && BlackY[i] == y){
                return 1;
        }else
        if(WhiteX[i] == x && WhiteY[i] == y){
            return 2;
        }

    }
    return 0;
};

char* tile(x,y){
    int i;
    int X = x;
    int Y = y;
    
    int ispiece = 0;
    
    char* piece="";
    if(X < 0 || X > 8 || Y < 0 || Y > 8){
        return "in-valid";
    }
    
    for(i=0;i < 16;i++){
        
        if(BlackX[i] == X && BlackY[i] == Y){
            piece =  pieces[i];
            ispiece = 1;
            break;
        }else
        if(WhiteX[i] == X && WhiteY[i] == Y){
            piece = pieces[i];
            ispiece = 1;
            break;
        }
        
    }

      
            return piece;
            
       
   
};

int ScanY(x,y,tempY){
    while (tempY != y){if( 0 == tileStat(x,tempY)) {
        ScanY(x,tempY-1);
    }else{
        return -1;
    }
    }
    
    return y;
};

int ScanX(x,y,tempX){
    while (tempX != x){if( 0 == tileStat(tempX,y)) {
        ScanX(y,tempX-1);
    }else{
        return -1;
    }
    }
    
    return x;
};

int ScanXY(x,tempX, y,tempY){
    while (tempX != x){if( 0 == tileStat(tempX,tempY) ) {
        ScanXY(x,tempX-1,y,tempY-1);
    }else{
        return -1;
    }
    }
    
    return x;
};

int board(){
    int i;
    int r=0;
    
    
    
    int j;
    int k;
    int number = 16;
    int full = 0;
    printf("\n              WHITE SIDE 2  \n");
    for(j=1;j<9;j++){
        
        for(k=1;k<9;k++){
            for(i=0;i<16;i++){
                if(BlackX[i]== k && BlackY[i]== j){ printf("[%s]",pieces[i]); full=1;break;};
                if(WhiteX[i]== k && WhiteY[i]== j){ printf("[%s]",pieces[i]); full=1;break;};
            }
            if(full==1){}else{                            printf("[%d,%d]", k, j);number++;};
            
            full = 0;
        }
        printf("\n");
    }
    printf("             BLACK SIDE 1  \n");
    
    
    return 0;
    
};

int calculateScore(piece,boardPos){
    int x,y;
    x = BoardPosToXCoord(boardPos);
    y =BoardPosToYCoord(boardPos);
    
    int i;
    for(i=1;i<8;i++){
        
        
        
        if((0 == strcmp(tile(x+1,y+1), "pa1")|| 0 == strcmp(tile(x-1,y+1), "pa1")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        if((0 == strcmp(tile(x+1,y+1), "pa2")|| 0 == strcmp(tile(x-1,y+1), "pa2")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        if((0 == strcmp(tile(x+1,y+1), "pa3")|| 0 == strcmp(tile(x-1,y+1), "pa3")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        if((0 == strcmp(tile(x+1,y+1), "pa4")|| 0 == strcmp(tile(x-1,y+1), "pa4")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        if((0 == strcmp(tile(x+1,y+1), "pa5")|| 0 == strcmp(tile(x-1,y+1), "pa5")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        if((0 == strcmp(tile(x+1,y+1), "pa6")|| 0 == strcmp(tile(x-1,y+1), "pa6")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        if((0 == strcmp(tile(x+1,y+1), "pa7")|| 0 == strcmp(tile(x-1,y+1), "pa7")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        if((0 == strcmp(tile(x+1,y+1), "pa8")|| 0 == strcmp(tile(x-1,y+1), "pa8")) && contains("white",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - (Scoring[piece]/Scoring[9])*Scoring[piece] ;break; }
        
        
        if((0 == strcmp(tile(x+1,y-1), "pa1")|| 0 == strcmp(tile(x-1,y-1), "pa1")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        if((0 == strcmp(tile(x+1,y-1), "pa2")|| 0 == strcmp(tile(x-1,y-1), "pa2")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        if((0 == strcmp(tile(x+1,y-1), "pa3")|| 0 == strcmp(tile(x-1,y-1), "pa3")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        if((0 == strcmp(tile(x+1,y-1), "pa4")|| 0 == strcmp(tile(x-1,y-1), "pa4")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        if((0 == strcmp(tile(x+1,y-1), "pa5")|| 0 == strcmp(tile(x-1,y-1), "pa5")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        if((0 == strcmp(tile(x+1,y-1), "pa6")|| 0 == strcmp(tile(x-1,y-1), "pa6")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        if((0 == strcmp(tile(x+1,y-1), "pa7")|| 0 == strcmp(tile(x-1,y-1), "pa7")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        if((0 == strcmp(tile(x+1,y-1), "pa8")|| 0 == strcmp(tile(x-1,y-1), "pa8")) && contains("black",x,y) == 1)
        { return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[9])*Scoring[piece]) ;break; }
        
        
        if(0 == strcmp(tile(x-2,y-1), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-2,y-1), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x-2,y+1), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-2,y+1), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x+2,y-1), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+2,y-1), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x+2,y+1), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+2,y+1), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        
        
        
        if(0 == strcmp(tile(x-1,y-2), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-1,y-2), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x-1,y+2), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-1,y+2), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x+1,y-2), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+1,y-2), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x+1,y+2), "*kn")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+1,y+2), "kn*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[1])*Scoring[piece]) ;break; }
        
        
        
        
        
        
        if(0 == strcmp(tile(x+i,y), "*ro")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+i,y), "ro*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x,y+i), "*ro")){ Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x,y+i), "ro*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x-i,y), "*ro")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-i,y), "ro*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x,y-i), "*ro")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x,y-i), "ro*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[0])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x-i,y-i), "*bi")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-i,y-i), "bi*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x+i,y+i), "*bi")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+i,y+i), "bi*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x+i,y-i), "*bi")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+i,y-i), "bi*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        
        if(0 == strcmp(tile(x-i,y+i), "*bi")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-i,y+i), "bi*")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[2])*Scoring[piece]) ;break; }
        

        if(0 == strcmp(tile(x+i,y), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+1,y), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        

        if(0 == strcmp(tile(x,y+i), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x,y+1), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        

        if(0 == strcmp(tile(x-i,y), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-1,y), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        

        if(0 == strcmp(tile(x,y-i), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x,y-1), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        

        if(0 == strcmp(tile(x-i,y-i), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-1,y-1), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        
        
        if(0 == strcmp(tile(x+i,y+i), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+1,y+1), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        
        
        if(0 == strcmp(tile(x+i,y-i), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x+1,y-1), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        

        if(0 == strcmp(tile(x-i,y+i), "Q*U")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[3])*Scoring[piece]) ;break; }
        if(0 == strcmp(tile(x-1,y+1), "K*I")){ return Score[boardPos] = Scoring[piece] - ((Scoring[piece]/Scoring[4])*Scoring[piece]) ;break; }
        
   
        }
    
   
/*    printf("%d %d \n",x, y);  */
/*    printf("%s\n",tile(x,y)); */
    
    return Score[boardPos];
}

int boardScore(){
    int column = 0;
    int i;
    int full=0;
    int j;
    for(j=0;j<64;j++){
        
        for(i=0;i<16;i++){
            if(BlackX[i]== BoardPosToXCoord(j) && BlackY[i]== BoardPosToYCoord(j)){ Score[j]=Scoring[i];calculateScore(i,j);printf("[ %d ]",calculateScore(i,j));full=1;column++;break;};
            if(WhiteX[i]== BoardPosToXCoord(j) && WhiteY[i]== BoardPosToYCoord(j)){ Score[j]=Scoring[i]; calculateScore(i,j);printf("[ %d ]",calculateScore(i,j));full=1;column++; break;};
            
        }
        if(full==1){}else{   printf("[   ]");column++;};
        
        full = 0;
        if(column == 8){ printf("\n");column = 0;}
        
        
    };
    printf("\n");
    return 0;
    
};

int blackTurn(){
    curTurn = 1;
    int x,y,n;
    char p[3];
    printf("Black's Turn");
    printf(" enter piece to move: ");
    scanf("%s", p);
    printf("and new %s's new cooridants: ", p);
    scanf(" %d %d", &x, &y);
    
    if(0 == strcmp(p, "*ro")){n=0;curPiece=0; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa1")){n=8;curPiece=8; BlackX[n] = x; BlackY[n] = y;}
    if(0 == strcmp(p, "*kn")){n=1;curPiece=1; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa2")){n=9;curPiece=9; BlackX[n] = x; BlackY[n] = y;}
    if(0 == strcmp(p, "*bi")){n=2;curPiece=2; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa3")){n=10;curPiece=10; BlackX[n] = x; BlackY[n] = y;}
    if(0 == strcmp(p, "Q*U")){n=3;curPiece=3; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa4")){n=11;curPiece=11; BlackX[n] = x; BlackY[n] = y;}
    if(0 == strcmp(p, "K*I")){n=4;curPiece=4; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa5")){n=12;curPiece=12; BlackX[n] = x; BlackY[n] = y;}
    if(0 == strcmp(p, "bi*")){n=5;curPiece=5; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa6")){n=13;curPiece=13; BlackX[n] = x; BlackY[n] = y;}
    if(0 == strcmp(p, "kn*")){n=6;curPiece=6; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa7")){n=14;curPiece=14; BlackX[n] = x; BlackY[n] = y;}
    if(0 == strcmp(p, "ro*")){n=7;curPiece=7; BlackX[n] = x; BlackY[n] = y;} if(0 == strcmp(p, "pa8")){n=15;curPiece=15; BlackX[n] = x; BlackY[n] = y;}
   

    board();
    return 0;
}

int whiteTurn(){
    curTurn = -1;
    int x,y,n;
    char p[3];
    printf("White's Turn");
    printf(" enter piece to move: ");
    scanf("%s", p);
 printf("and new %s's new cooridants: ", p);
    scanf(" %d %d", &x, &y);
    
    if(0 == strcmp(p, "*ro")){n=0;curPiece=0; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa1")){n=8;curPiece=8; WhiteX[n] = x; WhiteY[n] = y;}
    if(0 == strcmp(p, "*kn")){n=1;curPiece=1; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa2")){n=9;curPiece=9; WhiteX[n] = x; WhiteY[n] = y;}
    if(0 == strcmp(p, "*bi")){n=2;curPiece=2; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa3")){n=10;curPiece=10; WhiteX[n] = x; WhiteY[n] = y;}
    if(0 == strcmp(p, "Q*U")){n=3;curPiece=3; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa4")){n=11;curPiece=11; WhiteX[n] = x; WhiteY[n] = y;}
    if(0 == strcmp(p, "K*I")){n=4;curPiece=4; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa5")){n=12;curPiece=12; WhiteX[n] = x; WhiteY[n] = y;}
    if(0 == strcmp(p, "bi*")){n=5;curPiece=5; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa6")){n=13;curPiece=13; WhiteX[n] = x; WhiteY[n] = y;}
    if(0 == strcmp(p, "kn*")){n=6;curPiece=6; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa7")){n=14;curPiece=14; WhiteX[n] = x; WhiteY[n] = y;}
    if(0 == strcmp(p, "ro*")){n=7;curPiece=7; WhiteX[n] = x; WhiteY[n] = y;} if(0 == strcmp(p, "pa8")){n=15;curPiece=15; WhiteX[n] = x; WhiteY[n] = y;}
    
  
    board();
    return 0;
}




int gamePlay(){
    
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    board();
    while(1==1){
    boardScore();
    blackTurn();
    whiteTurn();
    };
    
    
    return 0;
}




