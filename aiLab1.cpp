#include<cstdio>

int main()
{
    int edges;
    printf("number of edges: ");
    scanf("%d",&edges);
    int con[100][100];
    int s[100], d[100];
    int source, destination;
    for(int i = 0; i < edges; i++)
    {
        printf("Source and Destination for Edge %d:  ", i );
        scanf("%d %d", &source,&destination);
        s[i]=source;
        d[i]=destination;

//        for(int j = 0; j < edges; j++)
//        {
//            scanf("%d", &con[i][j]);
//            //printf("\n%d %d %d\n%d\n",i,j, con[i][j],isConnected);
//        }
    }
    int maxS, maxD;
    for(int i=1;i<edges;i++)
    {
        if(s[i] > s[i-1]) maxS=s[i]; else maxS=s[i-1];
        if(d[i] > d[i-1]) maxD=d[i]; else maxD=d[i-1];
    }
    int nodes;
    if(maxS>maxD) nodes=maxS; else nodes=maxD;

    printf("%d", nodes);

//
//    bool isLineFinished=false;
//    for(int i = 0; i < node; i++)
//    {
//        printf("\n    ");
//        if(!isLineFinished)
//        {
//            for(int x=0; x<node; x++)
//            {
//                printf("E%d ",x);
//            }
//            isLineFinished=true;
//        }
//        printf("\nV%d  ",i);
//
//        for(int j = 0; j < node; j++)
//        {
//            printf("%d  ", con[i][j]);
//        }
//    }
}
