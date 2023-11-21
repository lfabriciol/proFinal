#include <iostream>
#include <vector>
#include <windows.h> //gotoxy
#include <conio.h>   //getch(ocultar palabra)
using namespace std;
struct Login
{
	int codLogin;
	string nomLogin;
	string usuarioLogin;
	string passLogin;
};

struct Producto
{
	int codProducto;	
	string nomProducto;
	float preProducto;
	int cantProducto;	
};

struct Registro
{
	int codRegistro;
	int cantRegistro;
	string nomRegistro;
	string clienteRegistro;
	float preRegistro;
};
vector<Login> vecLogin;
vector<Producto> vecProducto;
vector<Registro> vecRegistro;

void 	registrarTienda();
void 	addVector();
void 	iniciarSeccion();
void 	listEmpleados();
void 	addProducto();
void	buscarPorCodigo();
void	removeProducto();
void 	modificarProducto();
int 	obtenerPosicionDelRegistro(int);
void 	listProductos();
void	comprasCliente();
void 	listaClientes();

int 	getCorrelativo();
int 	getCodigoP();


void 	gotoxy(int, int);
void 	recuadro(int, int, int, int);

int main() 
{
	system("mode con: cols=100 lines=35"); // tamaño de la consola
	
	registrarTienda();
}
void registrarTienda()
{
	addVector();
	int opcion;	
	do
	{
		cout << "      MENU DE OPCIONES\n";
		cout << "==========================\n";
		cout << "INICIAR SECCION		[1]\n";
		cout << "SALIR			[2]\n";
		cout << "==========================\n";			
		cout << "Ingrese una opcion [1-2]: ";cin >> opcion;
		
		switch(opcion)
		{
		case 1 :  system("cls");
				  iniciarSeccion();
				  system("pause");
				  system("cls");
				  break;
		case 2 :  break;
		default: cout << "Ingrese una opcion valida[1-2]\n ";
		}
	} while(opcion != 2);
}
void addVector()
{
	//ADMIN
	vecLogin.push_back({1, "Lucho Perez", "l100", "l1234"}); 
	//VENDEDORES
	vecLogin.push_back({2, "Jose Jimenez", "j100", "j1234"});
	vecLogin.push_back({3, "Mario Olaya", "m100", "m1234"});	
	
	//PRODUCTOS
	vecProducto.push_back({1, "Leche Gloria", 2.50, 30});
	vecProducto.push_back({2, "Coca Cola", 6, 25});
	vecProducto.push_back({3, "Harina", 1.80, 15});
}
void agregarVendedores()
{	
	string usuaLog,
		passLog,
		nomLog,
		rpta;
	int cod;
	do{
	cod = getCorrelativo();
	cout << "Codigo: "<<cod<<endl;
	cin.ignore();
	cout << "Nombre: "; getline(cin,nomLog);
	cout << "Ingrese Usuario: ";cin >> usuaLog;
	cout << "Ingrese Contraseña: "; cin >> passLog;
	
	
	Login login;
	login.codLogin = cod;
	login.nomLogin = nomLog;
	login.usuarioLogin = usuaLog;
	login.passLogin = passLog;
	
	vecLogin.push_back(login);
	cout << "Seguir agregando empleados(S/s): ";
	cin >> rpta;
	}while(rpta=="S"||rpta=="s");
}
void iniciarSeccion()
{
	string  usuario,
			contra;
	int 	ch,
			contador = 0,
			opcion;
	bool 	flag = false;
	do
	{
	system("cls");
	recuadro(32, 2, 64,11 );
	
	gotoxy(38,5);cout << "USER :     ";cin >> usuario;
	gotoxy(38,7);cout << "PASSWORD : ";
	ch = getch(); 
	while(ch!=13)//poner el texto ingresado oculto           
	{
		if(ch != 8)	//'8' = caracter de borrado
		{	
		contra.push_back(ch);
		cout <<'*';
		}
		else
		{
			if(contra.length() > 0) //contraseña al menos tenga un caracter
			{
			cout << "\b \b"; //efecto de borrado
			contra  = contra.substr(0,contra.length() - 1); //tomar primeros caracteres menos el ultimo
			/*borra el ultimo caracter*/
			
			}
		}
		ch = getch();
	}
	for(int i = 0; i <vecLogin.size();i++)
	{
			if(usuario == vecLogin[i].usuarioLogin && contra == vecLogin[i].passLogin)
			{
				system("cls");				
				cout << "LOGIN EXITOSO: Bienvenido "<< vecLogin[i].nomLogin << endl;
				system("pause");system("cls");
				flag = true;
				if(vecLogin[i].codLogin == 1)
				{
				  do
				  {
					cout << "\tMENU ADMINISTRADOR\n";
					cout << "===============================\n";					
					cout << "Agregar Vendedores       [1]\n";
					cout << "Listar Vendedores	 [2]\n";
					cout << "Agregar Productos	 [3]\n";
					cout << "Buscar Producto	         [4]\n";
					cout << "Eliminar Producto        [5]\n";
					cout << "Modificar Producto       [6]\n";
					cout << "Listar Producto          [7]\n";
					cout << "Registro Clientes	 [8]\n";
					cout << "Salir                    [9]\n";
					cout << "===============================\n";					
					cout << "Ingrese una opcion [1-9]: ";
					cin >>opcion;
					switch(opcion)
					{
					case 1: system("cls");
							agregarVendedores();
							system("pause");
							system("cls");							
							break;
					case 2: system("cls");
							listEmpleados();
							system("pause");
							system("cls");
							break;
					case 3: system("cls");
							addProducto();
							system("pause");
							system("cls");
							break;
					case 4: system("cls");
							buscarPorCodigo();
							system("pause");
							system("cls");
							break;
					case 5:	system("cls");
							removeProducto();
							system("pause");
							system("cls");
							break;
					case 6:	system("cls");
							modificarProducto();
							system("pause");
							system("cls");
							break;
					case 7: system("cls");
							listProductos();
							system("pause");
							system("cls");
							break;
					case 8: system("cls");
							listaClientes();
							system("pause");
							system("cls");
							break;
					case 9: break;
					default: cout << "Ingrese una opcion valida [1-9]...";break;							
					}
				  }while(opcion != 9);
					break;
				}
				else
				{
				  do
				  {
					cout << "VENTAMAS: MENU DE VENTAS\n";
					cout << "===============================\n";						
					cout << "Buscar Producto	         [1]\n";
					cout << "Listar Producto          [2]\n";
					cout << "Orden			 [3]\n";
					cout << "Salir                    [4]\n";
					cout << "===============================\n";	
					cout << "Ingrese una opcion [1-4]: ";
					cin >> opcion;
					switch(opcion)
					{
					case 1:	system("cls");
							buscarPorCodigo();
							system("pause");
							system("cls");
							break;
					case 2:	system("cls");
							listProductos();
							system("pause");
							system("cls");
							break;
					case 3: system("cls");
							comprasCliente();
							system("pause");
							system("cls");
							break;
					case 4: break;
					default: cout << "Ingrese una opcion valida [1-4]...";break;
					}
				  }while(opcion != 4); break;
				}
			}		
	}
	if(flag == false)
	{
		gotoxy(1,17);cout << "\n'ERROR': ACCESO DENEGADO\n";
		contador ++;
	}
	}while(flag  == false && contador < 3);
	if( flag == false)
	{
		cout << "MUCHOS INTENTOS REGISTRADOS. CERRANDO LOGIN...."<<endl;
	}
}
void addProducto()
{
	string rpta, 
		   nomPro;
	int    cod, 
		   stkPro;
	float  prePro;
	
	/*Agregando datos al arreglo*/
	do
	{
		cod = getCodigoP();
		cout << "Codigo: "<<cod<<endl;
		cin.ignore();
		cout << "Producto :"; getline(cin,nomPro);
		cout << "Precio :"; cin >> prePro;
		cout << "Stock: "; cin >> stkPro;
		
		/*Declarar un tipo de dato para la estructura*/
		Producto producto;
		producto.codProducto = cod;
		producto.nomProducto = nomPro;
		producto.preProducto = prePro;
		producto.cantProducto = stkPro;
		
		/*Agregar el registro al arreglo*/
		vecProducto.push_back(producto);
		cout <<"Deseas continuar registrando producto...(S/s): ";
		cin >>rpta;
		
		system("cls");
	} while(rpta=="S"||rpta=="s");
}
void buscarPorCodigo()
{
	int codigo;
	cout << "Ingrese el codigo a buscar: ";
	cin  >> codigo;
	for(int i = 0; i < vecProducto.size(); i++)
	{
		if (codigo == vecProducto[i].codProducto)
		{
			cout << "Codigo: " << vecProducto[i].codProducto << endl;
			cout << "Nombre: " << vecProducto[i].nomProducto << endl;
			cout << "Precio: " << vecProducto[i].preProducto << endl;
			cout << "Stock: "  << vecProducto[i].cantProducto << endl;
			break;//Salir del ciclo
		}
	}	
}
void removeProducto()
{
	int cod;
	bool flag = false;
	cout << "Ingrese el codigo del producto a eliminar: ";
	cin >> cod;
	for(int i =0; i < vecProducto.size();i++)
	{
		if(cod == vecProducto[i].codProducto)
		{
			vecProducto.erase(vecProducto.begin() + i);
			flag = true;
			break;
		}
	}
	if(flag == true)
	{
		cout << "Registro eliminado satisfactoriamente!!!\n";
	}
	else
	{
		cout << "Registro no encontrado!!!\n";
	}
}
void modificarProducto()
{
	int cod;
	cout << "Ingrese el codigo del registro a modificar: ";
	cin >> cod;
	int posEncontrada = obtenerPosicionDelRegistro(cod);
	if(posEncontrada == -1)
	{
		cout << "El codigo ingresado no exite!!!\n";
	}
	else
	{	
		int opcion;
		string nombre;
		float precio;
		int stock;
		cout << "Ver Registro a modificar:\n";
		cout << "==========================\n";
		cout << "Codigo: "<<vecProducto[posEncontrada].codProducto << endl;
		cout << "Nombre: "<<vecProducto[posEncontrada].nomProducto << endl;
		cout << "Precio: "<<vecProducto[posEncontrada].preProducto << endl;
		cout << "Stock: "<<vecProducto[posEncontrada].cantProducto << endl;
		cout << "==========================\n";	
		cout << "MODIFICACIONES\n";
		cout << "*********************\n";
		cout << "Nombre\t\t[1]\n";
		cout << "Precio\t\t[2]\n";
		cout << "Stock\t\t[3]\n";
		cout << "*********************\n";
		cout << "Seleccionar una opcion a modificar: ";
		cin >> opcion;
		switch(opcion)
		{
		case 1:
			cin.ignore();
			cout << "Cambiar Nombre: ";
			getline(cin, nombre);
			vecProducto[posEncontrada].nomProducto = nombre;break;
		case 2: 
			cout << "Cambiar Precio: ";
			cin >> precio;
			vecProducto[posEncontrada].preProducto = precio;break;
		case 3: 
			cout << "Cambiar Stock: ";
			cin >> stock;
			vecProducto[posEncontrada].cantProducto = stock;break;
		default: cout << "Ingrese una opcion correcta[1-3]\n";
		}
	}
}
int obtenerPosicionDelRegistro(int codigo)
{
	for(int i = 0; i < vecProducto.size();i++)
	{
		if(codigo == vecProducto[i].codProducto)
		{
			return i;
		}
	}
	return -1;
}
void listProductos()
{
	for(int i=0; i<vecProducto.size();i++)
	{
		cout <<"===========================================\n";
		cout <<"Codigo:  " <<  vecProducto[i].codProducto << endl;
		cout <<"Nombre:  " <<  vecProducto[i].nomProducto << endl;
		cout <<"Precio:  " <<  vecProducto[i].preProducto << endl;
		cout <<"Stock:   " <<  vecProducto[i].cantProducto << endl;
		cout <<"===========================================\n";		
	}
}
void listEmpleados()
{
	for(int i=1; i<vecLogin.size();i++)
	{
		cout <<"===========================================\n";
		cout <<"Nombre:  " <<  vecLogin[i].nomLogin << endl;
		cout <<"Usuario:  " <<  vecLogin[i].usuarioLogin << endl;
		cout <<"Contraseña:  " <<  vecLogin[i].passLogin << endl;
		cout <<"===========================================\n";		
	}	
}
void comprasCliente()
{
	int cod,cantidad;
	string cliente,rpta;
	float importeAPagar = 0;
	bool flag = false;

	cout << "\t  ORDEN" << endl;
	listProductos();
	cin.ignore();
	cout << "Cliente: ";getline(cin, cliente);
	do
	{
		flag = false;
	cout << "Ingrese codigo del producto: ";
	cin >> cod;	
	cout << "cantidad: ";
	cin >> cantidad;
	for(int i = 0 ; i < vecProducto.size();i++)
	{
		if (cod == vecProducto[i].codProducto)
		{
			flag = true;
			if(cantidad <= vecProducto[i].cantProducto)
			{
			importeAPagar += vecProducto[i].preProducto*cantidad;
			vecProducto[i].cantProducto = vecProducto[i].cantProducto - cantidad;
			
			Registro registro;
			registro.codRegistro = vecProducto[i].codProducto;
			registro.nomRegistro = vecProducto[i].nomProducto;
			registro.cantRegistro = cantidad;
			registro.preRegistro = vecProducto[i].preProducto*cantidad;
			registro.clienteRegistro = cliente;
			vecRegistro.push_back(registro);
			break;
			}
			else
			{
				cout << "\nLa cantidad solicitada supera al stock..."<<endl;
				break;
			}
		}
	}
	if(flag == false)
	{
		cout << "\nProducto no encontrado"<<endl;
	}	
	cout << "\nContinuar(S/s): "; cin >> rpta;
	system("cls");
	cout << "\t  ORDEN" << endl;listProductos();
	}while(rpta == "S" || rpta == "s");
	
	
	system("cls");
	cout << "\t\tRECIBO " << endl;
	
	cout << "\n #" << "\tproducto" << "\t\tprecio"<<endl;
	cout << "\n====================================="<<endl;	
	cout << "CLIENTE: " << cliente <<endl;

		cout << " x" << vecRegistro[vecRegistro.size() - 1].cantRegistro  <<"\t" << vecRegistro[vecRegistro.size() - 1].nomRegistro << "\t\t" <<vecRegistro[vecRegistro.size() - 1].preRegistro  << endl;
	
	cout << "\n====================================="<<endl;
	cout << "\nTotal a pagar: "  << importeAPagar<<endl;
	
}
void listaClientes()
{
	for(int i = 0; i < vecRegistro.size(); i++)
	{
		cout << "===========================\n" << endl;		
		cout << "CLIENTE: " <<vecRegistro[i].clienteRegistro << endl;
		cout << "PRODUCTO: " << vecRegistro[i].nomRegistro << endl;
		cout << "CANTIDAD: " << vecRegistro[i].cantRegistro << endl;
		cout << "COSTO: " << vecRegistro[i].preRegistro << endl;
		cout << "===========================\n" << endl;
	}	
}

int getCorrelativo()
{
	if (vecLogin.size() == 0)//Esta vacio
	{
		return 1;
	}
	else
	{
		return vecLogin[vecLogin.size()-1].codLogin + 1;
	}	
}
int getCodigoP()
{
	if (vecProducto.size() == 0)//Esta vacio
	{
		return 1;
	}
	else
	{
		return vecProducto[vecProducto.size()-1].codProducto + 1;
	}	
}

void gotoxy(int x, int y)//funcion para posicionar elementos
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}
void recuadro(int xs,int ys, int xi, int yi) 
{
	for(int i= xs; i <= xi;i++)
	{
		gotoxy(i,ys);printf("%c",196);
		gotoxy(i,yi);printf("%c",196);	
	}
	for(int i= ys; i <= yi;i++)
	{
		gotoxy(xs,i);printf("%c",179);
		gotoxy(xi,i);printf("%c",179);	
	}
	gotoxy(xs,ys); printf("%c",218);
	gotoxy(xi,yi); printf("%c",217);
	gotoxy(xi,ys); printf("%c",191);
	gotoxy(xs,yi); printf("%c",192);	
}

