#ifndef Component_H 
#define Component_H

#include <iostream> 

// Class declaration
class Component {
private:


public:
	virtual ~Component() = default;

};

// Public inheritance to allow usage of ~Component
// Health Component to store entity health
class HealthComponent : public Component {
private:

public:
	int health;

	HealthComponent(int health);
};

//
class VelocityComponent : public Component {
private: 

public:


};

//
class PositionComponent : public Component {
private:

public:


};

//
class ColliderComponent : public Component {
private:

public:


};

//
class TerrainColliderComponent : public Component {
private:

public:


};

//
class PlayerComponent : public Component {
private:

public:


};

//
class EnemyComponent : public Component {
private:

public:


};



#endif 
