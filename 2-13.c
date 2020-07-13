#include <stdio.h>

#define VMAX   21

typedef struct {
	char name[20];
	int height;
	double vision;	
}PhysCheck;

double ave_height(const PhysCheck dat[],int n)
{
	int i;
	double sum = 0;
	for(i = 0;i < n;i++)
		sum += dat[i].height;
	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[]){
	int i;
	for(i = 0;i < VMAX;i++)
		dist[i] = 0;

	for(i = 0;i < n;i++)
		if(dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0);
			dist[(int)(dat[i].vision * 10)]++;
}

int main(){
	int i;
	PhysCheck x[] = {
		{"AKASAKA Taodao",  162, 0.3},
		{"KATOH Tomiaki",   173, 0.7},
		{"SAITOH Syouji",   175, 2.0},
		{"D",   171, 1.5},
		{"E",   168, 0.4},
		{"F",   174, 1.2},
		{"G",   169, 0.8},

	} ;
	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];

	puts("***Physical Check***");
	puts(" Name       height  vision");
	puts("--------------------");
	for(i = 0;i < nx; i++)
		printf("%-18.18s%4d%5.1f\n",x[i].name,x[i].height,x[i].vision);
	printf("\nAverage height: %5.1fcm\n", ave_height(x,nx));
	dist_vision(x,nx,vdist);

	printf("\nvision distribution\n");
	for(i = 0;i < VMAX; i++)
		printf("%3.1f~:%2d people\n",i / 10.0, vdist[i]);

	return 0;
}

