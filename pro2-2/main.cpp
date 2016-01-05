

#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define ImageHeight 374
#define ImageWidth 388


void GImageRead(unsigned char ImageData[ImageHeight][ImageWidth], const char * FileName )
{
	FILE * ReadFile;
	if ( !(ReadFile = fopen(FileName,"rb")))
	{
		cout << "Input Image Error!\n"<<endl;
		system("pause");
		exit(1);
	}
	fread(ImageData, sizeof(unsigned char), ImageHeight*ImageWidth, ReadFile);
	fclose(ReadFile);
}

void GImageWrite(unsigned char ImageData[ImageHeight][ImageWidth] , const char * FileName)
{
	FILE * WriteFile;
	if (!(WriteFile = fopen(FileName, "wb")))
	{
		cout<<"Input Image Error!\n"<<endl;
		system("pause");
		exit(1);
	}
	fwrite(ImageData, sizeof(unsigned char), ImageHeight*ImageWidth, WriteFile);
	fclose(WriteFile);
}

void ImageWrite(unsigned char ImageData[ImageHeight][ImageWidth][3], const char * FileName)
{
	FILE * WriteFile;
	if (!(WriteFile = fopen(FileName, "wb")))
	{
		cout<<"Input Image Error!\n"<<endl;
		system("pause");
		exit(1);
	}
	fwrite(ImageData, sizeof(unsigned char), ImageHeight*ImageWidth*3, WriteFile);
	fclose(WriteFile);
}

void HistWrite1(int hist[222], const char * FileName )
{
	FILE * WriteFile;
	if (!(WriteFile = fopen(FileName, "wb")))
	{
		cout<<"Output Image Error!\n"<<endl;
		system("pause");
		exit(1);
	}
    
    for(int i=0;i!=256;i++)
    {
        fprintf(WriteFile,"%d\t",hist[i]);
    }
    
    
    fclose(WriteFile);
}

void HistWrite2(int hist[176], const char * FileName )
{
	FILE * WriteFile;
	if (!(WriteFile = fopen(FileName, "wb")))
	{
		cout<<"Output Image Error!\n"<<endl;
		system("pause");
		exit(1);
	}
    
    for(int i=0;i!=256;i++)
    {
        fprintf(WriteFile,"%d\t",hist[i]);
    }
    
    
    fclose(WriteFile);
}


