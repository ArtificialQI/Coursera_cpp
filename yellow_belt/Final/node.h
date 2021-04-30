#pragma once

#include "date.h"

#include <string>
#include <set>
#include <utility>

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,

};

enum class LogicalOperation {
	Or,
	And,
};
class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};
 
class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison& cmp, Date& date) : cmp_(cmp), date_(date) {}
	template<class RandomIt>
	pair<RandomIt, RandomIt> Evaluate(const Date& date_, const string& event) const override {
		pair<RandomIt, RandomIt> predicate = [date_, event](map<Date, set<string>> storage) {
			auto begin = storage.begin();
			auto end = storage.end();
			switch (cmp_) {
			case Comparison::Less:
				auto lower = storage.lower_bound(date_);
				return {begin, --lower};
				break;
			case Comparison::LessOrEqual:
			auto lower = storage.lower_bound(date_);
				return {begin, lower};
				break;
			case Comparison::Greater:
				/* code */
				break;
			case Comparison::GreaterOrEqual:
				/* code */
				break;
			case Comparison::Equal:
				/* code */
				break;
			case Comparison::NotEqual:
				/* code */
				break;
			default:
				break;
			}
		};
		return predicate;
	} 
private:
	const Comparison cmp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& value) : cmp_(cmp), value_(value) {}
	template<class Function>
	Function Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison cmp_;
	const string value_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation log, shared_ptr<Node> left, shared_ptr<Node> right) : log_(log), left_(left), right_(right) {}
	template<class Function>
	Function Evaluate(const Date& date, const string& event) const override {
		return Evaluate(left_) log_ Evaluate(right_); // переделать под итераторы
		// (first, second) && (third, fourth);
	}
private:
	LogicalOperation log_;
	shared_ptr<Node> left_;
	shared_ptr<Node> right_;
};