#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<array>
#include<ctime>
using namespace std;    //在函数外部使用的命名空间是全局的

//结构相关
struct information
{
    string name;    //结构体的成员name，age，cast
    int age;
    float cast;
}woman ={"maria", 16, 25.62};   //直接在}外侧加属性可以直接生成



information people1, people2, people3;  //另一中结构变量定义方式

int main()
{   
    clock_t project_start_time = clock();   //捕捉程序开始时的系统时间
    //指针相关
    int val1 = 5;
    int* p3 = new int;  //分配内存过程就完成了定义
    int* p1 = &val1;    //int*只是说明定义一个指向int的指针，是(int*)p2而不是int(*p2),指针自己也不是int
    *p3 = 100;
    cout << *p3 <<"  "<< p3 << endl;
    delete p3;
    double* p2 = new double [3];//动态数组，new分配内存，与delete成对使用 type_name* pointer_name = new type name [] 接下行
    //delete [] pointer_name 为实体分配内存而不是数组时则不写
    p2[0] = 0.2;
    p2[1] = 0.3;
    p2[2] = 0.5;
    cout << *p2 <<endl;     //指针指向数组的第一个元素
    delete [] p2;       //释放动态数组内存
    cout << *p1 <<"  "<< p1 <<endl;   //*p1指指针p1对应的值

    //结构与指针，结构已经在程序开始定义出来了
    people1.age = 25;
    information* pa = &people2;     //指针pa指向people2，information只是说明他是一个information格式的结构体
    pa->name = "kangkang";      //pa为指针不可不是直接的变量，所以需要用->来引用成员变量
    information man[2] =    //定义结构数组的方法
    {   
        {"yaoming", 20, 53.2},
        {"liu", 65, 32.2}
    };
    
    information alian[2];   //先定义出结构数组然后在给成员赋值
    alian[0].age = 284;     //给第一个结构直接赋值
    (alian+1)->age = 285;   //数组名alian是一个指针
    cout << alian->age << endl;

    //指针数组
    information* arp[3] = {&people1, &people2, &people3};
    cout << arp[1]->name << endl;
    information ** ppa = arp;//arp是一个数组所以他同时也是一个指向第一个元素的指针，他的第一个元素也是一个指针所以使用const information**
    //**表示指针指向一个存储指针的空间，被存储的指针指向数据(int之类)

    //指针与字符串
    const char* p4 = "gugu";//这里的指针确实是指向"gugu"的地址，但是没有必要知道里面的值是什么，只需要照搬照抄即可
    //那用地址指里面的内容不是更省事吗？实际上对p4进行赋值的话是把其他指针也指向这个地址，而不是对这个地址里的内容进行修改，下面进行说明解决方法
    cout << p4 <<"  "<< *p4 << endl;    //使用*p4的话会只打印第一个字符
    char* p5 = new char [strlen(p4) + 1];   //先申请内存，在字符数组中最后一位为\0以表示结束，在strlen计算长度时并不会计算在内所以需要手动+1为\0空间
    strncpy(p5, p4, 20);    //先开辟新的内存之后再p4的值复制到p5中去，得到得到一个内存地址不同的值,20为复制大小（可设置不完全复制）
    cout << p5 <<endl;

    //vector类，vector类是自动的new，delete动态数组，方便但效率稍低
    vector<double> v1;      //建立一个空vector，类型为double，名字为v1
    vector<double> v2(5);       //建立一个长度为5，类型为double，名字为v2的vector

    //array类，array采用static来创建，所以不可变长，但是比数组安全，注意！不可用变量来规定长度
    array<double, 4> arr2 = {1.0, 2.0, 3.0, 3.2};      //建立一个长度为4类型为double的array
    array<double, 4> arr1 = {};
    arr1 = arr2;    //array可以直接赋值其他array
    cout << arr1[3] << " " << arr2[3] <<endl; 

    //循环
    int i, j;  
    for (i = 0, j = 3;i <= 3, j>=0;i++, j--)//在for循环中可以使用逗号来构建多个不同的控制部分，逗号也是运算优先级最低的运算符
    {
       cout << arr1[i] <<endl; 
       cout << arr1[j] <<endl;
    }
    
    //字符串检测，使用strcmp==>strcmp(str1, str2) relationship 
    const char* str1 = "have a nice day";
    const char* str2 = "good luck";
    char str3[10] = "declare";
    cout << int(strcmp(str1, str2) !=0) << endl ; //判断字符(char定义字符串而非string)是否相等，可以改为 == 等其他判断条件
    
    //字符循环，只是一种对循环的练习
    string str4 = "?nd"; 
    for (char ch = 'a'; str4 != "end"; ch++)
    {
        str4[0] = ch;
        cout << str4 << endl;  
    }

    //一种字符遍历方法
    int k = 0;
    char str5[20];
    cout << "input string: ";
    cin >> str5;
    while (str5[k] != '\0')
    {
        cout << str5[k] <<" ";
        k++;
    }
    cout << endl;

    //一种计时方式
    double time;
    cout << "input time: ";
    cin >> time;
    clock_t display_time = time * CLOCKS_PER_SEC;
    clock_t time_start = clock();
    while ((clock() - time_start) < display_time);
    cout << "done" <<endl;

    //二维数组操作
    int arr_dimen2[2][3] = {
        {1, 2, 3},
        {3, 4, 5}
    };
    cout << sizeof(arr_dimen2) << " " << sizeof(arr_dimen2[0]) << endl;

    //指针常量，常量指针
    int num1 = 1;
    int num2 = 2;
    const int* p6 = &num1;
    //*p6 = num2;不可以修改指针指向的值
    p6 = &num2;     //可以修改指针的指向
    int* const p7 = &num2;
    *p7 = num1;     //可以修改指针指向的值
    //p7 = &num1;不可以修改指针的指向




    clock_t project_final_time = clock();   //捕捉程序结束时的系统时间
    cout << (project_final_time - project_start_time) / CLOCKS_PER_SEC;     //CLOCK_PER_SEC是每秒走过的系统时间，为常数
    return 0;  
}

