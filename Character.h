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
    Kaiser();
    ~Kaiser();
};
class Swimmer : public Character {
    Swimmer();
    ~Swimmer();
};
class Physics : public Character {
    Physics();
    ~Physics();
};
class Depttop : public Character {
    Depttop();
    ~Depttop();
};

class KAIST : public Character {
    KAIST();
    ~KAIST();
};
class UNIST : public Character {
    UNIST();
    ~UNIST();
};
class GIST : public Character {
    GIST();
    ~GIST();
};

#endif // CHARACTER_H
