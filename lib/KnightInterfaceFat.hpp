#pragma once

class DragonInterface;

class KnightInterface {
public:
  virtual void Scream() = 0;
  virtual void RunAway() = 0;
  virtual void Block() = 0;
  virtual void Attack() = 0;
  virtual void Die() = 0;
  virtual void Engage(DragonInterface *dragon) = 0;
};