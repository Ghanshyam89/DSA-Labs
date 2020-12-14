// Developed by: Ghanshyam Prajapati

#include <stdio.h>
 
int main(){
	long long H;
	long long  c,q;
	scanf("%lld%lld%lld", &H,&c,&q);
	long h[c],s[c],e[c];
	for(long long  i=0;i<c;i++)
	scanf("%lld%lld%lld",&h[i],&s[i],&e[i]);
	for(long long  z=0;z<q;z++)
	{
		long  long x,y;
		scanf("%lld%lld",&x,&y);
		long long b=0;
		for(long long  i=0;i<c;i++)
		{
			if(y>=s[i] && y<=e[i])
			{
              if(x>h[i])
				  b++;
			  else
				  {printf("NO\n");
			       break;
				  } 
			}
			else
			{
				if(y<=H)
				b++;
				else
				{
					printf("NO\n");
					break;
				}
			}
		}
		if (b==c)
		printf("YES\n");
	}
	}
