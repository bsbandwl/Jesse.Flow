#pragma once
#include <opencv2/opencv.hpp>
#include <sys/time.h>    
#include <iostream>

#define CV
long getCurrentTime();
class getImage
{
    cv::VideoCapture cap;
public:
    int cols,rows;
    getImage(int i):
        cap(1)
    {
        printf("Stated\n");
        if(!cap.isOpened())  // check if we succeeded
        {
            printf("open failed");
        }
        cv::Mat frame;
        cap>>frame;
        this->cols=frame.cols;
        this->rows=frame.rows;
        printf("cols: %d rows:%d\n",cols,rows);
    }
    void drawMat(int i,int j,int size)
    {
        cv::rectangle( frame[0],
           cv::Point( i,j ),
           cv::Point( i+size, j+size),
           cv::Scalar( 0, 255, 255 ),
           2,
           8 );
    }
    void drawMat(int k,int i,int j,int size)
    {
        cv::rectangle( frame[k],
           cv::Point( i,j ),
           cv::Point( i+size, j+size),
           cv::Scalar( 0, 255, 255 ),
           2,
           8 );
    }
    void showDebug()
    {
    }
    void SpeedTest()
    {
        cv::Mat frame;
        long la;
        long st;
        while(true)
        {
            st=getCurrentTime();
            printf("%ld\n", st-la);
            la=st;
            cap>>frame;
        }
    }
    cv::Mat frame[3];
    uchar* getFrame()
    {
        cv::Mat temp,res;
        cap>>temp;
        imshow("pci",temp);
        cvtColor(temp,res, CV_BGR2GRAY);
        uchar *resptr=new uchar[cols*rows];
        //printf("%d %d \n",res.cols,res.rows );
        int k=res.cols+res.rows;
        memcpy(resptr, res.data, cols*rows*sizeof(uchar));
        return resptr;
    }
    uchar* getFrame(int i)
    {
        cv::Mat temp;
        if(i==0)
        {
            temp=cv::imread("/Users/xuhao/temp/0.jpg");
            cvtColor(temp,frame[0],CV_BGR2GRAY);
            return frame[0].data;
        }
        temp=cv::imread("/Users/xuhao/temp/1.jpg");
        cvtColor(temp,frame[1],CV_BGR2GRAY);
        return frame[1].data;
    }

    void Print()
    {}
};
