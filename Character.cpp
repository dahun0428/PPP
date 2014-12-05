#include "Character.h"

double Character::getSpeed() {return speed;}
double Character::getAccuracy() {return accuracy;}
double Character::getIntelligence() {return intelligence;}

Character::Character() {
    speed = 1.3;
    accuracy = 3.0;
    intelligence = 3.0;
}
Character::~Character() {}

Pobba::Pobba() {
    speed = 2.0;
    accuracy = 4.5;
    intelligence = 3.0;
}
Pobba::~Pobba() {}

Kaiser::Kaiser() {
    speed = 2.4;
    accuracy = 4.0;
    intelligence = 3.0;
}
Kaiser::~Kaiser() {}

Swimmer::Swimmer() {
    speed = 10.0;
    accuracy = 3.0;
    intelligence = 3.0;
}
Swimmer::~Swimmer() {}

Physics::Physics() {
    speed = 1.3;
    accuracy = 5.0;
    intelligence = 4.0;
}
Physics::~Physics() {}

Depttop::Depttop() {
    speed = 1.3;
    accuracy = 3.0;
    intelligence = 6.0;
}
Depttop::~Depttop() {}

Kaist::Kaist() {
    speed = 1.8;
    accuracy = 4.0;
    intelligence = 4.5;
}
Kaist::~Kaist() {}

Unist::Unist() {
    speed = 2.5;
    accuracy = 4.5;
    intelligence = 4.5;
}
Unist::~Unist() {}

Gist::Gist() {
    speed = 3.4;
    accuracy = 5.0;
    intelligence = 4.0;
}
Gist::~Gist() {}
