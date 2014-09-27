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
    
//    openNIDevice.addHandsGenerator();
//    openNIDevice.addAllHandFocusGestures();
//    openNIDevice.setMaxNumHands(10);
    
    openNIDevice.setMaxNumUsers(10);
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
    
//    for (int i = 0; i < 10 ; i++){
//        flock.addBoid(i*50, i*50);
//        printf("\n\n\n%f\n\n\n",flock.boids[i].initPosition.x);
//    }
    
//    flock.addBoid(0, 10);
//    flock.addBoid(50, 10);
//    flock.addBoid(100, 10);
//    flock.addBoid(150, 10);
//    flock.addBoid(200, 10);
//    flock.addBoid(250, 10);
//    flock.addBoid(300, 10);
//    flock.addBoid(350, 10);
//    flock.addBoid(400, 10);
//    flock.addBoid(450, 10);
//    flock.addBoid(500, 10);
//    flock.addBoid(550, 10);
//    flock.addBoid(600, 10);
//    flock.addBoid(650, 10);
//    flock.addBoid(700, 10);
//    flock.addBoid(750, 10);
//    flock.addBoid(800, 10);
//    flock.addBoid(850, 10);
//    flock.addBoid(900, 10);
//    flock.addBoid(950, 10);
//    flock.addBoid(1000, 10);
//    flock.addBoid(1050, 10);
//    flock.addBoid(1100, 10);
//    flock.addBoid(1150, 10);
//    flock.addBoid(1200, 10);
//    flock.addBoid(1250, 10);
//    flock.addBoid(1300, 10);
//    flock.addBoid(1350, 10);
//    
//    flock.addBoid(10, 0);
//    flock.addBoid(10, 50);
//    flock.addBoid(10, 100);
//    flock.addBoid(10, 150);
//    flock.addBoid(10, 200);
//    flock.addBoid(10, 250);
//    flock.addBoid(10, 300);
//    flock.addBoid(10, 350);
//    flock.addBoid(10, 400);
//    flock.addBoid(10, 450);
//    flock.addBoid(10, 500);
//    flock.addBoid(10, 550);
//    flock.addBoid(10, 600);
//    flock.addBoid(10, 650);
//    flock.addBoid(10, 700);
//    flock.addBoid(10, 750);
    
    // N
    flock.addBoid(100, 200);
    flock.addBoid(100, 250);
    flock.addBoid(100, 300);
    flock.addBoid(100, 350);
    flock.addBoid(100, 400);
    flock.addBoid(100, 450);
    flock.addBoid(100, 500);
    flock.addBoid(100, 550);
    
    flock.addBoid(300, 200);
    flock.addBoid(300, 250);
    flock.addBoid(300, 300);
    flock.addBoid(300, 350);
    flock.addBoid(300, 400);
    flock.addBoid(300, 450);
    flock.addBoid(300, 500);
    flock.addBoid(300, 550);
    
    flock.addBoid(100 + (200/7)*1 , 250);
    flock.addBoid(100 + (200/7)*2 , 300);
    flock.addBoid(100 + (200/7)*3 , 350);
    flock.addBoid(100 + (200/7)*4 , 400);
    flock.addBoid(100 + (200/7)*5 , 450);
    flock.addBoid(100 + (200/7)*6 , 500);
    
    // E
    flock.addBoid(400, 200);
    flock.addBoid(400, 250);
    flock.addBoid(400, 300);
    flock.addBoid(400, 350);
    flock.addBoid(400, 400);
    flock.addBoid(400, 450);
    flock.addBoid(400, 500);
    flock.addBoid(400, 550);
    
    flock.addBoid(450, 200);
    flock.addBoid(500, 200);
    flock.addBoid(550, 200);
    flock.addBoid(600, 200);

    flock.addBoid(450, 375);
    flock.addBoid(500, 375);
    flock.addBoid(550, 375);
    flock.addBoid(600, 375);
    
    flock.addBoid(450, 550);
    flock.addBoid(500, 550);
    flock.addBoid(550, 550);
    flock.addBoid(600, 550);
    
    //X
    flock.addBoid(700, 200);
    flock.addBoid(700 + (200/7)*1 , 250);
    flock.addBoid(700 + (200/7)*2 , 300);
    flock.addBoid(700 + (200/7)*3 , 350);
    flock.addBoid(700 + (200/7)*4 , 400);
    flock.addBoid(700 + (200/7)*5 , 450);
    flock.addBoid(700 + (200/7)*6 , 500);
    flock.addBoid(900, 550);
    
    flock.addBoid(700, 550);
    flock.addBoid(700 + (200/7)*1 , 500);
    flock.addBoid(700 + (200/7)*2 , 450);
    flock.addBoid(700 + (200/7)*3 , 400);
    flock.addBoid(700 + (200/7)*4 , 350);
    flock.addBoid(700 + (200/7)*5 , 300);
    flock.addBoid(700 + (200/7)*6 , 250);
    flock.addBoid(900, 200);
    
    //T
    flock.addBoid(1000, 200);
    flock.addBoid(1050, 200);
    flock.addBoid(1100, 200);
    flock.addBoid(1150, 200);
    flock.addBoid(1200, 200);
    
    flock.addBoid(1100, 250);
    flock.addBoid(1100, 300);
    flock.addBoid(1100, 350);
    flock.addBoid(1100, 400);
    flock.addBoid(1100, 450);
    flock.addBoid(1100, 500);
    flock.addBoid(1100, 550);
    

    for ( int i = 0 ; i < JOINT_UNKOWN-2 ; i++ ){
        userJoints[(Joint)i] = ofPoint(0,0);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
    printf("message : %s \n", message.c_str());
    if(message == "" || message.empty()) {
        isConnected = false;
    } else {
        isConnected = true;
    }
    stringToPoint(message);
    
    if(userNum>0) {
        string send = pointToString();
        udpConnection.Send(send.c_str(),send.length());
    }
    
    
    
    //local
    map<Joint, ofPoint>::iterator it;
    int flag[JOINT_UNKOWN * 2] = {0, };
    for(it=userJoints.begin() ; it != userJoints.end() ; it++) {
        for (int i = 0; i < flock.boids.size(); ++i) {
            if (flock.boids[i].loc.x - 50 <= it->second.x && it->second.x <= flock.boids[i].loc.x + 50
                && flock.boids[i].loc.y - 50 <= it->second.y && it->second.y <= flock.boids[i].loc.y + 50) {
                flock.boids[i].avoid(it->second);
                //flock.boids[i].joint = it->first;
                flock.boids[i].checker = it->first;
                //flag[it->first] = 1;
            } else {
                if (flock.boids[i].checker == it->first){
                    flock.boids[i].arrive(flock.boids[i].initPosition);
                }
            }
        }
    }
    
    for(it=RemoteUserJoints.begin() ; it != RemoteUserJoints.end() ; it++) {
        for (int i = 0; i < flock.boids.size(); ++i) {
            if (flock.boids[i].loc.x - 50 <= it->second.x && it->second.x <= flock.boids[i].loc.x + 50
                && flock.boids[i].loc.y - 50 <= it->second.y && it->second.y <= flock.boids[i].loc.y + 50) {
                flock.boids[i].avoid(it->second);
                //flock.boids[i].joint = it->first;
                flock.boids[i].checker = it->first + 100;
                //flag[it->first + JOINT_UNKOWN] = 2;
            } else {
                if (flock.boids[i].checker == it->first + 100){
                    flock.boids[i].arrive(flock.boids[i].initPosition);
                }
            }
        }
    }
    
    // for (seeker in seekers)
//    for (int i = 0; i < flock.boids.size(); ++i) {
//        if (flock.boids[i].loc.x - 50 <= leftHand.x && leftHand.x <= flock.boids[i].loc.x + 50
//            && flock.boids[i].loc.y - 50 <= leftHand.y && leftHand.y <= flock.boids[i].loc.y + 50) {
//            flock.boids[i].avoid(leftHand);
//            flock.boids[i].joint = JOINT_LEFT_HAND;
//            // flock.boids[i].setSeeker = seekerId;
//        } else {
//            if (flock.boids[i].joint == JOINT_LEFT_HAND){
//                flock.boids[i].arrive(flock.boids[i].initPosition);
//            }
//        }
//        //if (boids[i]->seeker.x, y +- 50 ) arrive
//    }
//    
//    for (int i = 0; i < flock.boids.size(); ++i) {
//        if (flock.boids[i].loc.x - 50 <= rightHand.x && rightHand.x <= flock.boids[i].loc.x + 50
//            && flock.boids[i].loc.y - 50 <= rightHand.y && rightHand.y <= flock.boids[i].loc.y + 50) {
//            flock.boids[i].avoid(rightHand);
//            flock.boids[i].joint = JOINT_RIGHT_HAND;
//            // flock.boids[i].setSeeker = seekerId;
//        } else {
//            if (flock.boids[i].joint == JOINT_RIGHT_HAND){
//                flock.boids[i].arrive(flock.boids[i].initPosition);
//            }
//        }
//        //if (boids[i]->seeker.x, y +- 50 ) arrive
//    }
    //network
//    for (int i = 0; i < flock.boids.size(); ++i) {
//        if (flock.boids[i].loc.x - 50 <= networkSeeker.x && networkSeeker.x <= flock.boids[i].loc.x + 50
//            && flock.boids[i].loc.y - 50 <= networkSeeker.y && networkSeeker.y <= flock.boids[i].loc.y + 50) {
//            flock.boids[i].avoid(networkSeeker);
//        } else {
//            flock.boids[i].arrive(flock.boids[i].initPosition);
//        }
//    }
    
    flock.update();
    openNIDevice.update();
    
//    map<Joint, ofPoint>::iterator it;
//    for(it=userJoints.begin() ; it != userJoints.end() ; it++) {
//        printf("%d joint - %f \n", it->first, it->second.x);
//    }
}

