#pragma once

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
	int Evaluate() const override;
};

class EventComparisonNode : public Node {
public:
	int Evaluate() const override;
};

class LogicalOperationNode : public Node {
public:
	int Evaluate() const override;
};