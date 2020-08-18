#include <iostream>
#include <string>

using namespace std;

struct Estudiante
{
	string nombre, carrera, hobby;
	int edad;
	Estudiante *signombre, *sigedad, *sigcarrera, *sighobby;
};

struct Datos
{
	string atrib;
	Estudiante *pos;
};

Estudiante * buscarPosNombre(string nom, Estudiante *cab)
{
	Estudiante *aux, *aux1;
	aux=cab;

	if ((aux == NULL) || (nom < aux->nombre))
	{
		return NULL;
	}
	else
	{
		while ((aux != NULL) && (nom > aux->nombre))
		{
			aux1=aux;
			aux=aux->signombre;
		}
	}
	return aux1;
}

Estudiante * buscarPosCarrera(string car, Estudiante *cab)
{
	Estudiante *aux, *caja;
	aux=cab;

	if ((aux == NULL) || (car == aux->carrera))
	{
		return NULL;
	}
	else
	{
		while ((aux != NULL) && (car == aux->carrera))
		{
			caja=aux;
			aux=aux->sigcarrera;
		}
	}
	return caja;
}

Estudiante * buscarPosHobby(string hob, Estudiante *cab)
{
	Estudiante *aux, *caja;
	aux=cab;

	if ((aux == NULL) || (hob == aux->hobby))
	{
		return NULL;
	}
	else
	{
		while ((aux != NULL) && (hob == aux->hobby))
		{
			caja=aux;
			aux=aux->sighobby;
		}
	}
	return caja;
}

Estudiante * buscarPosEdad(int edad, Estudiante *cab)
{
	Estudiante *aux, *caja;
	aux=cab;

	if ((aux == NULL) || (edad > aux->edad))
	{
		return NULL;
	}
	else
	{
		while ((aux != NULL) && (edad < aux->edad))
		{
			caja=aux;
			aux=aux->sigedad;
		}
	}
	return caja;
}

string getNombre(Estudiante *sel)
{
	return sel->nombre;
}

int getEdad(Estudiante *sel)
{
	return sel->edad;
}

string getCarrera(Estudiante *sel)
{
	return sel->carrera;
}

string getHobby(Estudiante *sel)
{
	return sel->hobby;
}

Estudiante * getSigNombre(Estudiante *sel)
{
	return sel->signombre;
}

Estudiante * getSigCarrera(Estudiante *sel)
{
	return sel->sigcarrera;
}

Estudiante * getSigEdad(Estudiante *sel)
{
	return sel->sigedad;
}

Estudiante * getSigHobby(Estudiante *sel)
{
	return sel->sighobby;
}

void insertar(string nom, string carr, string hob, int edad, Estudiante *cab, Datos C[])
{
	Estudiante *ant, *nuevo;

	nuevo=new Estudiante;

	nuevo->nombre=nom;
	nuevo->carrera=carr;
	nuevo->hobby=hob;
	nuevo->edad=edad;

	nuevo->signombre=NULL;
	nuevo->sigcarrera=NULL;
	nuevo->sighobby=NULL;
	nuevo->sigedad=NULL;

	ant=buscarPosNombre(nom, C[0].pos);

	if (ant == NULL)
	{
		nuevo->signombre=C[0].pos;
		C[0].pos=nuevo;
	}
	else
	{
		nuevo->signombre=ant->signombre;
		ant->signombre=nuevo;
	}

	int x;
	if (carr == "sistemas")
	{
		ant=buscarPosCarrera(carr, C[3].pos);
		x=3;
	}
	else if (carr == "electronica")
	{
		ant=buscarPosCarrera(carr, C[1].pos);
		x=1;
	}
	else if (carr == "industrial")
	{
		ant=buscarPosCarrera(carr, C[2].pos);
		x=2;
	}

	if (ant == NULL)
	{
		nuevo->sigcarrera=C[x].pos;
		C[x].pos=nuevo;
	}
	else
	{
		nuevo->sigcarrera=ant->sigcarrera;
		ant->sigcarrera=nuevo;
	}

	ant=buscarPosEdad(edad, C[4].pos);

	if (ant == NULL)
	{
		nuevo->sigedad=C[4].pos;
		C[4].pos=nuevo;
	}
	else
	{
		nuevo->sigedad=ant->sigedad;
		ant->sigedad=nuevo;
	}

	if (hob == "danza")
	{
		ant=buscarPosHobby(hob, C[5].pos);
		x=5;
	}
	else if (hob == "natacion")
	{
		ant=buscarPosHobby(hob, C[6].pos);
		x=6;
	}
	else if (hob == "baloncesto")
	{
		ant=buscarPosHobby(hob, C[7].pos);
		x=7;
	}
	else if (hob == "beisbol")
	{
		ant=buscarPosHobby(hob, C[8].pos);
		x=8;
	}

	if (ant == NULL)
	{
		nuevo->sighobby=C[x].pos;
		C[x].pos=nuevo;
	}
	else
	{
		nuevo->sighobby=ant->sighobby;
		ant->sighobby=nuevo;
	}
}

int main ()
{
	int i;
	Estudiante *cab, *pos;
	cab=new Estudiante;
	Datos C[9];

	C[0].atrib = "Nombre";
	C[1].atrib = "Carrera Electronica";
	C[2].atrib = "Carrera Industrial";
	C[3].atrib = "Carrera Sistemas";
	C[4].atrib = "Edad";
	C[5].atrib = "Hobby Danza";
	C[6].atrib = "Hobby Natacion";
	C[7].atrib = "Hobby Baloncesto";
	C[8].atrib = "Hobby Beisbol";

	for (i=0;i<9;i++)
	{
		C[i].pos=NULL;
	}

	for (i=1;i<=4;i++)
	{
		cout<<"----------------------------"<<endl;
		cout<<"Iteracion "<<i<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"Ingrese nombre: ";
		string n,c,h;
		int e;
		cin>>n;
		cout<<"Ingrese carrera: ";
		cin>>c;
		cout<<"Ingrese edad: ";
		cin>>e;
		cout<<"Ingrese hobby: ";
		cin>>h;

		insertar(n,c,h,e,cab,C);
	}

	cout<<"Nombre------"<<endl;

	pos=C[0].pos;
	while (pos != NULL)
	{
	 	cout<<getNombre(pos)<<endl;
	 	pos=getSigNombre(pos);
	}

	cout<<"Carrera------"<<endl;

	pos=C[3].pos;
	while (pos != NULL)
	{
		cout<<getNombre(pos)<<endl;
		pos=getSigCarrera(pos);
	}

	cout<<"Edad------"<<endl;

	pos=C[4].pos;
	while (pos != NULL)
	{
		cout<<getNombre(pos)<<endl;
		pos=getSigEdad(pos);
	}

	cout<<"Hobby------"<<endl;

	pos=C[7].pos;
	while (pos != NULL)
	{
		cout<<getNombre(pos)<<endl;
		pos=getSigHobby(pos);
	}

	return 0;
}
