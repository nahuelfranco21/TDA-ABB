# TDA ABB

Alumno: Sixto Gaspar Nahuel Franco - 108352 - sgfranco@fi.uba.ar

- Para compilar:

```bash
make pruebas_alumno
```

- Para ejecutar:

```bash
make pruebas
```

- Para ejecutar con valgrind:
```bash
make valgrind-alumno
```
---
##  Funcionamiento

El trabajo de arboles en general permite entender el funcionamiento y como manipular este tipo de dato. 
Se lo entiende a traves de funciones basicas (abb_crear, abb_insertar, abb_buscar, abb_vacio, abb_quitar, abb, tamanio, abb_destruir) tambien hay distintos recorridos para los arboles, inorden, preorden y postorden.

Es importante aclarar que este arbol binario se inserta de una forma predeterminada, los elementos mayores al nodo raiz van hacia la derecha y los menores o iguales hacia la izquierda.

Paso a dar una breve descripcion de ellas

- abb_t *abb_crear(abb_comparador comparador);

En esta funcion me encargo de crear e inicializar un nuevo arbol, este arbol es de tipo binario. 

Se usa un comparador que determina el orden de los elementos

paso a mostrar un diagrama de flujo de la funcion:

![](img/diagrama_abb_crear.svg)

Tambien muestro un diagrama de memoria del mismo:

![](img/diagrama_memoria_abb_crear.svg)


- abb_t *abb_insertar(abb_t *arbol, void *elemento);

En esta funcion inserto un elemento en el arbol binario. Se usa para agregar los datos manteniendo una estructura ordenada

- void *abb_quitar(abb_t *arbol, void *elemento);

En la funcion me dedico a quitar un elemento del arbol binario, el dato es uno especifico

- void *abb_buscar(abb_t *arbol, void *elemento);

Me encargo de buscar un elemento en el arbol binario, puedo usar esta funcion para buscar y acceder a un dato especifico del arbol


- bool abb_vacio(abb_t *arbol);

Aca verifico si el arbol esta vacio, puede ser despues de eliminar elementos o simplemente despues de crearlo por dar dos ejemplos, tambien para verificar si hay elementos

- size_t abb_tamanio(abb_t *arbol);

Con esta funcion puedo saber la cantidad de elementos que hay en el arbol.

- void abb_destruir(abb_t *arbol);

En esta funcion me encargo de destruir el arbol y toda la memoria asociada al programa.


## ¿Que es un arbol?

-   Un arbol es un tipo de dato abstracto (TDA), este esta compuesto por nodos que estan conectados entre ellos.
Una forma de explicar los arboles es decir que un arbol tiene un nodo padre, este tiene subnodos (se les puede llamar hijos).
Cada nodo tiene un nodo padre, el unico que no lo tiene es el nodo raiz,que seria el superior a todos. Podemos incluir tambien a los nodos hermanos, que esos mismos serian los que comparten un mismo nodo padre.

![](img/arbol_normal.svg)


## ¿Que es un arbol binario?

-   Un arbol binario es un TDA, este se compone de nodos. Cada nodo solamente puede tener como maximo dos nodos hijos conectados a el, uno izquierdo y uno derecho, puede definirse que si un elemento a insertar es menor que el nodo padre, este se inserta a la izquierda, si es mayor a su derecha.

![](img/arbol_binario.svg)

## ¿Que es un arbol binario de busqueda?

-   Es una estructura de datos con una raiz superior y como maximo dos nodos hijos. La particularidad de este tipo de arbol es que esta ordenado, en esta implementacion los nodos con valor mayor a la raiz van hacia la derecha, los que son de menor o igual valor, van a la izquierda. Esta implementacion facilita la busqueda ya que se encarga de aplicar un sistema de busqueda eficiente.

![](img/arbol_binario_busqueda.svg)

### Operaciones basicas y complejidad en los arboles basicos

Las operaciones que se realizan en los arboles son 3:

Busqueda, insercion y eliminacion

-Busqueda: la complejidad es O(log(n))

-Insercion: la complejidad es O(log(n))

-Eliminacion: la complejidad es O(log(n))

#### Insercion y complejidad en arboles binarios

Se inserta un nodo en una posicion determinada, esto siguiendo un determinado espectro, en este caso mayores a la derecha, menores a la izquierda

La complejidad en el peor caso es O(n), pero si no seria O(log(n))

#### Tipos de recorridos en arboles binarios

Los recorridos son 3:

-Inorden: el recorrido que realiza es izquierda,raiz,derecha.

-Preorden: el recorrido que realiza es raiz,izquierda,derecha.

-Postorden:  el recorrido que realiza es izquierda,derecha,raiz.

La complejidad es O(n), ya que tiene que recorrer todos los nodos del arbol.

### Operaciones basicas en los arboles binarios de busqueda

Las operaciones que se realizan son 3:

Busqueda, insercion y eliminacion

### Insercion y complejidad en arboles binarios de busqueda

Se inserta el nodo en la posicion que le corresponde, como se dijo antes se toma izquierda para numeros menores y derecha para los mayores. Se hace esto para mantener la propiedad de que el arbol siga siendo binario.

La complejidad mayormente es O(log(n)), pero si se trata de un arbol desbalanceado por ejemplo, este podria ser de O(n).

### Busqueda y complejidad en el arbol binario

Se decide que elemento buscar y va comparando, si es menor o mayor al nodo actual, entonces se va desplazando hacia la izquierda o la derecha.

La complejidad es O(log(n)), va a ser O(n) en el peor caso

### Eliminacion y complejidad en el arbol binario

Para implementar esto primero tengo que realizar una busqueda, despues de encontrar el nodo, tengo que realizar una operacion para que el arbol siga cumpliendo sus propiedades, luego de hacer eso elimino el nodo y reorganizo toda la estructura

La complejidad es O(log(n)), va a ser O(n) en el peor caso

## ¿Por qué es importante la distinción de cada uno de estos diferentes tipos de árboles?

ES importante saber las diferencias para entender sobre que usarlas, si por ejemplo necesito una flexibilidad mayor respecto a los nodos puedo directamente usar un arbol generico, ya que puedo tener multiples hijos por cada nodo.

SI necesito una mayor eficiencia y simplificacion puedo usar el arbol binario.

El arbol binario de busqueda puedo necesitarlo por necesidad de eficiencia en operaciones, por ejemplo busqueda, eliminacion e insercion, ya que tengo un orden preestablecido de los datos.


### Implementacion
La implementacion trata sobre arboles binarios, insertar, eliminar y buscar, el tp fue planteado de forma recursiva porque al querer hacer las cosas de forma iterativa encontraba muchas complicaciones, por ejemplo la forma de querer usar los nodos y tambien la eficiencia, el codigo tambien quedaba menos legible.

La dificultad principal respecto al uso de nodos fue el no entender bien el tema del nodo raiz y como se actualizaba cada vez recursivamente, una vez comprendido eso fue mas llevadera la implementacion.

Otra dificultad al realizar el trabajo fue la interpretacion sobre el informe, estaba centrado en explicar las funciones privadas del programa antes que las publicas y tenia una gran confusion en ese caso.