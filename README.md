# Event-Driven Entity-Component-System (ECS) Game Engine

This project is an event-driven game engine built using the Entity-Component-System (ECS) architecture in C++. It demonstrates a comprehensive understanding of ECS patterns, event-driven programming, and efficient memory management.

## Features

-   **Entity-Component-System (ECS) Architecture:**
    -   **Entity:** Represents a unique game object identifier.
    -   **Component:** Holds data attributes for entities.
    -   **System:** Contains logic to process entities with specific components.

-   **Event-Driven Design:**
    -   Implements an event bus system for communication between components and systems, promoting loose coupling and modularity.

-   **Memory Management:**
    -   Utilizes custom memory pools and manual memory control to handle allocation and deallocation efficiently, crucial for real-time performance in gaming applications.

## Core Components

-   **EntityManager:** Manages the creation, deletion, and tracking of entities and their associated components.

-   **Component:** Serves as a base class for all components, enabling polymorphic behavior and type identification.

-   **Systems:**
    -   **CollisionManager:** Detects and responds to collisions between entities.
    -   **InputManager:** Handles user input and translates it into game actions.
    -   **MovementManager:** Updates entity positions based on their velocities and other movement parameters.
    -   **PhysicsManager:** Applies physics calculations to entities, such as gravity and force applications.
    -   **TerrainManager:** Manages terrain data and interactions between entities and the terrain.

-   **Event System:**
    -   **EventManager:** Manages the subscription and broadcasting of events between systems and components.
    -   **Event:** Base class for all events, allowing for the creation of custom event types.

## How It Works

1.  **Entity Creation:** Entities are created and assigned unique identifiers.
2.  **Component Attachment:** Components are attached to entities to define their data attributes.
3.  **System Processing:** Systems process entities with specific components each frame.
4.  **Event Handling:** Events are emitted and handled by subscribed systems to facilitate communication and trigger actions.

## Getting Started

### Prerequisites

-   C++17 compatible compiler
-   CMake 3.10 or higher

### Building the Project

1.  Clone the repository:

    ```bash
    git clone [https://github.com/JackLaingDev/gameEngine.git](https://github.com/JackLaingDev/gameEngine.git)
    ```

2.  Navigate to the project directory:

    ```bash
    cd gameEngine
    ```

3.  Create a build directory:

    ```bash
    mkdir build && cd build
    ```

4.  Run CMake to configure the project:

    ```bash
    cmake ..
    ```

5.  Build the project:

    ```bash
    make
    ```

### Running the Engine

After building, execute the engine binary located in the build directory:

```bash
./gameEngine
