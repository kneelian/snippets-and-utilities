bool is_prime(uint32_t in)
{
	if(in == 1) { return false; } else
	if(in == 2 or in == 3) { return true; } else
	if(in % 2 == 0) { return false; }
	

	for(int i = 3; i < sqrt(in) + 1; i++)
	{
		if(in % i == 0) { return false; }
	}
	return true;
}