/*Find R_prime of input*/

long RP(long input)
{
	long temp,i,m,p;
	if(input==1)
		{
			p=1;
		}
		else
		{			
			temp=p=input;	
			if(temp==1)
			{
				p=0;
			}
			else
			{			
				for(i=0;prime[i]<=sqrt(input);i++)
				{
					m=0;
					while(input%prime[i]==0)
					{
						input=input/prime[i];
						m=1;	
					}	
					if(m)
					{
						p=(p/prime[i])*(prime[i]-1);
					}
					if(input==1)
					{
						break;
					}
				}
				
				if(input>1)
				{
					p=(p/input)*(input-1);
				}
			}		
		}

		return p;
}