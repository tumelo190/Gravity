#pragma once

#include <geode/Geode.hpp>
#include <cocos2d.h>
#include <vector>
#include <string>

#include "managers.hpp"

using namespace geode::prelude;

enum class MenuPlatform {
    Mobile,
    PC
};

class MenuManager {
public:
    static MenuManager& get();

    void showMenu();
    void hideMenu();
    bool isMenuVisible() const { return m_menuVisible; }
    void updateMenuStyle(bool isMobile);
    void setPlatform(MenuPlatform platform);

    // UI callbacks
    void onTabSelected(CCObject* sender);
    void onTogglePressed(CCObject* sender);

    CCLayer* getLayer() const { return m_menuLayer; }

private:
    MenuManager();

    bool m_menuVisible = false;
    bool m_isMobileStyle = false;
    MenuPlatform m_platform = MenuPlatform::Mobile;

    CCLayer* m_menuLayer = nullptr;
    CCLayer* m_mobilePanel = nullptr;
    CCLayer* m_pcPanel = nullptr;

    void buildMobileMenu();
    void buildPCMenu();
    void rebuildMenu();
    void addHeader(CCLayer* parent, const std::string& title);
    void addToggleRow(CCLayer* parent, const std::string& name, float yPos);
};
