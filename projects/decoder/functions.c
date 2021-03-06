/* The useful functions in wordScrambler and decoder. */

int is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')\
			|| (c >= '0' && c <= '9'))
		return 1;
	else
		return 0;
}

int is_lower_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else
		return 0;
}

int is_upper_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}

int is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}
