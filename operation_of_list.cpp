#include<iostream>
#include<string>
using namespace std;

typedef struct Node
{
    int id;
    int score;
    Node* next;
}Node;
Node* list_head;
void scan_list();
void print_list();
void bubble_sort();
void add_point();
void delete_point();


int main()
{
    scan_list();
    //print_list();
    //bubble_sort();
    cout<<"-----------------"<<endl;
    //print_list();
    add_point();
    cout<<"-----------------"<<endl;
    print_list();
    return 0;
}

void scan_list()
{
    int id;
    Node* list_temp = NULL; //过渡指针，负责链间各节点，就算temp指向位置1的时候，使temp->next指向位置二就可以了
    list_head = NULL; //头指针，初始化为NULL
    list_temp = list_head;  //一开始将过渡指针指向头部
    cout<<"please input id, if you want stop inputing, please input #: "<<endl;
    while(cin>>id) //判断是否有id输入
    {   
        cout<<"please input score: "<<endl;
        Node* list_body = new Node; //为list_body申请空间，因为需要存储数据，所以new暂时不需要delete
        list_body->id = id; //id唯一确定，直接赋值即可
        cin>>list_body->score; //输入id对应的score
        list_body->next = NULL; //在每一次输入过程中，刚输入那一位的后面就没有数据了，所以为NULL
        if(list_head == NULL) //如果头部没有数据的话
        {
            list_head = list_body;
        }
        else
        {
            list_temp->next = list_body;
        }
        list_temp = list_body; //移动过渡指针，准备下一次连接
        cout<<"please input id: "<<endl;
    }
    string haha;
    cin >> haha;
}

void print_list()
{
    Node* list_temp = list_head; //操作链表是从头开始的，所以一开始的过渡指针和全局指针list_head指向相同
    while(list_temp != NULL)
    {
        cout<<"id: "<< list_temp->id<<"--"<<"score: "<< list_temp->score<< endl;
        list_temp = list_temp->next;
    }
}

void bubble_sort()
{
    Node* list_end = NULL; //初始化一个表末指针
    Node* list_temp = list_head;
    while(list_temp != list_end) //检验N
    {   
        while(list_temp->next !=list_end) //检验N-1
            {   
                int cache_score, cache_id;
                if(list_temp->score < list_temp->next->score)
                    {
                        cache_score = list_temp->score;
                        list_temp->score = list_temp->next->score;
                        list_temp->next->score = cache_score; 
                        cache_id = list_temp->id;
                        list_temp->id = list_temp->next->id;
                        list_temp->next->id = cache_id;
                    }
                list_temp = list_temp->next; //换下两个数字进行比较
            }          
        list_end = list_temp;
        list_temp = list_head;
    }
}

void add_point()
{   
    string choose;
    Node* list_temp = list_head;
    Node* new_body = new Node;
    cout<<"you want to add a point? [y/n]" << endl;
    cin>>choose;
    cout<<choose<<endl;
    while(choose == "y")
    {   
        cout<<"please input new id of new point: " << endl;
        cin>>new_body->id;
        cout<<"please input new score of new point: " << endl;
        cin>>new_body->score;
        new_body->next = NULL;
        if(list_temp == NULL||new_body->score >list_temp->score)
        {
            new_body->next = list_temp;
            list_head = new_body;
        }
        else
        {
            while(list_temp != NULL && new_body->score < list_temp->score)
            {
                if(new_body->score > list_temp->next->score)
                    break;
                list_temp = list_temp->next;
            }
                new_body->next = list_temp->next;
                list_temp->next = new_body;
        }
    cout<<"you want continue add a point? [y/n]";
    cin>>choose;
    }
}

void delete_point()
{   
    string choose;
    int id;
    cout<<"want to delete point? [y/n]";
    cin>>choose;
    while(choose == "y")
    {   
        cout<<"please input id which you wanna delete: ";
        Node* list_temp = list_head;
        Node* cache = NULL;
        if(list_head != NULL)
        {
            if(id == list_temp->id)
            {
                cache = list_temp->next;
                delete list_temp;
                list_temp =NULL;
                list_head = cache;
            }
            else
            {
                while(id != list_temp->id && list_temp->next != NULL)
                {   
                    cache = list_temp;
                    list_temp = list_temp->next;
                    if(list_temp->id == id)
                    {
                        cache->next = list_temp->next;
                        delete list_temp;
                        list_temp =NULL;
                    }
                    list_temp = list_temp->next;
                }
            }
        }
    cout<<"continue delete point? [y/n]";
    }
}




