//
//  MapPieceFactory.cpp
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#include "MapPieceFactory.h"

MapPiece* MapPieceFactory::create(Variables::PIECE_TYPE type, const char* pszFileName) {
    MapPiece* piece;
    if (type == Variables::FIELD_PIECE) {
        piece = FieldPiece::create(pszFileName);
    }
    return piece;
}
