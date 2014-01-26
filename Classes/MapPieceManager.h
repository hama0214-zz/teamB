//
//  MapPieceManager.h
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#ifndef __teamB__MapPieceManager__
#define __teamB__MapPieceManager__

#include "cocos2d.h"
#include "Variables.h"
#include "MapPieceFactory.h"
#include "Variables.h"

USING_NS_CC;

/**
 * マップパーツを管理するクラス。
 */
class MapPieceManager : CCObject{
public:
    /** 1マスの横幅 */
    static const int CELL_WIDTH;

    /** 1マスの縦幅 */
    static const int CELL_HEIGHT;


    // TODO: マップデータからマネージャーを作る
    /** クリエイトメソッド */
    static MapPieceManager* create();

    /**
     * 指定したノードにマップパーツを配置する。
     * @param node ノード
     */
    void makeMapForNode(CCNode* node);

    /**
     * 全てのマップピースオブジェクトを取得する。
     * @return 全てのマップピースオブジェクト。
     */
    CCArray* getAllMapPieces();

private:
    /** 全てのマップピースオブジェクトを管理する配列 */
    CCArray* m_mapPieceMatrix;

    /** デストラクタ */
    ~MapPieceManager();

    /**
     * 初期化する
     * @return 初期化に成功したかどうか。
     */
    bool init();

    
    /** 1マスのオブジェクトの生成に必要な情報 */
    struct PieceData {
        /** ピースタイプ */
        Variables::PIECE_TYPE m_pieceType;

        /** 画像のタイプ */
        Variables::PIECE_IMAGE m_imageType;

        /**
         * 最大4桁の数からピースオブジェクトの生成に必要な情報を生成する。
         * @param dataValue 4桁の数。
         * @return ピースオブジェクトの生成に必要な情報。
         */
        PieceData(int dataValue) {
            // 上2桁をピースタイプとして扱う
            m_pieceType = convertToPieceType(dataValue / 100);

            // 下2桁を画像タイプとして扱う
            m_imageType = convertToImageType(dataValue % 100);
        }

        /**
         * ピースタイプを取得する。
         * @return ピースタイプ。
         */
        Variables::PIECE_TYPE const getPieceType() {return m_pieceType;}
        
        /**
         * 画像タイプを取得する。
         * @return 画像タイプ。
         */
        Variables::PIECE_IMAGE const getImageType() {return m_imageType;}

        /**
         * 2桁の数字からピースタイプに変換する。
         * @param pieceTypeValue ピースタイプに変換する数字。
         * @return ピースタイプ。
         */
        static Variables::PIECE_TYPE convertToPieceType(int pieceTypeValue) {
            switch (pieceTypeValue) {
                case 0:
                    // TODO: 空白のマスオブジェクトタイプを返す。現状フィールドタイプを返している。
                    return Variables::FIELD_PIECE;
                case 1:
                    return Variables::FIELD_PIECE;
                case 2:
                    return Variables::ITEM_PIECE;
                default:
                    CCAssert(false, "不正な数を指定された。");
                    break;
            }
        }

        /**
         * 2桁の数字から画像タイプに変換する。
         * @param pieceTypeValue 画像タイプに変換する数字。
         * @return 画像タイプ。
         */
        static Variables::PIECE_IMAGE convertToImageType(int imageTypeValue) {
            switch (imageTypeValue) {
                case 0:
                    // TODO: 空白の画像タイプを返す。現状フィールド画像タイプを返している。
                    return Variables::FIELD_PIECE_IMAGE_0;
                case 1:
                    return Variables::FIELD_PIECE_IMAGE_1;
                case 2:
                    return Variables::FIELD_PIECE_IMAGE_2;
                case 3:
                    return Variables::ITEM_PIECE_IMAGE_0;
                case 4:
                    return Variables::ITEM_PIECE_IMAGE_1;
                case 5:
                    return Variables::ITEM_PIECE_IMAGE_2;
                default:
                    CCAssert(false, "不正な数を指定された。");
                    break;
            }
        }
    };
};

#endif /* defined(__teamB__MapPieceManager__) */
