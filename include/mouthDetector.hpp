#include <opencv2/opencv.hpp>
#include <ctime>
#include <iostream>

using namespace std;
using namespace cv;

class MouthDetector {
    private:
        CascadeClassifier mouth_cascade;
        String mouth_cascade_path = samples::findFile("../data/haarcascades/mouth.xml");
        int flag = 0;
        clock_t detectionStartTime;
        clock_t detectionStopTime;
        bool mouthIsPresent = false;
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
        bool faceHasMouth() {
            /**
             *All of the timer stuff is to minimize the effects of temporary false positives or false negatives
             * */
            if (mouths.size() > 0) {
                if (flag == 0){
                    flag = 1;
                    detectionStartTime = clock();
                }
            } else {
                if (flag == 1) {
                    flag = 0;
                    detectionStopTime = clock();
                }
            }
            if (flag == 1 && ((clock() - detectionStartTime)/CLOCKS_PER_SEC) > 2) {
                mouthIsPresent = true;
            }
            else if (flag == 0 && ((clock() - detectionStopTime)/CLOCKS_PER_SEC) > 2) {
                mouthIsPresent = false;
            }
            return mouthIsPresent;
        }
        bool isWearingMask() {
            return !(faceHasMouth());
        }
};
