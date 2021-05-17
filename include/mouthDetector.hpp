#include <opencv2/opencv.hpp>
#include <ctime>
#include <iostream>

using namespace std;
using namespace cv;

class MouthDetector {
    private:
        CascadeClassifier mouth_cascade;
        String mouth_cascade_path = samples::findFile("data/haarcascades/mouth.xml");
        int flag = 0;
        clock_t detectionStartTime;
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
            if (mouths.size() > 0) {
                if (flag == 0){
                    flag = 1;
                    detectionStartTime = clock();
                    cout << "Started Clock!\n";
                }
            } else {
                flag = 0;
            }
            if (flag == 1 && ((clock() - detectionStartTime)/CLOCKS_PER_SEC) > 2) {
                return true;
            }
            else return false;
        }
};
