#include <stdio.h>
#include <stdlib.h>




int* ac(int * B)
{
    B[0] = 1;
    B[1] = 2;
    B[2] = '\0';
    return B;
}

int max_list(int* A , int N)
{
    int max_number=0 , now_number=0;
    for(int j = 0 ; j<N ; j++){
        now_number = 0;
        for(int i=j ; i<N ; i++){
            now_number += A[i];
            if(now_number > max_number) {
                max_number = now_number;
            }
        }
    }
    return max_number;
}

int Max_List(int* A , int N)
{
    int max ,now;
    max = now = 0;
    for(int i=0 ; i<N ; i++){
        now += A[i];
        if(now > max){
            max = now;
        }else if(now < 0){
            now = 0;
        }
    }
    return max;
}

int Binary_Search(int* A , int N , int X)       //对分算法求已排好序数组下标
{
    int Low = 0 , High = N-1;
    int Mid;
    while (Low <= High)
    {
        Mid = (Low + High) / 2;
        if(A[Mid] < X){
            Low = Mid + 1;
        }else if(A[Mid] > X){
            High = Mid - 1;
        } else{
            return Mid;
        }
    }return -1;
}

struct ListNode
{
    int data;
    struct ListNode* next;
};

typedef struct ListNode Node;
//创建新节点
Node* creatNode(int data)
{
    Node* creatNode = (Node*) malloc(sizeof(Node));
    creatNode -> data = data;
    creatNode -> next = NULL;
    return creatNode ;
}
//添加新节点
void appendNode(Node* *head , int data)
{
    Node* newNode = creatNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return;
}
//打印链表
void printList(Node* Node)
{
    while (Node != NULL){
        printf("%d\n" , Node ->data);
        Node = Node ->next;
    }
    return;
}

Node* findPrevious(int data , Node* List)
{
    Node* P;
    P = List;
    while(P->next != NULL && P->next->data != data ){
        P = P->next;
    }
    return P;
}
void deleteData(Node** headRef , int data)
{
    Node* head = *headRef;
    if(head != NULL && head->data == data){
        *headRef = head->next;
        free(head);
        return;
    }
    Node* previousNode = findPrevious(data , head);
    if(previousNode != NULL && previousNode->next != NULL){
        Node* deletedata = previousNode->next;
        previousNode->next = deletedata->next;
        free(deletedata);
    }
}
Node* findData(int data , Node* List)
{
    Node* P;
    P = List;
    while( P->next->data != data && P->next != NULL){
        P = P->next;
    }
    return P->next;
}


void Insert(int old_data , Node** headRef , int new_data)
{
    Node* head = *headRef;
    Node* Location = findData(old_data , head);
    if(Location != NULL)
    {
        Node* newNode = creatNode(new_data);
        newNode->next = Location->next;
        Location->next = newNode;
    }

}
void Insert_last(int new_data , Node** headRef)
{
    Node* head = *headRef;
    while (head->next != NULL)
    {
        head = head->next;
    }
    Node* new_Node = creatNode(new_data);
    head->next = new_Node;
}

//多项式ADT
#define MaxDegree 10

typedef struct
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
}*Polynomial;

typedef Polynomial Poly1,Poly2;

void ZeroPolynomial(Polynomial Poly)    //多项式清零
{
    for(int i=0 ; i<MaxDegree ; i++){
        Poly->CoeffArray[i] = 0;
        Poly->HighPower = 0;
    }
}
/*比较最大的幂*/
int FindMaxPower(Polynomial Poly1 , Polynomial Poly2)
{
    return (Poly1->HighPower > Poly2->HighPower) ?Poly1->HighPower :Poly2->HighPower;
}
/*多项式相加*/
void AddPolynomial(Polynomial Poly1 , Polynomial Poly2 , Polynomial PolySum)
{
    ZeroPolynomial(PolySum);
    PolySum->HighPower = FindMaxPower(Poly1 , Poly2);
    for(int i=PolySum->HighPower ; i>=0 ; i--){
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }
}
/*多项式相乘*/
void MultPolymial(const Polynomial Poly1 ,const Polynomial Poly2 , Polynomial PolyMult)
{
    ZeroPolynomial(PolyMult);
    PolyMult->HighPower = FindMaxPower(Poly1 , Poly2);
    if(PolyMult->HighPower >MaxDegree){
        printf("Exceeded array size\n");
    }else{
        for(int i=0 ; i<MaxDegree ; i++){
            for(int j=0 ; i<MaxDegree ; j++){
                PolyMult->CoeffArray[i+j] = Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
            }
        }
    }
}


int main() {
    //Node* head = NULL;
    Node* head = NULL;
    appendNode( &head, 1);
    appendNode(&head , 2);
    appendNode(&head , 3);
    printList(head);
    printf("\n");
    //deleteData(&head , 1);
    //Insert(3 , &head , 5);
    Insert_last(4 , &head);
    printList(head);

    return 0;
}
