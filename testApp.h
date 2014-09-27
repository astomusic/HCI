#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "ofxFlocking.h"
#include "ofxNetwork.h"

class testApp : public ofBaseApp{

public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

    void userEvent(ofxOpenNIUserEvent & event);
    
    string pointToString(ofPoint target);
    ofPoint stringToPoint(string target);
    
	ofxOpenNI openNIDevice;
    ofxFlocking flock;
    
    ofTrueTypeFont verdana;
    
    ofPoint leftHand;
    ofPoint rightHand;
    ofPoint neck;
    ofPoint networkSeeker;
    
    int numHands;
    
    map<Joint, ofPoint> userJoints;
    
    ofxUDPManager udpConnection;

//    enum Joint {
//        
//        // start at root joint
//        JOINT_TORSO = 0,
//        JOINT_NECK,
//        JOINT_HEAD,
//        
//        // left arm + shoulder
//        JOINT_LEFT_SHOULDER,
//        JOINT_LEFT_ELBOW,
//        JOINT_LEFT_HAND,
//        
//        // right arm + shoulder
//        JOINT_RIGHT_SHOULDER,
//        JOINT_RIGHT_ELBOW,
//        JOINT_RIGHT_HAND,
//        
//        // left leg
//        JOINT_LEFT_HIP,
//        JOINT_LEFT_KNEE,
//        JOINT_LEFT_FOOT,
//        
//        // right leg
//        JOINT_RIGHT_HIP,
//        JOINT_RIGHT_KNEE,
//        JOINT_RIGHT_FOOT,
//        
//        JOINT_COUNT,
//        JOINT_UNKOWN
//    };

};

#endif
