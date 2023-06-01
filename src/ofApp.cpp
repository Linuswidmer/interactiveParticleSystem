#include "ofApp.h"
#include "particle.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

  int mouseX;
  int mouseY;

  mouseX = ofGetMouseX();
  mouseY = ofGetMouseY();

  float deltaTime = ofGetLastFrameTime();

  particles.erase(std::remove_if(particles.begin(), particles.end(), [](const Particle& particle) {
    return particle.isParticleOutsideWindow();
}), particles.end());


  // for (int i = 0; i < particles.size(); i++) {
  //       for (int j = i + 1; j < particles.size(); j++) {
  //           if (particles[i].checkCollision(particles[j])) {
  //             particles[i].followMousePos(mouseX, mouseY);
  //           }
  //       }
  //   }

  for (int i = 0; i < particles.size(); i++)
  {
    particles[i].moveCenter(particles);
    // particles[i].followMousePos(mouseX, mouseY);
  }
  // for (auto& particle : particles)
  // {
  //   particle.followMousePos(mouseX, mouseY);
  //   // particle.moveRight(deltaTime);
  // }
}

//--------------------------------------------------------------
void ofApp::draw(){
  // auto is a placeholder for the type of a varibale
  // the following loop is iterating over the vector particles, each element it
  // assesses is called particle. So for each iteration it draws the particle
  for(const auto& particle : particles) 
  {
    particle.draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == ' ')
  {
    // particle = Particle(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 20);
    Particle newParticle(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 20);
    particles.push_back(newParticle);
  }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
