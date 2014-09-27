#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    // we don't want to be running to fast
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    //create the socket and set to send to 127.0.0.1:11999
	udpConnection.Create();
	udpConnection.Connect("10.73.39.126",11999);
    udpConnection.Bind(11999);
	udpConnection.SetNonBlocking(true);
    
    
    ofBackground(0, 0, 0);
    
    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();
//    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(5);
    openNIDevice.start();
    
    // set properties for all user masks and point clouds
    //openNIDevice.setUseMaskPixelsAllUsers(true); // if you just want pixels, use this set to true
//    openNIDevice.setUseMaskTextureAllUsers(true); // this turns on mask pixels internally AND creates mask textures efficiently
//    openNIDevice.setUsePointCloudsAllUsers(true);
//    openNIDevice.setPointCloudDrawSizeAllUsers(10); // size of each 'point' in the point cloud
//    openNIDevice.setPointCloudResolutionAllUsers(10); // resolution of the mesh created for the point cloud eg., this will use every second depth pixel
    
    // you can alternatively create a 'base' user class
//    ofxOpenNIUser user;
//    user.setUseMaskTexture(true);
//    user.setUsePointCloud(true);
//    user.setPointCloudDrawSize(2);
//    user.setPointCloudResolution(2);
//    openNIDevice.setBaseUserClass(user);
      
 //   verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
    
    for (int i = 0; i < 10 ; i++){
        flock.addBoid(i*50, i*50);
        printf("\n\n\n%f\n\n\n",flock.boids[i].initPosition.x);
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
    stringToPoint(message);
    
    string send = pointToString(seeker);
	udpConnection.Send(send.c_str(),send.length());
    
    openNIDevice.update();
    
    for (int i = 0; i < flock.boids.size(); ++i) {
        if (flock.boids[i].loc.x - 50 <= seeker.x && seeker.x <= flock.boids[i].loc.x + 50
            && flock.boids[i].loc.y - 50 <= seeker.y && flock.boids[i].loc.y + 50) {
            flock.boids[i].avoid(seeker);
        } else {
            flock.boids[i].arrive(flock.boids[i].initPosition);
        }
    }
    flock.update();
}

string testApp::pointToString(ofPoint target) {
    stringstream result;
    
    result << target.x;
    result << ",";
    result << target.y;

    return result.str();
}

ofPoint testApp::stringToPoint(string target) {
    ofPoint result;
    
    int comma = target.find(",");
    result.x = std::atof(target.substr(0, comma).c_str());
    result.y = std::atof(target.substr(comma+1, target.length()-comma).c_str());

    return result;
}


//--------------------------------------------------------------
void testApp::draw(){
    
	ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    // draw debug (ie., image, depth, skeleton)
    //openNIDevice.drawDebug();
    openNIDevice.drawSkeletons();
    ofPopMatrix();
    
    //printf("HAHAHA: %l\n", openNIDevice.getCurrentTrackedUsers().size());
    //printf("HOHOHO %d\n", openNIDevice.getCurrentTrackedUsers()[0].getNumJoints());
    
    if (openNIDevice.getCurrentTrackedUsers().size() > 0) {
        ofxOpenNIUser & user = openNIDevice.getTrackedUser(0);
        //printf("hihihi %d\n", user.getNumJoints());
        for( int i = 0; i < user.getNumJoints();  ++i) {
            //printf("DDD: %f\n", user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().x);
            seeker.x = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().x * 2;
            seeker.y = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().y * 800/480;
        }
    }

    
    
    //int num= openNIDevice.getNumTrackedUsers();
    
    // draw some info regarding frame counts etc
	ofSetColor(255, 255, 0);

    flock.draw();
    ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::userEvent(ofxOpenNIUserEvent & event){
    // show user event messages in the console
    ofLogNotice() << getUserStatusAsString(event.userStatus) << "for user" << event.id << "from device" << event.deviceID;
}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}