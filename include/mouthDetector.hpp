#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class MouthDetector {
    private:
        CascadeClassifier mouth_cascade;
        String mouth_cascade_path = samples::findFile("data/haarcascades/mouth.xml");
    public:
        vector<Rect> mouths;

        MouthDetector() {
            if (!mouth_cascade.load(mouth_cascade_path)) {
                cout << "Error loading the mouth cascade!\n";
            }
            cout << "Mouth detector successfully initialized.\n";
        }

        void detectMouths(Mat face) {
            Mat gray;
            cvtColor(face, gray, COLOR_BGR2GRAY);
            equalizeHist(gray, gray);
           mouth_cascade.detectMultiScale(gray, mouths, 4, 13);
        }
        /*
        ** TODO: add a timer to measure how long mouths are in frame,
        **       since false positives becuase of eyes usually don't last for
        **      long. If mouths.size() > 0 for over a few seconds it's probably actually
        **      a mouth
         */
        bool faceHasMouth(Mat face) {
            detectMouths(face);
            if (mouths.size() > 0) {
                return true;
            }
            else return false;
        }
};
