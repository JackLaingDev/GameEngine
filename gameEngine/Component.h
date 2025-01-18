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
class HealthComponent : public Component {
private:

public:
	int health;

	HealthComponent(int health);
};



#endif 
