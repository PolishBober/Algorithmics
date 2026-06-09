#include <bits/stdc++.h>
using namespace std;

string s;

bool CzyCyf(char a)
{
    if (a >= 48 && a <= 57) return 1;
    else return 0;
}

bool CzyLit(char a)
{
    if ((a >= 97 && a <= 122) || (a >= 65 && a <= 90)) return 1;
    else return 0;
}

bool Pal(int a, int b)
{
    int dlug = b-a;
    for (int i = 0; i < dlug / 2; i++)
    {
        if (tolower(s[a+i]) != tolower(s[b-i]))
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int spacje = 0, liczby = 0, slowa = 0, zdania = 0, palindromy = 0, bzdania = 0, idxSlowa = -1;
    int n;

    cin >> n;

    short int tab[n];

    for (int i = 0; i < n; i++) cin >> tab[i];

    cin.ignore();
    getline(cin, s);

    s.append(" ");

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') spacje++;

        if (CzyCyf(s[i]) == 1)
            if (CzyCyf(s[i+1]) == 0) liczby++;

        if (CzyLit(s[i]) == 1)
        {
            if (idxSlowa == -1) idxSlowa = i;
            if (CzyLit(s[i+1]) == 0)
            {
                slowa++;
                if (Pal(idxSlowa, i) == 1) palindromy++;
                idxSlowa = -1;
            }
        }

        if (s[i] == '.')
        {
            if (bzdania != slowa) zdania += 1;
            bzdania = slowa;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (tab[i] == 1) cout << spacje-1 << " ";
        else if (tab[i] == 2) cout << liczby << " ";
        else if (tab[i] == 3) cout << slowa << " ";
        else if (tab[i] == 4) cout << zdania << " ";
        else if (tab[i] == 5) cout << palindromy << " ";
    }

    return 0;
}