#ifndef JURY
#define JURY

int jury(const char *binary, const char *inputs[], const char *expected_outputs[], const int testset_len, int (*eval)(char *output, const char *expected_output));
int equal_outputs(char *output, const char *expected_output);

#endif