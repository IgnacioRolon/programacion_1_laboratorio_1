int getInt(char *message, char *errorMessage, int minimum, int maximum, int tries, int *input);
int isValidInt(int number, int maximum, int minimum);
int getFloat(char *message, char *errorMessage, float minimum, float maximum, int retries, float *input);
int isValidFloat(float number, float minimum, float maximum);
int getChar(char *message, char *errorMessage, char minimum, char maximum, int retries, char *input);
int isValidChar(char letter, char minimum, char maximum);
int isStrOnlyChar(char buffer[]); //analiza un array de caracteres. Devuelve 0 si algun caracter NO es letra.
