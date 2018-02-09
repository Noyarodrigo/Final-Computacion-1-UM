#include "candidatoviewer.h"
#include <iostream>
#include <map>
#include <typeinfo>
#include <stdlib.h>
#include "getpost.h"
#include "usuariodao.h"
#include "string.h"
#include <sstream>

using namespace std;

CandidatoViewer::CandidatoViewer()
{
    //ctor
}

CandidatoViewer::~CandidatoViewer()
{
    //dtor
}
void CandidatoViewer::mostrar(){
  map<string,string> Get;
  initializeGet(Get);
  if (Get.find("categoria")!=Get.end()) {
    listar(Get["categoria"]);
    }else{
      cout<<"Content-type: text/html"<<endl<<endl;
      cout<<"<html><head>"<<endl;
      cout<<"<font color='blue'><h1 align='center'>Elije el tipo de eleccion a continuacion</h1></font>"<<endl;
      cout<<"</body></html>"<<endl;
      cout<<"	<br>	"<<endl;
      cout<<"	<br>"<<endl;
      cout<<"	<br>"<<endl;
      cout<<"<form class='form-signin' method='get'>"<<endl;
      cout<<"  <fieldset>"<<endl;
      cout<<"    <legend>Elige una categoria luego, haz click en siguiente</legend>>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"          <input type=\"radio\" name=\"categoria\" value=\"1\"> Consejales"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"           <input type=\"radio\" name=\"categoria\" value=\"2\"> Legisladores"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"          <input type=\"radio\" name=\"categoria\" value=\"3\"> Senadores"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"          <input type=\"radio\" name=\"categoria\" value=\"4\"> Diputados"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"           <input type=\"radio\" name=\"categoria\" value=\"5\"> Intendentes"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"          <input type=\"radio\" name=\"categoria\" value=\"6\"> Gobernadores"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"          <input type=\"radio\" name=\"categoria\" value=\"7\"> Presidentes"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"  </fieldset>"<<endl;
      cout<<"	<br>	"<<endl;
      cout<<"<div align='center'>"<<endl;
      cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Ingresar</button>"<<endl;
      cout<<"</div>"<<endl;
      cout<<"</form>"<<endl;
      cout<<"</body></html>"<<endl;

  }
}

void CandidatoViewer::listar(string opc){
  cout<<"Content-type: text/html"<<endl<<endl;
  cout<<"<html><head>"<<endl;
  cout<<"<font color='green'><h1 align='center'>ACA VA LA LISTA</h1></font>"<<endl;
  cout<<"<font color='green'><h1 align='center'>eleccion"<<opc<<endl;
  cout<<"</h1></font>"<<endl;
  cout<<"</body></html>"<<endl;
  //((new UsuarioDAO())->checkcandidato(Post["documento"]));
}