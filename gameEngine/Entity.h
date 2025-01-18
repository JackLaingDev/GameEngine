#ifndef Entity_H 
#define Entity_H

#include <iostream> 

// Class declaration
class Entity {
private:
    int id;

public:
    explicit Entity(int id);
    ~Entity();

    int getId();
    
};

#endif 
