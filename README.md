# Event-Driven Entity-Component-System (ECS) Game Engine

This project is an event-driven game engine built using the Entity-Component-System (ECS) architecture in C++. It demonstrates ECS patterns, event-driven programming, and efficient memory management.

## Features

- **Entity-Component-System (ECS) Architecture:**
  - **Entity:** Represents unique game object identifiers.
  - **Component:** Stores data attributes for entities.
  - **System:** Processes entities with specific components.

- **Event-Driven Design:**
  - Implements an event bus for communication between components and systems, enhancing modularity.

- **Memory Management:**
  - Custom memory pools and manual control ensure optimal performance for real-time game scenarios.

## Core Components

- **EntityManager:** Manages creation, deletion, and tracking of entities and components.

- **Component:** Base class for all components, allowing polymorphism.

- **Systems:**
  - **CollisionManager:** Handles collision detection.
  - **InputManager:** Manages user input.
  - **MovementManager:** Updates entity positions.
  - **PhysicsManager:** Applies physics simulations.
  - **TerrainManager:** Manages terrain interactions.

- **Event System:**
  - **EventManager:** Handles event subscription and broadcasting.
  - **Event:** Base class for custom event types.

## Installation and Setup

### Prerequisites
- C++17 compatible compiler
- CMake 3.10 or higher
- SFML 3.0.0

### Installing SFML 3.0.0

#### Windows
1. Download pre-compiled binaries for SFML 3.0.0 from [SFML Website](https://www.sfml-dev.org/download.php).
2. Extract to a folder, e.g., `C:\SFML`.
3. Add SFML include and lib paths in your project settings.

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get install libsfml-dev
```

#### macOS
Install via Homebrew:
```bash
brew install sfml
```

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/JackLaingDev/gameEngine.git
   ```
2. Navigate to the project:
   ```bash
   cd gameEngine
   ```
3. Create build directory:
   ```bash
   mkdir build && cd build
   ```
4. Configure the project:
   ```bash
   cmake .. -DSFML_DIR="path/to/SFML"
   ```
5. Build the project:
   ```bash
   make
   ```

### Running the Engine

Execute the binary located in the build directory:
```bash
./gameEngine
```

## Contributing

Contributions are welcome! Fork the repository and submit pull requests.

## License

Licensed under the MIT License. See [LICENSE.txt](LICENSE.txt) for details.
