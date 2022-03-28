#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <iterator>
#include <type_traits>
#include <vector>
#include <random>
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
* @brief            冒泡排序 ( o(n2) )
* @date             2022-03-20
**/
template<typename V_ITERRAL>
void BubbleSort(V_ITERRAL begin, V_ITERRAL end)
{
    if(nullptr == begin || nullptr == end) return;

    for(size_t i = 0; i < end - begin -1; i++)
    {
        for(size_t j = 0; j < end - begin - 1 - i; j++)
        {
            if((*(begin + j)) > (*(begin + j + 1)))
            {
                commonswap(*(begin + j), *(begin + j + 1)); //相邻两个数比较后交换
            }
        }
    }
}

/**
* @function         /
* @brief            选择排序 ( o(n2) )
* @date             2022-03-27
**/
template<typename V_ITERRAL>
void SelectSort(V_ITERRAL begin, V_ITERRAL end)
{
    if(nullptr == begin || nullptr == end) return;

    size_t arrLength = end - begin;
    for(size_t i = 0; i < arrLength -1; i++) //i ~ N-1
    {
        size_t minIndex = i;
        for(size_t j = i + 1; j < arrLength; j++ ) //i+1 ~ N 上找最小值
        {
            minIndex = *(begin + j) < *(begin + minIndex) ? j : minIndex;
        }
        commonswap(*(begin + i), *(begin + minIndex));
    }
}

/**
* @function         /
* @brief            归并排序合并出来
* @date             2022-03-27
**/
template <typename V_ITERRAL>
static void merge(V_ITERRAL begin, size_t L, size_t M, size_t R)
{
    using value_type = std::iterator_traits<V_ITERRAL>::value_type ; //获取到实际数据类型
    std::vector<value_type> help;
    help.resize(R - L +1);

    size_t i=0;
    size_t p1 = L;
    size_t p2 = M+1;
    while(p1 <= M && p2 <= R) //左部分 和 右部分 合并，谁小谁先放入帮助数组
    {
        help[i++] = *(begin + p1) < *(begin + p2) ? *(begin + p1++) : *(begin + p2++);
    }
    //将剩下的放入数组
    while(p1 <= M)
    {
        help[i++] = *(begin + p1++);
    }
    while(p2 <= R)
    {
        help[i++] = *(begin + p2++);
    }
    //将值返回给输入
    for(size_t j = 0; j < help.size(); j++)
    {
        *(begin + j + L) = help[j]; //注意 + L
    }
}


/**
* @function         /
* @brief            归并排序递归处理
* @date             2022-03-27
**/
template <typename V_ITERRAL>
static void mergeProcess(V_ITERRAL begin, size_t left, size_t right)
{
    if(nullptr == begin || left == right) return;

    size_t mid = left + ((right - left) >> 1);
    mergeProcess(begin, left, mid);
    mergeProcess(begin, mid+1, right);
    merge(begin, left, mid, right);

}

/**
* @function         /
* @brief            归并排序 ( 时间:o(NlgN)  空间:o(N))
* @date             2022-03-27
**/

template <typename V_ITERRAL>
void MergeSort(V_ITERRAL begin, V_ITERRAL end)
{
    if(nullptr == begin || nullptr == end) return;
    if(end - begin < 2) return;

    mergeProcess(begin, 0, end - begin - 1);
}

/**
* @function         /
* @brief            快速排序交换
*                   处理arr[l ... r]
*                   默认以arr[r]为划分，arr[r]->p   :  <p  ==p  >p
*                   返回等于区域（左边界，右边界）
* @date             2022-03-28
**/
template <typename V_ITERRAL>
static std::pair<int, int> QuickPartition(V_ITERRAL begin, long int left, long int right)
{
    long int less = left - 1; // <区右边界
    long int more = right; // >区左边界
    while(left < more) //L表示当前数位置
    {
        if(*(begin + left) < *(begin + right)) //当前值 < 划分值
        {
            ++less; //<区右边界下一位置
            commonswap(*(begin + less), *(begin + left)); //将当前值与<区右边界下一位置的值交换
            left++; //向后走
        }
        else if(*(begin + left) > *(begin + right)) //当前值 > 划分值
        {
            --more; //>区左边界左边一位
            commonswap(*(begin + more), *(begin + left)); //将当前值与>区左边界左边一位值交换，当前位置不变
        }
        else //当前值== 划分值
        {
            left++;  //向后走
        }
    }
    commonswap(*(begin + more), *(begin + right)); //将>区域左边界值 与 划分值交换
    return std::pair<int, int>(less+1, more); //返回等于区 左右边界位置
}

/**
* @function         /
* @brief            快速排序递归处理
* @date             2022-03-28
**/
template <typename V_ITERRAL>
void static QuickProcess(V_ITERRAL begin, long int left, long int right)
{
    if(nullptr == begin || left >= right) return;

    std::random_device rd;  // 将用于为随机数引擎获得种子
    std::mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
    std::uniform_int_distribution<> dis(left, right);
    int index = dis(gen); //随机生成划分值p的下标
    commonswap(*(begin + index), *(begin + right));

    std::pair<int, int> indexs = QuickPartition(begin, left, right);
    QuickProcess(begin, left, indexs.first - 1);
    QuickProcess(begin, indexs.second + 1, right);

}

/**
* @function         /
* @brief            快速排序
* @date             2022-03-28
**/
template <typename V_ITERRAL>
void QuickSort(V_ITERRAL begin, V_ITERRAL end)
{
    if(nullptr == begin || nullptr == end) return;
    if(end - begin < 2) return;

    QuickProcess(begin, 0, end - begin - 1);
}

}



#endif // SORT_H
