#include "ISOExtractor.cpp"

int main(int argCount, char *argValues[])
{
	ISOExtractor extractor;

	extractor.Execute("test.iso");

	return EXIT_SUCCESS;
}