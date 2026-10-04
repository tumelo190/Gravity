#pragma once

#include <geode/Geode.hpp>
#include "managers.hpp"

using namespace geode::prelude;

class MenuManager {
public:
    static MenuManager& get();
    
    void showMenu();
    void hideMenu();
    bool isMenuVisible() const;
    void updateMenuStyle(bool isMobile);
    
protected:
    MenuManager() = default;
    bool m_menuVisible = false;
    bool m_isMobileStyle = false;
};
