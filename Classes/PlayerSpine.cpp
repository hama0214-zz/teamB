//
//  PlayerSpine.cpp
//  teamB
//
//  Created by Kenji on 14/02/02.
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
    setPosition(ccp(200, 200)); // 初期位置

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
            break;
            
        case RUN:
            break;
            
        case JUMP:
            break;
            
        case DOUBLE_JUMP:
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

void PlayerSpine::setAnimation(const char* name, bool loop, int stateIndex) {
    timeScale = 1.0f;
    CCSkeletonAnimation::setAnimation(name, loop);
}

void PlayerSpine::jump()
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
    CCJumpBy* jump = CCJumpBy::create(0.45f, ccp(0, 0), 180, 1);
    // 着地時に再び走る
    CCCallFunc* runFunc = CCCallFunc::create(this, callfunc_selector(PlayerSpine::run));
    m_jumpAction = CCSequence::create(jump, runFunc, NULL);
    runAction(m_jumpAction);
}

void PlayerSpine::run()
{
    setState(RUN);
    setAnimation(RUN_ANIM_NAME, true);
}

