#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const { return true; }

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (cmp_) {
		case Comparison::Less:
			return date < date_;
		case Comparison::LessOrEqual:
			return date <= date_;
		case Comparison::Greater:
			return date > date_;
		case Comparison::GreaterOrEqual:
			return date >= date_;
		case Comparison::Equal:
			return date == date_;
		case Comparison::NotEqual:
			return date != date_; 
		default:
			break;
		}
} 

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event) : cmp_(cmp), event_(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (cmp_) {
		case Comparison::Less:
			return event_ < event;
		case Comparison::LessOrEqual:
			return event_ <= event;
		case Comparison::Greater:
			return event_ > event;
		case Comparison::GreaterOrEqual:
			return event_ >= event;
		case Comparison::Equal:
			return event_ == event;
		case Comparison::NotEqual:
			return event_ != event;
		default:
			break;
	}
}
LogicalOperationNode::LogicalOperationNode(const LogicalOperation& log, const shared_ptr<Node>& left, const shared_ptr<Node>& right) : log_(log), left_(left), right_(right) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	switch (log_) {
		case LogicalOperation::And:
			return left_->Evaluate(date, event) && right_->Evaluate(date, event);
		case LogicalOperation::Or:
			return left_->Evaluate(date, event) || right_->Evaluate(date, event);
		default:
			break;
	}
}
