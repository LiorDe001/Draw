#pragma once

#include <map>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include "Employee.h"
#include <vector>
#include <numeric>
//#include <stdlib.h>
#include <malloc.h>
#include <algorithm>

using namespace std;

//在min~max之间随机产生一个数
int RandomBetween(int min, int max);

//RAND_MAX在stdlib.h中被定义成一个常亮 0-32767
//权重之和
int SumOfWeight(map<int, int>& map1);

//返回几等奖
int Random(map<int, int>& map1);

vector<int> CreateRandomNums(int min, int max, int num);

int* GetRandomNumWithWeight(vector<int> weight, int number);

//void startLuckDraw();