#pragma once

#include "date.h"

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
	virtual int Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
	int Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison& cmp, Date& date) : cmp_(cmp), date_(date) {}
	int Evaluate(const Date& date, const string& event) const override {
		return 
	}
private:
	const Comparison cmp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& value) : cmp_(cmp), value_(value) {}
	int Evaluate(const Date& date, const string& event) const override;
private:
	const Comparison cmp_;
	const string value_;
};

class LogicalOperationNode : public Node {
public:
	int Evaluate(const Date& date, const string& event) const override;
};