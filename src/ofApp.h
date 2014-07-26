#pragma once

#include "ofMain.h"
#include "Pyramid2D.h"
#include "ofxUI.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    protected:
        void initPyramids();
    private:
        std::vector< shared_ptr< Pyramid2D > > pyrs2d;

        ofxUISuperCanvas * gui;
        void guiEvent(ofxUIEventArgs &e);

        bool isPdfRendering;
};
