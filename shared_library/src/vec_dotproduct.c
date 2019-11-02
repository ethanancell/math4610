double vec_dotproduct(double u[], double v[], int length)
{
	double sum = 0.0;
	for(int i=0; i<length; i++)
	{
		sum += u[i] * v[i];
	}

	return sum;
}
