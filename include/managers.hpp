#pragma once

#include <geode/Geode.hpp>
#include <vector>
#include <string>

using namespace geode::prelude;

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
    std::string id;
    std::string name;
    ToggleCategory category;
    bool enabled;
    std::string description;
};

struct InterfaceTheme {
    std::string id;
    std::string name;
    std::string primaryColor;
    std::string secondaryColor;
    std::string accentColor;
    std::string textColor;
};

class ToggleManager {
public:
    static ToggleManager& get();
    
    void init();
    ToggleEntry* find(const std::string& id);
    void set(const std::string& id, bool state);
    bool get(const std::string& id) const;
    const std::vector<ToggleEntry>& all() const;
    std::vector<ToggleEntry> getByCategory(ToggleCategory cat) const;
    void saveSettings();
    void loadSettings();
    size_t getTotalCount() const { return m_toggles.size(); }

private:
    ToggleManager() = default;
    std::vector<ToggleEntry> m_toggles;
};

class ThemeManager {
public:
    static ThemeManager& get();
    
    void initMobileThemes(); // 45 themes
    void initPCThemes();     // 10 themes
    const std::vector<InterfaceTheme>& getAllThemes() const;
    const InterfaceTheme& getTheme(size_t index) const;
    const InterfaceTheme& getThemeById(const std::string& id) const;
    void setCurrentTheme(size_t index);
    size_t getCurrentThemeIndex() const { return m_currentTheme; }
    bool isMobileTheme() const { return m_isMobileTheme; }

private:
    ThemeManager() = default;
    std::vector<InterfaceTheme> m_themes;
    size_t m_currentTheme = 0;
    bool m_isMobileTheme = true;
};
