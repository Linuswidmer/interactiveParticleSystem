#include "particle.h"
#include "ofMain.h"

// Particle::Particle(float posX, float posY, float particleSize)
// {
//   x = posX;
//   y = posY;
//   size = particleSize;
// }

void Particle::update(float deltaTime)
{
  x += velocityX * deltaTime;
  y += velocityY * deltaTime;
}

void Particle::draw() const 
{
  ofSetColor(255);
  ofDrawCircle(x, y, size);
}


// bool Particle::isParticleOutsideWindow() 
// {
//   // Check if the particle's position is outside the window bounds
//   // Replace the condition with your desired logic, e.g., based on window size
//   if (x < 0 || x > ofGetWidth() || y < 0 || y > ofGetHeight())
//     return true;
//   else
//     return false;
// }
