#pragma once
#include <iostream>
#include <fstream>
#include "getImage.h"
class flow
{
public:
    int rows,cols;
    getImage source;
    std::ofstream ofs;
    flow(int i):
        source(i),ofs("/Users/xuhao/dat.txt")
    {
        cols=source.cols;
        rows=source.rows;
    }

    //所有搜索仅仅是正方形
    bool Compute_Diff(uchar *frame,int offX,int offY,int size,int min_diff);
    int Compute_Flow(uchar *frame1,uchar*frame2,float & speedx,float& sppedy);
    int  Compute_SAD (uchar *frame1,uchar *frame2,int off1X,int off1Y,int off2X,int off2Y,int size);
    void Debug();
};
