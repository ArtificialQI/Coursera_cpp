#include "node.h"

int EmptyNode::Evaluate(const Date& date, const string& event) const
{
	return 0;
}

int DateComparisonNode::Evaluate(const Date& date, const string& event) const
{	
	
	return 0;
}

int EventComparisonNode::Evaluate(const Date& date, const string& event) const
{
	return 0;
}

int LogicalOperationNode::Evaluate(const Date& date, const string& event) const
{
	return 0;
}
