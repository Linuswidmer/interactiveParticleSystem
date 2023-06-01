#pragma once

#include "ofAppRunner.h"

class Particle {
  public:
  Particle(float posX, float posY, float particleSize)
    : x(posX), y(posY), size(particleSize), velocityX(30.0f), velocityY(30.0f)
    {}

  // void update(float deltaTime);
  void moveRight(float deltaTime);
  // void moveCenter(vector<Particle>& particles);
  void moveCenter(std::vector<Particle>& particles);
  void followMousePos(int mouseX, int mouseY);
  bool checkCollision(const Particle& other, int moveX, int moveY) const;
  void draw() const;

  // bool isParticleOutsideWindow() const;
  bool isParticleOutsideWindow() const {
        // Check if the particle's position is outside the window bounds
        // Replace the condition with your desired logic, e.g., based on window size
        if (x < 0 || x > ofGetWidth() || y < 0 || y > ofGetHeight()) {
            return true;
        }
        return false;
    }

  private:
    float x;
    float y;
    float size;
    float velocityX;
    float velocityY;
};
