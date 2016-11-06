#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print_lista(vector< vector<int> > lista, map<int, string> rede, string caminho);
int rota(vector <vector<int> > lista, string caminho);

int main()
{
	map<int, string> rede;
	vector< vector<int> > lista;
	vector<int> v;

	int matriz[8][8] = {
        {0,0,1,0,0,0,1,0},
        {0,0,1,0,0,0,0,1},
        {0,0,1,0,0,0,0,0},
        {0,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0},
        {1,1,1,1,0,1,0,1},
        {0,0,0,1,0,0,1,0}
    };

	string caminho = "1721";

	rede[0] = "Ronily";
	rede[1] = "Pablo";
    rede[2] = "Michael";
    rede[3] = "Camilla";
    rede[4] = "Pedro";
    rede[5] = "Anderson";
    rede[6] = "Vitoria";
    rede[7] = "Bruno";

    for(int i = 0; i < 8; i++)
    {
    	lista.push_back(v);
    	for(int j = 0; j < 8; j++)
    	{
    		if(matriz[i][j])
    			lista[i].push_back(j);
    	}
    }

    print_lista(lista,rede,caminho);

    cout << rota(lista,caminho) << endl;

	return 0;
}

void print_lista(vector< vector<int> > lista, map<int, string> rede, string caminho)
{
	for(int i = 0; i < 8; i++)
	{
		cout << rede[i] << ": ";
		for(int j = 0; j < lista[i].size(); j++)
		{
			cout << rede[lista[i][j]] << " ";
		}
		cout << endl;
	}
}

int rota(vector <vector<int> > lista, string caminho)
{
	string::iterator it;
	int cont,i = 0;
	for(it = caminho.begin(); it != caminho.end()-1; it++)
	{
		i++;
		cont = 0;
		for(int j = 0; j < lista[(*it)-'0'].size(); j++)
		{
			if(lista[(*it)-'0'][j] == (*(it+1) - '0'))
				cont++;
		}
		if(!cont)
			return i;
	}
	return 1;
}