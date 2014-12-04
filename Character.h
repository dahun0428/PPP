#ifndef CHARACTER_H
#define CHARACTER_H
#include "Global.h"

class Character {
public:
    Character();
    ~Character();
    double getSpeed();
    double getAccuracy();
    double getIntelligence();
protected:
    double speed;
    double accuracy;
    double intelligence;
};

class Pobba : public Character {
public:
    Pobba();
    ~Pobba();
};
class Kaiser : public Character {
public:
    Kaiser();
    ~Kaiser();
};
class Swimmer : public Character {
public:
    Swimmer();
    ~Swimmer();
};
class Physics : public Character {
public:
    Physics();
    ~Physics();
};
class Depttop : public Character {
public:
    Depttop();
    ~Depttop();
};

class Kaist : public Character {
public:
    Kaist();
    ~Kaist();
};
class Unist : public Character {
public:
    Unist();
    ~Unist();
};
class Gist : public Character {
public:
    Gist();
    ~Gist();
};

#endif // CHARACTER_H
