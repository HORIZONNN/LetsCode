
int next(char *s, int *nex, int pos)
{
    int i = 1;
    nex[1] = 0;
    int j = 0;
    while(i < s[0])
    {
        if( j == 0 || s[i] == s[j])
        {
            i++;
            j++;
            if(s[i] != s[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
}

int KMP(char *s1, char *s2)
{
    int i = 1;
    int j = 1;
    while(i <= s1[0] && j <= s2[0])
    {
        if(j == 0 || s1[i] == s2[j])
        {
            i++;
            j++;
            next[i] == j;
        }else
            j = next[j];
    }
    if(j > s2[0])
        return i-s2[0];
    else
        return 0;
}

int main()
{
    return 0;
}
