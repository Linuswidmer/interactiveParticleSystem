#include "particle.h"
#include "ofMain.h"

// Particle::Particle(float posX, float posY, float particleSize)
// {
//   x = posX;
//   y = posY;
//   size = particleSize;
// }

void Particle::moveRight(float deltaTime)
{
  x += velocityX * deltaTime;
  y += velocityY * deltaTime;
}

void Particle::moveCenter(vector<Particle>& particles)
{
  int centerX;
  int centerY;
  int moveX;
  int moveY;

  centerX = ofGetWidth() / 2;
  centerY = ofGetHeight() /2;
  moveX = (centerX- x) / 50;
  moveY = (centerY - y) / 50;

   for (auto& other : particles) {
        if (this != &other && !checkCollision(other, moveX, moveY)) {
            // Handle collision with 'other' particle
            // Adjust positions, velocities, or take any other necessary action
            x += moveX;
            y += moveY;
        }
    }
}

void Particle::followMousePos(int mouseX, int mouseY)
{
  int moveX;
  int moveY;

  moveX = (mouseX - x) / 20;
  moveY = (mouseY - y) / 20;
  x += moveX;
  y += moveY;
}

void Particle::draw() const 
{
  ofSetColor(255);
  ofDrawCircle(x, y, size);
}

bool Particle::checkCollision(const Particle& other, int moveX, int moveY) const 
{
  // Calculate the distance between the centers of the two particles
  float distance = ofDist(x + moveX, y + moveY, other.x, other.y);
        
  // Check if the distance is less than the sum of their radii
  if (distance < size + other.size) 
  {
    return true; // Collision detected
  }      
  return false; // No collision
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
