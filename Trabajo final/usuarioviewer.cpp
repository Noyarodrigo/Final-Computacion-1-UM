#include "usuarioviewer.h"
#include <iostream>
#include <map>
#include <typeinfo>
#include <stdlib.h>
#include "getpost.h"
#include "usuariodao.h"
#include "candidatoviewer.h"
#include "usuariocontroller.h"
using namespace std;

UsuarioViewer::UsuarioViewer()
{
    //ctor
}

UsuarioViewer::~UsuarioViewer()
{
    //dtor
}


void UsuarioViewer::listar(Queue* queue)
{
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><head>"<<endl;
	/*cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
	cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
	cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;*/
	cout << "</head>" <<endl;
	cout << "<body>   <div class='container'>"<<endl;
	cout<<"<div class='centrar'></div>"<<endl;
	cout<<"<div>"<<endl;
	cout<<"</div>"<<endl;
	queue->show();
	cout<<"</div></body></html>"<<endl;


}
void UsuarioViewer::inicio(){
	int z=0,x=0;

	x=(new UsuarioDAO())->checkLogin();

	if (x==0) {
		map<string,string> Post;
		initializePost(Post);
		cout<<"Content-type: text/html"<<endl<<endl;
		cout<<"<html><head>"<<endl;
		cout<<"<title>Elecciones 2018</title>"<<endl;
    cout<<"<link rel=\"stylesheet\" href=\"http://localhost/css.css\">"<<endl;
		href='https://fonts.googleapis.com/css?family=Lato:400,700' rel='stylesheet' type='text/css'>
		cout<< "</head>" <<endl;
		cout<< "<body>   <div class='container'>"<<endl;
		cout<<"<div class='header'></div>"<<endl;
		cout<<"<h1>LOG IN<h1>\n";
		cout<<"<div class='input'>"<<endl;
	  cout<<"<form class='form-signin' method='post'>"<<endl;
	  cout<<"<h2 class='form-signin-heading'>Ingrese su documento</h2>"<<endl;
	  cout<<"<label for='documento' class='sr-only'>Usuario</label>"<<endl;
	  cout<<"<input type='text' name='documento' class='form-control' placeholder='Documento' required autofocus>"<<endl;
	  cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Ingresar</button>"<<endl;
	  cout<<"</form>"<<endl;
	  cout<<"</div>"<<endl;


	      if (Post.find("documento")!=Post.end()) {
					z=(new UsuarioDAO())->checkusuario(Post["documento"]);
	          if(z == 1){
								((new UsuarioDAO()) ->setLogin(Post["documento"]));
								cout<<"<font color='green'><h1 align='center'>Ingreso con Exito!</h1></font>"<<endl;
								cout<<"<form align='center'>"<<endl;
								cout<<"<input value='Ir a las categorias' onClick='document.location.reload()' type='button' class='btn btn-outline-success my-2 my-sm-0'>"<<endl;
								cout<<"</form>"<<endl;
							}else{fracaso();}
						}

		cout<<"</div></body></html>"<<endl;
	}else{

		(new CandidatoController())->ver();

	}

}
void UsuarioViewer::votar(){
	map<string,string> Post;
	initializePost(Post);
	cout<<"<html><head>"<<endl;
	cout<< "</head>" <<endl;
	cout<< "<body>   <div class='container'>"<<endl;
	cout<<"<div class='centrar'></div>"<<endl;
	cout<<"<h3 color='grey'>Ingrese el codigo del candidato que desea votar<h1>\n";
	cout<<"<div class='container'>"<<endl;
	cout<<"<form class='form-signin' method='post'>"<<endl;
	cout<<"<label for='codigo' class='sr-only'>Codigo</label>"<<endl;
	cout<<"<input type='text' name='codigo' class='form-control' placeholder='Ingreselo AQUI' required autofocus>"<<endl;
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>VOTAR</button>"<<endl;
	cout<<"</form>"<<endl;
	cout<<"</div>"<<endl;
	 if (Post.find("codigo")!=Post.end()) {
		 (new UsuarioController())->control(Post["codigo"]);
	 }//else fail();


}
void UsuarioViewer::fracaso()
{
	cout<<"<font color='red'><h1 align='center'>Ingreso Incorrecto!</h1></font>"<<endl;
}

void UsuarioViewer::fail(){
	cout<<"<font color='red'><h1 align='center'>Ya has votado en esa categoria!</h1></font>"<<endl;
}
void UsuarioViewer::info(string id, string categoria) {
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><head>"<<endl;
  cout<<"	<br>	"<<endl;
	cout<<"<font color='grey'>"<<endl;
  cout<<"</h1>\n";
  cout<<"<h3>categoria: "<<categoria<<endl;
  cout<<"</h3>\n";
	cout<<"<h3>Su id de votante es:"+id<<endl;
	cout<<"</h3>\n";
	cout<<"</font>"<<endl;
	cout<<"</body></html>"<<endl;
}

void UsuarioViewer::yav(){
	cout<<"<font color='Green'><h1 align='center'>Voto ingresado !</h1></font>"<<endl;
}
