#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define ImageHeight 374
#define ImageWidth 388
#define height 376
#define width 390
#define n 1
#define Dx 10
#define Dy 10
#define pi 3.14


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



void Extention_Image(unsigned char Image[ImageHeight][ImageWidth],
                     unsigned char AddImage[height][width])
{
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            
            AddImage[i+n][j+n]=Image[i][j];
            
            
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            
            AddImage[i][j+n]=Image[n-i][j];
            AddImage[ImageHeight+n+i][j+n]=Image[ImageHeight-i-1][j];
            
        }
    }
    
    
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            AddImage[i+n][j]=Image[i][n-j];
            AddImage[i+n][j+n+ImageWidth]=Image[i][ImageWidth-j-1];
            
            
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            AddImage[i][j]=AddImage[i][(2*n-j)];
            AddImage[i][j+n+ImageWidth]=AddImage[i][ImageWidth+n-j-1];
            AddImage[ImageHeight+n+i][j]=AddImage[ImageHeight+n+i][(2*n-j)];
            AddImage[ImageHeight+n+i][j+n+ImageWidth]=AddImage[ImageHeight+n+i][ImageWidth+n-j-1];
            
            
        }
    }
    
}



void Pre_enhance(unsigned char OriImage[height][width],
                 double Orientation[ImageHeight][ImageWidth],
                 unsigned char NewImage[ImageHeight][ImageWidth])
{
    double xg[ImageHeight][ImageWidth]={0};
    double yg[ImageHeight][ImageWidth]={0};
    double Image[ImageHeight][ImageWidth]={0};
    double Gxy=0,Gxx=0,Gyy=0,t,u1,v1,h,s=0;
    
    for(int i=1;i<ImageHeight+1;i++)
    {
        for(int j=1;j<ImageWidth+1;j++)
        {
            xg[i-1][j-1]=OriImage[i-1][j+1]+2*OriImage[i][j+1]+OriImage[i+1][j+1]-OriImage[i-1][j-1]
            -2*OriImage[i][j-1]-OriImage[i+1][j-1];
            yg[i-1][j-1]=OriImage[i-1][j-1]+2*OriImage[i-1][j]+OriImage[i-1][j+1]-OriImage[i+1][j-1]
            -2*OriImage[i+1][j]-OriImage[i+1][j+1];
        }
    }
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            for(int h=-8;h<=8;h++)
            {
                for(int k=-8;k<=8;k++)
                {
                    Gxy=Gxy+xg[i+h][j+k]*yg[i+h][j+k];
                    Gxx=Gxx+xg[i+h][j+k]*xg[i+h][j+k];
                    Gyy=Gyy+yg[i+h][j+k]*yg[i+h][j+k];
                }
            }
            
            t=2*Gxy;
            Orientation[i][j]=0.5*pi+0.5*atan2(t,Gxx-Gyy);
            Gxy=0;
            Gxx=0;
            Gyy=0;
        }
    }
    
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            
            for(int u=-5;u<=5;u++)
            {
                for(int v=-5;v<=5;v++)
                {
                    u1=u*cos(Orientation[i][j])+v*sin(Orientation[i][j]);
                    v1=-u*sin(Orientation[i][j])+v*cos(Orientation[i][j]);
                    h=exp(-0.5*(pow(u1,2)/pow(Dx,2)+pow(v1,2)/pow(Dy,2)))*cos(2*pi*0.1*u1);
                    s=s+h*double(OriImage[i+1-u][j+1-v]);
                }
            }
            Image[i][j]=s;
            s=0;
        }

    }
    
    
    double max=Image[0][0];
    double min=Image[0][0];
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
           if(Image[i][j]>max)
               max=Image[i][j];
            if(Image[i][j]<min)
               min=Image[i][j];
        }
    }
  
    
    for(int i=0;i<ImageHeight;i++)
        {
            for(int j=0;j<ImageWidth;j++)
            {
                NewImage[i][j]=255*(Image[i][j]-min)/(max-min);
            }
        }
    
    
    
}


