//
//  PlayerSpine.h
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/02/02.
//
//

#ifndef __teamB__PlayerSpine__
#define __teamB__PlayerSpine__

#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
#include "Variables.h"

USING_NS_CC;
using namespace cocos2d::extension;

/**
 * プレイヤークラス。
 * Spine（http://esotericsoftware.com）のオブジェクトを扱う。
 *
 * http://www.slideshare.net/
 /20130625-cocos2d-xspine
 * 上記URLに清水さんによる簡単な使い方が紹介されています。
 */
class PlayerSpine: public CCSkeletonAnimation
{
public:
    /**
     * クリエイトメソッド。
     * @return プレイヤーキャラクター
     */
    static PlayerSpine* create();
    
    /** ジャンプする */
    void jump();

    /**
     * 当たり判定を取得する
     * @return 当たり判定。
     */
    const CCRect& getRect();
    
private:
    /** スケルトンデータファイル名 */
    static const char* JSON_FILE_NAME;
    
    /** アトラスデータファイル名 */
    static const char* ATLAS_FILE_NAME;
    
    /** 待機のアニメ名 */
    static const char* STAY_ANIM_NAME;
    
    /** 走りのアニメ名 */
    static const char* RUN_ANIM_NAME;
    
    /** プレイヤーの状態 */
    enum State
    {
        /** 不正な値や初期値として使う */
        NONE = -1,
        
        /** 待機 */
        STAY,
        
        /** 走り */
        RUN,
        
        /** ジャンプ */
        JUMP,
        
        /** 2段ジャンプ */
        DOUBLE_JUMP,
        
        /** ダメージ */
        DAMAGE,
        
        /** やられ */
        DOWN,
        
        /** ゲームクリアー */
        CLEAR,
        
        /** 状態の数 */
        NUM_STATUS
    };
    
    /** プレイヤーの状態を設定する */
    State m_state;
    
    /** 当たり判定 */
    CCRect m_rect;
    
    /** プレイヤーのジャンプアクション */
    CCActionInterval* m_jumpAction;
    
    /**
     * コンストラクタ。
     * @param skeletonDataFile スケルトンファイル。
     * @param atlasFile アトラスファイル。
     * @param scale サイズ。デフォルトは0.5。
     */
    PlayerSpine(const char* skeletonDataFile, const char* atlasFile, float scale = 0.5f);
    
    /** デストラクタ */
    ~PlayerSpine();
    
    /** 初期化 */
    bool init();

    /** 状態遷移 */
    void setState(State state);
    
    /** 再生スピードを等倍に戻して、アニメーションを再生する。 */
	void setAnimation(const char* name, bool loop, int stateIndex = 0);
    
    /** あたり判定*/
    void hitObject(Variables::PIECE_TYPE);
    
    /** 走る */
    void run();
};

#endif /* defined(__teamB__PlayerSpine__) */
