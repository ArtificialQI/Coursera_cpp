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

class Node {
public:
	virtual int Evaluate() const = 0;
};

class EmptyNode : public Node {
public:
	int Evaluate() const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison& cmp, Date& date) : cmp_(cmp), date_(date) {}
	int Evaluate() const override;
private:
	const Comparison cmp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& value) : cmp_(cmp), value_(value) {}
	int Evaluate() const override;
private:
	const Comparison cmp_;
	const string value_;
};

class LogicalOperationNode : public Node {
public:
	int Evaluate() const override;
};