#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofEnableSmoothing();
    ofSetupScreenOrtho();
    ofEnableDepthTest();
    ofSetVerticalSync( true );

    isPdfRendering = false;

    gui = new ofxUISuperCanvas("MAD SPIRY");
    gui->addSpacer();
    gui->addFPSSlider("FPS SLIDER");

    initPyramids();
}

void ofApp::initPyramids()
{
    pyrs2d.clear();
    for( int i = 0; i < 70; i++ )
    {
        shared_ptr< Pyramid2D > pyr = shared_ptr< Pyramid2D > (
            new Pyramid2D(
                ofVec2f( ofRandomWidth(), ofRandomHeight() ),
                6 + ofRandomuf() * 10,
                static_cast< int > ( ofRandomuf() * 50 ),
                ofRandomf(),
                ofRandomf() * 2
            ));
        for( int j = 0; j < 80; j++ )
        {
            pyr->addLayer();
        }
        pyrs2d.push_back( pyr );
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


    if( isPdfRendering )
    {
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    }

    ofBackground( 127 );
    for( std::vector< shared_ptr< Pyramid2D > >::iterator it = pyrs2d.begin(); it != pyrs2d.end(); ++it )
    {
        ( * it )->draw();
    }

    if( isPdfRendering )
    {
        ofEndSaveScreenAsPDF();
        isPdfRendering = false;
    }
}

void ofApp::guiEvent(ofxUIEventArgs & a )
{

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch( key )
    {
    case 'e':
        isPdfRendering = !isPdfRendering;
        ofExit();
        break;
    case 'r':
        initPyramids();
        break;
    }
}
