#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Display {
    private:
        Point tl;
        Point br;
    public:
        Mat frame;
        void drawFace(Rect faceRect) {
            tl.x = faceRect.x;
            tl.y = faceRect.y;
            br.x = faceRect.x + faceRect.width;
            br.y = faceRect.y + faceRect.height;
            rectangle(frame, tl, br, Scalar(0, 0, 255), 2, LINE_8);
        }
        void drawMouth(Rect mouthRect) {
            Point mouthTl(mouthRect.x, mouthRect.y);
            Point mouthBr(mouthRect.x + mouthRect.width, mouthRect.y + mouthRect.height);
            rectangle(frame, tl + mouthTl, tl + mouthBr, Scalar(0, 0, 255), 2, LINE_8);
        }

        void showFrame() {
            imshow("Mask Detector", frame);
        }
};
