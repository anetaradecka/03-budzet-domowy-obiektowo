#include "Transaction.h"

void Transaction::setCategory(string newCategory)
{
    category = newCategory;
}

void Transaction::setDate(int newDate)
{
    date = newDate;
}

void Transaction::setAmount(string newAmount)
{
    if(!AuxiliaryMethods::checkAmountForComma(newAmount))
    {
     amount = AuxiliaryMethods::convertStringToFloat(newAmount);
    }
    else
    {
    newAmount = AuxiliaryMethods::convertCommaToDot(newAmount);
    amount = AuxiliaryMethods::convertStringToFloat(newAmount);
    }

}

string Transaction::getCategory()
{
    return category;
}

int Transaction::getDate()
{
    return date;
}

float Transaction::getAmount()
{
    return amount;
}



