#include<stdio.h>
#include<string.h>
#include<math.h>
#define IN 99
#define N 6

int dijkstra(int cost[][N],int source,int target);
int dijkstra(int cost[][N],int source,int target)
{
	int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
	char path[N];
	for(i=1;i<N;i++)
	{
		dist[i]=IN;
		prev[i]=-1;
	}
	start=source;
	selected[start]=1;
	dist[start]=0;
	while(selected[target]==0)
	{
		min=IN;
		m=0;
		for(i=1;i< N;i++)
		{
			d = dist[start] +cost[start][i];
			if(d<dist[i]&&selected[i]==0)
			{
				dist[i] = d;
				prev[i] = start;
			}
			if(min>dist[i] && selected[i]==0)
			{
				min = dist[i];
				m = i;
			}
		}
		start = m;
		selected[start] = 1;
	}
	start = target;
	j = 0;
	while(start != -1)
	{
		path[j++] = start+64;
		start = prev[start];
	}
	path[j]='\0';
	for(i=strlen(path)-1;i>0;i--)
		printf("%c--->",path[i]);
	printf("%c",path[0]);
	return dist[target];
}
int main()
{
	int cost[N][N],i,j,w,ch,co;
	int source, target,x,y;
	printf("\tShortest Path Algorithm(DIJKSRTRA's ALGORITHM\n\n");
	for(i=1;i< N;i++)
		for(j=1;j< N;j++)
			cost[i][j] = IN;
	for(x=1;x< N;x++)
	{
		for(y=x+1;y< N;y++)
		{
			printf("Enter the weight of the path between node %c and %c: ",x+64,y+64);
			scanf("%d",&w);
			cost [x][y] = cost[y][x] = w;
		}
		printf("\n");
	}
	printf("\nEnter The Source:");
	scanf("%d", &source);
	printf("\nEnter The target");
	scanf("%d", &target);
	co = dijkstra(cost,source,target);
	printf("\nShortest Path: %d",co);
}
