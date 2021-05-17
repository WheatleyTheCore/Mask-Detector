#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class FaceDetector {
    private:
        CascadeClassifier face_cascade;
        String face_cascade_path = samples::findFile("../data/haarcascades/haarcascade_frontalface_alt.xml");
    public:
        vector<Rect> faces;
        FaceDetector() {
            if (!face_cascade.load(face_cascade_path)) {
                cout << "Error loading the face cascade!\n";
            }
            cout << "FaceDetector successfully initialized.\n";
        }

        void detectFaces(Mat frame) {
            face_cascade.detectMultiScale(frame, faces);
        }

        vector<Rect> getFaces() {
            return faces;
        }

};
