#pragma once

class DragonInterface {
public:
  virtual void Roar() = 0;
  virtual void BreathFire() = 0;
  virtual void Bite() = 0;
  virtual void Claw() = 0;
  virtual void ClubWithTail() = 0;
  virtual void FlyAway() = 0;
  virtual void Die() = 0;
};
