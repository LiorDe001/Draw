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

//��min~max֮���������һ����
int RandomBetween(int min, int max);

//RAND_MAX��stdlib.h�б������һ������ 0-32767
//Ȩ��֮��
int SumOfWeight(map<int, int>& map1);

//���ؼ��Ƚ�
int Random(map<int, int>& map1);

vector<int> CreateRandomNums(int min, int max, int num);

int* GetRandomNumWithWeight(vector<int> weight, int number);

//void startLuckDraw();