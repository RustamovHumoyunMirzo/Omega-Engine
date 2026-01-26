# OmegaEngine

🚧 **OmegaEngine** is a 3D game engine written in **C++**, currently in **active development**.

This project is a work in progress and is not yet production-ready. APIs, architecture, and features may change frequently.

---

## Overview

OmegaEngine aims to become a fully featured 3D game engine with an integrated editor, modern rendering, scripting support, and a flexible plugin system.

The engine is being developed as a learning-focused but long-term project.

---

## Planned Features

- 🧩 Editor UI (ImGui-based)
- 🎮 3D scene rendering using **bgfx**
- 🗺️ Asset importing via **Assimp**
- 🧠 ECS powered by **entt**
- 🔊 Audio system using **FMOD**
- 📜 Scripting APIs:
  - C++
  - Python
  - JavaScript
  - Lua
- 🔌 Plugin system (C++ only)

---

## Dependencies

Currently, some dependencies must be provided manually.

- **ImGui**  
  Developers must download the full ImGui source code and place it into: `external/imgui`


Other dependencies will be integrated as development progresses.

---

## Build Instructions

### Requirements
- CMake ≥ 3.16
- Ninja (recommended)
- MinGW (Windows)
- C++20 compatible compiler

### Configure

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
```

For Debug builds:

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
```

**Build**

```bash
cmake --build build
```

The executable will be generated inside the `build/` directory.

**Project Status**

- 🚧 Early development

- ⚠️ Engine systems are incomplete

- 🔄 Architecture is evolving

This repository is under active development.
