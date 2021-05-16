
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include "faceDetector.hpp"

using namespace std;
using namespace cv;

CascadeClassifier face_cascade;

int main() {
	String face_cascade_path = samples::findFile("data/haarcascades/haarcascade_frontalface_alt.xml");

	if (!face_cascade.load(face_cascade_path)) {
		cout << "ERROR\n";
		return -1;
		}

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
		//vector<Rect> faces;
		//face_cascade.detectMultiScale(frame, faces);
		//for (int i = 0; i < faces.size(); i++) {
		//	Point topLeft(faces[i].x, faces[i].y);
		//	Point bottomRight(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
		//	rectangle(frame, topLeft, bottomRight, Scalar(0, 0, 225), 2, LINE_8);

		//}
		imshow("faces", frame);
        if( waitKey(10) == 27 )
        {
            break; // escape
        }
	}

	return 0;
}
