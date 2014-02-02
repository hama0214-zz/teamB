//
//  PlayerSpine.cpp
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/02/02.
//
//

#include "PlayerSpine.h"
#include "MapPieceManager.h"

const char* PlayerSpine::JSON_FILE_NAME = "samurai.json";

const char* PlayerSpine::ATLAS_FILE_NAME = "samurai.atlas";

const char* PlayerSpine::STAY_ANIM_NAME = "wait1";

const char* PlayerSpine::RUN_ANIM_NAME = "run";

PlayerSpine::~PlayerSpine()
{
    m_jumpAction = NULL;
    m_state = NONE;
}

PlayerSpine::PlayerSpine(const char* skeletonDataFile, const char* atlasFile, float scale) : CCSkeletonAnimation(skeletonDataFile, atlasFile, scale)
{
    // 何もしない
}

PlayerSpine* PlayerSpine::create()
{
    PlayerSpine *ret = new PlayerSpine(JSON_FILE_NAME, ATLAS_FILE_NAME);
    if (ret != NULL && ret->init()) {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool PlayerSpine::init()
{
    setScaleX(-1); // 右向き表示
    setPosition(ccp(200, 170)); // 初期位置

//    setAnchorPoint(ccp(0.9f,0.9f));
    
    m_rect = CCRectMake(0, 0, MapPieceManager::CELL_WIDTH, MapPieceManager::CELL_HEIGHT);
    m_jumpAction = NULL;
    
    run();
    return true;
}

const CCRect& PlayerSpine::getRect()
{
    m_rect.setRect(getPositionX() - MapPieceManager::CELL_WIDTH / 2.0f,
                   getPositionY() - MapPieceManager::CELL_HEIGHT / 2.0f,
                   MapPieceManager::CELL_WIDTH,
                   MapPieceManager::CELL_HEIGHT);
    return m_rect;
}

void PlayerSpine::setState(State state)
{
    switch (state) {
        case STAY:
            m_state=STAY;
            break;
            
        case RUN:
            m_state=RUN;
            break;
            
        case JUMP:
            m_state=JUMP;
            break;
            
        case DOUBLE_JUMP:
            m_state=DOUBLE_JUMP;
            break;
            
        case DAMAGE:
            break;
            
        case DOWN:
            break;
            
        case CLEAR:
            break;
            
        default:
            CCAssert(false, "不正な状態を指定された。");
            return;
    }
    
    m_state = state;
}

void PlayerSpine::setAnimation(const char* name, bool loop, int stateIndex)
{
    timeScale = 1.0f;
    CCSkeletonAnimation::setAnimation(name, loop);
}

void PlayerSpine::jump()
{
   // CCLog("ポジション %f %f",getAnchorPoint().x,getAnchorPoint().y);
    
    if (m_state==RUN)
    {
        setState(JUMP);
        
        if (m_jumpAction != NULL) {
            stopAction(m_jumpAction);
            m_jumpAction = NULL;
        }
    
        // 走りアニメを止める
        // TODO:止めるメソッドがわからないので、走りモーションを再生させなおし、最終フレームで止まるようにしてある。
        setAnimation(RUN_ANIM_NAME, false);
        timeScale = 20.0f;

        // ジャンプ
        CCJumpTo* jump = CCJumpTo::create(0.5f, ccp(200, 170), 180, 1);

        // 着地時に再び走る
        CCCallFunc* runFunc = CCCallFunc::create(this, callfunc_selector(PlayerSpine::run));
        m_jumpAction = CCSequence::create(jump, runFunc, NULL);
        runAction(m_jumpAction);
    
    }
    else if (m_state==JUMP)
    {
        setState(DOUBLE_JUMP);
        
        if (m_jumpAction != NULL) {
            stopAction(m_jumpAction);
            m_jumpAction = NULL;
        }
        
        // ジャンプ
        CCJumpTo* jump = CCJumpTo::create(0.5f, ccp(200, 170), 300, 1);
        CCRotateBy* rotate =CCRotateBy::create(0.5f,360);
        CCSpawn* spawn=CCSpawn::create(rotate,jump,NULL);
        
        // 着地時に再び走る
        CCCallFunc* runFunc = CCCallFunc::create(this, callfunc_selector(PlayerSpine::run));
        m_jumpAction = CCSequence::create(spawn, runFunc, NULL);
        runAction(m_jumpAction);
    }
    
}

/*
 
 */
void PlayerSpine::hitObject(Variables::PIECE_TYPE piece_type)
{
 
    
    
}

void PlayerSpine::goal()
{
    CCLog("%f",getPosition().y);
    if (m_state!=CLEAR)
    {
        if (m_jumpAction != NULL) {
            stopAction(m_jumpAction);
            m_jumpAction = NULL;
        }

        setState(CLEAR);

        setAnimation(RUN_ANIM_NAME, false);
        CCMoveTo* goalMove1=CCMoveTo::create(0.5f,ccp(80,170));

        CCJumpTo* goalMove2=CCJumpTo::create(51.5f,ccp(80,170),200,50);
   //     CCRepeatForever *repeatF = CCRepeatForever::create(goalMove2);
        
        CCSequence* goalMove = CCSequence::create(goalMove1,goalMove2,NULL);
        runAction(goalMove);
    }
}


void PlayerSpine::reset()
{
    stopAction(m_jumpAction);
}


void PlayerSpine::run()
{
    setState(RUN);
    setAnimation(RUN_ANIM_NAME, true);
}

