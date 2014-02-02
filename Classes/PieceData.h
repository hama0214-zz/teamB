//
//  PieceData.h
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/02/02.
//
//

#ifndef __teamB__PieceData__
#define __teamB__PieceData__

#include "cocos2d.h"
#include "Variables.h"

USING_NS_CC;

/** 1マスのオブジェクトの生成に必要な情報 */
class PieceData : CCObject
{
public:
    /**
     * 最大4桁の数からピースオブジェクトの生成に必要な情報を生成する。
     * @param dataValue 4桁の数。
     * @return ピースオブジェクトの生成に必要な情報。
     */
    static PieceData* create(int dataValue);
    
    /**
     * ピースタイプを取得する。
     * @return ピースタイプ。
     */
    inline Variables::PIECE_TYPE getPieceType() const {return m_pieceType;}
    
    /**
     * 画像タイプを取得する。
     * @return 画像タイプ。
     */
    inline Variables::PIECE_IMAGE getImageType() const {return m_imageType;}
    
private:
    /** ピースタイプ */
    Variables::PIECE_TYPE m_pieceType;
    
    /** 画像のタイプ */
    Variables::PIECE_IMAGE m_imageType;
    
    /**
     * 初期化する。
     * @param dataValue 4桁の数。
     * @return 初期化に成功したかどうか。
     */
    bool init(int dataValue);
    
    /**
     * 2桁の数字からピースタイプに変換する。
     * @param pieceTypeValue ピースタイプに変換する数字。
     * @return ピースタイプ。
     */
    Variables::PIECE_TYPE convertToPieceType(int pieceTypeValue);
    
    /**
     * 2桁の数字から画像タイプに変換する。
     * @param pieceTypeValue 画像タイプに変換する数字。
     * @return 画像タイプ。
     */
    Variables::PIECE_IMAGE convertToImageType(int imageTypeValue);
};

#endif /* defined(__teamB__PieceData__) */
