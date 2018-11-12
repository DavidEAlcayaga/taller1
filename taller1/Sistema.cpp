#include "stdafx.h"
#include "Sistema.h"


Sistema::Sistema()
{
  this->administradores = new ListaPersona(1000);
  this->clientes = new ListaPersona(1000);
  this->eventos = new ListaEvento(1000);
  this->correlativoAdmn = 0;
  this->correlativoCliente = 0;
  this->correlativoEvento = 0;
}

bool Sistema::LeerArchivos()
{
	return false;
}

bool Sistema::GuardarArchivos()
{
	return false;
}

bool Sistema::AgregarEvento()
{
	cout << "Ingrese nombre" << endl;
	string nombre = NULL;
	cin >> nombre;
	cout << "Ingrese ciudad" << endl;
	string ciudad = NULL;
	cin >> ciudad;
	cout << "Ingrese idCliente" << endl;
	string idCliente = NULL;
	cin >> idCliente;
	cout << "ingrese tipo de evento" << endl;
	string tipo = NULL;
	cin >> tipo;
	cout << "Ingrese cantidad de personas esperadas" << endl;
	int personasEsperadas = 0;
	cin >> personasEsperadas;
	string idAdmin = NULL;
	int min = 99999;
	Administrador* adminAux = nullptr;

	for (int i = 0; i < this->administradores->getN(); i++) {
		if (this->administradores->getPosAdmin(i)->getEventosAdministrados()->getN() < min && this->administradores->getPosAdmin(i)->getCiudad().compare(ciudad) == 0) {
			min = this->administradores->getPosAdmin(i)->getEventosAdministrados()->getN();
			adminAux = this->administradores->getPosAdmin(i);
		}
	}
	if (adminAux == nullptr) {
		cout << "No hay administrador disponible en la ciudad, por favor agregue uno." << endl;
		return false;
	}
	else {
		idAdmin = adminAux->getId();
	}
	Evento* evento = new Evento(nombre, ciudad, idCliente, tipo, personasEsperadas, idAdmin);
	administradores->buscarAdmin(idAdmin)->getEventosAdministrados()->addEvento(*evento);
	eventos->addEvento(*evento);

}

bool Sistema::AgregarAdministrador()
{
	cout << "Ingrese nombre" << endl;
	string nombre = NULL;
	cin >> nombre;
	cout << "Ingrese apellido" << endl;
	string apellido = NULL;
	cin >> apellido;
	cout << "Ingrese ciudad" << endl;
	string ciudad = NULL;
	cin >> ciudad;
	Administrador* admin = new Administrador(nombre, apellido, ciudad, 7000, NULL);
	administradores->addAdmin(*admin);
}

bool Sistema::AgregarCliente()
{
	cout << "Ingrese nombre" << endl;
	string nombre = NULL;
	cin >> nombre;
	cout << "Ingrese apellido" << endl;
	string apellido = NULL;
	cin >> apellido;
	cout << "Ingrese ciudad" << endl;
	string ciudad = NULL;
	cin >> ciudad;
	cout << "Ingrese telefono" << endl;
	int telefono = NULL;
	cin >> telefono;
	Cliente* cliente = new Cliente(nombre, apellido, ciudad, telefono, "");
	clientes->addCliente(*cliente);
}

bool Sistema::EventoRealizado(string id, int cantidadAsistentes)
{
	Evento* evento;
	evento = eventos->buscarEvento(id);
	if (evento == nullptr) {
		cout << "No se encuentra el evento." << endl;
		return false;
	}
	else {
		if (evento->getPersonasAsistentes() > evento->getPersonasEsperadas()) {
			cout << "No v�lido, las personas asistentes no deben superar a las esperadas." << endl;
			return false;
		}
		else {
			cout << "Utilidad:  ";
			cout << evento->utilidad();
			cout << "  d�lares." << endl;
			Administrador* admin = administradores->buscarAdmin(evento->getIdAdministrador());
			admin->setMonto(admin->getMonto() + (evento->utilidad()*0.5));
			if (admin->getMonto() <= 0) {
				cout << "El administrador: ";
				cout << admin->toString();
				cout << "  fue despedido." << endl;
				administradores->eliminarPersona(admin->getId());
			}
			return true;
		}
	}
}

