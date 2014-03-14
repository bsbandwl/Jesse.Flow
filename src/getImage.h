#pragma once
#include <opencv2/opencv.hpp>
#include <sys/time.h>    

#define CV
long getCurrentTime();
class getImage
{
    cv::VideoCapture cap;
public:
    getImage():
        cap(1)
    {
        printf("Stated\n");
        if(!cap.isOpened())  // check if we succeeded
        {
            printf("open failed");
        }
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
    uchar* getFrame()
    {
        cv::Mat frame,res;
        cap>>frame;
        cvtColor(frame,res, CV_BGR2GRAY);
        return res.data;
    }
};
