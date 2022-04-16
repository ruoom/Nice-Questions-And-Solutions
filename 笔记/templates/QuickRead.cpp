
bool space;
inline int read() {
    space = 0;
    int w = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))if (c == '-')f = -1, c = getchar();
    while (isdigit(c))w = (w << 1) + (w << 3) + (c ^ 48), c = getchar();
    if (c == ' ')space = 1;
    return w * f;
}
//-------------------------------------------------------------------------------------
