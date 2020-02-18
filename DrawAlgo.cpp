#include "DrawAlgo.h"

//��min~max֮���������һ����
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

//Ȩ��֮��
int SumOfWeight(map<int, int>& map1)
{
    int sumweight = 0;
    for (auto& it : map1)
    {
        sumweight += it.second;
    }
    return sumweight;
}

//���ؼ��Ƚ�
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

//input: int max �ڴ�����������ֵ��int min �ڴ����������Сֵ�� int num ��Ҫ��������ĸ���
//output: vector<int> װ�ز��������������������ǲ�ͬ�ģ�
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

//���ɾ���Ȩ�ص�������������ranIndex���ɵ�����ΪȨ�ص��ܺͣ�����Ȩ�طָ������䡣
// Parameter: vector<int> weight��:Ȩ��
// Parameter: int number	������:���������������
int* GetRandomNumWithWeight(vector<int> weight, int number)
{
    if (number <= 0 ) {
        printf("������������������Ϸ���\n");
        exit(-1);
    }
    int* p = (int*)malloc(number * sizeof(int));
    int ptr = 0;
    //*info = new vector<Employee>();
    int size = weight.size();

    //����Ȩ�ص��ܺ�
    //accumulate���������βΣ�ͷ�����β�ָ��Ҫ�ۼӵ�Ԫ�ط�Χ���������β������ۼӵĳ�ֵ
    int accumulateVal = accumulate(weight.begin(), weight.end(), 0);
    //cout << "Ȩ��֮�ͣ�" << accumulateVal << endl;
    //cout << "weight.size()��" << size << endl;
    auto randoms = CreateRandomNums(0, size, number);
    for (int i = 0; i < number; i++)
    {
        if (i < 0) {
            printf("����Ķ�̬��ַ���Ϸ���\n");
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
        int ranIndex = RandomBetween(0, accumulateVal);//����һ�������
        cout << i << "������һ�������:" << ranIndex << endl;

        //0 ~ weight[0]Ϊ1��weight[0]+1 ~ weight[1]Ϊ2����������
        //for (int j = 0; j < size && tem != (*info)->end(); j++, tem++)
        for (int j = 0; j < size ; j++)
        {
            tempSum += weight[j];
            if (ranIndex <= tempSum + weight[j])//&&(ranIndex > tempSum))
            {
               res[i] = j;
               cout << "�н����±꣺" << res[i] << endl;
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
    vector<int> weight = { 8000, 1000, 500, 10, 10, 10, 10, 10, 10, 10};//Ȩ��
    GetRandomNumWithWeight(weight, 3);//�������������
}
*/

/*
//�齱������
void startLuckDraw()
{
    //�齱����
    int luckyDrawNum = $("#txtNum").val();
    if (luckyDrawNum > remainPerson.length) {
        //����
    }
    //����н���
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
    //ʣ�������޳����н�����
    remainPerson = remainPerson.delete(randomPerson);
    //�н���Ա
    luckyMan = luckyMan.concat(randomPerson);
    //���ó齱����������Ϊ��
    $("#txtNum").val("");
}

*/
