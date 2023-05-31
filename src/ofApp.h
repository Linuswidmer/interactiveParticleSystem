#pragma once

#include "ofMain.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:
   
    // when we are working with a vector we do not have to initialize it nut we can
    ofApp() 
    {
      particles.push_back(Particle(ofGetWidth() /2, ofGetHeight() / 2, 20));  
    }
    // ofApp() : particle(0,0,0) {} // we have to provide a constructor for the ofApp for the member particle
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

  private:
    // Particle particle  
    vector<Particle> particles;
};
