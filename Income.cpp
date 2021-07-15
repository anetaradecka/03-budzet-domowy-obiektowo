#include "Income.h"

void Income::setIncomeId(int newId)
{
    id = newId;
}

void Income::setUserId(int activeUserId)
{
    userId = activeUserId;
}

int Income::getIncomeId()
{
    return id;
}

int Income::getUserId()
{
    return userId;
}
