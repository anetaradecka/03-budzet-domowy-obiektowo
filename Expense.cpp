#include "Expense.h"

void Expense::setExpenseId(int newId)
{
    id = newId;
}

void Expense::setUserId(int activeUserId)
{
    userId = activeUserId;
}

int Expense::getExpenseId()
{
    return id;
}

int Expense::getUserId()
{
    return userId;
}
