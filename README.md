# Gravity - Advanced Mod Menu

A powerful custom mod menu for Geometry Dash with **200+ toggles on Mobile** and **160 toggles on PC**, featuring platform-specific UIs and extensive customization options.

## 🎮 Platform Support

- **Mobile**: Custom tab-based interface with 200+ toggles
- **PC**: MegaHack windows-style panel with 160 toggles

## ✨ Features

### **Gameplay Toggles (35+)**
- God Mode, No Clip, Instant Complete
- Fly Mode, Auto Jump, Auto Tap
- Slow Motion, Frame Advance, Freeze Game
- Gravity Control (Anti-Gravity, Mega Gravity)
- And 25+ more gameplay modifiers

### **Movement System (25+)**
- Gravity Control (Off, Low, High)
- Jump Variants (Double, Triple, Wall Jump)
- Dash Abilities, Phase Through, Swim Mode
- Wall Climbing, Teleport Jump, Speed Burst
- Advanced momentum and velocity controls

### **Visual Effects (35+)**
- Hide UI/HUD elements selectively
- Player customization (Giant, Tiny, Transparent, Glow)
- Trail effects (Rainbow, Thick, Hidden)
- Color modes (Dark, Light, Grayscale, Inverted, Sepia, Neon)
- Object visibility toggles (Spikes, Platforms, Enemies, Background)

### **Speed Control (20+)**
- Speed modifiers (0.25x to 4x)
- Custom speed settings
- Animation & Physics speed control
- Particle & Scroll speed adjustment

### **Practice Mode (15+)**
- Checkpoint system with save/load
- Infinite attempts
- Death counter & Timer display
- Ghost recording and playback
- Segment jumping and markers

### **Utilities (20+)**
- Auto-save system
- Quick restart & Level skip
- Free Play & Sandbox mode
- Editor tools with NoClip
- Object spawn/delete/copy/paste
- Camera tools, Grid snap, Layer control

### **Audio System (10+)**
- Selective muting (All, Music, SFX)
- Volume control & Equalizer
- 3D surround sound
- Pitch & Fade controls

### **Bot System (15+)**
- Click Bot & Macro Bot
- AI & Physics simulation
- Perfect & Timing bots
- Path finder & Collision avoidance
- Speed runner & Replay bot
- Learning & Multi-bot support

### **Interface Customization (20+)**
- 45 mobile themes (Crimson, Emerald, Neon, Rainbow, Matrix, etc.)
- 10 PC themes (Classic MegaHack, Dark Mode, Cyber Purple, etc.)
- Menu position, size, and opacity control
- Search bar & Favorites panel
- Keyboard shortcuts & Controller support

### **Miscellaneous (20+)**
- Fullscreen & VSync control
- Graphics effects (Anti-aliasing, Motion Blur, Bloom, etc.)
- Performance monitoring (FPS, Stats, Memory)
- Battery Saver mode
- Debug mode & Developer tools

## 🎨 UI Features

### Mobile Version
- **Tab Navigation**: Main, Gameplay, Movement, Visual, Speed, Practice, Utility
- **Scrollable Toggle List**: View all 200+ toggles with smooth scrolling
- **Floating Action Button**: Draggable "G" button with pulsing glow
- **45 Themes**: Extensive color customization for mobile

### PC Version
- **Centered Window Panel**: Classic MegaHack-style interface
- **Sidebar Categories**: Organized toggle categories
- **160 Visible Toggles**: Optimized for PC display
- **10 Professional Themes**: Dark/Light modes and specialty themes

## 🔧 Technical Details

### Architecture
```
Gravity/
├── src/
│   ├── main.cpp                 # Entry point
│   ├── menu.cpp                 # Menu UI management
│   ├── managers.cpp             # Toggle, Theme managers (245+ toggles/55 themes)
│   ├── floating_button.cpp      # FAB with drag & animations
│   └── toggles/                 # Toggle implementations
├── include/
│   ├── menu.hpp                 # Menu interface
│   ├── managers.hpp             # Manager definitions
│   └── floating_button.hpp      # FAB definition
├── CMakeLists.txt
├── geode.json
├── mod.json
└── build scripts
```

### Key Components

**MenuManager**
- Handles mobile/PC UI switching
- Manages menu visibility and layering
- Supports platform detection and theme application

**ToggleManager**
- 245 total toggles organized by category
- Mobile: 200 toggles, PC: 160 toggles
- Persistent state saving/loading
- Category filtering system

**ThemeManager**
- 45 mobile themes with custom color schemes
- 10 PC themes (MegaHack compatible)
- Dynamic theme switching

**FloatingButton**
- Draggable FAB with physics-based edge snapping
- Pulsing animation with gradient circles
- Touch-enabled with tap/drag distinction

## 📋 Toggle Categories

1. **Gameplay** (35) - Core game mechanics
2. **Movement** (25) - Player movement modifiers
3. **Visual** (35) - Graphics and appearance
4. **Speed** (20) - Speed multipliers
5. **Practice** (15) - Practice mode features
6. **Utility** (20) - Helper tools
7. **Audio** (10) - Sound controls
8. **Bots** (15) - Automation features
9. **Interface** (20) - UI customization
10. **Misc** (20) - Graphics effects & settings

## 🛠️ Build Instructions

### Prerequisites
- C++20 compatible compiler
- CMake 3.21 or higher
- Geode SDK

### Compilation
```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

## 📱 Usage

1. **Launch Gravity** - Tap the floating "G" button
2. **Navigate Tabs** - Switch between categories (mobile)
3. **Toggle Features** - Tap checkboxes to enable/disable
4. **Customize Theme** - Access settings for color options
5. **Save Settings** - Use SAVE/LOAD buttons for persistence

## 🎨 Customization

### Mobile Themes
Crimson, Emerald, Sapphire, Neon Cyan, Gold, Purple Pulse, Sunset, Midnight, Matrix, Ghost White, Dark Blue, Coral, Aqua, Lime, Rose, Violet, Orange, Ice, Lava, Arctic, Electric, Plasma, Forest, Space, Pink, Red, Blue, Green, Yellow, Magenta, Rainbow, Steam, Moonlight, Shadow, Heatwave, Flash, Holo, Chrome, Frosted, Soft Gray, Dark Gold, Cyber, Obsidian, Neon Pink, Neon Green, Neon Blue

### PC Themes
Classic MegaHack, Modern UI, Dark Mode, Light Mode, Neon Bright, Midnight Blue, Cyber Purple, Hacker Green, Sunset Orange, Ice Blue

## 📊 Statistics

- **Total Toggles**: 245
- **Mobile Toggles**: 200+
- **PC Toggles**: 160
- **Mobile Themes**: 45
- **PC Themes**: 10
- **Categories**: 10
- **Code Lines**: 6000+

## 🔐 License

Apache License 2.0 - See LICENSE file for details

## 📚 Resources

- [Geometry Dash](https://www.robtopgames.com/)
- Custom development framework
- Community-driven mod features

## 🤝 Contributing

This is a personal development project. Suggestions and improvements are welcome!

## 📝 Version

**Current**: 1.8.0 - Feature complete with all systems implemented

---

**Status**: In Active Development ✅

Last Updated: October 2026