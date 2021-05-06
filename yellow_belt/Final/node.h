#pragma once

#include "date.h"

#include <string>
#include <set>
#include <utility>
#include <memory>
#include <vector>

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
			auto lower = storage.lower_bound(date_);
			auto upper = storage.upper_bound(date_);
			auto find_ = find(date_);
			switch (cmp_) {
			case Comparison::Less:
				return {begin, --lower};
				break;
			case Comparison::LessOrEqual:
				return {begin, lower};
				break;
			case Comparison::Greater:
				return {upper, --end};
				break;
			case Comparison::GreaterOrEqual:
				return {lower, --end};
				break;
			case Comparison::Equal:
				return {find_, find_};
				break;
			case Comparison::NotEqual:
				if (find_ = end)
					return {begin, --end}
				storage.erase(find_);
				return {begin, --end};
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
	EventComparisonNode(const Comparison& cmp, const string& event) : cmp_(cmp), event_(event) {}
	template<class RandomIt>
	pair<RandomIt, RandomIt> Evaluate(const Date& date, const string& event_) const override {
		pair<RandomIt, RandomIt> predicate = [date, event_](map<Date, set<string>> storage) {
			auto begin = storage.begin();
			auto end = storage.end();

			switch (cmp_) {
			case Comparison::Less:
				for (auto [key, value] : storage)
					if (value.count(event_) > 0)
				break;
			case Comparison::LessOrEqual:
				break;
			case Comparison::Greater:
				break;
			case Comparison::GreaterOrEqual:
				break;
			case Comparison::Equal:

				break;
			case Comparison::NotEqual:
				break;
			default:
				break;
			}
		};
		return predicate;
	} 
private:
	const Comparison cmp_;
	const string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation log, shared_ptr<Node> left, shared_ptr<Node> right) : log_(log), left_(left), right_(right) {}
	template<class Function>
	Function Evaluate(const Date& date, const string& event) const override {

		switch (log_)
		{
		case LogicalOperation::And:
			/* code */
			break;
		case LogicalOperation::Or:

			break;
		
		default:
			break;
		}
	}
private:
	LogicalOperation log_;
	shared_ptr<Node> left_;
	shared_ptr<Node> right_;
};