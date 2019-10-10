#include "chess.hpp"
//
// Created by April on 9/3/2019.
//

#include <vector>
#include <algorithm>

#include "chess.hpp"

RuleException::RuleException(RuleException::Type type, std::string&& message):
    std::runtime_error{message},
    type_{type}
{}

RuleException::Type RuleException::type() const {
    return type_;
}

Chess::Chess() :
    board_{8, 8},
    cur_team_{Team::White}
{}

bool Chess::make_move(Point from, Point onto) {
    if (!board_[from]) {
        return false;
    }
    Piece& cur = *board_[from];
    std::vector<Point> moves = cur.moves(from, board_);
    if (cur.team() != cur_team_ ||
        std::find(moves.begin(), moves.end(), onto) == moves.end()
    ) {
        return false;
    }
    board_.move_piece(from, onto);

}
