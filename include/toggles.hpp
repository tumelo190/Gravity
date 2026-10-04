#pragma once

#include <string>
#include <vector>
#include <array>

enum class ToggleCategory {
    Gameplay,
    Movement,
    Visual,
    Speed,
    Practice,
    Utility,
    Audio,
    HUD,
    Bots,
    Interface,
    Misc
};

struct ToggleEntry {
    const char* id;
    const char* name;
    ToggleCategory category;
    bool enabled;
    const char* description;
};

struct InterfaceTheme {
    const char* id;
    const char* name;
    const char* primaryColor;
    const char* secondaryColor;
    const char* accentColor;
    const char* textColor;
};

class ToggleManager {
public:
    static ToggleManager& get() {
        static ToggleManager instance;
        return instance;
    }

    void init();
    ToggleEntry* find(const char* id);
    void set(const char* id, bool state);
    bool get(const char* id) const;
    const std::vector<ToggleEntry>& all() const;
    std::vector<ToggleEntry> getByCategory(ToggleCategory cat) const;
    void saveSettings();
    void loadSettings();

private:
    std::vector<ToggleEntry> m_toggles;
};

class InterfaceThemeManager {
public:
    static InterfaceThemeManager& get() {
        static InterfaceThemeManager instance;
        return instance;
    }

    void init();
    const std::array<InterfaceTheme, 45>& getAllThemes() const { return m_themes; }
    const InterfaceTheme& getTheme(int index) const;
    const InterfaceTheme& getThemeById(const char* id) const;
    void setCurrentTheme(int index);
    int getCurrentThemeIndex() const { return m_currentTheme; }

private:
    std::array<InterfaceTheme, 45> m_themes{};
    int m_currentTheme = 0;
};