int Conditional(double InputImage[ImageHeight][ImageWidth],
                double map[ImageHeight][ImageWidth])
{
    double st_cond[3][3][58]={0};
    
    st_cond[0][0][0]=0;st_cond[0][1][0]=0;st_cond[0][2][0]=0;
    st_cond[1][0][0]=1;st_cond[1][1][0]=1;st_cond[1][2][0]=0;
    st_cond[2][0][0]=1;st_cond[2][1][0]=0;st_cond[2][2][0]=0;
    
    st_cond[0][0][1]=0;st_cond[0][1][1]=0;st_cond[0][2][1]=0;
    st_cond[1][0][1]=0;st_cond[1][1][1]=1;st_cond[1][2][1]=0;
    st_cond[2][0][1]=1;st_cond[2][1][1]=1;st_cond[2][2][1]=0;
    
    st_cond[0][0][2]=0;st_cond[0][1][2]=0;st_cond[0][2][2]=0;
    st_cond[1][0][2]=0;st_cond[1][1][2]=1;st_cond[1][2][2]=0;
    st_cond[2][0][2]=0;st_cond[2][1][2]=1;st_cond[2][2][2]=1;
    
    st_cond[0][0][3]=0;st_cond[0][1][3]=0;st_cond[0][2][3]=0;
    st_cond[1][0][3]=0;st_cond[1][1][3]=1;st_cond[1][2][3]=1;
    st_cond[2][0][3]=0;st_cond[2][1][3]=0;st_cond[2][2][3]=1;
    
    //STK4
    st_cond[0][0][4]=0;st_cond[0][1][4]=0;st_cond[0][2][4]=1;
    st_cond[1][0][4]=0;st_cond[1][1][4]=1;st_cond[1][2][4]=1;
    st_cond[2][0][4]=0;st_cond[2][1][4]=0;st_cond[2][2][4]=1;
    
    st_cond[0][0][5]=1;st_cond[0][1][5]=1;st_cond[0][2][5]=1;
    st_cond[1][0][5]=0;st_cond[1][1][5]=1;st_cond[1][2][5]=0;
    st_cond[2][0][5]=0;st_cond[2][1][5]=0;st_cond[2][2][5]=0;
    
    st_cond[0][0][6]=1;st_cond[0][1][6]=0;st_cond[0][2][6]=0;
    st_cond[1][0][6]=1;st_cond[1][1][6]=1;st_cond[1][2][6]=0;
    st_cond[2][0][6]=1;st_cond[2][1][6]=0;st_cond[2][2][6]=0;
    
    st_cond[0][0][7]=0;st_cond[0][1][7]=0;st_cond[0][2][7]=0;
    st_cond[1][0][7]=0;st_cond[1][1][7]=1;st_cond[1][2][7]=0;
    st_cond[2][0][7]=1;st_cond[2][1][7]=1;st_cond[2][2][7]=1;
    
    //ST5
    st_cond[0][0][8]=1;st_cond[0][1][8]=1;st_cond[0][2][8]=0;
    st_cond[1][0][8]=0;st_cond[1][1][8]=1;st_cond[1][2][8]=1;
    st_cond[2][0][8]=0;st_cond[2][1][8]=0;st_cond[2][2][8]=0;
    
    st_cond[0][0][9]=0;st_cond[0][1][9]=1;st_cond[0][2][9]=0;
    st_cond[1][0][9]=0;st_cond[1][1][9]=1;st_cond[1][2][9]=1;
    st_cond[2][0][9]=0;st_cond[2][1][9]=0;st_cond[2][2][9]=1;
    
    st_cond[0][0][10]=0;st_cond[0][1][10]=1;st_cond[0][2][10]=1;
    st_cond[1][0][10]=1;st_cond[1][1][10]=1;st_cond[1][2][10]=0;
    st_cond[2][0][10]=0;st_cond[2][1][10]=0;st_cond[2][2][10]=0;
    
    st_cond[0][0][11]=0;st_cond[0][1][11]=0;st_cond[0][2][11]=1;
    st_cond[1][0][11]=0;st_cond[1][1][11]=1;st_cond[1][2][11]=1;
    st_cond[2][0][11]=0;st_cond[2][1][11]=1;st_cond[2][2][11]=0;
    
    //ST5
    st_cond[0][0][12]=0;st_cond[0][1][12]=1;st_cond[0][2][12]=1;
    st_cond[1][0][12]=0;st_cond[1][1][12]=1;st_cond[1][2][12]=1;
    st_cond[2][0][12]=0;st_cond[2][1][12]=0;st_cond[2][2][12]=0;
    
    st_cond[0][0][13]=1;st_cond[0][1][13]=1;st_cond[0][2][13]=0;
    st_cond[1][0][13]=1;st_cond[1][1][13]=1;st_cond[1][2][13]=0;
    st_cond[2][0][13]=0;st_cond[2][1][13]=0;st_cond[2][2][13]=0;
    
    st_cond[0][0][14]=0;st_cond[0][1][14]=0;st_cond[0][2][14]=0;
    st_cond[1][0][14]=1;st_cond[1][1][14]=1;st_cond[1][2][14]=0;
    st_cond[2][0][14]=1;st_cond[2][1][14]=1;st_cond[2][2][14]=0;
    
    st_cond[0][0][15]=0;st_cond[0][1][15]=0;st_cond[0][2][15]=0;
    st_cond[1][0][15]=0;st_cond[1][1][15]=1;st_cond[1][2][15]=1;
    st_cond[2][0][15]=0;st_cond[2][1][15]=1;st_cond[2][2][15]=1;
    
    //ST6
    st_cond[0][0][16]=1;st_cond[0][1][16]=1;st_cond[0][2][16]=0;
    st_cond[1][0][16]=0;st_cond[1][1][16]=1;st_cond[1][2][16]=1;
    st_cond[2][0][16]=0;st_cond[2][1][16]=0;st_cond[2][2][16]=1;
    
    st_cond[0][0][17]=0;st_cond[0][1][17]=1;st_cond[0][2][17]=1;
    st_cond[1][0][17]=1;st_cond[1][1][17]=1;st_cond[1][2][17]=0;
    st_cond[2][0][17]=1;st_cond[2][1][17]=0;st_cond[2][2][17]=0;
    
    //STK6
    st_cond[0][0][18]=1;st_cond[0][1][18]=1;st_cond[0][2][18]=1;
    st_cond[1][0][18]=0;st_cond[1][1][18]=1;st_cond[1][2][18]=1;
    st_cond[2][0][18]=0;st_cond[2][1][18]=0;st_cond[2][2][18]=0;
    
    st_cond[0][0][19]=0;st_cond[0][1][19]=1;st_cond[0][2][19]=1;
    st_cond[1][0][19]=0;st_cond[1][1][19]=1;st_cond[1][2][19]=1;
    st_cond[2][0][19]=0;st_cond[2][1][19]=0;st_cond[2][2][19]=1;
    
    st_cond[0][0][20]=1;st_cond[0][1][20]=1;st_cond[0][2][20]=1;
    st_cond[1][0][20]=1;st_cond[1][1][20]=1;st_cond[1][2][20]=0;
    st_cond[2][0][20]=0;st_cond[2][1][20]=0;st_cond[2][2][20]=0;
    
    st_cond[0][0][21]=1;st_cond[0][1][21]=1;st_cond[0][2][21]=0;
    st_cond[1][0][21]=1;st_cond[1][1][21]=1;st_cond[1][2][21]=0;
    st_cond[2][0][21]=1;st_cond[2][1][21]=0;st_cond[2][2][21]=0;
    
    st_cond[0][0][22]=1;st_cond[0][1][22]=0;st_cond[0][2][22]=0;
    st_cond[1][0][22]=1;st_cond[1][1][22]=1;st_cond[1][2][22]=0;
    st_cond[2][0][22]=1;st_cond[2][1][22]=1;st_cond[2][2][22]=0;
    
    st_cond[0][0][23]=0;st_cond[0][1][23]=0;st_cond[0][2][23]=0;
    st_cond[1][0][23]=1;st_cond[1][1][23]=1;st_cond[1][2][23]=0;
    st_cond[2][0][23]=1;st_cond[2][1][23]=1;st_cond[2][2][23]=1;
    
    st_cond[0][0][24]=0;st_cond[0][1][24]=0;st_cond[0][2][24]=0;
    st_cond[1][0][24]=0;st_cond[1][1][24]=1;st_cond[1][2][24]=1;
    st_cond[2][0][24]=1;st_cond[2][1][24]=1;st_cond[2][2][24]=1;
    
    st_cond[0][0][25]=0;st_cond[0][1][25]=0;st_cond[0][2][25]=1;
    st_cond[1][0][25]=0;st_cond[1][1][25]=1;st_cond[1][2][25]=1;
    st_cond[2][0][25]=0;st_cond[2][1][25]=1;st_cond[2][2][25]=1;
    
    //STK7
    st_cond[0][0][26]=1;st_cond[0][1][26]=1;st_cond[0][2][26]=1;
    st_cond[1][0][26]=0;st_cond[1][1][26]=1;st_cond[1][2][26]=1;
    st_cond[2][0][26]=0;st_cond[2][1][26]=0;st_cond[2][2][26]=1;
    
    st_cond[0][0][27]=1;st_cond[0][1][27]=1;st_cond[0][2][27]=1;
    st_cond[1][0][27]=1;st_cond[1][1][27]=1;st_cond[1][2][27]=0;
    st_cond[2][0][27]=1;st_cond[2][1][27]=0;st_cond[2][2][27]=0;
    
    st_cond[0][0][28]=1;st_cond[0][1][28]=0;st_cond[0][2][28]=0;
    st_cond[1][0][28]=1;st_cond[1][1][28]=1;st_cond[1][2][28]=0;
    st_cond[2][0][28]=1;st_cond[2][1][28]=1;st_cond[2][2][28]=1;
    
    st_cond[0][0][29]=0;st_cond[0][1][29]=0;st_cond[0][2][29]=1;
    st_cond[1][0][29]=0;st_cond[1][1][29]=1;st_cond[1][2][29]=1;
    st_cond[2][0][29]=1;st_cond[2][1][29]=1;st_cond[2][2][29]=1;
    
    //STK8
    st_cond[0][0][30]=0;st_cond[0][1][30]=1;st_cond[0][2][30]=1;
    st_cond[1][0][30]=0;st_cond[1][1][30]=1;st_cond[1][2][30]=1;
    st_cond[2][0][30]=0;st_cond[2][1][30]=1;st_cond[2][2][30]=1;
    
    st_cond[0][0][31]=1;st_cond[0][1][31]=1;st_cond[0][2][31]=1;
    st_cond[1][0][31]=1;st_cond[1][1][31]=1;st_cond[1][2][31]=1;
    st_cond[2][0][31]=0;st_cond[2][1][31]=0;st_cond[2][2][31]=0;
    
    st_cond[0][0][32]=1;st_cond[0][1][32]=1;st_cond[0][2][32]=0;
    st_cond[1][0][32]=1;st_cond[1][1][32]=1;st_cond[1][2][32]=0;
    st_cond[2][0][32]=1;st_cond[2][1][32]=1;st_cond[2][2][32]=0;
    
    st_cond[0][0][33]=0;st_cond[0][1][33]=0;st_cond[0][2][33]=0;
    st_cond[1][0][33]=1;st_cond[1][1][33]=1;st_cond[1][2][33]=1;
    st_cond[2][0][33]=1;st_cond[2][1][33]=1;st_cond[2][2][33]=1;
    
    //STK9
    st_cond[0][0][34]=1;st_cond[0][1][34]=1;st_cond[0][2][34]=1;
    st_cond[1][0][34]=0;st_cond[1][1][34]=1;st_cond[1][2][34]=1;
    st_cond[2][0][34]=0;st_cond[2][1][34]=1;st_cond[2][2][34]=1;
    
    st_cond[0][0][35]=0;st_cond[0][1][35]=1;st_cond[0][2][35]=1;
    st_cond[1][0][35]=0;st_cond[1][1][35]=1;st_cond[1][2][35]=1;
    st_cond[2][0][35]=1;st_cond[2][1][35]=1;st_cond[2][2][35]=1;
    
    st_cond[0][0][36]=1;st_cond[0][1][36]=1;st_cond[0][2][36]=1;
    st_cond[1][0][36]=1;st_cond[1][1][36]=1;st_cond[1][2][36]=1;
    st_cond[2][0][36]=1;st_cond[2][1][36]=0;st_cond[2][2][36]=0;
    
    st_cond[0][0][37]=1;st_cond[0][1][37]=1;st_cond[0][2][37]=1;
    st_cond[1][0][37]=1;st_cond[1][1][37]=1;st_cond[1][2][37]=1;
    st_cond[2][0][37]=0;st_cond[2][1][37]=0;st_cond[2][2][37]=1;
    
    st_cond[0][0][38]=1;st_cond[0][1][38]=1;st_cond[0][2][38]=1;
    st_cond[1][0][38]=1;st_cond[1][1][38]=1;st_cond[1][2][38]=0;
    st_cond[2][0][38]=1;st_cond[2][1][38]=1;st_cond[2][2][38]=0;
    
    st_cond[0][0][39]=1;st_cond[0][1][39]=1;st_cond[0][2][39]=0;
    st_cond[1][0][39]=1;st_cond[1][1][39]=1;st_cond[1][2][39]=0;
    st_cond[2][0][39]=1;st_cond[2][1][39]=1;st_cond[2][2][39]=1;
    
    st_cond[0][0][40]=1;st_cond[0][1][40]=0;st_cond[0][2][40]=0;
    st_cond[1][0][40]=1;st_cond[1][1][40]=1;st_cond[1][2][40]=1;
    st_cond[2][0][40]=1;st_cond[2][1][40]=1;st_cond[2][2][40]=1;
    
    st_cond[0][0][41]=0;st_cond[0][1][41]=0;st_cond[0][2][41]=1;
    st_cond[1][0][41]=1;st_cond[1][1][41]=1;st_cond[1][2][41]=1;
    st_cond[2][0][41]=1;st_cond[2][1][41]=1;st_cond[2][2][41]=1;
    
    //STK10
    st_cond[0][0][42]=1;st_cond[0][1][42]=1;st_cond[0][2][42]=1;
    st_cond[1][0][42]=0;st_cond[1][1][42]=1;st_cond[1][2][42]=1;
    st_cond[2][0][42]=1;st_cond[2][1][42]=1;st_cond[2][2][42]=1;
    
    st_cond[0][0][43]=1;st_cond[0][1][43]=1;st_cond[0][2][43]=1;
    st_cond[1][0][43]=1;st_cond[1][1][43]=1;st_cond[1][2][43]=1;
    st_cond[2][0][43]=1;st_cond[2][1][43]=0;st_cond[2][2][43]=1;
    
    st_cond[0][0][44]=1;st_cond[0][1][44]=1;st_cond[0][2][44]=1;
    st_cond[1][0][44]=1;st_cond[1][1][44]=1;st_cond[1][2][44]=0;
    st_cond[2][0][44]=1;st_cond[2][1][44]=1;st_cond[2][2][44]=1;
    
    st_cond[0][0][45]=1;st_cond[0][1][45]=0;st_cond[0][2][45]=1;
    st_cond[1][0][45]=1;st_cond[1][1][45]=1;st_cond[1][2][45]=1;
    st_cond[2][0][45]=1;st_cond[2][1][45]=1;st_cond[2][2][45]=1;
    
   //S1
    st_cond[0][0][46]=0;st_cond[0][1][46]=0;st_cond[0][2][46]=1;
    st_cond[1][0][46]=0;st_cond[1][1][46]=1;st_cond[1][2][46]=0;
    st_cond[2][0][46]=0;st_cond[2][1][46]=0;st_cond[2][2][46]=0;
    
    st_cond[0][0][47]=1;st_cond[0][1][47]=0;st_cond[0][2][47]=0;
    st_cond[1][0][47]=0;st_cond[1][1][47]=1;st_cond[1][2][47]=0;
    st_cond[2][0][47]=0;st_cond[2][1][47]=0;st_cond[2][2][47]=0;

    st_cond[0][0][48]=0;st_cond[0][1][48]=0;st_cond[0][2][48]=0;
    st_cond[1][0][48]=0;st_cond[1][1][48]=1;st_cond[1][2][48]=0;
    st_cond[2][0][48]=1;st_cond[2][1][48]=0;st_cond[2][2][48]=0;
    
    st_cond[0][0][49]=0;st_cond[0][1][49]=0;st_cond[0][2][49]=0;
    st_cond[1][0][49]=0;st_cond[1][1][49]=1;st_cond[1][2][49]=0;
    st_cond[2][0][49]=0;st_cond[2][1][49]=0;st_cond[2][2][49]=1;

    //S2
    st_cond[0][0][50]=0;st_cond[0][1][50]=0;st_cond[0][2][50]=0;
    st_cond[1][0][50]=0;st_cond[1][1][50]=1;st_cond[1][2][50]=1;
    st_cond[2][0][50]=0;st_cond[2][1][50]=0;st_cond[2][2][50]=0;

    st_cond[0][0][51]=0;st_cond[0][1][51]=1;st_cond[0][2][51]=0;
    st_cond[1][0][51]=0;st_cond[1][1][51]=1;st_cond[1][2][51]=0;
    st_cond[2][0][51]=0;st_cond[2][1][51]=0;st_cond[2][2][51]=0;
    
    st_cond[0][0][52]=0;st_cond[0][1][52]=0;st_cond[0][2][52]=0;
    st_cond[1][0][52]=1;st_cond[1][1][52]=1;st_cond[1][2][52]=0;
    st_cond[2][0][52]=0;st_cond[2][1][52]=0;st_cond[2][2][52]=0;
    
    st_cond[0][0][53]=0;st_cond[0][1][53]=0;st_cond[0][2][53]=0;
    st_cond[1][0][53]=0;st_cond[1][1][53]=1;st_cond[1][2][53]=0;
    st_cond[2][0][53]=0;st_cond[2][1][53]=1;st_cond[2][2][53]=0;
    
    //S3
    st_cond[0][0][54]=0;st_cond[0][1][54]=0;st_cond[0][2][54]=1;
    st_cond[1][0][54]=0;st_cond[1][1][54]=1;st_cond[1][2][54]=1;
    st_cond[2][0][54]=0;st_cond[2][1][54]=0;st_cond[2][2][54]=0;
    
    st_cond[0][0][55]=0;st_cond[0][1][55]=1;st_cond[0][2][55]=1;
    st_cond[1][0][55]=0;st_cond[1][1][55]=1;st_cond[1][2][55]=0;
    st_cond[2][0][55]=0;st_cond[2][1][55]=0;st_cond[2][2][55]=0;

    st_cond[0][0][56]=1;st_cond[0][1][56]=1;st_cond[0][2][56]=0;
    st_cond[1][0][56]=0;st_cond[1][1][56]=1;st_cond[1][2][56]=0;
    st_cond[2][0][56]=0;st_cond[2][1][56]=0;st_cond[2][2][56]=0;
    
    st_cond[0][0][57]=1;st_cond[0][1][57]=0;st_cond[0][2][57]=0;
    st_cond[1][0][57]=1;st_cond[1][1][57]=1;st_cond[1][2][57]=0;
    st_cond[2][0][57]=0;st_cond[2][1][57]=0;st_cond[2][2][57]=0;
    
    
    


    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            int flag=0;
            for(int t=0;t<58;t++)
            {
                
                if(InputImage[i-1][j-1]==st_cond[0][0][t]&&InputImage[i-1][j]==st_cond[0][1][t]&&
                   InputImage[i-1][j+1]==st_cond[0][2][t]&&InputImage[i][j-1]==st_cond[1][0][t]&&
                   InputImage[i][j]==st_cond[1][1][t]&&InputImage[i][j+1]==st_cond[1][2][t]&&
                   InputImage[i+1][j-1]==st_cond[2][0][t]&&InputImage[i+1][j]==st_cond[2][1][t]&&
                   InputImage[i+1][j+1]==st_cond[2][2][t])
                {
                    map[i][j]=1;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                map[i][j]=0;
        }
    }
    
    
    
    
    double st_uncond[3][3][69]={0};
    //Spur
    st_uncond[0][0][0]=0;st_uncond[0][1][0]=0;st_uncond[0][2][0]=1;
    st_uncond[1][0][0]=0;st_uncond[1][1][0]=1;st_uncond[1][2][0]=0;
    st_uncond[2][0][0]=0;st_uncond[2][1][0]=0;st_uncond[2][2][0]=0;
    
    st_uncond[0][0][1]=1;st_uncond[0][1][1]=0;st_uncond[0][2][1]=0;
    st_uncond[1][0][1]=0;st_uncond[1][1][1]=1;st_uncond[1][2][1]=0;
    st_uncond[2][0][1]=0;st_uncond[2][1][1]=0;st_uncond[2][2][1]=0;
    //Single 4-connection
    st_uncond[0][0][2]=0;st_uncond[0][1][2]=0;st_uncond[0][2][2]=0;
    st_uncond[1][0][2]=0;st_uncond[1][1][2]=1;st_uncond[1][2][2]=0;
    st_uncond[2][0][2]=0;st_uncond[2][1][2]=1;st_uncond[2][2][2]=0;
    
    st_uncond[0][0][3]=0;st_uncond[0][1][3]=0;st_uncond[0][2][3]=0;
    st_uncond[1][0][3]=0;st_uncond[1][1][3]=1;st_uncond[1][2][3]=1;
    st_uncond[2][0][3]=0;st_uncond[2][1][3]=0;st_uncond[2][2][3]=0;
    //L Cluster
    st_uncond[0][0][4]=0;st_uncond[0][1][4]=0;st_uncond[0][2][4]=1;
    st_uncond[1][0][4]=0;st_uncond[1][1][4]=1;st_uncond[1][2][4]=1;
    st_uncond[2][0][4]=0;st_uncond[2][1][4]=0;st_uncond[2][2][4]=0;
    
    st_uncond[0][0][5]=0;st_uncond[0][1][5]=1;st_uncond[0][2][5]=1;
    st_uncond[1][0][5]=0;st_uncond[1][1][5]=1;st_uncond[1][2][5]=0;
    st_uncond[2][0][5]=0;st_uncond[2][1][5]=0;st_uncond[2][2][5]=0;
    
    st_uncond[0][0][6]=1;st_uncond[0][1][6]=1;st_uncond[0][2][6]=0;
    st_uncond[1][0][6]=0;st_uncond[1][1][6]=1;st_uncond[1][2][6]=0;
    st_uncond[2][0][6]=0;st_uncond[2][1][6]=0;st_uncond[2][2][6]=0;
    
    st_uncond[0][0][7]=1;st_uncond[0][1][7]=0;st_uncond[0][2][7]=0;
    st_uncond[1][0][7]=1;st_uncond[1][1][7]=1;st_uncond[1][2][7]=0;
    st_uncond[2][0][7]=0;st_uncond[2][1][7]=0;st_uncond[2][2][7]=0;
    
    st_uncond[0][0][8]=0;st_uncond[0][1][8]=0;st_uncond[0][2][8]=0;
    st_uncond[1][0][8]=1;st_uncond[1][1][8]=1;st_uncond[1][2][8]=0;
    st_uncond[2][0][8]=1;st_uncond[2][1][8]=0;st_uncond[2][2][8]=0;
    
    st_uncond[0][0][9]=0;st_uncond[0][1][9]=0;st_uncond[0][2][9]=0;
    st_uncond[1][0][9]=0;st_uncond[1][1][9]=1;st_uncond[1][2][9]=0;
    st_uncond[2][0][9]=1;st_uncond[2][1][9]=1;st_uncond[2][2][9]=0;
    
    st_uncond[0][0][10]=0;st_uncond[0][1][10]=0;st_uncond[0][2][10]=0;
    st_uncond[1][0][10]=0;st_uncond[1][1][10]=1;st_uncond[1][2][10]=0;
    st_uncond[2][0][10]=0;st_uncond[2][1][10]=1;st_uncond[2][2][10]=1;
    
    st_uncond[0][0][11]=0;st_uncond[0][1][11]=0;st_uncond[0][2][11]=0;
    st_uncond[1][0][11]=0;st_uncond[1][1][11]=1;st_uncond[1][2][11]=1;
    st_uncond[2][0][11]=0;st_uncond[2][1][11]=0;st_uncond[2][2][11]=1;
    //4-Connected offset
    st_uncond[0][0][12]=0;st_uncond[0][1][12]=1;st_uncond[0][2][12]=1;
    st_uncond[1][0][12]=1;st_uncond[1][1][12]=1;st_uncond[1][2][12]=0;
    st_uncond[2][0][12]=0;st_uncond[2][1][12]=0;st_uncond[2][2][12]=0;
    
    st_uncond[0][0][13]=1;st_uncond[0][1][13]=1;st_uncond[0][2][13]=0;
    st_uncond[1][0][13]=0;st_uncond[1][1][13]=1;st_uncond[1][2][13]=1;
    st_uncond[2][0][13]=0;st_uncond[2][1][13]=0;st_uncond[2][2][13]=0;
    
    st_uncond[0][0][14]=0;st_uncond[0][1][14]=1;st_uncond[0][2][14]=0;
    st_uncond[1][0][14]=0;st_uncond[1][1][14]=1;st_uncond[1][2][14]=1;
    st_uncond[2][0][14]=0;st_uncond[2][1][14]=0;st_uncond[2][2][14]=1;
    
    st_uncond[0][0][15]=0;st_uncond[0][1][15]=0;st_uncond[0][2][15]=1;
    st_uncond[1][0][15]=0;st_uncond[1][1][15]=1;st_uncond[1][2][15]=1;
    st_uncond[2][0][15]=0;st_uncond[2][1][15]=1;st_uncond[2][2][15]=0;
    //Spur corner cluster
    st_uncond[0][0][16]=0;st_uncond[0][1][16]=1;st_uncond[0][2][16]=1;
    st_uncond[1][0][16]=0;st_uncond[1][1][16]=1;st_uncond[1][2][16]=0;
    st_uncond[2][0][16]=1;st_uncond[2][1][16]=0;st_uncond[2][2][16]=0;
    
    st_uncond[0][0][17]=0;st_uncond[0][1][17]=0;st_uncond[0][2][17]=1;
    st_uncond[1][0][17]=0;st_uncond[1][1][17]=1;st_uncond[1][2][17]=1;
    st_uncond[2][0][17]=1;st_uncond[2][1][17]=0;st_uncond[2][2][17]=0;
    
    st_uncond[0][0][18]=0;st_uncond[0][1][18]=1;st_uncond[0][2][18]=1;
    st_uncond[1][0][18]=0;st_uncond[1][1][18]=1;st_uncond[1][2][18]=1;
    st_uncond[2][0][18]=1;st_uncond[2][1][18]=0;st_uncond[2][2][18]=0;
    
    st_uncond[0][0][19]=1;st_uncond[0][1][19]=0;st_uncond[0][2][19]=0;
    st_uncond[1][0][19]=1;st_uncond[1][1][19]=1;st_uncond[1][2][19]=0;
    st_uncond[2][0][19]=0;st_uncond[2][1][19]=0;st_uncond[2][2][19]=1;
    
    st_uncond[0][0][20]=1;st_uncond[0][1][20]=1;st_uncond[0][2][20]=0;
    st_uncond[1][0][20]=0;st_uncond[1][1][20]=1;st_uncond[1][2][20]=0;
    st_uncond[2][0][20]=0;st_uncond[2][1][20]=0;st_uncond[2][2][20]=1;
    
    st_uncond[0][0][21]=1;st_uncond[0][1][21]=1;st_uncond[0][2][21]=0;
    st_uncond[1][0][21]=1;st_uncond[1][1][21]=1;st_uncond[1][2][21]=0;
    st_uncond[2][0][21]=0;st_uncond[2][1][21]=0;st_uncond[2][2][21]=1;
    
    st_uncond[0][0][22]=0;st_uncond[0][1][22]=0;st_uncond[0][2][22]=1;
    st_uncond[1][0][22]=1;st_uncond[1][1][22]=1;st_uncond[1][2][22]=0;
    st_uncond[2][0][22]=1;st_uncond[2][1][22]=0;st_uncond[2][2][22]=0;
    
    st_uncond[0][0][23]=0;st_uncond[0][1][23]=0;st_uncond[0][2][23]=1;
    st_uncond[1][0][23]=0;st_uncond[1][1][23]=1;st_uncond[1][2][23]=0;
    st_uncond[2][0][23]=1;st_uncond[2][1][23]=1;st_uncond[2][2][23]=0;
    
    st_uncond[0][0][24]=0;st_uncond[0][1][24]=0;st_uncond[0][2][24]=1;
    st_uncond[1][0][24]=1;st_uncond[1][1][24]=1;st_uncond[1][2][24]=0;
    st_uncond[2][0][24]=1;st_uncond[2][1][24]=1;st_uncond[2][2][24]=0;
    
    st_uncond[0][0][25]=1;st_uncond[0][1][25]=0;st_uncond[0][2][25]=0;
    st_uncond[1][0][25]=0;st_uncond[1][1][25]=1;st_uncond[1][2][25]=0;
    st_uncond[2][0][25]=0;st_uncond[2][1][25]=1;st_uncond[2][2][25]=1;
    
    st_uncond[0][0][26]=1;st_uncond[0][1][26]=0;st_uncond[0][2][26]=0;
    st_uncond[1][0][26]=0;st_uncond[1][1][26]=1;st_uncond[1][2][26]=1;
    st_uncond[2][0][26]=0;st_uncond[2][1][26]=0;st_uncond[2][2][26]=1;
    
    st_uncond[0][0][27]=1;st_uncond[0][1][27]=0;st_uncond[0][2][27]=0;
    st_uncond[1][0][27]=0;st_uncond[1][1][27]=1;st_uncond[1][2][27]=1;
    st_uncond[2][0][27]=0;st_uncond[2][1][27]=1;st_uncond[2][2][27]=1;
    //Corner cluster
    st_uncond[0][0][28]=1;st_uncond[0][1][28]=1;st_uncond[0][2][28]=2;
    st_uncond[1][0][28]=1;st_uncond[1][1][28]=1;st_uncond[1][2][28]=2;
    st_uncond[2][0][28]=2;st_uncond[2][1][28]=2;st_uncond[2][2][28]=2;
    //Tee branch
    st_uncond[0][0][29]=2;st_uncond[0][1][29]=1;st_uncond[0][2][29]=0;
    st_uncond[1][0][29]=1;st_uncond[1][1][29]=1;st_uncond[1][2][29]=1;
    st_uncond[2][0][29]=2;st_uncond[2][1][29]=0;st_uncond[2][2][29]=0;
    
    st_uncond[0][0][30]=0;st_uncond[0][1][30]=1;st_uncond[0][2][30]=2;
    st_uncond[1][0][30]=1;st_uncond[1][1][30]=1;st_uncond[1][2][30]=1;
    st_uncond[2][0][30]=0;st_uncond[2][1][30]=0;st_uncond[2][2][30]=2;
    
    st_uncond[0][0][31]=0;st_uncond[0][1][31]=0;st_uncond[0][2][31]=2;
    st_uncond[1][0][31]=1;st_uncond[1][1][31]=1;st_uncond[1][2][31]=1;
    st_uncond[2][0][31]=0;st_uncond[2][1][31]=1;st_uncond[2][2][31]=2;
    
    st_uncond[0][0][32]=2;st_uncond[0][1][32]=0;st_uncond[0][2][32]=0;
    st_uncond[1][0][32]=1;st_uncond[1][1][32]=1;st_uncond[1][2][32]=1;
    st_uncond[2][0][32]=2;st_uncond[2][1][32]=1;st_uncond[2][2][32]=0;
    
    st_uncond[0][0][33]=2;st_uncond[0][1][33]=1;st_uncond[0][2][33]=2;
    st_uncond[1][0][33]=1;st_uncond[1][1][33]=1;st_uncond[1][2][33]=0;
    st_uncond[2][0][33]=0;st_uncond[2][1][33]=1;st_uncond[2][2][33]=0;
    
    st_uncond[0][0][34]=0;st_uncond[0][1][34]=1;st_uncond[0][2][34]=0;
    st_uncond[1][0][34]=1;st_uncond[1][1][34]=1;st_uncond[1][2][34]=0;
    st_uncond[2][0][34]=2;st_uncond[2][1][34]=1;st_uncond[2][2][34]=2;
    
    st_uncond[0][0][35]=0;st_uncond[0][1][35]=1;st_uncond[0][2][35]=0;
    st_uncond[1][0][35]=0;st_uncond[1][1][35]=1;st_uncond[1][2][35]=1;
    st_uncond[2][0][35]=2;st_uncond[2][1][35]=1;st_uncond[2][2][35]=2;
    
    st_uncond[0][0][36]=2;st_uncond[0][1][36]=1;st_uncond[0][2][36]=2;
    st_uncond[1][0][36]=0;st_uncond[1][1][36]=1;st_uncond[1][2][36]=1;
    st_uncond[2][0][36]=0;st_uncond[2][1][36]=1;st_uncond[2][2][36]=0;
    //Vee branch
    st_uncond[0][0][37]=1;st_uncond[0][1][37]=2;st_uncond[0][2][37]=1;
    st_uncond[1][0][37]=2;st_uncond[1][1][37]=1;st_uncond[1][2][37]=2;
    st_uncond[2][0][37]=1;st_uncond[2][1][37]=1;st_uncond[2][2][37]=1;
    
    st_uncond[0][0][38]=1;st_uncond[0][1][38]=2;st_uncond[0][2][38]=1;
    st_uncond[1][0][38]=2;st_uncond[1][1][38]=1;st_uncond[1][2][38]=2;
    st_uncond[2][0][38]=1;st_uncond[2][1][38]=1;st_uncond[2][2][38]=0;
    
    st_uncond[0][0][39]=1;st_uncond[0][1][39]=2;st_uncond[0][2][39]=1;
    st_uncond[1][0][39]=2;st_uncond[1][1][39]=1;st_uncond[1][2][39]=2;
    st_uncond[2][0][39]=1;st_uncond[2][1][39]=0;st_uncond[2][2][39]=1;
    
    st_uncond[0][0][40]=1;st_uncond[0][1][40]=2;st_uncond[0][2][40]=1;
    st_uncond[1][0][40]=2;st_uncond[1][1][40]=1;st_uncond[1][2][40]=2;
    st_uncond[2][0][40]=1;st_uncond[2][1][40]=0;st_uncond[2][2][40]=0;
    
    st_uncond[0][0][41]=1;st_uncond[0][1][41]=2;st_uncond[0][2][41]=1;
    st_uncond[1][0][41]=2;st_uncond[1][1][41]=1;st_uncond[1][2][41]=2;
    st_uncond[2][0][41]=0;st_uncond[2][1][41]=1;st_uncond[2][2][41]=1;
    
    st_uncond[0][0][42]=1;st_uncond[0][1][42]=2;st_uncond[0][2][42]=1;
    st_uncond[1][0][42]=2;st_uncond[1][1][42]=1;st_uncond[1][2][42]=2;
    st_uncond[2][0][42]=0;st_uncond[2][1][42]=1;st_uncond[2][2][42]=0;
    
    st_uncond[0][0][43]=1;st_uncond[0][1][43]=2;st_uncond[0][2][43]=1;
    st_uncond[1][0][43]=2;st_uncond[1][1][43]=1;st_uncond[1][2][43]=2;
    st_uncond[2][0][43]=0;st_uncond[2][1][43]=0;st_uncond[2][2][43]=1;
    
    st_uncond[0][0][44]=1;st_uncond[0][1][44]=2;st_uncond[0][2][44]=1;
    st_uncond[1][0][44]=2;st_uncond[1][1][44]=1;st_uncond[1][2][44]=1;
    st_uncond[2][0][44]=1;st_uncond[2][1][44]=2;st_uncond[2][2][44]=1;
    
    st_uncond[0][0][45]=1;st_uncond[0][1][45]=2;st_uncond[0][2][45]=0;
    st_uncond[1][0][45]=2;st_uncond[1][1][45]=1;st_uncond[1][2][45]=1;
    st_uncond[2][0][45]=1;st_uncond[2][1][45]=2;st_uncond[2][2][45]=1;
    
    st_uncond[0][0][46]=1;st_uncond[0][1][46]=2;st_uncond[0][2][46]=1;
    st_uncond[1][0][46]=2;st_uncond[1][1][46]=1;st_uncond[1][2][46]=0;
    st_uncond[2][0][46]=1;st_uncond[2][1][46]=2;st_uncond[2][2][46]=1;
    
    st_uncond[0][0][47]=1;st_uncond[0][1][47]=2;st_uncond[0][2][47]=0;
    st_uncond[1][0][47]=2;st_uncond[1][1][47]=1;st_uncond[1][2][47]=0;
    st_uncond[2][0][47]=1;st_uncond[2][1][47]=2;st_uncond[2][2][47]=1;
    
    st_uncond[0][0][48]=1;st_uncond[0][1][48]=2;st_uncond[0][2][48]=1;
    st_uncond[1][0][48]=2;st_uncond[1][1][48]=1;st_uncond[1][2][48]=1;
    st_uncond[2][0][48]=1;st_uncond[2][1][48]=2;st_uncond[2][2][48]=0;
    
    st_uncond[0][0][49]=1;st_uncond[0][1][49]=2;st_uncond[0][2][49]=0;
    st_uncond[1][0][49]=2;st_uncond[1][1][49]=1;st_uncond[1][2][49]=1;
    st_uncond[2][0][49]=1;st_uncond[2][1][49]=2;st_uncond[2][2][49]=0;
    
    st_uncond[0][0][50]=1;st_uncond[0][1][50]=2;st_uncond[0][2][50]=1;
    st_uncond[1][0][50]=2;st_uncond[1][1][50]=1;st_uncond[1][2][50]=0;
    st_uncond[2][0][50]=1;st_uncond[2][1][50]=2;st_uncond[2][2][50]=0;
    
    st_uncond[0][0][51]=1;st_uncond[0][1][51]=1;st_uncond[0][2][51]=1;
    st_uncond[1][0][51]=2;st_uncond[1][1][51]=1;st_uncond[1][2][51]=2;
    st_uncond[2][0][51]=1;st_uncond[2][1][51]=2;st_uncond[2][2][51]=1;
    
    st_uncond[0][0][52]=0;st_uncond[0][1][52]=1;st_uncond[0][2][52]=1;
    st_uncond[1][0][52]=2;st_uncond[1][1][52]=1;st_uncond[1][2][52]=2;
    st_uncond[2][0][52]=1;st_uncond[2][1][52]=2;st_uncond[2][2][52]=1;
    
    st_uncond[0][0][53]=1;st_uncond[0][1][53]=0;st_uncond[0][2][53]=1;
    st_uncond[1][0][53]=2;st_uncond[1][1][53]=1;st_uncond[1][2][53]=2;
    st_uncond[2][0][53]=1;st_uncond[2][1][53]=2;st_uncond[2][2][53]=1;
    
    st_uncond[0][0][54]=0;st_uncond[0][1][54]=0;st_uncond[0][2][54]=1;
    st_uncond[1][0][54]=2;st_uncond[1][1][54]=1;st_uncond[1][2][54]=2;
    st_uncond[2][0][54]=1;st_uncond[2][1][54]=2;st_uncond[2][2][54]=1;
    
    st_uncond[0][0][55]=1;st_uncond[0][1][55]=1;st_uncond[0][2][55]=0;
    st_uncond[1][0][55]=2;st_uncond[1][1][55]=1;st_uncond[1][2][55]=2;
    st_uncond[2][0][55]=1;st_uncond[2][1][55]=2;st_uncond[2][2][55]=1;
    
    st_uncond[0][0][56]=0;st_uncond[0][1][56]=1;st_uncond[0][2][56]=0;
    st_uncond[1][0][56]=2;st_uncond[1][1][56]=1;st_uncond[1][2][56]=2;
    st_uncond[2][0][56]=1;st_uncond[2][1][56]=2;st_uncond[2][2][56]=1;
    
    st_uncond[0][0][57]=1;st_uncond[0][1][57]=0;st_uncond[0][2][57]=0;
    st_uncond[1][0][57]=2;st_uncond[1][1][57]=1;st_uncond[1][2][57]=2;
    st_uncond[2][0][57]=1;st_uncond[2][1][57]=2;st_uncond[2][2][57]=1;
    
    st_uncond[0][0][58]=1;st_uncond[0][1][58]=2;st_uncond[0][2][58]=1;
    st_uncond[1][0][58]=1;st_uncond[1][1][58]=1;st_uncond[1][2][58]=2;
    st_uncond[2][0][58]=1;st_uncond[2][1][58]=2;st_uncond[2][2][58]=1;
    
    st_uncond[0][0][59]=1;st_uncond[0][1][59]=2;st_uncond[0][2][59]=1;
    st_uncond[1][0][59]=1;st_uncond[1][1][59]=1;st_uncond[1][2][59]=2;
    st_uncond[2][0][59]=0;st_uncond[2][1][59]=2;st_uncond[2][2][59]=1;
    
    st_uncond[0][0][60]=1;st_uncond[0][1][60]=2;st_uncond[0][2][60]=1;
    st_uncond[1][0][60]=0;st_uncond[1][1][60]=1;st_uncond[1][2][60]=2;
    st_uncond[2][0][60]=1;st_uncond[2][1][60]=2;st_uncond[2][2][60]=1;
    
    st_uncond[0][0][61]=1;st_uncond[0][1][61]=2;st_uncond[0][2][61]=1;
    st_uncond[1][0][61]=0;st_uncond[1][1][61]=1;st_uncond[1][2][61]=2;
    st_uncond[2][0][61]=0;st_uncond[2][1][61]=2;st_uncond[2][2][61]=1;
    
    st_uncond[0][0][62]=0;st_uncond[0][1][62]=2;st_uncond[0][2][62]=1;
    st_uncond[1][0][62]=1;st_uncond[1][1][62]=1;st_uncond[1][2][62]=2;
    st_uncond[2][0][62]=1;st_uncond[2][1][62]=2;st_uncond[2][2][62]=1;
    
    st_uncond[0][0][63]=0;st_uncond[0][1][63]=2;st_uncond[0][2][63]=1;
    st_uncond[1][0][63]=1;st_uncond[1][1][63]=1;st_uncond[1][2][63]=2;
    st_uncond[2][0][63]=0;st_uncond[2][1][63]=2;st_uncond[2][2][63]=1;
    
    st_uncond[0][0][64]=0;st_uncond[0][1][64]=2;st_uncond[0][2][64]=1;
    st_uncond[1][0][64]=0;st_uncond[1][1][64]=1;st_uncond[1][2][64]=2;
    st_uncond[2][0][64]=1;st_uncond[2][1][64]=2;st_uncond[2][2][64]=1;
    //Diagonal branch
    st_uncond[0][0][65]=2;st_uncond[0][1][65]=1;st_uncond[0][2][65]=0;
    st_uncond[1][0][65]=0;st_uncond[1][1][65]=1;st_uncond[1][2][65]=1;
    st_uncond[2][0][65]=1;st_uncond[2][1][65]=0;st_uncond[2][2][65]=2;
    
    st_uncond[0][0][66]=0;st_uncond[0][1][66]=1;st_uncond[0][2][66]=2;
    st_uncond[1][0][66]=1;st_uncond[1][1][66]=1;st_uncond[1][2][66]=0;
    st_uncond[2][0][66]=2;st_uncond[2][1][66]=0;st_uncond[2][2][66]=1;
    
    st_uncond[0][0][67]=2;st_uncond[0][1][67]=0;st_uncond[0][2][67]=1;
    st_uncond[1][0][67]=1;st_uncond[1][1][67]=1;st_uncond[1][2][67]=0;
    st_uncond[2][0][67]=0;st_uncond[2][1][67]=1;st_uncond[2][2][67]=2;
    
    st_uncond[0][0][68]=1;st_uncond[0][1][68]=0;st_uncond[0][2][68]=2;
    st_uncond[1][0][68]=0;st_uncond[1][1][68]=1;st_uncond[1][2][68]=1;
    st_uncond[2][0][68]=2;st_uncond[2][1][68]=1;st_uncond[2][2][68]=0;
    
    int t;
    
    int temp=0;
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            if(map[i][j]==1)
            {
                for(t=0;t<69;t++)
                {
                    int flag=0;
                    for(int m=-1;m<=1;m++)
                    {
                        for(int n=-1;n<=1;n++)
                        {
                            if(st_uncond[m+1][n+1][t]!=2)
                            {
                                if(map[i+m][j+n]!=st_uncond[m+1][n+1][t])
                                {
                                    flag=1;
                                }
                            }
                        }
                        
                    }
                    if(flag==0)
                        break;
                    if(t==68&&flag==1)
                    {
                        InputImage[i][j]=0;
                        temp=1;
                    }
                    
                }
                
            }
        }
    }
    
    
    
    
    
    return temp;
    
    
}

