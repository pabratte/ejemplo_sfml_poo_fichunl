# Ejemplo SFML
## Programación Orientada a Objetos FICH-UNL

Ejemplo de videojuego desarrollado utilizando [SFML](https://www.sfml-dev.org) y técnicas de Programación Orientada a Objetos


## Ideas generales

El ejemplo está dividido en 2 partes. Por un lado los archivos correspondientes a un mini motor de videojuegos o gestor de escenas que se encuentran en la carpeta *poo_game*, que no deberían ser modificados. Por otro lado, los archivos de la carpeta *src*, que corresponden a las escenas y entidades del juego de ejemplo, que pueden ser tomados como base y modificados o reemplazados por otros archivos. Se sugiere que todos los archivos de código correspondientes al juego (y no a la biblioteca) se almacenen en la carpeta src.

Dentro del proyecto también hay una carpeta *assets* destinada a guardar los recursos del juego (texturas, fuentes, sonidos, etc).


## Escenas

Todo juego tiene al menos una escena. Una escena es una colección de entidades (elementos del juego, como por ej: el personaje, items, enemigos, etc) que se actualizan y dibujan en pantalla. La escena inicial del juego se especifica cuando se crea una instancia de la clase **Game** desde la función *main()*.

Para crear un nuevo juego es necesario definir una escena creando una clase que herede de **BaseScene** y redefiniendo algunos de sus métodos.

La clase BaseScene tiene algunos de los siguientes métodos:

```cpp
virtual void update(float elapsed);
virtual void draw(sf::RenderWindow &w);
void add(Entity *e);
void remove(Entity *e);
```

Los métodos *update(...)* y *draw(...)* se encargan de actualizar y dibujar la escena. Su comportamiento por defecto es invocar a los métodos homónimos para cada una de las entidades asociadas a la escena (como veremos más adelante, las entidades también tienen métodos *update(...)* y *draw(...)* propios). Estas funciones son virtuales, por lo que pueden reimplementarse en nuestras propias escenas.

El comportamiento por defecto de la función *draw(...)* mencionada anteriormente generalmente será suficiente para cualquier tipo de juego. Por otro lado, es bastante probable que se quiera redefinir el método *update(...)* en nuestra clase hija para agregar nuestra propia lógica de actualizado.

El método update recibe como único parámetro el tiempo transcurrido desde la última actualización. Al redefinir el método *update(...)* es necesario tener en cuenta que no nos interesa sobreescribir completamente el método en nuestra clase hija, sino agregarle nuestro propio código. Para ésto, lo que debemos hacer es, en nuestra redefinición del método, invocar al método update(...) de la clase padre.

```cpp
void MiEscena::update(float elapsed){
    BaseScene::update(elaspsed);

    /// agregar aqui la logica especifica de nuestra escena
}
```

Finalmente, los métodos *add(...)* y *remove(...)* permiten agregar y eliminar entidades de la escena. Ambos reciben un puntero a cualquier objeto que herede de la clase **Entity**.

En el constructor de nuestra escena inicializaremos las entidades que la componen y las agregaremos a la misma utilizando *add(...)*. 


## Creando entidades

Las entidades son los elementos que componen la escena. Cada entidad tiene métodos *update(...)* y *draw(...)* que indican cómo debe actualizarse y cómo debe dibujarse la misma. Dichos métodos serán invocados automáticamente por la escena en la cual se encuentre la entidad.

Para definir un elemento del juego (como por ej: el jugador o la pelota) debemos heredar de la clase **Entity** y definir (ya que la clase es abstracta) los métodos *update(...)* y *draw(...)*. En el caso del ejemplo, tanto el jugador como la pelota poseen como atributo un **sf::Sprite** y el método *draw(...)* indica cómo dibujarlo en la ventana. La lógica de cada elemento está definida en *update(...)*


### TODO/Ideas

* Agregar una clase SpriteEntity como para facilitar las cosas y para el fondo

### Ideas un poco más locas

* Un manejador de texturas
* Un manejador de animaciones