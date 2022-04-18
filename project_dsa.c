#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define inf  INT_MAX
struct vertex
{
    char name[30];
};
struct edge
{
    int distance;
    int walk;
    int scooter;
    int bicycle;
};
int min_dist(int *,int *,int);
void shortest_distance(int ,int ,struct edge mat[][12],struct vertex v[12],int );
void shortest_walking(int s,int d,struct edge mat[][12],struct vertex v[12],int n);
void shortest_cycling(int s,int d,struct edge mat[][12],struct vertex v[12],int n);
void shortest_riding(int s,int d,struct edge mat[][12],struct vertex v[12],int n);
void edge_created(struct edge mat[12][12],int);
void vertex_display();
void vertex_created(struct vertex *,int);
void display_only(struct vertex *,int);
void display(struct vertex *,int);
void edge_display(struct edge mat[12][12],int,struct vertex v[12]);

int main()
{
    int s,d,ch,ch2;
    struct vertex v[12];
    struct edge mat[12][12];
    vertex_created(v,12);
    edge_created(mat,12);
    do{
    system("clear");
    printf("                    *      Go Goa Gone!        *\n");
    printf("\t1. Display Tourist Points\n\t2. Display distance between Tourist Points\n\t3. Edit database\n\t4. Find the shortest path\n\t5. Exit\n");
    printf("                           *****\n");
    printf("What would you like to do?\n");
    scanf("%d",&ch);
    switch(ch)
    {

            case 1: printf("\nThese are the Tourist Points on the map:\n");
                    display_only(v,12);
                    printf("\nPress enter to continue...\n");
                    fflush(stdin);
                    getchar();
                    break;
            case 2: edge_display(mat,12,v);
                    printf("\nPress enter to continue...\n");
                    fflush(stdin);
                    getchar();
                    break;
            case 3: printf("Enter source location->  ");
                    scanf("%d",&s);
                    printf("Enter destination->  ");
                    scanf("%d",&d);
                    printf("Initial distance, walking time, cycling time, riding time from %s to %s is ",v[s].name,v[d].name);
                    printf("%d km, %d hr, %d hr, %d hr respectively\n",mat[s][d].distance,mat[s][d].walk,mat[s][d].bicycle,mat[s][d].scooter);
                    printf("Enter the new distance, walking time, cycling time, riding time respectively:\n");
                    scanf("%d%d%d%d",&mat[s][d].distance,&mat[s][d].walk,&mat[s][d].bicycle,&mat[s][d].scooter);
                    printf("\nData updated successfully!\n");
                    printf("New distance, walking time, cycling time, riding time from %s to %s is ",v[s].name,v[d].name);
                    printf("%d km, %d hr, %d hr, %d hr respectively\nPress enter to continue...\n",mat[s][d].distance,mat[s][d].walk,mat[s][d].bicycle,mat[s][d].scooter);
                    fflush(stdin);
                    getchar();
                    break;
            case 4: printf("Enter source location->  ");
                    fflush(stdin);
                    scanf("%d",&s);
                    fflush(stdin);
                    printf("Enter destination->  ");
                    fflush(stdin);
                    scanf("%d",&d);
                    fflush(stdin);
                    printf("\nYou want to go from %s to %s.\n",v[s].name,v[d].name);
                    fflush(stdin);
                    printf("\n1. Minimise distance\n2. Minimise walking time\n3. Minimise cycling time\n4. Minimise riding time\n\nEnter your choice: ");
                    fflush(stdin);
                    scanf("%d",&ch2);
                    fflush(stdin);
                    switch(ch2)
                    {
                        case 1: shortest_distance(s,d,mat,v,12);
                                break;
                        case 2: shortest_walking(s,d,mat,v,12);
                                break;
                        case 3: shortest_cycling(s,d,mat,v,12);
                                break;
                        case 4: shortest_riding(s,d,mat,v,12);
                                break;
                        default:printf("Invalid Input\n");
                    }
                    printf("\nPress enter to continue...\n");
                    fflush(stdin);
                    getchar();
                    break;
            case 5: printf("Press 0 to exit and any other number to cancel\n");
                    scanf("%d",&ch);
                    break;
            default:printf("Invalid input, please try again\n");
                    printf("\nPress enter to continue...\n");
                    fflush(stdin);
                    getchar();
    }
    }while(ch);



}
void shortest_distance(int s,int d,struct edge mat[][12],struct vertex v[12],int n)
{
  int c[n],vertex[n],i,u,j,p[n];
  for(i=0;i<n;i++)
  {
    if(i==s)
        c[i]=0;
    else
        c[i]=inf;
    vertex[i]=0;
  }

  p[s]=-1;

  for(i=0;i<n-1;i++)
  {
     u=min_dist(c,vertex,n);  //Selecting Nearest vertex

     vertex[u]=1;

     for(j=0;j<n;j++)   //Relaxation
     {
         if(mat[u][j].distance != 0 && vertex[j] == 0)
         {
             if(mat[u][j].distance + c[u] < c[j])
             {
                c[j] = c[u] + mat[u][j].distance;
                p[j]=u;
             }
         }
     }
  }
  int fn=11,ar[12],fnf=c[d];
  ar[fn]=d;
  do
  {
      ar[--fn]=p[d];
      d=p[d];
  }while(p[d]!=-1);
  for(;fn<11;fn++)
    printf("%s--->",v[ar[fn]].name);
  printf("%s",v[ar[11]].name);
  printf("\nTotal distance = %d km\n",fnf);
}