void Binarize(unsigned char InputImage[ImageHeight][ImageWidth],unsigned char OutputImage[ImageHeight][ImageWidth])
{
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
          double sum=0;
          double ave=0;
            
            for(int s=-10;s<=10;s++)
            {
                for(int t=-10;t<=10;t++)
                {
                    sum=sum+InputImage[i+s][j+t];
                }
            }
            ave=sum/(21*21);
            if(InputImage[i][j]<ave)
                OutputImage[i][j]=255;
            else
                OutputImage[i][j]=0;
        }
    }
    
}

void Post_enhance(unsigned char InputImage[ImageHeight][ImageWidth],unsigned char OutputImage[ImageHeight][ImageWidth])
{int i,j,y;
    for(i=0;i<ImageHeight;i++)
    {
        for(j=0;j<ImageWidth;j++)
        {
            if(InputImage[i][j]<=220)
                break;
        }
        for(y=0;y<j;y++)
            OutputImage[i][y]=0;
        
        for(j=ImageWidth-1;j>=0;j--)
            {
                if(InputImage[i][j]<=220)
                    break;
            }
        for(y=ImageWidth-1;y>j;y--)
            OutputImage[i][y]=0;
    }
}

void median(unsigned char InputImage[ImageHeight][ImageWidth])
{
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            int array[9]={0};
            int s=0;
            for(int m=-1;m<=1;m++)
            {
                for(int t=-1;t<=1;t++)
                {
                    array[s]=InputImage[i+m][j+t];
                    s++;
                }
            }
            sort(array,array+9);
            InputImage[i][j]=array[4];
        }
    }
}

int main()
{
    unsigned char OriImage1[ImageHeight][ImageWidth]={0};
    unsigned char OriImage2[ImageHeight][ImageWidth]={0};
    unsigned char ExtendImage1[height][width]={0};
    unsigned char ExtendImage2[height][width]={0};
    double Orientation1[ImageHeight][ImageWidth]={0};
    double Orientation2[ImageHeight][ImageWidth]={0};
    unsigned char Pre1[ImageHeight][ImageWidth]={0};
    unsigned char Pre2[ImageHeight][ImageWidth]={0};
    unsigned char bi1[ImageHeight][ImageWidth]={0};
    unsigned char bi2[ImageHeight][ImageWidth]={0};
    

    GImageRead(OriImage1,"/Users/Aria/Documents/USC/569/hw2/hw2_images/fingerprint_good.raw");
    GImageRead(OriImage2,"/Users/Aria/Documents/USC/569/hw2/hw2_images/fingerprint_bad.raw");
    
    Extention_Image(OriImage1,ExtendImage1);
    Extention_Image(OriImage2,ExtendImage2);
    
    Pre_enhance(ExtendImage1,Orientation1,Pre1);
    Pre_enhance(ExtendImage2,Orientation2,Pre2);
    
    GImageWrite(Pre1,"/Users/Aria/Documents/USC/569/hw2/hw2_images/Pre1.raw");
    GImageWrite(Pre2,"/Users/Aria/Documents/USC/569/hw2/hw2_images/Pre2.raw");
    
    Binarize(Pre1, bi1);
    Binarize(Pre2, bi2);
    
    GImageWrite(bi1,"/Users/Aria/Documents/USC/569/hw2/hw2_images/bi1.raw");
    GImageWrite(bi2,"/Users/Aria/Documents/USC/569/hw2/hw2_images/bi2.raw");
    
    Post_enhance(OriImage1,bi1);
    Post_enhance(OriImage2,bi2);
    
    GImageWrite(bi1,"/Users/Aria/Documents/USC/569/hw2/hw2_images/Post1.raw");
    GImageWrite(bi2,"/Users/Aria/Documents/USC/569/hw2/hw2_images/Post2.raw");
    
    median(bi1);
    median(bi2);
    
    median(bi1);
    median(bi2);
    
    
    for(int i=0;i<ImageHeight;i++)
    {
        for(int j=0;j<ImageWidth;j++)
        {
            if(bi1[i][j]!=0)
                bi1[i][j]=255;
            if(bi2[i][j]!=0)
                bi2[i][j]=255;
            
        }
    }
    
 
  

    GImageWrite(bi1,"/Users/Aria/Documents/USC/569/hw2/hw2_images/median1.raw");
    GImageWrite(bi2,"/Users/Aria/Documents/USC/569/hw2/hw2_images/median2.raw");
    
}

