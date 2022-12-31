#include "WiPro.h"
#pragma warning(disable:4996)

int main()
{
    cout << "Hello World!\n";

    int x = 0;
    int y = 0;

    FILE* gnupipe = NULL;
    FILE* fp = NULL;

    const char* gnucommands[] = {"set title \"Demos\"", "plot 'data.tmp'"};

    fp = fopen("data.tmp", "w");

    if (!fp) {
        std::perror("File opening failed");
        return 0;
    }

    gnupipe = _popen("gnuplot -persistent", "w");

    for (int i = 0; i < 13; i++)
    {
        fprintf(fp, "%d %d\n", x, y);
        x += 2;
        y += 1;
    }

    for (int i = 0; i < 2; i++)
    {
        fprintf(gnupipe, "%s\n", gnucommands[i]);
    }
}