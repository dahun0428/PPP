#include "Character.h"

double Character::getSpeed() {return speed;}
double Character::getAccuracy() {return accuracy;}
double Character::getIntelligence() {return intelligence;}

Character::Character() {
    speed = 3.0;
    accuracy = 3.0;
    intelligence = 3.0;
}
Character::~Character() {}

Pobba::Pobba() {
    speed = 4.5;
    accuracy = 4.5;
    intelligence = 3.0;
}
Pobba::~Pobba() {}

Kaiser::Kaiser() {
    speed = 5.0;
    accuracy = 4.0;
    intelligence = 3.0;
}
Kaiser::~Kaiser() {}

Swimmer::Swimmer() {
    speed = 6.0;
    accuracy = 3.0;
    intelligence = 3.0;
}
Swimmer::~Swimmer() {}

Physics::Physics() {
    speed = 3.0;
    accuracy = 5.0;
    intelligence = 4.0;
}
Physics::~Physics() {}

Depttop::Depttop() {
    speed = 3.0;
    accuracy = 3.0;
    intelligence = 6.0;
}
Depttop::~Depttop() {}

KAIST::KAIST() {
    speed = 4.0;
    accuracy = 4.0;
    intelligence = 4.0;
}
KAIST::~KAIST() {}

UNIST::UNIST() {
    speed = 4.5;
    accuracy = 4.5;
    intelligence = 4.5;
}
UNIST::~UNIST() {}

GIST::GIST() {
    speed = 5.0;
    accuracy = 5.0;
    intelligence = 5.0;
}
GIST::~GIST() {}
