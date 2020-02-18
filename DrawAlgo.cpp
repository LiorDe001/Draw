#include "DrawAlgo.h"

//在min~max之间随机产生一个数
int RandomBetween(int min, int max)
{
    srand((int)clock());
    if (min == max)
        return min;
    int rand_value = 0;
    if (min > max)
        rand_value =  rand() % (int)(min - max + 1.0) + max;
    else
        rand_value =  rand() % (int)(max - min + 1.0) + min;
    return rand_value;
}

//权重之和
int SumOfWeight(map<int, int>& map1)
{
    int sumweight = 0;
    for (auto& it : map1)
    {
        sumweight += it.second;
    }
    return sumweight;
}

//返回几等奖
int Random(map<int, int>& map1)
{
    int current = 0;
    int sumweight = SumOfWeight(map1);
    int randnum = RandomBetween(1, sumweight);

    for (map<int, int>::iterator it = map1.begin(); it != map1.end(); ++it)
    {
        if (current <= randnum && randnum <= current + it->second)
            return it->first;
        current += it->second;
    }
    return 0;
}

//input: int max 期待随机数的最大值，int min 期待随机数的最小值， int num 需要的随机数的个数
//output: vector<int> 装载产生的随机数（随机数都是不同的）
vector<int> CreateRandomNums(int min, int max, int num)
{
    vector<int> res;
    res.clear();
    if (max - min + 1 < num)
    {
        return res;
    }
    srand((int)clock());
    for (auto i{ 0 }; i < num; i++)
    {
        while (true)
        {
            auto temp{ rand() % (max + 1 - min) + min };
            auto iter{ find(res.begin(), res.end(), temp) };
            if (res.end() == iter)
            {
                res.push_back(temp);
                break;
            }
        }
    }
    return res;
}

//生成具有权重的随机数。随机数ranIndex生成的区间为权重的总和，根据权重分割子区间。
// Parameter: vector<int> weight　:权重
// Parameter: int number	　　　:生成随机数的数量
int* GetRandomNumWithWeight(vector<int> weight, int number)
{
    if (number <= 0 ) {
        printf("生成随机数的数量不合法！\n");
        exit(-1);
    }
    int* p = (int*)malloc(number * sizeof(int));
    int ptr = 0;
    //*info = new vector<Employee>();
    int size = weight.size();

    //计算权重的总和
    //accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值
    int accumulateVal = accumulate(weight.begin(), weight.end(), 0);
    //cout << "权重之和：" << accumulateVal << endl;
    //cout << "weight.size()：" << size << endl;
    auto randoms = CreateRandomNums(0, size, number);
    for (int i = 0; i < number; i++)
    {
        if (i < 0) {
            printf("分配的动态地址不合法！\n");
            exit(-1);
        }
        p[i] = randoms[i];
        cout << p[i] << endl;
    }
    /*
    for_each(randoms.cbegin(), randoms.cend(), 
        [](int val)->void {
            cout << val << endl; 
        });
    
    vector<int> res(number, 0);
    for (int i = 0; i < number; i++)
    {
        int tempSum = 0;
        int ranIndex = RandomBetween(0, accumulateVal);//生成一个随机数
        cout << i << "次生成一个随机数:" << ranIndex << endl;

        //0 ~ weight[0]为1，weight[0]+1 ~ weight[1]为2，依次类推
        //for (int j = 0; j < size && tem != (*info)->end(); j++, tem++)
        for (int j = 0; j < size ; j++)
        {
            tempSum += weight[j];
            if (ranIndex <= tempSum + weight[j])//&&(ranIndex > tempSum))
            {
               res[i] = j;
               cout << "中奖者下标：" << res[i] << endl;
               p[ptr] = res[i];
               ptr++;
              // perror("iterator01");
               break;
            }
        }
    }
    */
    return p;
}

/*
int main()
{
    vector<int> weight = { 8000, 1000, 500, 10, 10, 10, 10, 10, 10, 10};//权重
    GetRandomNumWithWeight(weight, 3);//生成三个随机数
}
*/

/*
//抽奖主程序
void startLuckDraw()
{
    //抽奖人数
    int luckyDrawNum = $("#txtNum").val();
    if (luckyDrawNum > remainPerson.length) {
        //分类
    }
    //随机中奖人
    var randomPerson = getRandomArrayElements(remainPerson, luckyDrawNum);
    var tempHtml = "";
    $.each(randomPerson, function (i, person) {
        var sizeStyle = "";
        if (person.length > 3) {
            sizeStyle = " style=font-size:" + 3 / person.length + "em";
        }
        if (leaderArr.indexOf(person) > -1 && times == 1) {
            tempHtml += "<span><span " + sizeStyle + "><b>" + person + "</b></span></span>";
        }
        else {
            tempHtml += "<span><span " + sizeStyle + ">" + person + "</span></span>";
        }
    });
    $("#result>div").html(tempHtml);
    //剩余人数剔除已中奖名单
    remainPerson = remainPerson.delete(randomPerson);
    //中奖人员
    luckyMan = luckyMan.concat(randomPerson);
    //设置抽奖人数框数字为空
    $("#txtNum").val("");
}

*/
