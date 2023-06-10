#ifndef MANEJADOR_ASSETS_H
#define MANEJADOR_ASSETS_H

#include <SFML\Graphics.hpp>
#include <map>
#include <string>

class ManejadorAssets
{
public:

 //constructor
 ManejadorAssets();

 //funcion estatica para obtener las texturas
 static sf::Texture &obtenerTextura(std::string const &nombreArchivo);

private:

 //mapa que me servira manejar las texturas por medio de identificadores de cadenas
 std::map<std::string, sf::Texture> m_Texturas;

 //El manejador de assets es un singleton, esto solo es una instancia que puede
 //existir al mantener un puntero estatico en una simple instancia del manejador
 static ManejadorAssets *sIntancia;
};

#endif
