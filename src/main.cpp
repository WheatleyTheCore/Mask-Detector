
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include "faceDetector.hpp"

using namespace std;
using namespace cv;


int main() {
	FaceDetector fd;
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()) {
		cout << "ERROR 2\n";
		return -1;
	}
	Mat frame;
	while (cap.read(frame)){
		if (frame.empty()) {
			cout << "No captured frame!\n";
			return -1;
		}
		fd.detectFaces(frame);
		for (int i = 0; i < fd.faces.size(); i++) {
			Point topLeft(fd.faces[i].x, fd.faces[i].y);
			Point bottomRight(fd.faces[i].x + fd.faces[i].width, fd.faces[i].y + fd.faces[i].height);
			rectangle(frame, topLeft, bottomRight, Scalar(0, 0, 225), 2, LINE_8);

		}
		imshow("faces", frame);
        if( waitKey(10) == 27 )
        {
            break; // escape
        }
	}

	return 0;
}
