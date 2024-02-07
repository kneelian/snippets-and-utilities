float  FUNC_PRINTBOY(void);
void    SUB_PRINTMAN(void);
void SUB_PRINTFATHER(void);

void* EXT2()
{
	return (void*)SUB_PRINTFATHER;
}

void* EXT3()
{
	return (void*)SUB_PRINTMAN;
}

typedef void (*fndef)(void);

void EXT4(void* A)
{
	fndef fptr = (fndef)A;
	fptr();
}

void EXTERNAL()
{
	FUNC_PRINTBOY();
	SUB_PRINTMAN();
	SUB_PRINTFATHER();
	return;
}