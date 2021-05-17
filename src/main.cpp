
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include "faceDetector.hpp"
#include "mouthDetector.hpp"
#include "display.hpp"


using namespace std;
using namespace cv;


int main() {
	FaceDetector fd;
	MouthDetector md;
	VideoCapture cap;

	cap.open(0);
	if (!cap.isOpened()) {
		cout << "ERROR 2\n";
		return -1;
	}
	Display disp;
	while (cap.read(disp.frame)){
		if (disp.frame.empty()) {
			cout << "No captured frame!\n";
			return -1;
		}


		fd.detectFaces(disp.frame);
		for (int i = 0; i < fd.faces.size(); i++) {
			disp.drawFace(fd.faces[i]);
			//Point topLeft(fd.faces[i].x, fd.faces[i].y);
			//Point bottomRight(fd.faces[i].x + fd.faces[i].width, fd.faces[i].y + fd.faces[i].height);
			//rectangle(frame, topLeft, bottomRight, Scalar(0, 0, 225), 2, LINE_8);

			md.detectMouths(disp.frame(fd.faces[i]));
			for (int j = 0; j < md.mouths.size(); j++) {
				disp.drawMouth(md.mouths[j]);
				//Point mouthTopLeft(md.mouths[j].x, md.mouths[j].y);
				//Point mouthBottomRight(md.mouths[j].x + md.mouths[j].width, md.mouths[j].y + md.mouths[j].height);
				//rectangle(frame, topLeft + mouthTopLeft, topLeft + mouthBottomRight, Scalar(0, 0, 225), 2, LINE_8);
			}

		}
		imshow("faces", disp.frame);
		cout << md.isWearingMask() << endl;
        if( waitKey(10) == 27 )
        {
            break; // escape
        }
	}

	return 0;
}
