#pragma once
#include <geode/Geode.hpp>

using namespace geode::prelude;

class MenuManager {
public:
    static MenuManager* get();
    
    void showMenu();
    void hideMenu();
    bool isMenuVisible() const;
    
    void updateMenuStyle(bool isMobile);
    
private:
    MenuManager();
    bool m_menuVisible = false;
    bool m_isMobileStyle = false;
};