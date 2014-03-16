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
        cap(i)
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
        cv::rectangle( frame,
           cv::Point( i,j ),
           cv::Point( i+size, j+size),
           cv::Scalar( 0, 255, 255 ),
           2,
           8 );
    }
    void showDebug()
    {
        cv::imshow("debug",frame);
        cv::waitKey();
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
    cv::Mat frame,res;
    uchar* getFrame()
    {
        cap>>frame;
        cvtColor(frame,res, CV_BGR2GRAY);
        cv::imshow("s",res);
        return res.data;
    }
    void Print()
    {}
};
