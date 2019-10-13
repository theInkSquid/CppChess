//
// Created by April on 9/3/2019.
//

#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "board.hpp"
#include "piece.hpp"

namespace chess {
    class RuleException : public std::runtime_error {
    public:
        enum class Type {
            NoPiece,
            IllegalMove,
            WrongTeam
        };

        explicit RuleException(Type type);

        Type type() const;

    private:
        Type type_;
    };

    namespace input {
        struct Input {
            virtual ~Input() = default;
            Team team;
        };

        struct Pass : public Input {};
        struct Move : public Input {
            Point from;
            Point onto;
        };
    }

    using input::Input;

    class Chess {
    public:
        Chess();

        std::unique_ptr<Piece> make_move(Point from, Point onto);

        void change_team();

        void handle_input(Input const& input);
    private:
        Board board_;
        Team cur_team_;
    };
}

using chess::Chess;