#include "GameObj.h"



void Player::print() const{
  std::cout << "Player " << getName() << ", ma: " << Character::hp();
}


void Bomb::print() const{

  std::cout << "Jego uderzenie odbiera: " << Hurting::hp();

}

void Boss::print() const{

  std::cout << "Bad Guy: " << getName() << ", ma: " << Character::hp() << "\nJego uderzenie odbiera: " <<  Hurting::hp();
}