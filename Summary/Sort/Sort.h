#ifndef SORT_H
#define SORT_H

/**
* @filename         Sort.h
* @brief            摘要
* @author           HXJ
* @date             2022-03-20
**/
namespace HXJ {

/**
* @function         void commonswap(V &right, V &left)
* @brief            通用交换函数
* @date             2022-03-20
**/
template<typename V>
void commonswap(V &right, V &left)
{
    V temp(left);
    left = right;
    right = temp;
}

/**
* @function         /
* @brief            冒泡排序
* @date             2022-03-20
**/
template<typename V_ITERRAL>
void BubbleSort(V_ITERRAL begin, V_ITERRAL end)
{
    for(int i = 0; i < end - begin -1; i++)
    {
        for(int j = 0; j < end - begin - 1 - i; j++)
        {
            if((*(begin + j)) > (*(begin + j + 1)))
            {
                commonswap(*(begin + j), *(begin + j + 1));
            }
        }
    }
}


}

#endif // SORT_H
