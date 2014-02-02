//
//  PlayerSpine.cpp
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/02/02.
//
//

#include "PlayerSpine.h"
#include "MapPieceManager.h"

const char* PlayerSpine::JSON_FILE_NAME = "spineboy.json";

const char* PlayerSpine::ATLAS_FILE_NAME = "spineboy.atlas";

const char* PlayerSpine::RUN_ANIM_NAME = "walk";

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
    setPosition(ccp(200, 165)); // 初期位置

//    setAnchorPoint(ccp(0.9f,0.9f));
    
    m_rect = CCRectMake(0, 0, MapPieceManager::CELL_WIDTH, MapPieceManager::CELL_HEIGHT);
    m_jumpAction = NULL;
    
    run();
    return true;
}

const CCRect& PlayerSpine::getRect()
{
    m_rect.setRect(getPositionX() - MapPieceManager::CELL_WIDTH / 4.0f,
                   getPositionY() - MapPieceManager::CELL_HEIGHT / 4.0f,
                   MapPieceManager::CELL_WIDTH / 2.0f,
                   MapPieceManager::CELL_HEIGHT / 2.0f);
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
    timeScale = 5.0f;
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
        CCJumpTo* jump = CCJumpTo::create(0.5f, ccp(200, 165), 180, 1);

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
        CCJumpTo* jump = CCJumpTo::create(0.5f, ccp(200, 165), 300, 1);
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
 
    if (piece_type==2){
        gameover();
        setState(DOWN);
    };
    
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
        CCMoveTo* goalMove1=CCMoveTo::create(0.9f,ccp(80,165));

        CCJumpTo* goalMove2=CCJumpTo::create(51.5f,ccp(80,165),300,50);
   //     CCRepeatForever *repeatF = CCRepeatForever::create(goalMove2);
        
        CCSequence* goalMove = CCSequence::create(goalMove1,goalMove2,NULL);
        runAction(goalMove);
    }
}

void PlayerSpine::gameover()
{
        stopAction(m_jumpAction);
    
    setAnimation(RUN_ANIM_NAME, false);
    CCJumpTo* deadMove=CCJumpTo::create(1.5f,ccp(200,-160),300,1);
    CCCallFunc* efFunc = CCCallFunc::create(this, callfunc_selector(PlayerSpine::gameoverEf));
    CCSequence * seq = CCSequence::create(deadMove,efFunc,NULL);
    runAction(seq);
}

void PlayerSpine::gameoverEf()
{
    CCParticleExplosion* p = CCParticleExplosion::create(); // 爆発的なエフェクトの初期化
	p->setDuration(0.1);     // エフェクトが停止するまでの時間
	p->setSpeed(1000);        // エフェクトの動く速さ
	p->setPosition(ccp(0,0)); // エフェクトの発生地点
	// エフェクトの表示
	this->addChild(p); // addChild するとすぐ表示
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

