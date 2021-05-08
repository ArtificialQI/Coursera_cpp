#pragma once

#include "date.h"

#include <string>
#include <map>
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
	virtual vector<pair<Date, set<string>>> Evaluate(const Date& date, const string& event) const = 0;
};
 
class EmptyNode : public Node {
public:
	vector<pair<Date, set<string>>> Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison& cmp, Date& date) : cmp_(cmp), date_(date) {}

		template <class RandomIt>
		vector<pair<Date, vector<RandomIt>>> Evaluate(const Date& date_, const string& event) const override {
		vector<pair<Date, vector<RandomIt>>> predicate = [&](map<Date, set<string>> storage) {
			auto begin = storage.begin();
			auto end = storage.end(); 
			auto lower = storage.lower_bound(date_);
			auto upper = storage.upper_bound(date_);
			auto find_ = storage.find(date_);
			vector<pair<Date, vector<RandomIt>>> data;
			switch (cmp_) {
			case Comparison::Less:
				for (auto it = begin; it != lower; ++it) {
					pair<Date, vector<RandomIt>> item;
					item.first = it->first;
					item.second = {it->second.begin(), it->second.end()};
					data.emplace(item);
				}
				return data; 
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
					return {begin, --end};
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
	//template<class RandomIt>
	//
	template<class RandomIt>
	vector<pair<RandomIt, vector<RandomIt>>> Evaluate(const Date& date, const string& event_) const override {
		vector<pair<RandomIt, vector<RandomIt>>> predicate = [date, event_](map<Date, set<string>> storage) {
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
			auto lhs = left->Evaluate();
			auto rhs = right->Evaluate();
			vector<pair<Date, vector<RandomIt>>> result;

			for (int i = 0; i != lhs.size() || i != rhs.size(); ++i) {
				if (lhs[i].first == rhs[i].first) {
					for ()
				}
			}
			return result;
			break;
		case LogicalOperation::Or:

			break;
		
		default:
			break;
		}
	}
private:
	const LogicalOperation log_;
	const shared_ptr<Node> left_;
	const shared_ptr<Node> right_;
};