int _strcat(char *string1, const char *addition, char *final_string)
{
	if (string1 == NULL || final_string == NULL)
		return (-1);
	char* ptr = final_string;
	while (*string1 != '\0')
	{
		*ptr = *string1;
		ptr++;
		string1++;
	}
	while (*addition != '\0')
	{
		*ptr = *addition;
		ptr++;
		addition++;
	}


}
