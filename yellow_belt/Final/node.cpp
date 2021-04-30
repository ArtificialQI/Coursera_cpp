#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const
{
	return 0;
}
template <class Function>
Function DateComparisonNode::Evaluate(const Date& date, const string& event) const
{	
	
	return 0;
}

template <class Function>
Function EventComparisonNode::Evaluate(const Date& date, const string& event) const
{
	return 0;
}

template <class Function>
Function LogicalOperationNode::Evaluate(const Date& date, const string& event) const
{
	return 0;
}
