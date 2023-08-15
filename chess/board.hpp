//
//  board.hpp
//  chess
//
//  Created by pardo jérémie on 10/08/2023.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include "basicGeometric.hpp"
#include <memory>
#include "piece.hpp"

class Board {
public:
    Board() {}
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=( const Board&) = delete;
    Board& operator=(Board&&) = delete;
    ~Board(){
        delete _playZone;
    }
    
    std::vector<Piece*>& getPiecesList() { return *_piecesList; }
    void setPiecesList(std::vector<Piece*>* piecesList);
    bool addToPiecesList(Piece* piece);
    bool deletInPiecesList(Piece* piece);
    
    bool onValidePosition(const Point& point, bool teamColor) const;
    
private:
    RectangleZone* _playZone = new RectangleZone(8,8);
    std::vector<Piece*>* _piecesList = NULL;
    
};
    

#endif /* board_hpp */