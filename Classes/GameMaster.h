#ifndef __GAME_MASTER_H__
#define __GAME_MASTER_H__

#include "cocos2d.h"


class GameMaster: public cocos2d::CCObject
{
public:
    int iPoint;
    int iMater;

    void show();
    void showPop(int);
    
    cocos2d::CCSprite* pPop;
    cocos2d::CCString* scoreStr;
    cocos2d::CCString* materStr;
    cocos2d::CCString* materDStr;
    cocos2d::CCSprite* popBtn;
private:
    cocos2d::CCLabelTTF* popLabel1;
    cocos2d::CCLabelTTF* popLabel2;
    cocos2d::CCLabelTTF* popLabel3;
    cocos2d::CCLabelTTF* popLabel4;
    cocos2d::CCLabelTTF* popLabel5;
    cocos2d::CCLabelTTF* popLabel6;
};

#endif //__GAME_MASTER_H__
