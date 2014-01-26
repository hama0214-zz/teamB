//
//  MapPieceFactory.cpp
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#include "MapPieceFactory.h"

/**
 * 引数から生成したいMapPieceを継承したクラスを判断して、インスタンスを返すクラスメソッド
 * @static
 * @param {Variables::PIECE_TYPE} type
 * @param {Variables::PIECE_IMAGE} image
 * @return {MapPiece*}
 */
MapPiece* MapPieceFactory::create(Variables::PIECE_TYPE type, Variables::PIECE_IMAGE image) {
    
    MapPiece* piece;
    
    switch (type) {
            
        // フィールド
        case Variables::FIELD_PIECE:
            piece = FieldPiece::create(image);
            break;
            
        // アイテム
        case Variables::ITEM_PIECE:
            // piece = ItemPiece::create(image);
            break;
            
        default:
            break;
    }
    
    return piece;
}
