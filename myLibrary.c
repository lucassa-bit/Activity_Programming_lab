#include "myLibrary.h"
#include <ctype.h>

// Return Values
double ListAverage(double * list_of_values, int listRange)
{
    int loopValue;
    double average = 0;

    for(loopValue = 0; loopValue < listRange; loopValue++)
        average += list_of_values[loopValue];

    average /= listRange;

    return average;
}
double ListAverageWeighted(double * list_of_values, double * list_of_weights, int listRange)
{
    int loopValue;
    double average = 0;

    for(loopValue = 0; loopValue < listRange; loopValue++) average += list_of_values[loopValue] * list_of_weights[loopValue];

    average /= ListSum(list_of_weights, listRange);

    return average;
}
int AverageForCounter(double * list_of_values,  double averageValue, int listRange)
{
    int loopValue, quantity = 0;

    for(loopValue = 0; loopValue < listRange; loopValue++)
        if(list_of_values[loopValue] > averageValue)
            quantity++;

    return quantity;
}
double ListProduct(double * list_of_values, int listRange)
{
    int loopValue;
    double product = 1;

    for(loopValue = 0; loopValue < listRange; loopValue++)
        product *= list_of_values[loopValue];

    return product;
}
double ListSum(double * list_of_values, int listRange)
{
    int loopValue;
    double sum = 0;

    for(loopValue = 0; loopValue < listRange; loopValue++)
        sum += list_of_values[loopValue];

    return sum;
}
double ExtremeValue(double * list_of_values, int listRange, int typeOfTheValue)
{
    int loopValue;
    double num = list_of_values[0];

    for(loopValue = 1; loopValue < listRange; loopValue++)
    {
        if(list_of_values[loopValue] > num && typeOfTheValue == 1)
            num = list_of_values[loopValue];

        else if(list_of_values[loopValue] < num && typeOfTheValue == -1)
            num = list_of_values[loopValue];
    }
    return num;
}

// Modify The list
int AlphaSpaceCheck(char * stringIn, int lenString)
{
    int loopValue;
    for(loopValue = 0; loopValue < lenString; loopValue++)
    {
        if(!isalpha(stringIn[loopValue]) && stringIn[loopValue] != ' ')
            return 1;
    }
    return 0;
}
void MultiplyTheList(double * list_of_values, double value_for_multiply, int listRange)
{
    int loopValue;

    for(loopValue = 0; loopValue < listRange; loopValue++)
        list_of_values[loopValue] *= value_for_multiply;
}
void SortList(double * list_of_values, int listRange, int typeOfTheValue)
{
    int loopValue, loopValue1;
    double temp;

    for(loopValue = 1; loopValue < listRange; loopValue++)
        for(loopValue1 = loopValue; loopValue1 > 0; loopValue1--)
        {
            if(list_of_values[loopValue1] < list_of_values[loopValue1 - 1] && typeOfTheValue == 1)
            {
                temp = list_of_values[loopValue1];
                list_of_values[loopValue1] = list_of_values[loopValue1 - 1];
                list_of_values[loopValue1 - 1] = temp;
            }
            else if(list_of_values[loopValue1] > list_of_values[loopValue1 - 1] && typeOfTheValue == -1)
            {
                temp = list_of_values[loopValue1];
                list_of_values[loopValue1] = list_of_values[loopValue1 - 1];
                list_of_values[loopValue1 - 1] = temp;
            }
        }
}
