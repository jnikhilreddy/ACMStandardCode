long gcd(long a,long b)
{
        if(!b)
			return a;
        return gcd(b,a%b);
}

/***************gcd ***************/
long gcd(long a,long b)
{
     long c=1;
     if(a&&b)
	 {
		while(c)
		{
			c=b%a;
			b=a;
			a=c;
		}
	 }
     else if(a||b==0)
	 {
		 b=a;
	 }
     return b;
}