int min_dist(int cost[],int vertices[],int n)
{
  int i,ind,min;
  for(i=0;i<n;i++)
    {
        if(vertices[i]==0)
            break;
    }
  ind=i;
  min=cost[i];
  i += 1;
  for(;i<n;i++)
  {
      if(vertices[i]==0)
      {
          if(cost[i]<min)
          {
              ind=i;
              min=cost[i];
          }

      }
  }
  return(ind);
}

void shortest_walking(int s,int d,struct edge mat[][12],struct vertex v[12],int n)
{
  int c[n],vertex[n],i,u,j,p[n];

  for(i=0;i<n;i++)
  {
    if(i==s)
        c[i]=0;
    else
        c[i]=inf;
    vertex[i]=0;
  }

  p[s]=-1;

  for(i=0;i<n-1;i++)
  {
     u=min_dist(c,vertex,n);  //Selecting Nearest vertex

     vertex[u]=1;

     for(j=0;j<n;j++)   //Relaxation
     {
         if(mat[u][j].walk != 0 && vertex[j] == 0)
         {
             if(mat[u][j].walk + c[u] < c[j])
             {
                c[j] = c[u] + mat[u][j].walk;
                p[j]=u;
             }
         }
     }
  }
  int fn=11,ar[12],fnf=c[d];
  ar[fn]=d;
  do
  {
      ar[--fn]=p[d];
      d=p[d];
  }while(p[d]!=-1);
  for(;fn<11;fn++)
    printf("%s--->",v[ar[fn]].name);
  printf("%s",v[ar[11]].name);
  printf("\nTotal walking time = %d hr\n",fnf);
}

