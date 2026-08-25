# Gravity - Geode Mod Menu

A comprehensive mod menu for Geometry Dash with 200+ toggles, featuring platform-specific UIs:
- **Mobile**: own custom style not anymore eclipse style
- **PC**: MegaHack windows-style menu

## Features

✨ **200+ Toggles including:**
- God Mode
- Practice Button Gone
- No Clip
- Instant Complete
- Speed Hacks
- Visibility Toggles
- And many more!

🎨 **Platform-Specific UIs:**
- Mobile (custom style with tabs)
- PC (MegaHack windows style panel)

💾 **Persistent Settings:** All toggle states saved automatically

## Setup

### Prerequisites
- Geode SDK v5.9.0
- CMake 3.21 or higher
- C++20 compatible compiler

### Building

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Project Structure

```
Gravity/
├── src/
│   ├── main.cpp
│   ├── menu/
│   │   ├── mobile_menu.cpp
│   │   ├── pc_menu.cpp
│   │   └── toggle_manager.cpp
│   └── toggles/
│       └── toggles.cpp
├── include/
│   ├── menu.hpp
│   ├── toggles.hpp
│   └── toggle_manager.hpp
├── CMakeLists.txt
├── mod.json
└── README.md
```

## Resources

- [Geode Documentation](https://docs.geode-sdk.org)
- [Geode GitHub](https://github.com/geode-sdk/geode)

## License

MIT License 
update soon