int singel(double InputImage[ImageHeight][ImageWidth])
{ int sum=0;
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            if(InputImage[i-1][j-1]==0&&InputImage[i-1][j]==0&&
               InputImage[i-1][j+1]==0&&InputImage[i][j-1]==0&&
               InputImage[i][j]==1&&InputImage[i][j+1]==0&&
               InputImage[i+1][j-1]==0&&InputImage[i+1][j]==0&&
               InputImage[i+1][j+1]==0)
            {
                sum++;
            }
          }
    }
    return sum;
}





int main()
{
    unsigned char OriImage1[ImageHeight][ImageWidth]={0};
    unsigned char OriImage2[ImageHeight][ImageWidth]={0};
    unsigned char shrink1[ImageHeight][ImageWidth]={0};
    unsigned char shrink2[ImageHeight][ImageWidth]={0};
    double InputImage1[ImageHeight][ImageWidth]={0};
    double InputImage2[ImageHeight][ImageWidth]={0};
    double InputImage3[ImageHeight][ImageWidth]={0};
    double InputImage4[ImageHeight][ImageWidth]={0};
    double map1[ImageHeight][ImageWidth]={0};
    double map2[ImageHeight][ImageWidth]={0};
    
    GImageRead(OriImage1,"/Users/Aria/Documents/USC/569/hw2/hw2_images/median1.raw");
    GImageRead(OriImage2,"/Users/Aria/Documents/USC/569/hw2/hw2_images/median2.raw");
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            InputImage1[i][j]=double(OriImage1[i][j])/255;
            InputImage2[i][j]=double(OriImage2[i][j])/255;
            InputImage3[i][j]=double(OriImage1[i][j])/255;
            InputImage4[i][j]=double(OriImage2[i][j])/255;
        }
    }
    
    int temp1,temp2;
    temp1=Conditional(InputImage1,map1);
    int s1=1;
    while(temp1==1)
    { temp1=Conditional(InputImage1,map1);
        s1++;
    }
    
    temp2=Conditional(InputImage2,map2);
    int s2=1;
    while(temp2==1)
    {
        temp2=Conditional(InputImage2,map2);
        s2++;

    }
    
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            shrink1[i][j]=InputImage1[i][j]*255;
            shrink2[i][j]=InputImage2[i][j]*255;
            
        }
    }
    
    GImageWrite(shrink1,"/Users/Aria/Documents/USC/569/hw2/hw2_images/shrink1.raw");
    GImageWrite(shrink2,"/Users/Aria/Documents/USC/569/hw2/hw2_images/shrink2.raw");
    
    int sum1=singel(InputImage1);
    int sum2=singel(InputImage2);
    cout<<"total number of ridges for good "<<sum1<<"\n";
    cout<<"total number of ridges for bad  "<<sum2<<"\n";
    
    
    
}



