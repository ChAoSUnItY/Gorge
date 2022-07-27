#include <string>
#include <memory>

#ifndef GORGE_SPAN_HPP
#define GORGE_SPAN_HPP

namespace Gorge {

class Line {
public:
    Line(int line_number, int offset, int len, std::string chars)
        :   line_number_(line_number),
            offset_(offset),
            len_(len),
            chars_(chars) {}
    ~Line() {}

    auto get_line_number() const -> int { return line_number_; }
    auto get_offset() const -> int { return offset_; }
    auto get_len() const -> int { return len_; }
    auto get_chars() const -> const std::string { return chars_; }
private:
    int line_number_;
    int offset_;
    int len_;
    std::string chars_;
};

class Position {
public:
    Position(int line, int pos)
        :   line_(line),
            pos_(pos) {}
    ~Position() {}

    auto get_line() const -> int { return line_; }
    auto get_pos() const -> int { return pos_; }
private:
    int line_;
    int pos_;
};

class Span {
public:
    Span(std::shared_ptr<Position> start_pos, std::shared_ptr<Position> end_pos)
        :   start_pos_(start_pos),
            end_pos_(end_pos) {}
    ~Span() {}
private:
    std::shared_ptr<Position> start_pos_;
    std::shared_ptr<Position> end_pos_;
};

}

#endif
