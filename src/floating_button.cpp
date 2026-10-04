#include "../../include/floating_button.hpp"
#include <geode/Geode.hpp>

using namespace geode::prelude;

FloatingButton* FloatingButton::create() {
    FloatingButton* pRet = new FloatingButton();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool FloatingButton::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    this->scheduleUpdate();
    
    createButtonUI();
    
    return true;
}

void FloatingButton::createButtonUI() {
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // Create button background circle - gradient effect
    CCLayerColor* buttonBg = CCLayerColor::create(ccc4(20, 120, 200, 255), 70, 70);
    buttonBg->setPosition(ccp(winSize.width - 50, 50));
    buttonBg->setAnchorPoint(ccp(0.5f, 0.5f));
    
    // Create a more circular appearance using a sprite or draw node
    CCDrawNode* circle = CCDrawNode::create();
    
    // Draw outer circle (blue gradient effect)
    circle->drawCircle(
        ccp(0, 0),
        35,
        ccc4f(0.08f, 0.47f, 0.78f, 1.0f),
        2.0f,
        ccc4f(0.2f, 0.6f, 1.0f, 1.0f)
    );
    
    // Draw inner red accent circle
    circle->drawCircle(
        ccp(0, 0),
        30,
        ccc4f(0.08f, 0.47f, 0.78f, 0.9f),
        1.0f,
        ccc4f(0.08f, 0.47f, 0.78f, 0.9f)
    );
    
    // Draw red accent ring on right side
    ccColor4F redColor = ccc4f(0.9f, 0.2f, 0.2f, 0.8f);
    circle->drawSegment(ccp(20, 0), ccp(30, 15), 3.0f, redColor);
    circle->drawSegment(ccp(25, 20), ccp(15, 28), 3.0f, redColor);
    
    circle->setPosition(ccp(winSize.width - 50, 50));
    this->addChild(circle, 1);
    m_button = CCSprite::create();
    
    // Create "G" text label
    CCLabelTTF* label = CCLabelTTF::create("G", "Arial", 32);
    label->setColor(ccc3(255, 255, 255));
    label->setPosition(ccp(winSize.width - 50, 50));
    label->setZOrder(2);
    this->addChild(label, 2);
    
    // Create pulsing glow effect
    CCSprite* glowCircle = CCSprite::create();
    glowCircle->setPosition(ccp(winSize.width - 50, 50));
    glowCircle->setZOrder(0);
    this->addChild(glowCircle, 0);
    
    // Add pulsing animation
    CCAction* pulse = CCSequence::create(
        CCScaleTo::create(0.6f, 1.1f),
        CCScaleTo::create(0.6f, 1.0f),
        nullptr
    );
    CCAction* repeatPulse = CCRepeatForever::create(pulse);
    circle->runAction(repeatPulse);
}

void FloatingButton::onTouchBegan(CCTouch* touch, CCEvent* event) {
    CCPoint touchPos = touch->getLocation();
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint buttonPos = ccp(winSize.width - 50, 50);
    
    float distance = ccpDistance(touchPos, buttonPos);
    
    if (distance < 40) {
        m_isDragging = true;
        m_touchStartPos = touchPos;
        m_buttonStartPos = buttonPos;
        return true;
    }
    
    return false;
}

void FloatingButton::onTouchMoved(CCTouch* touch, CCEvent* event) {
    if (!m_isDragging) return;
    
    CCPoint touchPos = touch->getLocation();
    CCPoint delta = ccpSub(touchPos, m_touchStartPos);
    
    if (ccpLength(delta) > m_dragThreshold) {
        CCPoint newPos = ccpAdd(m_buttonStartPos, delta);
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        // Clamp position to screen bounds
        newPos.x = clampf(newPos.x, 35, winSize.width - 35);
        newPos.y = clampf(newPos.y, 35, winSize.height - 35);
        
        updatePosition(newPos);
    }
}

void FloatingButton::onTouchEnded(CCTouch* touch, CCEvent* event) {
    CCPoint touchPos = touch->getLocation();
    CCPoint delta = ccpSub(touchPos, m_touchStartPos);
    
    if (ccpLength(delta) < m_dragThreshold) {
        // Tap detected - toggle menu
        toggleMenu();
    } else {
        // Dragging ended - snap to edge
        snapButtonToEdge();
    }
    
    m_isDragging = false;
}

void FloatingButton::updatePosition(const CCPoint& pos) {
    // Update button position
    // This would update all child elements
    m_buttonStartPos = pos;
}

void FloatingButton::snapButtonToEdge() {
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float centerX = m_buttonStartPos.x;
    
    // Snap to left or right edge based on position
    CCPoint targetPos = m_buttonStartPos;
    
    if (centerX < winSize.width / 2) {
        targetPos.x = 50; // Snap to left
    } else {
        targetPos.x = winSize.width - 50; // Snap to right
    }
    
    // Animate snap
    CCAction* snap = CCMoveTo::create(0.2f, targetPos);
    // Run action on children to move them
    updatePosition(targetPos);
}

void FloatingButton::toggleMenu() {
    m_menuOpen = !m_menuOpen;
    // Trigger menu open/close event
    // This would be connected to MenuManager
}

void FloatingButton::hide() {
    this->setVisible(false);
}

void FloatingButton::show() {
    this->setVisible(true);
}
