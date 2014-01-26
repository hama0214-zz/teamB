#ifndef __PLAYERSPRITE_H__
#define __PLAYERSPRITE_H__

#include "cocos2d.h"

class PlayerSprite : public cocos2d::CCSprite
{
public:
    
    PlayerSprite();
    static PlayerSprite *create(const char *pszFileName);
    void myInit(int,int);
    
    cocos2d::CCRect getRect();
    bool isTouchPoint(cocos2d::CCPoint);
    
    int pStatus;
    int pAction;
    int pGigantic;
    int pAbsorption;
    int pFlight;
    
    bool jump();
    void playerMoveFinished();
    void update(float);

    int getpStatus();
    bool getpGigantic();
    bool getpAbsorption();
    bool getpFlight();

private:
    /** デストラクタ */
    ~PlayerSprite();
    
    void landing();
    
    /**
     * 初期化する
     * @return 初期化に成功したかどうか。
     */
    bool init();

    
};

#endif