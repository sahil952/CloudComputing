#include <iostream>
using namespace std;

class Queue{
public:
    int size1;	  //size of array
    int f;        //front for deletion
    int r;        //rear for insertion
    int *a;       //array declaration
};

void enqueue(Queue *st,int data) // enqueue function for queue defined
{
    if(st->r==st->size1-1)  // rear == size - 1
	{
        cout<<"Queue FULL"<<endl;
    }
    else{
        st->r++;            //rear increment by 1
        st->a[st->r]=data;  //array[rear] = data
    }
}

int dequeue(Queue *st)   // dequeue function for queue defined
{
    int x=-1;
    if(st->f==st->r)     // front == rear
	{
        cout<<"Queue Empty"<<endl;
    }
    else{
        st->f++;         // front increment by 1
        x=st->a[st->f];  // data = array[front]
    }
    return x;            // function return data
}

int isempty(Queue *st)   // empty function for queue defined
{
    if(st->f==st->r)     // front == rear
	{
        return 1;
    }
    return 0;
}

int arr[8][8] = {{0,0,0,0,0,0,0,0},
                {0,0,1,1,1,0,0,0},
                {0,1,0,1,0,0,0,0},
                {0,1,1,0,1,1,0,0},
                {0,1,0,1,0,1,0,0},
                {0,0,0,1,1,0,1,1},
                {0,0,0,0,0,1,0,0},
                {0,0,0,0,0,1,0,0}}; // array declared and initialization - global variable

class graph{
public:
    int *visited;                   // visited array declared
};

void bfs(graph *t,Queue *q,int i)   // bfs function for graph defined
{
    cout<<i<<" ";
    t->visited[i]=1;                // source element i is marked visited
    enqueue(q,i);                   // enqueue visited element i
    while(!isempty(q))
	{
        int u = dequeue(q);         // dequeue element from queue if not empty
        for(int j=1;j<=8;j++){
            if(arr[u][j]==1&&t->visited[j]==0)  // check if path is present at position and it is not visited
			{
                cout<<j<<" ";       // print element
                t->visited[j]=1;    // mark it as visited
                enqueue(q,j);       // enqueue element
            }
        }
    }

}
void dfs(int u)						 // dfs function for graph defined
{
    static int visited[8]={0};       // initialize visited array elements by 0
    if(visited[u]==0)                // if not visited
	{
        cout<<u<<" ";                // print element
        visited[u]=1;                // mark visited
        for(int i=1;i<=8;i++){
            if(arr[u][i]==1 && visited[i]==0){  // check if path is present at position and it is not visited
                dfs(i);             // recursively call dfs
            }
        }
    }
}

int main()    //main function
{
    cout<<"*******MENU*******"<<'\n';    // menu driven program usinf switch case
    cout<<"1.BFS"<<'\n';
    cout<<"2.DFS"<<'\n';
    cout<<"3.Exit"<<'\n';
    int e=0;
    int c;
    while(e==0){
        cout<<'\n'<<"Enter Choice"<<'\n';
        cin>>c;                          // user enters choice
        switch(c){
            case 1:{
                graph t;
                Queue s;
                s.f=-1;                  // queue values initialised
                s.r=-1;
                s.size1=8;
                s.a=new int[8];
                t.visited=new int[8];    // visited initialised
                for(int i=0;i<8;i++){
                    t.visited[i]=0;
                }
                int c1;
                cout<<"Enter starting Vertex(1-7)"<<'\n';   
                cin>>c1;				 // source entered
                bfs(&t,&s,c1);           // bfs method called
                break;
            }
            case 2:{
                int c1;
                cout<<"Enter starting Vertex(1-7)"<<'\n';
                cin>>c1;                 // source entered
                dfs(c1);                 // dfs method called
                break;
            }
            case 3:{
                cout<<"Thank-You"<<'\n';
                e=1;
                break;
            }
            default: cout<<"Enter Valid Choice"<<endl;
        }
    }
    return 0;
}
