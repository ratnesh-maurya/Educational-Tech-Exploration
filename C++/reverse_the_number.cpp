int reverse(int x)
{
	int sign = 1;
	int rev = 0;
    
    if (x == -2147483648)
        return (0);
	if (x < 0)
	{
		sign = -1;
		x *= -1;
	}
	while (x / 10 != 0)
	{
		if ((2147483647 / 10) - rev < x % 10)
			return (0);
		rev = (rev + x % 10) * 10;
		x = x / 10;
	}
	rev += x;
	return (rev * sign);
}