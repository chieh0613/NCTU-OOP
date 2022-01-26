#include<iostream>
#include<fstream>
#include<windows.h>
#include"main.h"

using namespace std;

int main(int argc,char *argv[])
{
    float times=atof(argv[3]);;
    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;
    ifstream fin;
    ofstream fout;
    fin.open(argv[1],ios::in|ios::binary);
    fout.open(argv[2],ios::out|ios::binary);

    if(!fin)
    {
        cerr<<"File could not be opened"<<endl;
    }
    fin.read((char*)&file_header,sizeof(file_header));
    fin.read((char*)&info_header,sizeof(info_header));
    fout.write((char*)&file_header,sizeof(file_header));
    fout.write((char*)&info_header,sizeof(info_header));
    int byte=info_header.biBitCount;
    if(byte==24)
    {
        int width=info_header.biWidth;
        int height=info_header.biHeight;
        int padding=(width*9)%4;
        int row_size=3*width+padding;
        int x1,y1;
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<row_size; j++)
            {
                unsigned char ch=fin.get();
                int pixel=((int)ch*times)+0.5;
                try
                {
                    if(pixel>255)
                    {
                        pixel=255;
                        throw 1;
                    }

                }
                catch(int n)
                {
                    int y=(int)j/3;
                    if(j%3==0)
                    {
                        cout<<"Pixel ("<<y<<","<<i<<") is overflow"<<endl;
                        x1=j;
                        y1=i;
                    }
                    else if(j%3==1)
                    {
                        if((j-1)!=x1&&i!=y1)
                        {
                            cout<<"Pixel ("<<y<<","<<i<<") is overflow"<<endl;
                            x1=j-1;
                            y1=i;
                        }
                    }
                    else if(j%3==2)
                    {
                        if((j-2)!=x1&&i!=y1)
                        {
                            cout<<"Pixel ("<<y<<","<<i<<") is overflow"<<endl;
                        }
                    }

                }
                catch(...)
                {
                    cout<<"unknown errors"<<endl;
                }
                fout.write((char*)&pixel,1);
            }
        }
    }
    else if(byte==32)
    {
        int width=info_header.biWidth;
        int height=info_header.biHeight;
        int padding=(width*9)%4;
        int row_size=4*width+padding;
        int x1,y1;
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<row_size; j++)
            {
                unsigned char ch=fin.get();
                int pixel;
                if((j+1)%4!=0)
                {
                    pixel=((int)ch*times)+0.5;
                }
                try
                {
                    if(pixel>255)
                    {
                        pixel=255;
                        throw 1;
                    }

                }
                catch(int n)
                {
                    int y=(int)j/4;
                    if(j%4==0)
                    {
                        cout<<"Pixel ("<<y<<","<<i<<") is overflow"<<endl;
                        x1=j;
                        y1=i;
                    }
                    else if(j%4==1)
                    {
                        if((j-1)!=x1&&i!=y1)
                        {
                            cout<<"Pixel ("<<y<<","<<i<<") is overflow"<<endl;
                            x1=j-1;
                            y1=i;
                        }
                    }
                    else if(j%4==2)
                    {
                        if((j-2)!=x1&&i!=y1)
                        {
                            cout<<"Pixel ("<<y<<","<<i<<") is overflow"<<endl;
                        }
                    }

                }
                catch(...)
                {
                    cout<<"unknown errors"<<endl;
                }
                fout.write((char*)&pixel,1);
            }
        }
    }




    fin.close();
    fout.close();

    return 0;
}
