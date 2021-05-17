
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


		fd.detectFaces(disp.frame);                  //run facial detection only
		for (int i = 0; i < fd.faces.size(); i++) {
			disp.drawFace(fd.faces[i]);              //draw a box around detected faces

			md.detectMouths(disp.frame(fd.faces[i]));//detect mouths (if there is a mouth then we know there isn't a mask)
			for (int j = 0; j < md.mouths.size(); j++) {
				disp.drawMouth(md.mouths[j]);        // draw box around mouth
			}

		}
		disp.addText(md.isWearingMask());            // add text saying whether or not there is a face
		imshow("faces", disp.frame);                 // display the frame
        if( waitKey(10) == 27 )                      // if the user presses esc then exit
        {
            break; // escape
        }
	}

	return 0;
}
