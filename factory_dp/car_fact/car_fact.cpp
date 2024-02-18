#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;


class Standard
{
    public:
        virtual void veiculo() = 0;

};

class Carro : public Standard
{
    public:
        void veiculo()
        {
            cout << "Carro criado" << endl;
        }
};


class Bicicleta : public Standard 
{
    public: 
        void veiculo()
        {
            cout << "Bicicleta criada" << endl;
        }
};

class Moto : public Standard
{
    public:
        void veiculo()
        {
            cout << "Moto criada" << endl;
        }
};

enum Tipo
{
    CARRO,
    BICICLETA,
    MOTO

};

class Factory
{
    public:
        Standard *create(Tipo t)
        {
            switch(t)
            {
                case CARRO:
                    return  new Carro();
                case BICICLETA:
                    return new Bicicleta();
                case MOTO:
                    return new Moto();
            }
        }
};


int main()
{
    srand(NULL);
    vector<Standard*> s;
    Factory f;
    
    for(int i = 0; i < 3; i++)
    {
        int t = rand() % 2;
        if(t == 0)
            s.push_back(f.create(CARRO));
        else if(t == 1)
            s.push_back(f.create(BICICLETA));
        else
            s.push_back(f.create(MOTO));
    }

    for (Standard* s : s)
    {
        s->veiculo();
    }

    for(Standard* s : s)
    {
        delete s;
    }
    s.clear();
}