string testApp::pointToString() {
    stringstream result;
    
//    result << target.x;
//    result << ",";
//    result << target.y;
    
    if(userJoints[JOINT_LEFT_HAND].x != 0) {
        map<Joint, ofPoint>::iterator it;
        for(it=userJoints.begin() ; it != userJoints.find(JOINT_COUNT) ; it++) {
            printf("%d joint - %f \n", it->first, it->second.x);
            result << it->second.x;
            result << ",";
            result << it->second.y;
            result << "/";
        }
    }


    return result.str();
}

void testApp::stringToPoint(string target) {
    ofPoint result;
    vector<string> tokens;
    Tokenize(target, tokens);
    
    printf("token size: %lu\n", tokens.size());
    printf("JOINT_UNKOWN size: %d\n", JOINT_UNKOWN);
    for(int i=0; i < tokens.size() ; i++) {
        int comma = tokens[i].find(",");
        result.x = std::atof(tokens[i].substr(0, comma).c_str());
        result.y = std::atof(tokens[i].substr(comma+1, target.length()-comma).c_str());
        RemoteUserJoints[(Joint)i] = result;

    }

//    int comma = target.find(",");
//    //printf("this is comma : %d \n", comma);
//    result.x = std::atof(target.substr(0, comma).c_str());
//    //printf("this is result.x : %f \n", result.x);
//    result.y = std::atof(target.substr(comma+1, target.length()-comma).c_str());
//    //printf("this is result.y : %f \n", result.y);
//    
//    
//    return result;
    
}

