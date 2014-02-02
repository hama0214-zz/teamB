/* 作者: C25 白濱　学 */
#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene: public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(MenuScene);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
private:
    int iAni;
    void showStg();
    void pAnime(float fDelta);
    cocos2d::CCSprite* pBtn;
    cocos2d::CCSize bgSize;
    cocos2d::CCSprite* pBG;
    cocos2d::CCSprite* pAni;
    cocos2d::CCSize sizeM;
    
    cocos2d::CCSprite* pBtn1;
    cocos2d::CCSprite* pBtn2;
    cocos2d::CCSprite* pBtn3;
    cocos2d::CCSprite* pBtn4;
};

#endif //__MENU_SCENE_H__