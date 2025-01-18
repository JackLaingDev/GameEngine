# Event-Driven ECS Game Engine

This project is an event-driven game engine built using the **Entity-Component-System (ECS)** architecture in **C++**. The primary goal of this engine is to demonstrate an understanding of **ECS systems**, **memory management**, and **event-driven programming**.

## Features

- **Entity-Component-System (ECS)** Architecture: 
  - Separate data (components) and behavior (systems) for better flexibility and performance.
  - Efficient management of game entities and their attributes.
  
- **Event-Driven Design**: 
  - The engine uses events to trigger actions and communicate between different parts of the system.
  - Decouples systems for better modularity and scalability.
  
- **Memory Management**: 
  - Manual memory management is employed to demonstrate handling raw memory allocation and deallocation for optimal performance.
  - Implements custom memory pools, and allocators for controlling memory usage.

## How It Works

### Entity-Component-System (ECS)

- **Entity**: Represents a unique identifier for an object in the game. It doesn't contain any behavior or data on its own but can be associated with one or more components.
  
- **Component**: Contains data that defines the state of an entity. For example, a `PositionComponent` could hold position coordinates (`x`, `y`), and a `RenderComponent` could hold information about the entity's appearance.
  
- **System**: Contains logic to process entities that have specific components. A system will update entities with the required components every frame or in response to events.

### Event-Driven Programming

The engine uses an event queue to handle interactions between systems and entities. Events are dispatched in response to certain triggers, and each system subscribes to specific events to process them.

### Memory Management

Memory management is handled manually using custom allocators and memory pools:
- **Custom Allocators**: Memory is allocated and deallocated through custom allocators to ensure that memory is handled efficiently and predictably.
- **Memory Pools**: Group components of the same type into memory pools for faster access and to minimize fragmentation.

## Getting Started

### Prerequisites

To run and build this engine, you need the following:

- **C++ Compiler** (supporting C++11 or later)
- **CMake** for building the project
- **Google Test** (optional, for testing)

### Building

Clone the repository and build the engine with CMake:

```bash
git clone https://github.com/yourusername/ecs-game-engine.git
cd ecs-game-engine
mkdir build
cd build
cmake ..
make
