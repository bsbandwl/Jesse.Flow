#pragma once
class flow
{
    getImage source;
    flow(getImage sou):
        source(sou)
    {

    }
    static void Compute_flow(uchar *frame1,uchar*frame2);
};
