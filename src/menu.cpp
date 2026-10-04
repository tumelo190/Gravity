#include "../include/menu.hpp"

MenuManager& MenuManager::get() {
    static MenuManager instance;
    return instance;
}

MenuManager::MenuManager() {
    m_menuVisible = false;
    m_isMobileStyle = true;
}

void MenuManager::setPlatform(MenuPlatform platform) {
    m_platform = platform;
    rebuildMenu();
}

void MenuManager::updateMenuStyle(bool isMobile) {
    m_isMobileStyle = isMobile;
    rebuildMenu();
}

void MenuManager::showMenu() {
    if (!m_menuLayer) {
        rebuildMenu();
    }
    m_menuVisible = true;
    if (m_menuLayer) {
        m_menuLayer->setVisible(true);
    }
}

void MenuManager::hideMenu() {
    m_menuVisible = false;
    if (m_menuLayer) {
        m_menuLayer->setVisible(false);
    }
}

void MenuManager::rebuildMenu() {
    if (!m_menuLayer) {
        m_menuLayer = CCLayer::create();
        if (auto scene = CCDirector::sharedDirector()->getRunningScene()) {
            scene->addChild(m_menuLayer, 999);
        }
    }

    if (m_mobilePanel) {
        m_menuLayer->removeChild(m_mobilePanel, true);
        m_mobilePanel = nullptr;
    }
    if (m_pcPanel) {
        m_menuLayer->removeChild(m_pcPanel, true);
        m_pcPanel = nullptr;
    }

    if (m_isMobileStyle) {
        buildMobileMenu();
    } else {
        buildPCMenu();
    }
}

void MenuManager::buildMobileMenu() {
    m_mobilePanel = CCLayer::create();
    m_menuLayer->addChild(m_mobilePanel);

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto bg = CCLayerColor::create(ccc4(10, 12, 25, 210), winSize.width * 0.82f, winSize.height * 0.72f);
    bg->setPosition(ccp(winSize.width * 0.09f, winSize.height * 0.14f));
    m_mobilePanel->addChild(bg);

    auto title = CCLabelTTF::create("Gravity", "Arial-BoldMT", 26);
    title->setColor(ccc3(255, 255, 255));
    title->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.8f));
    m_mobilePanel->addChild(title);

    auto tabBar = CCLayerColor::create(ccc4(29, 35, 52, 255), winSize.width * 0.72f, 38);
    tabBar->setPosition(ccp(winSize.width * 0.14f, winSize.height * 0.72f));
    m_mobilePanel->addChild(tabBar);

    const std::vector<std::string> tabs = {
        "Main", "Gameplay", "Movement", "Visual", "Speed", "Practice", "Utility"
    };

    float x = winSize.width * 0.18f;
    for (size_t i = 0; i < tabs.size(); ++i) {
        auto button = CCLabelTTF::create(tabs[i].c_str(), "Arial", 14);
        button->setColor(ccc3(220, 220, 220));
        button->setPosition(ccp(x + static_cast<float>(i) * 62.0f, winSize.height * 0.72f + 18.0f));
        m_mobilePanel->addChild(button);
    }

    int index = 0;
    for (const auto& toggle : ToggleManager::get().all()) {
        if (index >= 15) break;
        addToggleRow(m_mobilePanel, toggle.name, winSize.height * 0.66f - static_cast<float>(index) * 24.0f);
        ++index;
    }
}

void MenuManager::buildPCMenu() {
    m_pcPanel = CCLayer::create();
    m_menuLayer->addChild(m_pcPanel);

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto bg = CCLayerColor::create(ccc4(20, 22, 27, 240), 720, 470);
    bg->setPosition(ccp((winSize.width - 720) * 0.5f, (winSize.height - 470) * 0.5f));
    m_pcPanel->addChild(bg);

    auto header = CCLayerColor::create(ccc4(40, 42, 48, 255), 720, 40);
    header->setPosition(ccp((winSize.width - 720) * 0.5f, (winSize.height - 470) * 0.5f + 430));
    m_pcPanel->addChild(header);

    auto title = CCLabelTTF::create("Gravity", "Arial-BoldMT", 18);
    title->setColor(ccc3(255, 255, 255));
    title->setPosition(ccp((winSize.width - 720) * 0.5f + 120, (winSize.height - 470) * 0.5f + 450));
    m_pcPanel->addChild(title);

    const std::vector<std::string> categories = {
        "Gameplay", "Movement", "Visual", "Speed", "Practice", "Utility", "Misc"
    };

    for (size_t i = 0; i < categories.size(); ++i) {
        auto catLabel = CCLabelTTF::create(categories[i].c_str(), "Arial", 15);
        catLabel->setColor(ccc3(210, 210, 210));
        catLabel->setPosition(ccp((winSize.width - 720) * 0.5f + 80, (winSize.height - 470) * 0.5f + 390 - static_cast<float>(i) * 44.0f));
        m_pcPanel->addChild(catLabel);
    }

    int index = 0;
    for (const auto& toggle : ToggleManager::get().all()) {
        if (index >= 22) break;
        addToggleRow(m_pcPanel, toggle.name, 350 - static_cast<float>(index) * 18.0f);
        ++index;
    }
}

void MenuManager::addHeader(CCLayer* parent, const std::string& title) {
    auto label = CCLabelTTF::create(title.c_str(), "Arial-BoldMT", 16);
    label->setColor(ccc3(255, 255, 255));
    parent->addChild(label);
}

void MenuManager::addToggleRow(CCLayer* parent, const std::string& name, float yPos) {
    auto label = CCLabelTTF::create(name.c_str(), "Arial", 14);
    label->setColor(ccc3(230, 230, 230));
    label->setPosition(ccp(120, yPos));
    parent->addChild(label);

    auto toggleBox = CCLayerColor::create(ccc4(30, 120, 200, 255), 12, 12);
    toggleBox->setPosition(ccp(320, yPos - 6));
    parent->addChild(toggleBox);
}

void MenuManager::onTabSelected(CCObject* sender) {
    (void)sender;
}

void MenuManager::onTogglePressed(CCObject* sender) {
    (void)sender;
}