void testApp::Tokenize(const string& str, vector<string>& tokens, const string& delimiters)
{
    // 맨 첫 글자가 구분자인 경우 무시
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // 구분자가 아닌 첫 글자를 찾는다
    string::size_type pos     = str.find_first_of(delimiters, lastPos);
    
    while (string::npos != pos || string::npos != lastPos)
    {
        // token을 찾았으니 vector에 추가한다
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // 구분자를 뛰어넘는다.  "not_of"에 주의하라
        lastPos = str.find_first_not_of(delimiters, pos);
        // 다음 구분자가 아닌 글자를 찾는다
        pos = str.find_first_of(delimiters, lastPos);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    // draw debug (ie., image, depth, skeleton)
    //openNIDevice.drawDebug();
    //openNIDevice.drawSkeletons();
    ofPopMatrix();
    
    //printf("HAHAHA: %l\n", openNIDevice.getCurrentTrackedUsers().size());
    //printf("HOHOHO %d\n", openNIDevice.getCurrentTrackedUsers()[0].getNumJoints());
    userNum =  openNIDevice.getCurrentTrackedUsers().size();
    for (int i=0 ; i<userNum ; ++i) {
        ofxOpenNIUser & user = openNIDevice.getTrackedUser(i);
        //printf("hihihi %d\n", user.getNumJoints());
        for( int i = 0; i < user.getNumJoints();  ++i) {
            //printf("DDD: %f\n", user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().x);
            //            leftHand.x = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().x * 2;
            //            leftHand.y = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().y * 800/480;
            //
            //            rightHand.x = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition().x * 2;
            //            rightHand.y = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition().y * 800/480;
            //
            //            neck.x = user.getJoint(JOINT_NECK).getProjectivePosition().x * 2;
            //            neck.y = user.getJoint(JOINT_NECK).getProjectivePosition().y * 800/480;
            
            map<Joint, ofPoint>::iterator it;
            for(it=userJoints.begin() ; it != userJoints.end() ; it++) {
                userJoints[it->first] = ofPoint(user.getJoint(it->first).getProjectivePosition().x*2,user.getJoint(it->first).getProjectivePosition().y*800/480);
            }
            
        }
    }
//    if (openNIDevice.getCurrentTrackedUsers().size() > 0) {
//        printf("SIZE!!!!!!!!!!!!! %lu\n", openNIDevice.getCurrentTrackedUsers().size());
//        ofxOpenNIUser & user = openNIDevice.getTrackedUser(0);
//        //printf("hihihi %d\n", user.getNumJoints());
//        for( int i = 0; i < user.getNumJoints();  ++i) {
//            //printf("DDD: %f\n", user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().x);
////            leftHand.x = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().x * 2;
////            leftHand.y = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition().y * 800/480;
////            
////            rightHand.x = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition().x * 2;
////            rightHand.y = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition().y * 800/480;
////            
////            neck.x = user.getJoint(JOINT_NECK).getProjectivePosition().x * 2;
////            neck.y = user.getJoint(JOINT_NECK).getProjectivePosition().y * 800/480;
//            
//            map<Joint, ofPoint>::iterator it;
//            for(it=userJoints.begin() ; it != userJoints.end() ; it++) {
//                userJoints[it->first] = ofPoint(user.getJoint(it->first).getProjectivePosition().x*2,user.getJoint(it->first).getProjectivePosition().y*800/480);
//            }
//            
//        }
//    }
    
//    // get number of current hands
//    numHands = openNIDevice.getNumTrackedHands();
//    
//    // iterate through users
//    for (int i = 0; i < numHands; i++){
//        
//        // get a reference to this user
//        ofxOpenNIHand & hand = openNIDevice.getTrackedHand(i);
//        
//        // get hand position
//        ofPoint & handPosition = hand.getPosition();
//        
//        ofCircle(handPosition.x * 2, handPosition.y* 800/480, 50);
//
//    }
    
    //int num= openNIDevice.getNumTrackedUsers();
    
    // draw some info regarding frame counts etc
	//ofSetColor(255, 255, 0);
    ofSetColor(255, 0, 0);
    if(isConnected) {
        map<Joint, ofPoint>::iterator it;
        for(it=RemoteUserJoints.begin() ; it != RemoteUserJoints.end() ; it++) {
            ofCircle(it->second.x, it->second.y, 50);
        }
    }
    ofSetColor(0, 0, 255);
    if(userNum > 0) {
        map<Joint, ofPoint>::iterator it;
        for(it=userJoints.begin() ; it != userJoints.end() ; it++) {
            ofCircle(it->second.x, it->second.y, 50);
        }
    }
    ofSetColor(255, 255, 255);
    flock.draw();
    
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