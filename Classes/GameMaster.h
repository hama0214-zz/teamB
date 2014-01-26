#ifndef __GAME_MASTER_H__
#define __GAME_MASTER_H__

#include "cocos2d.h"


class GameMaster
{
public:

    void show();
    void selShow();
    
    cocos2d::CCSprite* pPop;
    cocos2d::CCString* scoreStr;
    cocos2d::CCString* materStr;
    cocos2d::CCString* materDStr;

private:
};

#endif //__GAME_MASTER_H__
