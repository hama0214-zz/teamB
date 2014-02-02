//
//  MapPieceFactory.cpp
//  与えたタイプに応じたピースインスタンスを返すファクトリー
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#include "MapPieceFactory.h"
#include "EmptyPiece.h"

/**
 * 引数から生成したいMapPieceを継承したクラスを判断して、インスタンスを返すクラスメソッド
 * @static
 */
MapPiece* MapPieceFactory::create(Variables::PIECE_TYPE type, Variables::PIECE_IMAGE image) {
    
    MapPiece* piece;
    
    switch (type) {
        // 空のマップピース
        case Variables::NONE_PIECE:
            piece = EmptyPiece::getInstese();
            break;
            
        // フィールド
        case Variables::FIELD_PIECE:
            piece = FieldPiece::create(image);
            break;
        
        // 敵
        case Variables::ENEMY_PIECE:
            piece = EnemyPiece::create(image);
            break;
            
        // アイテム
        case Variables::ITEM_PIECE:
            piece = ItemPiece::create(image);
            break;
            
        default:
            CCAssert(false, "不正なタイプを指定された。");
            break;
    }
    
    return piece;
}
