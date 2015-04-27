#include "ISOExtractor.cpp"

int main(int argCount, char *argValues[])
{
	ISOExtractor extractor;

	extractor.TestEndianess();

	extractor.TestISO("test.iso");

	return EXIT_SUCCESS;
}