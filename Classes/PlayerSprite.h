#ifndef __PLAYERSPRITE_H__
#define __PLAYERSPRITE_H__

#include "cocos2d.h"

class PlayerSprite : public cocos2d::CCSprite
{
public:
    
    PlayerSprite(int,int);
    
    cocos2d::CCRect getRect();
    bool isTouchPoint(cocos2d::CCPoint);
    
};

#endif