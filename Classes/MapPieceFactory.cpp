//
//  MapPieceFactory.cpp
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#include "MapPieceFactory.h"

MapPiece* create(Variables::PIECE_TYPE type, const char* pszFileName) {
    if (type == Variables::FIELD_PIECE) {
        FieldPiece* piece = FieldPiece::create(pszFileName);
        return piece;
    }
}
