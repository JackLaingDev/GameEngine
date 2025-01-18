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
- **SFML** (For GUI Rendering)

  ## Installation (SFML)

This project uses the SFML library for graphics, window management, and other functionalities. To build and run this project, you'll need to install SFML on your Windows system.

1.  **Download SFML:**
    *   Visit the SFML download page: [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)
    *   Download the pre-built binaries for Windows that match your compiler version (e.g., Visual Studio 2022). It's recommended to download both the 32-bit and 64-bit versions for wider compatibility.

2.  **Extract the Archive:**
    *   Extract the downloaded archive to a convenient location on your system. A common location is a dedicated folder for libraries (e.g., `C:\libs\SFML` or `C:\Users\<YourUsername>\libs\SFML`).

3.  **Configure Your Project (Visual Studio Example):**
    *   Open your Visual Studio project.
    *   Right-click on your project in the Solution Explorer and select **Properties**.

    *   **Configuration Manager:** In the top dropdown, make sure you've selected either `Debug` or `Release` and the correct platform (`x64` or `Win32`). You'll need to repeat the following steps for each configuration/platform combination.

    *   **Include Directories:**
        *   Navigate to **C/C++** -> **General**.
        *   Under **Additional Include Directories**, add the path to the SFML `include` directory. For example: `C:\libs\SFML\include`.

    *   **Library Directories:**
        *   Go to **Linker** -> **General**.
        *   Under **Additional Library Directories**, add the path to the SFML `lib` directory. For example: `C:\libs\SFML\lib`.

    *   **Linker Input (Additional Dependencies):**
        *   Go to **Linker** -> **Input**.
        *   Under **Additional Dependencies**, add the names of the SFML libraries you need. Use the correct libraries for your configuration (Debug/Release and 32/64 bit):

            *   **Debug (32-bit):**
                ```
                sfml-graphics-d.lib
                sfml-window-d.lib
                sfml-system-d.lib
                sfml-main-d.lib
                ```
            *   **Release (32-bit):**
                ```
                sfml-graphics.lib
                sfml-window.lib
                sfml-system.lib
                sfml-main.lib
                ```
            *   **Debug (64-bit):**
                ```
                sfml-graphics-d.lib
                sfml-window-d.lib
                sfml-system-d.lib
                sfml-main-d.lib
                ```
            *   **Release (64-bit):**
                ```
                sfml-graphics.lib
                sfml-window.lib
                sfml-system.lib
                sfml-main.lib
                ```
        *   If you are using other SFML modules (audio, network), add the corresponding libraries (e.g., `sfml-audio-d.lib`, `sfml-network-d.lib`).

4.  **Copy DLLs (Dynamic Linking):**
    *   Copy the necessary DLL files from the SFML `bin` directory to the same directory where your executable (`.exe`) is built (usually `Debug` or `Release` folders inside your project directory). Use the correct DLLs for your configuration (Debug/Release and 32/64 bit).
        *   **Debug:** `sfml-graphics-d-2.dll`, `sfml-window-d-2.dll`, `sfml-system-d-2.dll`, `sfml-main-d-2.dll`
        *   **Release:** `sfml-graphics-2.dll`, `sfml-window-2.dll`, `sfml-system-2.dll`, `sfml-main-2.dll`
    *   If you're using other modules, copy their DLLs as well.

### Building

Clone the repository and build the engine with CMake:

```bash
git clone https://github.com/yourusername/ecs-game-engine.git
cd ecs-game-engine
mkdir build
cd build
cmake ..
make
