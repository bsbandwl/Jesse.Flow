#include "flow.h"
#include "getImage.h"
#include <iostream>
#include "math.h"

bool flow::Compute_Diff(uchar *frame,int offX,int offY,int size,int min_diff)
{
    //使用相邻像素的绝对值之差的和作为差异分析的依据
    int res=0;
    //先计算行内的差和
    for(int j=offY;j<offY+size-1;j++)
        for(int i=offX;i<offX+size;i++)
        {
            res+=abs(frame[j*cols+i]-frame[j*cols+i+1]);
        }

    //计算列内的差和
    for(int j=offY;j<offY+size;j++)
        for(int i=offX;i<offX+size-1;i++)
        {
            res+=abs(frame[j*cols+i]-frame[(j+1)*cols+i]);
        }
    if(res>min_diff*size*size)
        return 1;
    return 0;
}
void flow::Debug()
{
    uchar*frame1,*frame2;
    frame1=source.getFrame();
    cv::waitKey(1000);
    while(true)
    {
        int num=0;
        float x,y;
        frame2=source.getFrame();
        Compute_Flow(frame1,frame2,x,y);
    }
}
//motion is frame 1 to frame 2
//失败则返回0
int flow::Compute_Flow(uchar *frame1,uchar*frame2,float& speedx,float& speedy)
{
    int starty=50,endy=270;
    int startx=100,endx=540;
    int count=0;
    int maxmotion=5;
    int temp;
    int i2,j2;
    int size=8;
    int num=8;
    int xstep=(endx-startx)/num;
    int ystep=(endy-starty)/num;

    int minidist=50*size*size;
    speedx=0;
    speedy=0;
    int debug=0;
    long st=getCurrentTime();
    //TODO 使用KMP改进之
    //TODO 图形化之
    for(int j=starty;j<endy;j+=ystep)
        for(int i=startx;i<endx;i+=xstep)
        {
            if(!Compute_Diff(frame1,i,j,size,4))
                continue;
            debug++;
            source.drawMat(0,i,j,size);

            int dist=100000;
            for(int jj= j-maxmotion ;jj<j+maxmotion ; jj++)
                for(int ii=i-maxmotion ; ii < i+maxmotion ; ii++)
                    if( (temp=Compute_SAD(frame1,frame2,i,j,ii,jj,size))<dist)
                    {
                        dist=temp;
                        i2=ii;
                        j2=jj;
                    }

            if(dist<minidist)
            {
                source.drawMat(1,i2,j2,size);
                speedy+=j2-j;
                speedx+=i2-i;
                count++;
            }

        }
    long ed=getCurrentTime();

    speedx/=count;
    speedy/=count;
    printf("%d %5.1f %5.1f time:%d \n", count,speedx,speedy,ed-st);
    source.showDebug();
    if(count==0)
    {
        speedx=0;
        speedy=0;
        return 0;
    }
    return 1;
}
int  flow::Compute_SAD (uchar *frame1,uchar *frame2,int off1X,int off1Y,int off2X,int off2Y,int size)
{
    int mov2x=off2X-off1X;
    int mov2y=off2Y-off1Y;
    int res=0;
    for(int j=off1Y;j<off1Y+size;j++)
        for(int i=off1X;i<off1X+size;i++)
        {
            int i2=i+mov2x;
            int j2=j+mov2y;
            res+=abs(frame1[j*cols+i]-frame2[j2*cols+i2]);
        }
    return res;
}

int main()
{
    flow flo0(0);
    flo0.Debug();
    printf("Hello,World\n");
}

