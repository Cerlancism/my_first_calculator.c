#include <stdio.h>

#define FILE_NAME "my_first_calculator.c"

#define NUM_MIN 0
#define NUM_MAX 50

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

void printOperatorStatements(FILE *file, char sign, double min, double max, double((*func)(double, double)))
{
    double a, b;
    for (a = min; a <= max; a += 1)
    {
        for (b = min; b <= max; b += 1)
        {
            double c = func(a, b);
            fprintf(file, "%*sif (num1 == %d && sign == '%c' && num2 == %d)\n", 4, "", (int)a, sign, (int)b);
            fprintf(file, "%*sprintf(\"%d %c %d = %g\\n\");\n", 8, "", (int)a, sign, (int)b, c);
        }
    }
}

int main()
{
    FILE *outputFile = fopen(FILE_NAME, "w");

    fprintf(outputFile, "%*s%s\n", 0, "", "/* my_first_calculator.c by Cerlancism */");
    fprintf(outputFile, "%*s%s\n\n", 0, "", "/* TODO: Make it work for all floating point numbers too */");

    fprintf(outputFile, "%*s%s\n\n", 0, "", "#include <stdio.h>");

    fprintf(outputFile, "%*s%s\n", 0, "", "int main() {");
    fprintf(outputFile, "%*s%s\n", 4, "", "int num1 = 0, num2 = 0;");
    fprintf(outputFile, "%*s%s\n", 4, "", "char sign = '+';");
    fprintf(outputFile, "%*s%s\n", 4, "", "printf(\"Welcome to this calculator!\\n\");");
    fprintf(outputFile, "%*s%s\n", 4, "", "printf(\"It can add, subtract, multiply and divide whole numbers from 0 to 50\\n\");");
    fprintf(outputFile, "%*s%s\n", 4, "", "printf(\"Please choose your first number: \");");
    fprintf(outputFile, "%*s%s\n", 4, "", "scanf(\"%d\", &num1);");
    fprintf(outputFile, "%*s%s\n", 4, "", "printf(\"What do you want to do? +, -, /, or *: \");");
    fprintf(outputFile, "%*s%s\n", 4, "", "scanf(\" %c\", &sign);");
    fprintf(outputFile, "%*s%s\n", 4, "", "printf(\"Please choose your second number: \");");
    fprintf(outputFile, "%*s%s\n\n", 4, "", "scanf(\"%d\", &num2);");

    printOperatorStatements(outputFile, '+', NUM_MIN, NUM_MAX, add);
    printOperatorStatements(outputFile, '-', NUM_MIN, NUM_MAX, subtract);
    printOperatorStatements(outputFile, '/', NUM_MIN, NUM_MAX, divide);
    printOperatorStatements(outputFile, '*', NUM_MIN, NUM_MAX, multiply);

    fprintf(outputFile, "\n%*s%s\n", 4, "", "printf(\"Thanks for using this calculator, goodbye :)\");");

    fprintf(outputFile, "%*s%s\n", 4, "", "return 0;");
    fprintf(outputFile, "%*s%s\n", 0, "", "}");

    fclose(outputFile);
    return 0;
}