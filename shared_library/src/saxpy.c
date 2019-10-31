void saxpy(float scalar, float* u, float* v, int length)
{
	for(int i=0; i<length; i++)
	{
		v[i] = v[i] + scalar*u[i];
	}
}
