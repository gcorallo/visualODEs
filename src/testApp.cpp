 #include "testApp.h"
 #include "gui.h"
 #include <vector>

void testApp::setup(){

     // cout << "hola"<< endl;
     //cout << "hola2"<< endl;
    ofSetFrameRate(100);

    //Gui setup
    controls = ofxGui::Instance(this);
    setupControls();

    receiver.setup(PORT);

    N_particles = 5000;
    system.setup(N_particles);
    visual.setup(&system);

    drop = 0;
    guiOn=false;

}


void testApp::update(){

    //cout <<"c"<< endl;
    if(ofGetMousePressed(0))
    {
        if(drop>=N_particles)
            drop = 0;

        //system.p[drop].life = 0.6;
        system.p[drop].pos.set((float)mouseX/ofGetWidth()*4.0-2,(float)mouseY/ofGetHeight()*4.0-2);

        drop++;
    }


    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);

        string address = m.getAddress();

        if (address=="/visualODEs/maxVel")
        {
             visual.maxVel = m.getArgAsFloat(0);
        }
        else
            system.OscMessage(&m);
    }

    system.update();
}


void testApp::draw(){

    ofBackground(0);

    visual.displayParticles();

    //Gui Draw
    if(guiOn)
        controls->draw();
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if(key=='r')
        system.reset();

    if(key=='c')
        guiOn=!guiOn;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if(guiOn)
        controls->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(guiOn)
        controls->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if(guiOn)
        controls->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
