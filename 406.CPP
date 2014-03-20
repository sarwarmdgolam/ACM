	#include<stdio.h>
	#include<math.h>
	#define MAX  1001
	
	int * GetPrimeList()
	{		
		int primeList[MAX] ;
		int result[MAX] ,i,j,k;
		
		primeList[2]=1;
		for (i = 1; i < MAX; i=i+2)
			primeList[i] = 1;	
		
		double midPoint = ceil(MAX / 2.0);
		for ( j = 2; j <= midPoint; j++)
		{
			if (primeList[j] == 1)
			{
				for ( k = j + j; k < MAX; k = k + j)
					primeList[k] = 0;
			}
		}
		return primeList;
	}

	void PrintPrimeNumbers(int result[MAX], int startpoint, int endpoint)
	{
		int i;
		for(i=startpoint; i<=endpoint; i++)
		{
			printf(" %d",result[i]);
		}
		printf("\n\n");		
	}
	
	int main()
	{
		int j,N,C,len,startpoint,endpoint,midpoint;
		int primtListFinal[MAX];
		int primeCount[MAX];
		int index = 1;
		
		int *primeList = GetPrimeList();

		primtListFinal[0] = 0;
		for ( j = 1; j < MAX; j++)
		{
			if (primeList[j] == 1)
			{
				primtListFinal[index] = j;
				index++;
			}
			primeCount[j]=index-1;
		}

		while(scanf("%d%d", &N, &C)==2)
		{
			if (N < 1 || N>1000  )
				continue;
			printf("%d %d:",N,C);

			if(N==1 && C==1)
			{
				printf(" 1\n\n");
				continue;
			}
			len =  primeCount[N];
			midpoint = ceil( len/2.00 );

			if (C > midpoint)
				C = midpoint;

			if(len % 2 == 0)
			{
				startpoint = midpoint - (C-1);
				endpoint = midpoint + C;
			}
			else
			{
				startpoint = midpoint - (C-1);
				endpoint = midpoint + (C-1);
			}

			PrintPrimeNumbers(primtListFinal, startpoint, endpoint);
		}
		return 0;
	}
