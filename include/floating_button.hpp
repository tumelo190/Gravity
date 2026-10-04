#pragma once

#include <geode/Geode.hpp>
#include <cocos2d.h>

using namespace geode::prelude;

class FloatingButton : public CCLayer {
public:
    static FloatingButton* create();
    
    bool init() override;
    
    void onTouchMoved(CCTouch* touch, CCEvent* event);
    void onTouchEnded(CCTouch* touch, CCEvent* event);
    void onTouchBegan(CCTouch* touch, CCEvent* event);
    
    void toggleMenu();
    void updatePosition(const CCPoint& pos);
    void hide();
    void show();
    
    bool isMenuOpen() const { return m_menuOpen; }
    
private:
    CCSprite* m_button = nullptr;
    CCPoint m_touchStartPos;
    CCPoint m_buttonStartPos;
    bool m_isDragging = false;
    bool m_menuOpen = false;
    float m_dragThreshold = 5.0f;
    
    void createButtonUI();
    void snapButtonToEdge();
};
