#include <SFML\Graphics.hpp>
#include "ManejadorAssets.h"

int main()
{
 //Creo mi ventana
 sf::RenderWindow window(sf::VideoMode(640 , 480), "Animacion de Sprite Simple");
 window.setFramerateLimit(60);

 //Creo mi objeto manejador de Assets
 ManejadorAssets assets;

 //Creo mis variables que controlaran los tiempos
 sf::Time tiempoTranscurrido;
 sf::Clock reloj;

 //Variable para determinar el tamaño de mi sprite individual
 //algunos sprite sheet las separaciones pueden variar, sera necesario probar
 //hasta ajustar bien la animacion solo en algunas excepciones
 sf::Vector2i tamSprite(76, 64); 

 //Usando el manejador de assets creo mi sprite
 sf::Sprite sprite(ManejadorAssets::obtenerTextura("sheep.png"));

 //Coloco en el primer frame la primera imagen de mi sprite
 sprite.setTextureRect(sf::IntRect(0, 0, tamSprite.x, tamSprite.y));

 //establesco el numero de frames que contendra mi imagen
 int numFrames = 7;

 //establesco una duracion de retardo para cambiar al siguiente frame
 float duracionAnimacion = 1; //1 segundo

 //coloco una posicion de mi sprite en la escena
 sprite.setPosition(100, 100);

 //GameLoop
 while (window.isOpen())
 {
  window.clear();
  
  //Regresa el tiempo transcurrido y reinicia el reloj
  sf::Time deltaTime = reloj.restart();

  //Acumula el tiempo con cada frame que pasa
  tiempoTranscurrido += deltaTime;
  float tiempoEnSegundos = tiempoTranscurrido.asSeconds();

  //obtiene el frame de la animacion actual
  int frameAnimacion = static_cast<int>((tiempoEnSegundos / duracionAnimacion) * numFrames) % numFrames;

  //establece el rectangulo de la  textura, dependiendo en que frame se encuentre
  sprite.setTextureRect(sf::IntRect(frameAnimacion * tamSprite.x, 0, tamSprite.x, tamSprite.y));
  
  //dibujo la animacion
  window.draw(sprite);

  //Eventos
  sf::Event event;

  //Se manejan los eventos
  while (window.pollEvent(event))
  {
   //Creo una sentencia switch para controlar muchos eventos
   switch (event.type)
   {

   //Cierra la ventana
   case sf :: Event::EventType::Closed:
    window.close();
    break;

   default:
    break;
   }
  }

  window.display();
 }

 return 0;
}