void shortest_cycling(int s,int d,struct edge mat[][12],struct vertex v[12],int n)
{
  int c[n],vertex[n],i,u,j,p[n];

  for(i=0;i<n;i++)
  {
    if(i==s)
        c[i]=0;
    else
        c[i]=inf;
    vertex[i]=0;
  }

  p[s]=-1;

  for(i=0;i<n-1;i++)
  {
     u=min_dist(c,vertex,n);  //Selecting Nearest vertex

     vertex[u]=1;

     for(j=0;j<n;j++)   //Relaxation
     {
         if(mat[u][j].bicycle != 0 && vertex[j] == 0)
         {
             if(mat[u][j].bicycle + c[u] < c[j])
             {
                c[j] = c[u] + mat[u][j].bicycle;
                p[j]=u;
             }
         }
     }
  }
  int fn=11,ar[12],fnf=c[d];
  ar[fn]=d;
  do
  {
      ar[--fn]=p[d];
      d=p[d];
  }while(p[d]!=-1);
  for(;fn<11;fn++)
    printf("%s--->",v[ar[fn]].name);
  printf("%s",v[ar[11]].name);
  printf("\nTotal cycling time = %d hr\n",fnf);
}
void shortest_riding(int s,int d,struct edge mat[][12],struct vertex v[12],int n)
{
  int c[n],vertex[n],i,u,j,p[n];

  for(i=0;i<n;i++)
  {
    if(i==s)
        c[i]=0;
    else
        c[i]=inf;
    vertex[i]=0;
  }

  p[s]=-1;

  for(i=0;i<n-1;i++)
  {
     u=min_dist(c,vertex,n);  //Selecting Nearest vertex

     vertex[u]=1;

     for(j=0;j<n;j++)   //Relaxation
     {
         if(mat[u][j].scooter != 0 && vertex[j] == 0)
         {
             if(mat[u][j].scooter + c[u] < c[j])
             {
                c[j] = c[u] + mat[u][j].scooter;
                p[j]=u;
             }
         }
     }
  }
  int fn=11,ar[12],fnf=c[d];
  ar[fn]=d;
  do
  {
      ar[--fn]=p[d];
      d=p[d];
  }while(p[d]!=-1);
  for(;fn<11;fn++)
    printf("%s--->",v[ar[fn]].name);
  printf("%s",v[ar[11]].name);
  printf("\nTotal riding time = %d hr\n",fnf);
}

void vertex_display()
{
    printf("\nPlaces in the city are\n");
    printf("\n1. Baga Beach\n2. Vasco Da Gama\n3. Dudhsagar Falls\n4. Latin Quarter\n5. Chapora Falls\n6. Amboli Waterfalls\n7. Palolem Beach\n8. Agonda Beach\n9. Corjuem Fort\n10. Velsao Beach\n11. Immaculate Conception Church\n12. Escobar");
}
void vertex_created(struct vertex v[],int n)
{
    strcpy(v[0].name,"Baga Beach");
    strcpy(v[1].name,"Vasco Da Gama");
    strcpy(v[2].name,"Dudhsagar Falls");
    strcpy(v[3].name,"Latin Quarter");
    strcpy(v[4].name,"Chapora Falls");
    strcpy(v[5].name,"Amboli Waterfalls");
    strcpy(v[6].name,"Palolem Beach");
    strcpy(v[7].name,"Agonda Beach");
    strcpy(v[8].name,"Corjuem Fort");
    strcpy(v[9].name,"Velsao Beach");
    strcpy(v[10].name,"Immaculate Conception Church");
    strcpy(v[11].name,"Escobar");
}

void display_only(struct vertex v[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d. %s\n",i,v[i].name);
}

void display(struct vertex v[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf("press %d for %s\n",i,v[i].name);
}
void edge_created(struct edge mat[12][12],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
              mat[i][j].distance=0;
              mat[i][j].walk=0;
              mat[i][j].bicycle=0;
              mat[i][j].scooter=0;
            }
            else if(i<j)
            {
              mat[i][j].distance=rand()%100;
              mat[i][j].walk=rand()%15;
              mat[i][j].bicycle=rand()%15;
              mat[i][j].scooter=rand()%15;
            }
        }
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(i>j)
        {
          mat[i][j].distance=mat[j][i].distance;
          mat[i][j].walk=mat[j][i].walk;
          mat[i][j].bicycle=mat[j][i].bicycle;
          mat[i][j].scooter=mat[j][i].scooter;
        }
    }
}
void edge_display(struct edge mat[12][12],int n,struct vertex v[12])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(mat[i][j].distance)
        printf("%s to %s     =     %d Km\n",v[i].name,v[j].name,mat[i][j].distance);
    }
}