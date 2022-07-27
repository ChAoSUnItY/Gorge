#include <string>
#include <memory>
#include <vector>
#include <optional>

#include "span.hpp"

#ifndef GORGE_REPORT_HPP
#define GORGE_REPORT_HPP

namespace Gorge {

class Label {
public:
    Label(std::shared_ptr<Span> span, std::shared_ptr<std::string> message)
        :   span_(span),
            message_(message),
            hint_(std::nullopt) {}
    ~Label() {}

    auto get_span() const -> const std::shared_ptr<Span> { return span_; }
    auto get_message() const -> const std::shared_ptr<std::string> { return message_; }
    auto get_hint() const -> const std::optional<std::shared_ptr<std::string>> { return hint_; }
    auto set_hint(std::shared_ptr<std::string> hint) const -> void { const_cast<Label*>(this)->hint_ = hint; }
private:
    std::shared_ptr<Span> span_;
    std::shared_ptr<std::string> message_;
    std::optional<std::shared_ptr<std::string>> hint_;
};

enum ReportType {
    WARNING,
    ERROR
};

class Report {
public:
    Report(std::shared_ptr<Position> start_position, std::shared_ptr<Position> end_position, ReportType type, std::shared_ptr<std::string> message)
        :   common_span_(std::make_shared<Span>(start_position, end_position)) {}
    ~Report() {}

    auto get_span() const -> const std::shared_ptr<Span> { return common_span_; }
    auto get_labels() const -> const std::vector<std::shared_ptr<Label>> { return labels_; }
    auto add_label(std::shared_ptr<Label> label) const -> void { const_cast<Report*>(this)->labels_.push_back(label); }
    auto get_type() const -> const ReportType { return type_; }
    auto get_message() const -> const std::shared_ptr<std::string> { return message_; }
private:
    std::shared_ptr<Span> common_span_;
    std::vector<std::shared_ptr<Label>> labels_;
    ReportType type_;
    std::shared_ptr<std::string> message_;
};

}

#endif