bool Sistema::CancelarEvento(string id)
{
	Evento* evento;
	evento = eventos->buscarEvento(id);
	if (evento == nullptr) {
		cout << "No se encuentra el evento." << endl;
		return false;
	}
	else {
		Administrador* admin = administradores->buscarAdmin(evento->getIdAdministrador());
		admin->setMonto(admin->getMonto() + (evento->coste()*0.25));
		evento->setCancelado();
		cout << "Evento: ";
		cout << evento->getNombre();
		cout << " cancelado" << endl;
		if (admin->getMonto() <= 0) {
			cout << "El administrador: ";
			cout << admin->toString();
			cout << "  fue despedido." << endl;
			administradores->eliminarPersona(admin->getId());
			return true;
		}
	}
}

void Sistema::EventosTipo(string tipo)
{
	eventos->buscarEventoTipo(tipo);
}

void Sistema::ClientesCiudad(string ciudad)
{
	clientes->toString(ciudad);
}

void Sistema::Administradores()
{
	administradores->toString();
}


Sistema::~Sistema()
{
}

bool Sistema::LeerArchivos() {

    ifstream arch1 ("Eventos.txt");

    string line1;
    if(arch1.is_open()){
        while(getline(arch1,line1)){
            stringstream ss (line1);

            string nombre;
            string ciudad;
            string idCliente;
            string idAdmin;
            string idEvento;
            string tipo;
            string estado;
            string personasEsperadas;
            getline(ss,nombre,',');
            getline(ss,ciudad,',');
            getline(ss,idCliente,',');
            getline(ss,idAdmin,',');
            getline(ss,idEvento,',');
            getline(ss,tipo,',');
            getline(ss,estado,',');
            getline(ss,personasEsperadas,',');
            int esperadas = stoi(personasEsperadas);
            string personasAsistentes;
            int asistentes;
            Evento* nuevoEvento;
            if(estado == "Realizado"){
                getline(ss,personasAsistentes,',');
                asistentes = stoi(personasAsistentes);
                nuevoEvento=  new Evento(nombre,ciudad,idCliente,idAdmin,idEvento,tipo,estado,esperadas,asistentes);
            }
            else{
                nuevoEvento = new Evento(nombre,ciudad,idCliente,idAdmin,idEvento,tipo,estado,esperadas,0);
            }


            this->eventos->addEvento(*nuevoEvento);


        }
    }
    else{
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }

    arch1.close();

    ifstream arch2 ("Administradores.txt");
    string line2;
    if(arch2.is_open()){

        while(getline(arch2,line2)){
            stringstream ss (line2);
            string nombre;
            getline(ss,nombre,';');
            string apellido;
            getline(ss,apellido,';');
            string idAdmin;
            getline(ss,idAdmin,';');
            string ciudad;
            getline(ss,ciudad,';');
            string montoStr;
            getline(ss,montoStr,';');
            Administrador* nuevoAdmin = new Administrador(nombre,apellido,ciudad,stoi(montoStr),0);

            while(!ss.eof()){

                string idEvento;
                getline(ss,idEvento,';');
                //TODO: FALTA AGREGAR EVENTOS A LA LISTA DE EVENTOS DEL ADMINISTRADOR

            }
            //TODO: Slicing
            this->administradores->addPersona(*nuevoAdmin);
        }

    }
    else{
        cout<<"NO SE PUDO CARGAR EL ARCHIVO ADMINISTRADORES"<< endl;
        return false;
    }

    ifstream arch3 ("Clientes.txt");
    string line3;

    if(arch3.is_open()){
        while(getline(arch3,line3)){
            stringstream ss (line3);
            string nombre;
            getline(ss,nombre,';');
            string apellido;
            getline(ss,apellido,';');
            string ciudad;
            getline(ss,ciudad,';');
            string idCliente;
            getline(ss,idCliente,';');
            string telefono;
            getline(ss,telefono,';');
            Cliente *nuevoCliente = new Cliente(nombre,apellido,ciudad,stoi(telefono),stoi(idCliente));
            while(!ss.eof()){

                string idEvento;
                getline(ss,idEvento,';');
                //TODO: FALTA AGREGAR EVENTOS A LA LISTA DE EVENTOS DEL ADMINISTRADOR

            }

            //TODO:SLicing
            this->clientes->addPersona(*nuevoCliente);



        }
    }
    else{
        return false;
    }




    return true;


}
